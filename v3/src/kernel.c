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

#include "kernel.h"
#include "scheduler.h"
#include "video/textmode/serial/serial.h"
#include "io/led/led.h"

int main(void)
{
	// set for 16 MHz clock
	CPU_PRESCALE(0);
	
	initialize_serial();
	send_str(PSTR("Initialized serial communications.\r\n"));
	initialize_led();
	send_str(PSTR("Initialized LED I/O.\r\n"));

	send_str(PSTR("Starting process scheduler..."));
	initialize_scheduler();	
	send_str(PSTR("    ... done.\r\n"));
		
	while(1){
	}
}
