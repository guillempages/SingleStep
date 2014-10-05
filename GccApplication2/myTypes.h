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

#define ADC_CONVERTERS 1
#define ADLARREG ADMUX /* ADLAR bit in ADMUX */
#define MUX_VALUE (1<<ADLAR)
#define TEMP_SELECTOR_MASK 0b00001000 /* ADC4 */
#define TEMP_ADC           0b01101111 /* Mux value for temp in ATtiny85 */

#define RGB_LED_PORT PORTB  // Not enough pins for RGB; 
#define LED_W   LED_PORTx   // Treat all colours as white.
#define LED_R   LED_PORTx
#define LED_G   LED_PORTx
#define LED_B   LED_PORTx

#define USI_INTERRUPT USI_OVF_vect

/* AVR ATtiny 85 */
#elif defined (__AVR_ATtiny2313A__)
inline void setupPorts() {
    DDRA  = 0b00000000;
    PORTA = 0b00000100;
    DDRB  = 0b01000000;
    PORTB = 0b10100000;
    DDRD  = 0b00011101;
    PORTD = 0b00000010;
}
#define SS_HIGH (PIND & (1<<PORTD1))
#define LED_PORT PORTD
#define LED_PORTx (1<<PORTD0)
#undef ADC_CONVERTERS

#define RGB_LED_PORT PORTD
#define LED_W   (1<<PORTD0)
#define LED_R (1 <<PORTD2)
#define LED_G (1 <<PORTD3)
#define LED_B (1 <<PORTD4)


#define USI_INTERRUPT USI_OVERFLOW_vect

/* AVR ATtiny 2331A */
#elif defined (__AVR_ATtiny24A__)

inline void setupPorts() {
    DDRA  = 0b00101011;
    DIDR0 = 0b00101011;
    PORTA = 0b11010000;
    DDRB  = 0b00000001;
    PORTB = 0b00000010;
}
#define SS_HIGH (PINB & (1<<PORTB1))
#define LED_PORT PORTB
#define LED_PORTx (1<<PORTB0)

#define RGB_LED_PORT PORTA
#define LED_W (1<<PORTB0)
#define LED_R (1 <<PORTA3)
#define LED_G (1 <<PORTA1)
#define LED_B (1 <<PORTA0)

#define ADC_CONVERTERS 1
#define ADLARREG ADCSRB /* ADLAR bit in ADCSRB */
#define MUX_VALUE 0
#define TEMP_SELECTOR_MASK 0b00001000 /* If the 4th ADC selector bit is set, read internal temp sensor.*/
#define TEMP_ADC           0b10100010 /* Mux value for temp in ATtiny24 */

#define USI_INTERRUPT USI_OVF_vect

/* AVR ATtiny 24A */
#else
#error "uController not supported"
inline void setupPorts() {
    
}
#endif

#endif /* MYTYPES_H_ */