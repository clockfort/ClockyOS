#ifndef kernel_h
#define kernel_h

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

#endif
