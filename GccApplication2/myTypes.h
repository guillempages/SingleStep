/*
 * myTypes.h
 *
 * Created: 29/05/2014 18:19:03
 *  Author: guillem
 */ 

#ifndef MYTYPES_H_
#define MYTYPES_H_

typedef uint8_t bool;
#define true (1)
#define false (0)

#if defined (__AVR_ATtiny85__)

inline void setupPorts() {
        DDRB  = 0b00001010;
        PORTB = 0b00010101;
}

#define SS_HIGH (PINB & (1<<PORTB4))
#define LED_PORT PORTB
#define LED_PORTx (1<<PORTB3)

/* AVR ATtiny 85 */
#elif defined (__AVR_ATtiny24A__)

inline void setupPorts() {
    
}
/* AVR ATtiny 24A */
#else
inline void setupPorts() {
    
}
#endif

#endif /* MYTYPES_H_ */