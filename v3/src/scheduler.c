#include "scheduler.h"

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
                        send_str_from_ram("Ping!\r\n");
                }
}

void initialize_scheduler(){
        //Set CPU clock divider to ~61Hz
        TCCR0B |= _BV(CS02) | _BV(CS00);

        //Interrupt on timer0 overflow
        TIMSK0 |= _BV(TOIE0);

        proc_timer=0;
        TCNT0 = 0;

	//Enable interrupts
	sei();
}
