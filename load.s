LoadKern:
    ; print an H to show you started
    mov ah, 0xe
    mov al, 0x48
    mov bx, 7
    int 0x10

    mov bx, 0x2000
    mov es, bx
    mov ds, bx
    mov bx, 0   ; Offset
    mov ah, 02  ; function#
    mov al, 01  ; sector count
    mov ch, 00  ; Track#
    mov cl, 02  ; Sector#
    mov dh, 00  ; Head#
    mov dl, 00  ; Drive#
    int 0x13

    ; print the second sign from the sector
    mov ah, 0xe
    mov al, [0001]
    mov bx, 7
    int 0x10

.ende
    jmp .ende
