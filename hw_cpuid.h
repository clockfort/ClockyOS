#ifndef HW_CPU_H
#define HW_CPU_H
#include "vid_boottext.h"

void cpuid_string();
void cpuid_get_features();

struct cpu_features_ecx{
unsigned int stuff_I_dont_care_about: 11;
unsigned char SSE42: 1;
unsigned char SSE41: 1;
unsigned int still_dont_care: 9;
unsigned char SSSE3: 1;
unsigned char TM2: 1;
unsigned char speedstep: 1;
unsigned char yep_dont_care: 6;
unsigned char SSE3: 1;
};

struct cpu_features_edx{
unsigned char stuff_I_dont_care_about: 3;
unsigned char hyperthreading: 1;
unsigned char selfsnoop: 1;
unsigned char SSE2: 1;
unsigned char SSE: 1;
unsigned char FXSR: 1;
unsigned char MMX: 1;
unsigned char still_dont_care: 22;
unsigned char FPU: 1;
}
#endif
