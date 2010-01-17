bits 16
%include "macros.mac"
	
start:
	println dashes
	println boot_msg
	println dashes
	println endl

;data
dashes      db ' -------------------',0
boot_msg    db '| ClockBoot Started |',0
endl	    db 13,10,0

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
