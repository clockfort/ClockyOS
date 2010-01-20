#include "hw_cpuid.h"

void cpuid_string(){
        int word[4];
        char type=0;
        asm volatile("cpuid":"=b"(word[0]),
                     "=c"(word[2]),"=d"(word[1]):"0"(type));
        char *str = (char *) word;
        str[12]='\0';
        k_print_msg(str);
}

void cpuid_get_features(){
	int word[4];
	char type=1;
	asm volatile("cpuid":"=a"(word[0]),"=b"(word[1]),"=c"(word[2]),"=d"(word[3]):"0"(type));
	cpu_features_edx edx;
	*((int *)(&edx)) = word[3];
	if(edx.hyperthreading){
		k_print_msg("Hyperthreading Supported");
	}
	if(edx.SSE){
		k_print_msg("SSE Supported");
	}
	if(edx.SSE2){
		k_print_msg("SSE2 Supported");
	}
	if(edx.MMX){
		k_print_msg("MMX Supported");
	}
	if(edx.APIC){
		k_print_msg("APIC Supported");
	}
	if(edx.FPU){
		k_print_msg("FPU Supported");
	}

}

unsigned char cpuid_has_APIC()
{
   	unsigned int d;
   	asm volatile("cpuid":"=d"(d):"0"(1));
   	return d&0x200;
}

