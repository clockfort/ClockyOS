#define terminal_color 0x07
#define terminal_width 80
#define terminal_height 25
#define video_memory_start 0xb8000;
char cursor_x=0;
char cursor_y=0;

void k_clr(){
	for(unsigned char *vid_mem=video_memory_start; vid_mem < (unsigned char) 0xb8fa0; vid_mem+=2){
		*vid_mem=' ';  //set char to space
		*(vid_mem+1)= terminal_color; //set attribute to default
	}
}

void k_putch(char character, char attr){
	unsigned char *vid_mem=video_memory_start+2*(cursor_x+terminal_width*cursor_y);

	if(character==13){//CR
		cursor_x=0;
	}
	if(character==10){//LF
		cursor_y++;
		if(cursor_y >= terminal_height){
			cursor_y=terminal_height;
			scroll();
		}
	}
	*vid_mem=character;
        ++(*vid_mem)=attr;
	

	if(cursor_x >= terminal_width){
		cursor_x=0;
		cursor_y++;
		if(cursor_y >= terminal_height){
			cursor_y=terminal_height;
			scroll();
		}
	}

}

/* C needs default arguements :-( */
void k_putch(char c){
	k_putch(c, terminal_color);
}

void scroll(){
	
}

void k_puts(char *string){
	while(*string != 0)
		putch(*string);
		++string;
	}
}


