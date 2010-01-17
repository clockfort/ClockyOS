bits 16


start:
mov ax, 0x07c0
mov ds, ax

mov ah, 0x0e
mov bx, 7
mov si, hello
next:
lodsb
or al,al
loopme: jz short loopme
int 0x10
jmp short next

hello:    db 'Hello World',0

;Appease the bootloader gods - apply padding, and magic bytes
times 510-($-$$) db 0
dw 0xAA55

