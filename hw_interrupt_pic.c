#include "hw_interrupt.h"
#include "io_functions.h"

void hw_interrupt_dismiss(unsigned char irq){
if(irq >= 8){ outb(PIC2,PIC_EOI); }
outb(PIC1,PIC_EOI);
}

void hw_interrupt_shift(){
//Save PIC data
unsigned char pic1_mask = inb(PIC1_D);
unsigned char pic2_mask = inb(PIC2_D);

outb(PIC1, PIC_INIT+0x01);//start PIC1 initialization sequence
io_wait();
outb(PIC2, PIC_INIT+0x01);//start PIC2 initialization sequence
io_wait();
outb(PIC1_D, 0x20); //set offset PIC1 
io_wait();
outb(PIC2_D, 0x28);//set offset PIC2
io_wait();
outb(PIC1_D, 4); //continue initialization
io_wait();
outb(PIC2_D, 2);
io_wait();
outb(PIC1_D, 0x01); //set PIC1 to 8086mode
io_wait();
outb(PIC2_D, 0x01); //set PIC2 8086mode
io_wait();


//Restore PIC data
outb(PIC1_D, pic1_mask);
outb(PIC2_D, pic2_mask);
}

