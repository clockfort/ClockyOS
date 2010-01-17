bits 16
%include "macros.mac"
%define SIZE 50 		;#sectors kernel takes up
	
start:
        mov ax,0x7c0	;
        mov ds,ax 	;
	mov es,ax	;Address where the BIOS dumped us.
	mov ax,0x8000		;C stack
	mov ss,ax
	mov sp,0xf000

	
	println dashes
	println boot_msg
	println dashes
	println endl


	;; Time to load the kernel
	;; dl = drive number (0=1st floppy,1=2nd floppy,80h=drive 0,81h=drive1)
	mov [drive],dl
	;; Reset the disk in case the BIOS did something naughty
	mov ax,0x0000
	int 0x13

	;; Load kernel into memory
	push es
	mov ax,0x100
	mov es,ax	
	mov bx,0		;ES:BX = Buffer Area
	mov ah,2		;read disk mode
	mov al,SIZE		;num sectors to read
	mov ch, 0		;Track/Cylinder
	mov cl, 2 		;sector
	mov dh, 0		;head
	mov dl, [drive]		;drive
	int 0x13
	pop es

; Protected Mode (But first, a GDT!)
    cli
    lgdt [gdt_metadata]    ; charge la gdt
    mov eax, cr0
    or  al, 1
    mov cr0, eax        ; PE mis a 1 (CR0)
    jmp next;

next:
    mov ax, 0x10        ; segment de donne
    mov ds, ax
    mov fs, ax
    mov gs, ax
    mov es, ax
    mov ss, ax
    mov esp, 0x9F000    

    jmp dword 0x8:0x1000    ; reinitialise le segment de code

;data
dashes      db ' -------------------',0
boot_msg    db '| ClockBoot Started |',0
endl	    db 13,10,0
drive:	    db 0

gdt_metadata:
    dw gdt_end - gdt_start -1; end of gdt's address
    dd gdt_start
gdt_start:
    dd 0,0
gdt_middle:
;   limit_low, limit_high, base_1, base_2, base3, type, flags, base_4
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10011011b, 11011111b, 0x0
gdt_end:

puts:
	lodsb
	or al,al
	jz short gtfo
	mov ah, 0x0e;
	mov bx, 7
	int 0x10
	jmp puts
gtfo:
	ret

putch:
	mov ah, 0x0e
	mov bx, 7
	int 0x10
	ret

;Appease the bootloader gods - apply padding, and magic bytes
	times 510-($-$$) db 0
	dw 0xAA55
