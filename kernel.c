#include "vid_colortext.h"

void kmain( void* mbd, unsigned int magic )
{
  if ( magic != 0x2BADB002 ){
      k_puts("Bad multibood magic! Email devnull@csh.rit.edu if you got here on an unmodified kernel.\r\n");
      while(1){}
  }
 
  k_clr();
  k_puts("Video Mode Color Text Driver Online\r\n");
  k_cputs("Gentoo mode enabled!\r\n", dec_term_color );
  k_cputs("BSOD?\r\n", bsod_color ); 
  while(1){}
}
