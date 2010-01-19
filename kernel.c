#include "vid_colortext.h"
#include "vid_boottext.h"
#include "hw_interrupt.h"

void kmain( void* mbd, unsigned int magic )
{
  if ( magic != 0x2BADB002 ){
      k_puts("Bad multiboot magic! Email devnull@csh.rit.edu if you got here on an unmodified kernel.\r\n");
      while(1){}
  }
 
  k_clr();
  k_print_msg("Initialized color textmode video driver.");
  k_module_start_print("Setting up hardware interrupts (Shifting PIC offsets)...");
  hw_interrupt_shift();
  k_module_start_print_done();
  
  while(1){}
}

