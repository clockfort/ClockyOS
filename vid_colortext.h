#ifndef VIDCOLORGUARD
#define VIDCOLORGUARD
#define terminal_color 0x07
#define bsod_color 0x1f
#define dec_term_color 0x2a
#define green_on_black 0x02
#define blue_on_black 0x01

#define terminal_width 80
#define terminal_height 25

#define vid_mem_start ((unsigned char *) 0xb8000)
#define vid_mem_end   ((unsigned char *) 0xb8fa0)

void k_scroll();
void k_clr();
void k_cputch(char character, char attr);
void k_putch(char c);
void k_puts(char *string);
void k_cputs(char *string, char attr);
void k_set_cursor_x(char x);
#endif
