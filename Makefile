all: floppyA 
	@echo "If your CC isn't gcc, things might not work quite right. (They might not work quite right anyway...)"

floppyA: kernel grub/stage1 grub/stage2 grub/pad
	cat grub/stage1 grub/stage2 grub/pad kernel.bin > floppy.img 	
	@echo -e "Boot with: \n   kernel 200+`ls -s --block-size=512 kernel.bin`\n   boot"

kernel: kernel.o loader.o vid_boottext.o hw_interrupt.o hw_cpuid.o
	ld -melf_i386 -T linker.ld -o kernel.bin loader.o kernel.o vid_colortext.o hw_interrupt.o vid_boottext.o hw_cpuid.o

kernel.o: kernel.c 
	$(CC) -m32 -o kernel.o -c kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs 

loader.o: loader.s
	nasm -f elf -o loader.o loader.s

vid_colortext.o: vid_colortext.c
	$(CC) -m32 -std=gnu99 -c vid_colortext.c

hw_interrupt.o: hw_interrupt.c
	$(CC) -m32 -std=gnu99 -c hw_interrupt.c

vid_boottext.o: vid_boottext.c vid_colortext.o
	$(CC) -m32 -std=gnu99 -c vid_boottext.c

hw_cpuid.o: hw_cpuid.c
	$(CC) -m32 -std=gnu99 -c hw_cpuid.c

clean:
	rm -f *.o *.bin
