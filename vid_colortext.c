#define terminal_color 0x07
#define bsod_color 0x1f
#define dec_term_color 0x2a
#define terminal_width 80
#define terminal_height 25
#define vid_mem_start ((unsigned char *) 0xb8000)
#define vid_mem_end   ((unsigned char *) 0xb8fa0)
char cursor_x=0;
char cursor_y=0;

void k_scroll(){
	for(unsigned char *vid_mem= vid_mem_start;
		vid_mem < vid_mem_end; vid_mem+=2){
		if(vid_mem+160 < vid_mem_end){
			*(vid_mem)=*(vid_mem+160);
			*(vid_mem+1)=*(vid_mem+161);
		}
		else{//erase
			*vid_mem=' ';
			*(vid_mem+1)=terminal_color;
		}
	}
}

void k_clr(){
	for(unsigned char *vid_mem= vid_mem_start;
		vid_mem < vid_mem_end; vid_mem+=2){
		*vid_mem=' ';  //set char to space
		*(vid_mem+1)= terminal_color; //set attribute to default
	}
	cursor_x=0;
	cursor_y=0;
}

void k_cputch(char character, char attr){
	unsigned char *vid_mem=vid_mem_start+2*(cursor_x+terminal_width*cursor_y);
	if(character==0){//null
		//I guess we do nothing? I guess?
	}
	else if(character==13){//CR
		cursor_x=0;
	}
	else if(character==10){//LF
		cursor_y++;
		if(cursor_y > terminal_height){
			cursor_y=terminal_height;
			k_scroll();
		}
	}
	else if(cursor_x >= terminal_width){
		cursor_x=0;
		cursor_y++;
		if(cursor_y >= terminal_height){
			cursor_y=terminal_height;
			k_scroll();
		}
	}
	else if(cursor_y >= terminal_height){
		cursor_y=terminal_height;
		k_scroll();
	}
	
	if(character!=10 && character !=13 && character !=0){
	//Actually get around to outputing the character
		*vid_mem=character;
		*(++vid_mem)=attr;
		cursor_x++;
	}
}

/* C needs default arguements :-( */
void k_putch(char c){
	k_cputch(c, terminal_color);
}

void k_puts(char *string){
	while(*string != 0){
		k_putch(*string);
		++string;
	}
}

void k_cputs(char *string, char attr){
	while(*string != 0){
		k_cputch(*string, attr);
		++string;
	}
}
