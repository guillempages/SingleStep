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
#define USI_INTERRUPT USI_OVF_vect

/* AVR ATtiny 85 */
#elif defined (__AVR_ATtiny2313A__)
inline void setupPorts() {
    DDRB  = 0b01000000;
    PORTB = 0b10100000;
    DDRD  = 0b00000001;
    PORTD = 0b00000010;
}
#define SS_HIGH (PIND & (1<<PORTD1))
#define LED_PORT PORTD
#define LED_PORTx (1<<PORTD0)
#define USI_INTERRUPT USI_OVERFLOW_vect

/* AVR ATtiny 2331A */
#elif defined (__AVR_ATtiny24A__)

inline void setupPorts() {
    
}
/* AVR ATtiny 24A */
#else
inline void setupPorts() {
    
}
#endif

#endif /* MYTYPES_H_ */