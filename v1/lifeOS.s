bits 16
%include "macros.mac"

start:
        mov ax,0x7c0
        mov ds,ax

	println dashes
	println boot_msg
	println dashes
	println endl
	print boot_prompt
	jmp gets
.loopme jmp short .loopme

;data
dashes    db ' -------------------',0
boot_msg  db '| ClockBoot Started |',0
endl	db 13,10,0
boot_prompt db 'What would you like to boot? ',0

reboot:
	db 0x0ea
	dw 0x0000
	dw 0xffff

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

gets:
	mov ah, 0
	int 0x16 ;getch

	cmp al, 0x08 ;backspace
	je .back
	cmp al, 0x0D ;enter
	je .gtfo
	
	mov ah, 0x0e
	mov bx, 7
	int 0x10
	jmp gets	
.gtfo:
	ret
.back:
	ret

putch:
	mov ah, 0x0e
	mov bx, 7
	int 0x10
	ret


;Appease the bootloader gods - apply padding, and magic bytes
	times 510-($-$$) db 0
	dw 0xAA55
