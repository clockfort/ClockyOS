#include "vid_colortext.h"

void tick();
unsigned char gen_random();
int printBoard();
void randomFill();
void time_waster();
void gliderFill();
char getBoard(int height, int width);
void setBoard(int height, int width, int newValue);
char getNext(int height, int width);
void setNext(int height, int width, int newValue);
#define HEIGHT 25
#define WIDTH  40
unsigned char next[2][WIDTH/8+1];
unsigned char internalBoard[HEIGHT][WIDTH/8+1];
unsigned char seed=1324;

void kmain( void* mbd, unsigned int magic )
{
  if ( magic != 0x2BADB002 ){
      k_puts("Bad multibood magic! Email devnull@csh.rit.edu if you got here on an unmodified kernel.\r\n");
      while(1){}
  }
    int generation;
    int notEmpty;
    while(1){
    	randomFill();
        generation=0;
        notEmpty=1;
        while(generation <= 80 && notEmpty){
	    k_clr();
            notEmpty = printBoard();
            tick();
	    ++generation;
	    time_waster();
        }
    }
}

unsigned char gen_random(){
	seed <<= 1;
	seed |= (((seed&2)>>1) ^ ((seed&128)>>7));
	return seed;
}

void time_waster(){
int ceiling=3000;
unsigned char lockers[ceiling+1];
for(int i=1; i<=ceiling+1; i++){
	for(int j=i; j<=ceiling; j++){
		if((j%i)==0)
			lockers[i]=lockers[i]?0:1;
	}
}

}

char getBoard(int height, int width){
    return (internalBoard[height][width/8] >> width%8) & 1;
}
 
 
void setBoard(int height, int width, int newValue){
    if(newValue==1)
        internalBoard[height][width/8]=internalBoard[height][width/8] | (1<<(width%8));
    else
        internalBoard[height][width/8]=internalBoard[height][width/8] & ~(1<<(width%8));
}
 
 
char getNext(int height, int width){
    return (next[height][width/8] >> width%8) & 1;
}
 
 
void setNext(int height, int width, int newValue){
    if(newValue==1)
        next[height][width/8]=next[height][width/8] | (1<<(width%8));
    else
        next[height][width/8]=next[height][width/8] & ~(1<<(width%8));
}
 
 
void tick(){
    int neighbors;
    for(int row=0; row<HEIGHT; row++){
        for(int col=0; col<WIDTH; col++){
            neighbors=0;
            if(row>0){
                if(getBoard(row-1, col)==1)
                    ++neighbors;
                if(col>0){
                    if(getBoard(row-1, col-1)==1)
                        ++neighbors;
                }
            }
            if(row<(HEIGHT-1)){
                if(getBoard(row+1, col)==1)
                    ++neighbors;
                if(col<(WIDTH-1))
                    if(getBoard(row+1, col+1)==1)
                        ++neighbors;
            }
            if(col>0){
                if(getBoard(row, col-1)==1)
                    ++neighbors;
                if(row<(HEIGHT-1)){
                    if(getBoard(row+1, col-1)==1)
                        ++neighbors;
                }
            }
            if(col<(WIDTH-1)){
                if(getBoard(row, col+1)==1)
                    ++neighbors;
                if(row>0){
                    if(getBoard(row-1, col+1)==1)
                        ++neighbors;
                }
            }
 
        if(getBoard(row,col)==1)
            switch(neighbors){
                case 0://starvation
                case 1:
                    setNext(1,col,0);
                    break;
                case 2:
                case 3:
                    setNext(1,col,1);
                    break;
                case 4://overcrowding
                case 5:
                case 6:
                case 7:
                case 8:
                    setNext(1,col,0);
            }
        else if(neighbors==3)//necromancy
            setNext(1,col,1);
        else
            setNext(1,col,0);
        }
 
        if(row==0){
            for(int col=0; col<WIDTH; col++)
                setNext(0, col, getNext(1, col));
        }
        else if(row!=0 && row!=HEIGHT-1){
            //time to flush the buffer
            for(int col=0; col<WIDTH; col++){
                    setBoard(row-1, col, getNext(0,col));
                    setNext(0,col,getNext(1,col));
            }
        }
        else if(row==HEIGHT-1){//we need to flush here too
            for(int col=0; col<WIDTH; ++col){
                setBoard(row-1,col,getNext(0,col));
                setBoard(row, col, getNext(1,col));
            }
        }
    }
}
 
int printBoard(){
    int notEmpty=1;
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            if(getBoard(i,j)==1){
                k_putch((char) (getBoard(i,j)+63));
		k_putch(' ');
                notEmpty=1;
            }
            else
                k_puts("  ");
        }
        k_puts("\r\n");
    }
    return notEmpty;
}
 
void randomFill(){
    for(int i=0; i<HEIGHT; i++)
        for(int j=0; j<WIDTH; j++)
           	setBoard(i,j,gen_random()%2);
}
 
void gliderFill(){
    for(int i=0; i<HEIGHT; i++)
        for(int j=0; j<WIDTH; j++)
            setBoard(i,j,0);
        
    setBoard(0,1,1);
    setBoard(1,2,1);
    setBoard(2,0,1);
    setBoard(2,1,1);
    setBoard(2,2,1);
 
    setBoard(0, 11, 1);
    setBoard(1, 12, 1);
    setBoard(2, 10, 1);
    setBoard(2, 11, 1);
    setBoard(2, 12, 1);
}
 
