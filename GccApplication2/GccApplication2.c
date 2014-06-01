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

ISR (USI_INTERRUPT){
    USISR = (1<<USIOIF);              //Clear OVF flag

    spiCommand = USIDR;
   
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

void startLightMeasure() {
    ADMUX = LIGHT_MUX;
    ADCSRA = ((1<<ADEN)|(1<<ADSC)|(0<<ADATE)|(0<<ADIF)|(1<<ADIE)|(0<<ADPS2)|(0<<ADPS1)|(0<<ADPS0));
    
    nextSensorValid = (lastSensor != CMD_GET_LIGHT);
    lastSensor = CMD_GET_LIGHT;
}

void startStepMeasure() {
    ADMUX = STEP_MUX;
    ADCSRA = ((1<<ADEN)|(1<<ADSC)|(0<<ADATE)|(0<<ADIF)|(1<<ADIE)|(0<<ADPS2)|(0<<ADPS1)|(0<<ADPS0));
    
    nextSensorValid = (lastSensor != CMD_GET_STEP);
    lastSensor = CMD_GET_STEP;
}
#else //ADC_CONVERTERS

void startLightMeasure() {
    spiResult = 0; // No sensor
    spiResultValid = true;
}

void startStepMeasure() {
    spiResult = 0; // No sensor
    spiResultValid = true;
}
#endif //ADC_CONVERTERS

void executeCommand(uint8_t command) {
    switch (command) {
        case CMD_GET_LIGHT:
            startLightMeasure();
            break;
        case CMD_GET_STEP:
            startStepMeasure();
            break;
        case CMD_LED_FADE_ON:
            setLedFade(true);
            break;
        case CMD_LED_FADE_OFF:
            setLedFade(false);
            break;
        case CMD_LED_SET_ON:
            setLedState(true);
            break;
        case CMD_LED_SET_OFF:
            setLedState(false);
            break;
        case CMD_CONFIG1:
        case CMD_CONFIG2:
        case CMD_NOOP:
        default:
            //Nothing to do.
            break;
    }
    spiCommand = CMD_NOOP; //Command was executed.
}

int main(void)
{
    setup();
    usi_init();

    sei(); //Enable interrupts
    
    while(1)
    {
        if (SS_HIGH) {
            executeCommand(spiCommand);
        }
        runPWM();
    }
    return 0;               /* never reached */
}