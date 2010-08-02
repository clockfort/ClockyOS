extern void k_puts(char *);
extern void k_clr();
extern void k_putch(char);
extern void k_cputs(char *, char attr);
extern char dec_term_color;

int main();

void _start(void)
{
	main();
}
int main(void){
	k_clr();
	k_puts("Video Mode Color Text Driver Online\r\n");
	k_cputs("Gentoo mode enabled!\r\n", (unsigned char) 0x2a );	
	/*for(int i=0; i<13; i++){
	k_puts("Writing text to see if scrolling works!\r\n");
	k_puts("........\r\n");
	}
	k_clr();
	k_puts("Did that clear operation work properly?\r\n");
	*/
	while(1){}
}
 
