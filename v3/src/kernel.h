#ifndef kernel_h
#define kernel_h

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_CONFIG      (DDRD |= (1<<6))
#define LED_OFF         (PORTD &= ~(1<<6))
#define LED_ON          (PORTD |= (1<<6))
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

volatile uint8_t proc_timer;

#endif
