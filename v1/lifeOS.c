extern void k_puts(char *);
extern void k_clr();
extern void k_putch(char);

void main();
void tick();
int printBoard();
void randomFill();
void gliderFill();
char getBoard(int height, int width);
void setBoard(int height, int width, int newValue);
char getNext(int height, int width);
void setNext(int height, int width, int newValue);
#define HEIGHT 20
#define WIDTH  40
unsigned char next[2][WIDTH/8+1];
unsigned char internalBoard[HEIGHT][WIDTH/8+1];

void _start(void)
{
	main();
}
/**
int main(void){
	k_clr();
	k_puts("Video Mode Color Text Driver Online\r\n");
	for(int i=0; i<13; i++){
	k_puts("Writing text to see if scrolling works!\r\n");
	k_puts("........\r\n");
	}

	while(1){}
}
**/
 
void main() {
    int generation;
    int notEmpty;
    while(1){
        gliderFill();
        generation=0;
        notEmpty=1;
        while(generation <= 800 && notEmpty){
            notEmpty = printBoard();
            tick();
	    ++generation;
        }

	
	k_clr();
	
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
           	setBoard(i,j,j%2);
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
 
