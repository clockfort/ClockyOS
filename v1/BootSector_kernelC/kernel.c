
extern void scrollup(unsigned int);
extern void print(char *);

extern kY;
extern kattr;

int main();

void _start(void)
{
	main();
}

int main(void)
{
	kY = 16;

	kattr = 0x5E;
	print("un message\n");

	kattr = 0x4E;
	print("un autre message\n");

	scrollup(2);

	while (1);
}
