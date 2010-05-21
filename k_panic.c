#include "k_panic.h"
#include "vid_colortext.h"

void k_panic(char *string){
k_cputs("KERNEL PANIC: ", red_on_black);
k_puts(string);
//should disable interrupts here, but I don't have that controlling code yet
while(1){}
}

