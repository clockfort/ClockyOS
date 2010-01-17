reboot:
	db 0x0ea
	dw 0x0000
	dw 0xffff

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

