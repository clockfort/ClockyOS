#ifndef IO_FUNCTIONS_H
#define IO_FUNCTIONS_H

static __inline__ void outb(unsigned short port, unsigned char val)
{
   asm volatile("outb %0,%1"::"a"(val), "Nd" (port));
}

static __inline__ unsigned char inb(unsigned short port)
{
   unsigned char ret;
   asm volatile ("inb %1,%0":"=a"(ret):"Nd"(port));
   return ret;
}

static __inline__ void io_wait(void)
{
   asm volatile("outb %%al, $0x80" : : "a"(0));
}

#endif
