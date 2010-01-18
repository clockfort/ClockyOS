all: floppyA 
	@echo "You better be using GCC and output 32-bit... else this will end poorly."

floppyA: kernel grub/stage1 grub/stage2 grub/pad
	cat grub/stage1 grub/stage2 grub/pad kernel.bin > floppy.img 	
	@echo -e "Boot with: \n   kernel 200+`ls -s --block-size=512 kernel.bin`\n   boot"

kernel: kernel.o loader.o vid_colortext.o
	ld -melf_i386 -T linker.ld -o kernel.bin loader.o kernel.o vid_colortext.o

kernel.o: kernel.c 
	$(CC) -m32 -o kernel.o -c kernel.c -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs 

loader.o: loader.s
	nasm -f elf -o loader.o loader.s

vid_colortext.o: vid_colortext.c
	$(CC) -m32 -std=gnu99 -c vid_colortext.c

hw_interrupt.o: hw_interrupt.c
	$(CC) -m32 -std=gnu99 -c hw_interrupt.c

clean:
	rm -f *.o *.bin
