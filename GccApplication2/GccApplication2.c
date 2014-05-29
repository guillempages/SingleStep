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
    DDRB  = 0b00001010;
    PORTB = 0b00010101;

    initLeds();
}

void usi_init(void){
    USICR = ((0<<USISIE)|(1<<USIOIE)|(0<<USIWM1)|(1<<USIWM0)|(1<<USICS1)|(0<<USICS0)|(0<<USICLK)|(0<<USITC));
}

volatile uint8_t spiCommand = 0;
volatile uint8_t spiResult = 0;

ISR (USI_OVF_vect){
    USISR = (1<<USIOIF);              //Clear OVF flag
    
    if (spiResult != 0) {
        USIDR = spiResult;
        spiResult = 0;
    }
    spiCommand = USIBR;
}

void executeCommand(uint8_t command) {
    switch (command) {
        case CMD_GET_LIGHT:
            spiResult = 123;
            break;
        case CMD_GET_STEP:
            spiResult = 231;
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
        if (PORTB & (1<<PORTB4)) {
            executeCommand(spiCommand);
        }
        runPWM();
    }
    return 0;               /* never reached */
}