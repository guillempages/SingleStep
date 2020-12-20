#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "myTypes.h"

typedef enum {Blue, Green, Red, White, MAX} LedId;

void initLeds();

void runPWM();

void setLedFade(uint8_t value);

void setLedState(uint8_t value);

void setLedValue(LedId led, uint8_t value);

#endif //LED_CONTROL_H
