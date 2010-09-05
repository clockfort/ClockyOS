#ifndef schuleder_h
#define scheduler_h

#include <avr/interrupt.h>
#include "io/led/led.h"

volatile uint8_t proc_timer;

void initialize_scheduler(void);
#endif
