#ifndef COMMANDS_H
#define COMMANDS_H

#define CMD_NOOP          0b00000000
#define CMD_CONFIG1       0b01010101  //This command will be forwarded as such; can be used to check the number of slaves.
#define CMD_CONFIG2       0b01010100  //This command will be forwarded as such; can be used to check the number of slaves.
#define CMD_LED_SET       0b00110000  //Commands to switch the LED on or off, depending on the last bit.
#define CMD_LED_SET_OFF   CMD_LED_SET        //Switch the LED off, regardless of the current status.
#define CMD_LED_SET_ON    (CMD_LED_SET | 1)  //Switch the LED on, regardless of the current status. 
#define CMD_LED_FADE      0b00100000         //Fade the LED slowly on or off, depending on the last bit.
#define CMD_LED_FADE_OFF  CMD_LED_FADE       //Fade the LED slowly off.
#define CMD_LED_FADE_ON   (CMD_LED_FADE | 1)  //Fade the LED slowly on.
#define CMD_GET_STEP      0b00010000         //Get the value of the (step) sensor ADC converter
#define CMD_GET_LIGHT     0b00010001         //Get the value of the (light) sensor ADC converter

#endif //COMMANDS_H
