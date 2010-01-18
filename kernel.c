#include "vid_colortext.h"
#include "hw_interrupt.h"

void kmain( void* mbd, unsigned int magic )
{
  if ( magic != 0x2BADB002 ){
      k_puts("Bad multiboot magic! Email devnull@csh.rit.edu if you got here on an unmodified kernel.\r\n");
      while(1){}
  }
 
  k_clr();
  k_cputs("Initialized color textmode video driver.\r\n", bsod_color );

  k_puts("Setting up hardware interrupts (Shifting PIC offsets)... ");
  hw_interrupt_shift();
  k_cputs(" done!\r\n", bsod_color);
  
  while(1){}
}
