#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "myTypes.h"

void initLeds();

void runPWM();

void switchLed(bool value);

void setLedFade(bool value);

void setLedState(bool value);

#endif //LED_CONTROL_H
