#define terminal_color 0x07
#define terminal_width 80
#define terminal_height 25
#define video_memory_start 0xb8000
char cursor_x=0;
char cursor_y=0;
void scroll(){
}
void k_clr(){
	for(unsigned char *vid_mem=(unsigned char *) video_memory_start;
		vid_mem < (unsigned char *) 0xb8fa0; vid_mem+=2){
		*vid_mem=' ';  //set char to space
		*(vid_mem+1)= terminal_color; //set attribute to default
	}
}

void k_putchar(char character, char attr){
	unsigned char *vid_mem=(unsigned char *) video_memory_start+2*(cursor_x+terminal_width*cursor_y);

	if(character==13){//CR
		cursor_x=0;
	}
	else if(character==10){//LF
		cursor_y++;
		if(cursor_y > terminal_height){
			cursor_y=terminal_height;
			scroll();
		}
	}
	else if(cursor_x >= terminal_width){
		cursor_x=0;
		cursor_y++;
		if(cursor_y >= terminal_height){
			cursor_y=terminal_height;
			scroll();
		}
	}
	else if(cursor_y >= terminal_height){
		cursor_y=terminal_height;
		scroll();
	}
	
	if(character!=10 && character !=13){
	//Actually get around to outputing the character
		*vid_mem=character;
		*(++vid_mem)=attr;
		cursor_x++;
	}
}

/* C needs default arguements :-( */
void k_putch(char c){
	k_putchar(c, terminal_color);
}

void k_puts(char *string){
	while(*string != 0){
		k_putch(*string);
		++string;
	}
}


