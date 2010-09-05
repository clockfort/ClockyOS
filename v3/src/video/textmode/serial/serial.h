#ifndef serial_h
#define serial_h
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "usb_serial.h"

void initialize_serial(void);
uint8_t host_is_ready(void);
void block_on_host(void);
void send_str(const char *s);
void send_str_from_ram(const char *s);
uint8_t recv_str(char *buf, uint8_t size);

#endif
