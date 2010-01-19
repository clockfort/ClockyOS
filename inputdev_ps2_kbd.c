
char input_buffer= new char[64];
char reader=0;
char writer=0;

void keyboard_ISR(){
	byte scan_code = inportb(0x60);//take in scan_code
	//Disable irqs here please
	
	//if input_buffer[writer]==0
	//   translate scan code to ascii
	//   put in input_buffer[writer]
	//   increment writer
	//else
	//   do nothing
	//re-enable irqs here please

	dismiss_interrupt(1);
}

void update_leds(uint8_t status_leds){
	while((inportb(0x64)&2)!=0){} //wait until kbd buffer empty
	outportb(0x60,0xED);
 
	while((inportb(0x64)&2)!=0){} //wait until kbd buffer empty
	outportb(0x60,status_leds);
}

/* next_char() returns the next character in the keyboard buffer,
 * or returns zero if there is no next character to be read.
 *
 * TO-DO: Add interrupt disabling
 */
char next_char(){
	//Disable irqs here please
	char current = input_buffer[reader]; //read
	if(current == 0){
		return 0;
	}
	else{
	input_buffer[reader++]=0; //mark as read and increment reader pointer
	//re-enable irqs here please
	return current;
	}
}
