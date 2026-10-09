ORG 0x7c00
BITS 16

main:
    MOV ax,0
    MOV ds,ax
    MOV ss,ax
    MOV es,ax

    MOV sp,0x7C00

    mov si , msg
    call print


    MOV ah, 02h
    MOV al, 32
    MOV ch, 0
    MOV cl, 2
    MOV DH, 0
    MOV DL, 0x80
    MOV bx, 0x8000
    INT 0x13
    JC disk_error
    JMP 0x8000


    
    MOV si, ok_msg        ; ← add
    CALL print            ; ← add
    JMP 0x8000

; ...
ok_msg: DB "read ok", 13, 10, 0









   

halt:
    JMP halt

disk_error:
    MOV si, error_msg
    call print
    JMP halt


print:
    push si
    push ax
    push bx
print_loop:
    LODSB
    OR AL,0
    JZ done_print

    MOV ah, 0x0E
    MOV bh, 0
    INT 0x10
    JMP print_loop

    
done_print:
    pop bx
    pop ax
    pop si
    RET





error_msg: DB "loading failed",13,10,0
msg: DB "booted",13,10,0















TIMES 510 - ($-$$) DB 0

DW 0AA55h
