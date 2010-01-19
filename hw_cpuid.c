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
	
}
