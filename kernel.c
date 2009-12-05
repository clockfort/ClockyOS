extern void k_puts(char *);
extern void k_clr();
int main();

void _start(void)
{
	main();
}
int main(void){
	k_clr();
	k_puts("Video Mode Color Text Driver Online\n");
	while(1){}
}
