#ifndef HW_INT_GUARD
#define HW_INT_GUARD

#define PIC1 0x20
#define PIC2 0xA0
#define PIC1_D (PIC1+1)
#define PIC2_D (PIC2+1)
#define PIC_EOI 0x20
#define PIC_INIT 0x10

void hw_interrupt_dismiss(unsigned char irq);

void hw_interrupt_shift();

#endif
