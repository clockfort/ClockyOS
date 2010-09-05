#ifndef led_h
#define led_h

#include <avr/io.h>

#define LED_CONFIG      (DDRD |= (1<<6))
#define LED_OFF         (PORTD &= ~(1<<6))
#define LED_ON          (PORTD |= (1<<6))

#endif
