/*
 * GccApplication2.c
 *
 * Created: 17/05/2014 22:30:50
 *  Author: guillem
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "commands.h"

typedef uint8_t bool;
const bool true = 1;
const bool false = 0;

const uint8_t LED_OFF_FREQ = 0;
const uint8_t LED_ON_FREQ = 127;

bool ledStatus;
int8_t currentTrigger;

void switchLed(bool value) {
	if (value) {
		PORTB |= (1<<PORTB3);    /* switch LED on */
	} else {
	    PORTB &= ~(1<<PORTB3);    /* switch LED off */
   }
}

void setup() {
    DDRB  = 0b00001010;
    PORTB = 0b00010101;

    ledStatus = false;
    currentTrigger = LED_ON_FREQ;
}

void usi_init(void){
    USICR = ((0<<USISIE)|(1<<USIOIE)|(0<<USIWM1)|(1<<USIWM0)|(1<<USICS1)|(0<<USICS0)|(0<<USICLK)|(0<<USITC));
}

void runPWM() {
    static int8_t currentCount = LED_OFF_FREQ;

	if (ledStatus) {
    	if (currentCount < LED_ON_FREQ) {
       		currentCount++;
    	} else {
        	currentCount = LED_OFF_FREQ;
    	    if (currentTrigger > LED_OFF_FREQ) {
       		    currentTrigger--;
    	    }
  	    }
   	} else {
       	if (currentCount > LED_OFF_FREQ) {
       		currentCount--;
       	} else {
       		currentCount = LED_ON_FREQ;
       		if (currentTrigger < LED_ON_FREQ) {
           		currentTrigger++;
       		}
    	}
	}
    switchLed(currentCount > currentTrigger);
}

void setLedFade(bool value) {
    if (value) {
        ledStatus = true;
    } else {
        ledStatus = false;
    }
}

void setLedState(bool value) {
    if (value) {
        if (!ledStatus) {
            currentTrigger = LED_OFF_FREQ;
        }
            ledStatus = true;
        } else {
        if (ledStatus) {
            currentTrigger = LED_ON_FREQ;
        }
        ledStatus = false;
    }
}

volatile uint8_t SpiCommand = 0;
volatile uint8_t SpiResult = 0;

ISR (USI_OVF_vect){
    USISR = (1<<USIOIF);              //Clear OVF flag
    
    if (SpiResult != 0) {
        USIDR = SpiResult;
        SpiResult = 0;
    }

    SpiCommand = USIBR;
}

void executeCommand(uint8_t command) {
    switch (command) {
        case CMD_GET_LIGHT:
            SpiResult = 123;
            break;
        case CMD_GET_STEP:
            SpiResult = 231;
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
    SpiCommand = 0; //Command was executed.
}

int main(void)
{
    setup();
    usi_init();

    sei(); //Enable interrupts
    
    while(1)
    {
        if (PORTB & (1<<PORTB4)) {
            executeCommand(SpiCommand);
        }
        runPWM();
    }
    return 0;               /* never reached */
}