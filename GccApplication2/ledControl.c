#include <avr/io.h>
#include "myTypes.h"
#include "ledControl.h"

const uint8_t LED_OFF_FREQ = 0;
const uint8_t LED_ON_FREQ = 127;

bool ledStatus;
int8_t currentTrigger;

void initLeds() {
    ledStatus = false;
    currentTrigger = LED_ON_FREQ;
}    

void switchLed(bool value)
{
	if (value) {
		LED_PORT |= LED_PORTx;    /* switch LED on */
	} else {
	    LED_PORT &= ~LED_PORTx;    /* switch LED off */
   }
}

void runPWM()
{
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

void setLedFade(bool value)
{
    ledStatus = value;
}

void setLedState(bool value)
{
	if (value) {
        if (!ledStatus) {
            currentTrigger = LED_OFF_FREQ;
        }
    } else {
        if (ledStatus) {
            currentTrigger = LED_ON_FREQ;
        }
    }
    ledStatus = value;
}
