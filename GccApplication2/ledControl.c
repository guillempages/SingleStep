#include <avr/io.h>
#include "myTypes.h"
#include "ledControl.h"

const uint8_t LED_OFF_FREQ = 64;
const uint8_t LED_ON_FREQ = 127;

typedef enum {Blue, Green, Red, White, MAX=4} LedId;


bool ledStatus[MAX];
int8_t currentTrigger[MAX];
int8_t currentCount[MAX];

void initLeds() {
    for (int i = 0; i<MAX; i++) {
        ledStatus[i] = false;
        currentTrigger[i] = LED_ON_FREQ;
        currentCount[i] = LED_OFF_FREQ;
    }    
}    

void switchLed(LedId led, bool value)
{
    switch (led) {
        case White:
    	    if (value) {
	    	    LED_PORT |= LED_PORTx;    /* switch LED on */
    	    } else {
	            LED_PORT &= ~LED_PORTx;    /* switch LED off */
            }
            break;
        case Red:
            if (!value) {
                RGB_LED_PORT |= LED_R;    /* switch LED on */
            } else {
                RGB_LED_PORT &= ~LED_R;    /* switch LED off */
            }
            break;
        case Green:
            if (!value) {
                RGB_LED_PORT |= LED_G;    /* switch LED on */
            } else {
                RGB_LED_PORT &= ~LED_G;    /* switch LED off */
            }
            break;
        case Blue:
           if (!value) {
                RGB_LED_PORT |= LED_B;    /* switch LED on */
           } else {
                RGB_LED_PORT &= ~LED_B;    /* switch LED off */
           }
           break;
    }
}

void runPWMInternal(LedId led)
{
    if (ledStatus[led]) {
        if (currentCount[led] < LED_ON_FREQ) {
            currentCount[led]++;
        } else {
            currentCount[led] = LED_OFF_FREQ;
            if (currentTrigger[led] > LED_OFF_FREQ) {
                currentTrigger[led]--;
            }
        }
    } else {
        if (currentCount[led] > LED_OFF_FREQ) {
            currentCount[led]--;
        } else {
            currentCount[led] = LED_ON_FREQ;
            if (currentTrigger[led] < LED_ON_FREQ) {
                currentTrigger[led]++;
            }
        }
    }
    switchLed(led, currentCount[led] > currentTrigger[led]);
}

void runPWM() {
    for (int led = 0; led<MAX; led++) {
        runPWMInternal(led);
    }
}

void setLedFade(uint8_t value)
{
    for (int led = 0; led<=MAX; led++) {
        ledStatus[led] = value & (1<<led);
    }
}

void setLedState(uint8_t value)
{
    for (int led = 0; led <= MAX; led++) {
	    if (value & (1<<led)) {
            if (!ledStatus[led]) {
                currentTrigger[led] = LED_OFF_FREQ;
            }
        } else {
            if (ledStatus[led]) {
                currentTrigger[led] = LED_ON_FREQ;
            }
        }
        ledStatus[led] = value;
    }
}
