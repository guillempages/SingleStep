#include <avr/io.h>
#include "myTypes.h"
#include "ledControl.h"

const uint8_t LED_OFF_FREQ = 0;
const uint8_t LED_ON_FREQ = 16;
const uint8_t FADE_COUNTER_FREQ = 3;
bool fade = false;

typedef enum {Blue, Green, Red, White, MAX} LedId;


bool ledStatus[MAX];
int8_t currentTrigger[MAX];
int8_t currentCount[MAX];
int8_t fadeCounter[MAX];

void initLeds()
{
    for (int i = 0; i<MAX; i++) {
        ledStatus[i] = false;
        currentTrigger[i] = LED_OFF_FREQ;
        currentCount[i] = LED_OFF_FREQ;
		fadeCounter[i] = 0;
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
    if (currentCount[led] >= LED_ON_FREQ) {
        currentCount[led] = LED_OFF_FREQ;
    } else {
        currentCount[led]++;
    }
    if (fade && currentCount[led] == LED_OFF_FREQ) {
        fadeCounter[led]++;
        fadeCounter[led] %= FADE_COUNTER_FREQ;
        if (ledStatus[led] && currentTrigger[led] < LED_ON_FREQ) {
            if (fadeCounter[led] == 0) {
                currentTrigger[led]++;
            }
        } else if (!ledStatus[led] && currentTrigger[led] > LED_OFF_FREQ) {
            if (fadeCounter[led] == 0) {
                currentTrigger[led]--;
            }
        }
    }
    switchLed(led, currentCount[led] < currentTrigger[led]);
}

void runPWM()
{
    for (int led = 0; led<MAX; led++) {
        runPWMInternal(led);
    }
}

void setLedFade(uint8_t value)
{
    fade = true;
    for (int led = 0; led < MAX; led++) {
        ledStatus[led] = value & (1<<led);
    }
}

void setLedState(uint8_t value)
{
    fade = false;
    for (int led = 0; led < MAX; led++) {
        if (value & (1<<led)) {
            currentTrigger[led] = LED_ON_FREQ;
        } else {
            currentTrigger[led] = LED_OFF_FREQ;
        }
    }
}

void setLedValue(uint8_t led, uint8_t value)
{
    fade = false;
    currentTrigger[led] = value;
}
