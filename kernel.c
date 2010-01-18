#include "vid_colortext.h"
#include "hw_interrupt.h"

void kmain( void* mbd, unsigned int magic )
{
  if ( magic != 0x2BADB002 ){
      k_puts("Bad multiboot magic! Email devnull@csh.rit.edu if you got here on an unmodified kernel.\r\n");
      while(1){}
  }
 
  k_clr();
  k_cputs(" >>", green_on_black);
  k_puts("Initialized color textmode video driver.\r\n");
  k_cputs("*", green_on_black);
  k_puts("Setting up hardware interrupts (Shifting PIC offsets)...     ");
  hw_interrupt_shift();

  k_cputs("[",blue_on_black);
  k_cputs(" ok ", green_on_black);
  k_cputs("]\r\n",blue_on_black);
  
  while(1){}
}

