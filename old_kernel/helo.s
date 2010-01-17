start:
; this should print H
    mov ax, 0xe48
    mov bx, 7
    int 0x10
; E
    mov ax, 0xe45
    int 0x10
; L
    mov ax, 0xe4C
    int 0x10
; L
    mov ax, 0xe4C
    int 0x10
; O
    mov ax, 0xe4F
    int 0x10
.ende
    jmp .ende

