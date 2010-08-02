#include "vid_colortext.h" 

void k_module_start_print(char *string){
k_cputs(" * ", green_on_black);
k_puts(string);
}

void k_module_start_print_done(){
k_set_cursor_x(73);
k_cputs("[", blue_on_black);
k_cputs(" ok ", green_on_black);
k_cputs("]\r\n", blue_on_black);
}

void k_print_msg(char *string){
k_cputs(">> ", green_on_black);
k_puts(string);
k_puts("\r\n");
}
