/*
 * GccApplication2.c
 *
 * Created: 17/05/2014 22:30:50
 *  Author: guillem
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "myTypes.h"
#include "commands.h"
#include "ledControl.h"

bool testMode = true;

void setup() {
    setupPorts(); // see myTypes.h
    
#ifdef ADC_CONVERTERS
    PRR &= ~(1<<PRADC); //Activate ADC
    ADLARREG |= (1<<ADLAR); //ADC Result left adjusted
#endif 

    initLeds();
}

void usi_init(void){
    USICR = ((0<<USISIE)|(1<<USIOIE)|(0<<USIWM1)|(1<<USIWM0)|(1<<USICS1)|(0<<USICS0)|(0<<USICLK)|(0<<USITC));
}

volatile uint8_t spiCommand = 0;
volatile uint8_t spiResult = 0;
volatile bool spiResultValid = false;
volatile bool spiCommandValid = false;

volatile uint8_t eepromAddress = 0;
volatile bool writeEeprom = false;



ISR (USI_INTERRUPT){
    USISR = (1<<USIOIF);              //Clear OVF flag

    spiCommand = USIDR;
    spiCommandValid = true;
   
    if (spiResultValid) {
        USIDR = spiResult;
        spiResultValid = false;
    }
}

#ifdef ADC_CONVERTERS

uint8_t lastSensor = 0;
bool nextSensorValid = false;

ISR(ADC_vect) {
    if (!nextSensorValid) {
        ADCSRA = ((1<<ADEN)|(1<<ADSC)|(0<<ADATE)|(0<<ADIF)|(1<<ADIE)|(0<<ADPS2)|(0<<ADPS1)|(0<<ADPS0));
        nextSensorValid = true;
    } else {
        spiResult = ADCH;
        if (spiResult >= 250) { //Too high values mean no sensor present.
            spiResult = 0;
        }
        spiResultValid = true;
    }
}

void startMeasure(uint8_t address) {
    address &= CMD_PARAM_MASK;
    
    if (address & TEMP_SELECTOR_MASK) {
        ADMUX = TEMP_ADC;
    } else {
        ADMUX = (MUX_VALUE | address);
    }    
    ADCSRA = ((1<<ADEN)|(1<<ADSC)|(0<<ADATE)|(0<<ADIF)|(1<<ADIE)|(0<<ADPS2)|(0<<ADPS1)|(0<<ADPS0));
    
    nextSensorValid = (lastSensor != address);
    lastSensor = address;
}

#else //ADC_CONVERTERS

void startMeasure(uint8_t address) {
    spiResult = 0; // No sensor
    spiResultValid = true;
}
#endif //ADC_CONVERTERS

void EEPROM_write(unsigned int ucAddress, unsigned char ucData) {
    /*
    Wait for completion of previous write
    */
    while(EECR & (1<<EEPE));

    /* Set Programming mode */
    EECR = (0<<EEPM1)|(0<<EEPM0);
    /* Set up address and data registers */
    EEAR = ucAddress;
    EEDR = ucData;
    /* Write logical one to EEMPE */
    EECR |= (1<<EEMPE);
    /* Start eeprom write by setting EEPE */
    EECR |= (1<<EEPE);
}

unsigned char EEPROM_read(unsigned int ucAddress) {
    /* Wait for completion of previous write */
    while (EECR & (1<<EEPE));
    
    /* Set up address register */
    EEAR = ucAddress;
    /* Start eeprom read by writing EERE */
    EECR |= (1<<EERE);
    /* Return data from data register */
    return EEDR;
}    

void executeCommand(uint8_t command) {
    testMode = false;

    switch (command & CMD_COMMAND_MASK) {
        case CMD_READ_SENSOR:
            startMeasure(command & CMD_PARAM_MASK);
            break;
        case CMD_LED_FADE:
            setLedFade(command & CMD_PARAM_MASK);
            break;
        case CMD_LED_SET:
            setLedState(command & CMD_PARAM_MASK);
            break;
        case CMD_GET_THRESHOLD:
            spiResult = EEPROM_read(command & CMD_PARAM_MASK);
            spiResultValid = true;
            break;
        case CMD_SET_THRESHOLD:
            eepromAddress = command & CMD_PARAM_MASK;
            writeEeprom = true; //
            break;
        case CMD_INIT_1:
        case CMD_INIT_2:
        case CMD_NOOP:
        default:
            //Nothing to do.
            break;
    }
    spiCommand = CMD_NOOP; //Command was executed.
}

void runTestMode() {
    static uint16_t i = 0;
    static uint8_t value = 0;

    if (i == 0) {
        // Make the white LED blink as fast as the Green value, so that boards with only
        // White LED can be tested more easily
        uint8_t flippedValue = ((value & 2)<<2) | (value & 7);
        setLedFade(flippedValue);
        value++;
        value %= 16;
    }
    i++;
    i%= 2048;
}

int main(void)
{
    setup();
    usi_init();

    sei(); //Enable interrupts
    while(1)
    {
        if (SS_HIGH && spiCommandValid) {
            if (writeEeprom) {
                EEPROM_write(eepromAddress, spiCommand);
                writeEeprom = false;
            } else {
                executeCommand(spiCommand);
            }            
            spiCommandValid = false;
        }

        if (testMode) {
            runTestMode();
        }
        runPWM();
    }
    return 0;               /* never reached */
}