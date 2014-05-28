/*
 * GccApplication2.c
 *
 * Created: 17/05/2014 22:30:50
 *  Author: guillem
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

typedef uint8_t bool;
const bool true = 1;
const bool false = 0;

const uint8_t LED_OFF_FREQ = 0;
const uint8_t LED_ON_FREQ = 127;

void switchLed(bool value) {
	if (value) {
		PORTB |= 0b00001000;    /* switch LED on */
	} else {
	    PORTB &= 0b11110111;    /* switch LED off */
   }
}

void setup() {
//	DDRB = 0b00001000;           /* make the PB3 an output */
    DDRB = 0b00011010;
    PORTB = 0b00000101;
}

void usi_init(void){
    USICR = ((0<<USISIE)|(1<<USIOIE)|(0<<USIWM1)|(1<<USIWM0)|(1<<USICS1)|(0<<USICS0)|(0<<USICLK)|(0<<USITC));
}

void runPWM(bool value) {
    static bool ledStatus = false;
    static int8_t currentCount = LED_OFF_FREQ;
    static int8_t currentTrigger = LED_ON_FREQ;

	if (value) {
    	if (!ledStatus) {
       		currentTrigger = LED_OFF_FREQ;
    	}
    	ledStatus = true;
    } else {
    	ledStatus = false;
	}

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

volatile unsigned char SPI_Data = 0;

ISR (USI_OVF_vect){
    USISR = (1<<USIOIF);              //Clear OVF flag
    USIDR = SPI_Data;
    SPI_Data = USIBR;
}

int main(void)
{
    setup();
    usi_init();

    sei(); //Enable interrupts
    
    while(1)
    {
        runPWM(SPI_Data >= 100);
    }
    return 0;               /* never reached */
}