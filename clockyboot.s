bits 16
%include "macros.mac"
%define SIZE 50 		;#sectors kernel takes up
	
start:
        mov ax,0x7c0
        mov ds,ax
	mov es,ax
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

	;; Frenchman's code to load a Global Descriptor Table
; initialisation du pointeur sur la GDT
    mov ax, gdtend    ; calcule la limite de GDT
    mov bx, gdt
    sub ax, bx
    mov word [gdtptr], ax

    xor eax, eax      ; calcule l'adresse lineaire de GDT
    xor ebx, ebx
    mov ax, ds
    mov ecx, eax
    shl ecx, 4
    mov bx, gdt
    add ecx, ebx
    mov dword [gdtptr+2], ecx

; passage en modep
    cli
    lgdt [gdtptr]    ; charge la gdt
    mov eax, cr0
    or  ax, 1
    mov cr0, eax        ; PE mis a 1 (CR0)

    jmp next
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

gdt:
    db 0, 0, 0, 0, 0, 0, 0, 0
gdt_cs:
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10011011b, 11011111b, 0x0
gdt_ds:
    db 0xFF, 0xFF, 0x0, 0x0, 0x0, 10010011b, 11011111b, 0x0
gdtend:
;--------------------------------------------------------------------
gdtptr:
    dw 0  ; limite
    dd 0  ; base
;--------------------------------------------------------------------

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
