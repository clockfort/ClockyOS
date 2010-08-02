all: floppyA 
	echo "You better be using GCC and output 32-bit... else this will end poorly."

floppyA: clockyboot kernel
	cat clockyboot kernel /dev/zero | dd of=floppyA bs=512 count=2880

kernel: kernel.o vid_colortext.o
	ld --oformat binary -Ttext 1000 kernel.o vid_colortext.o -o kernel

clockyboot: clockyboot.s
	nasm -f bin -o $@ $^

kernel.o: kernel.c 
	$(CC) -std=gnu99 -c kernel.c

vid_colortext.o: vid_colortext.c
	$(CC) -std=gnu99 -c vid_colortext.c

clean:
	rm -f *.o clockyboot kernel floppyA
