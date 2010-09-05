/*
 * Copyright (c) 2010 Chris Lockfort <clockfort@csh.rit.edu>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_CONFIG	(DDRD |= (1<<6))
#define LED_OFF		(PORTD &= ~(1<<6))
#define LED_ON		(PORTD |= (1<<6))
#define CPU_PRESCALE(n)	(CLKPR = 0x80, CLKPR = (n))

volatile uint8_t proc_timer;

ISR(TIMER0_OVF_vect){
		++proc_timer;
		if(proc_timer<=61){
			LED_ON;
		}
		else{
			LED_OFF;
		}
		if(proc_timer>=122){
			proc_timer=0;
		}
}

int main(void)
{
	// set for 16 MHz clock
	CPU_PRESCALE(0);
	
	//Configure LED port
	LED_CONFIG;
	LED_OFF;
	
	//Set CPU clock divider to ~61Hz
	TCCR0B |= _BV(CS02) | _BV(CS00);

	//Interrupt on timer0 overflow
	TIMSK0 |= _BV(TOIE0);

	proc_timer=0;
	TCNT0 = 0;

	//Enable interrupts
	sei();
	
	//Set washer to spin cycle
	while(1){
	}
}
