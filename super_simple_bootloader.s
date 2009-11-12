; Start printing chars w/BIOS
start:
	mov ax, 0xe43
	mov bx, 7
	int 0x10
	mov ax, 0xe6c
	int 0x10
	mov ax, 0xe6f
	int 0x10
	mov ax, 0xe63
	int 0x10
	mov ax, 0xe6b
	int 0x10
	mov ax, 0xe79
	int 0x10
	
	mov ax, 0xe42
	int 0x10
	mov ax, 0xe6f
	int 0x10
	mov ax, 0xe6f
	int 0x10
	mov ax, 0xe74
	int 0x10

.loopme	jmp short .loopme

;Appease the bootloader gods - apply padding, and magic bytes
	times 510-($-$$) db 0
	dw 0xAA55
