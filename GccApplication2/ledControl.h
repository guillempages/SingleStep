#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "myTypes.h"

void initLeds();

void runPWM();

void setLedFade(uint8_t value);

void setLedState(uint8_t value);

#endif //LED_CONTROL_H
