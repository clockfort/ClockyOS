void keyboard_ISR(){
	byte scan_code = inportb(0x60);//take in scan_code

	outportb(0x20,0x20);//acknowledge IRQ
}
