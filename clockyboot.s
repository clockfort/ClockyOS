bits 16
%include "macros.mac"

start:
        mov ax,0x7c0
        mov ds,ax

	println dashes
	println boot_msg
	println dashes
	
.loopme	jmp short .loopme

;data
dashes    db 45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,0
boot_msg  db 124,' ClockBoot Started ',124,0
endl	db 13,10,0

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


;Appease the bootloader gods - apply padding, and magic bytes
	times 510-($-$$) db 0
	dw 0xAA55
