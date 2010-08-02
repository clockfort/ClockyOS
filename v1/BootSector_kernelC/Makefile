OBJ=floppyA

all: $(OBJ) 

floppyA: bootsect kernel
	cat bootsect kernel /dev/zero | dd of=floppyA bs=512 count=2880

kernel: kernel.o screen.o
	ld --oformat binary -Ttext 1000 kernel.o screen.o -o kernel

kernel.o: kernel.asm 
	nasm -f elf -o $@ $^

bootsect: bootsect.asm
	nasm -f bin -o $@ $^

.o: .c 
	$(CC) -c $^

clean:
	rm -f $(OBJ) *.o bootsect kernel
