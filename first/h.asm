ORG 0x8000
BITS 16

main:
  
    cli 
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    sti





    MOV si , msg
    MOV di, buffer 
print_loop:
    LODSB
    OR AL,0
    JZ scan_loop

    MOV ah, 0x0E
    MOV bh, 0
    INT 0x10
    JMP print_loop
    
scan_loop:
    MOV cx,0
    MOV ah, 0x00         ; wait for key
    int 0x16   
    cmp al,13

    je done_scan
    
    MOV [di], al
    inc di
    MOV ah, 0x0E
    INT 0x10
   

    JMP scan_loop

    
done_scan:
    MOV si, done
loop:
    LODSB
    OR AL,0
    jz here


    MOV ah, 0x0E
    MOV bh, 0
    INT 0x10
    JMP loop
here:
    MOV si, msg_done
loop2:
    LODSB
    cmp AL,0
    JZ halt

    MOV ah, 0x0E
    MOV bh, 0
    INT 0x10
    JMP loop2





halt:
    JMP halt





msg : db "MY OS>",0
msg_done :  db "You cliecked Enter",13,10,0
done: db 13,10,0
buffer: TIMES 10 db 0

TIMES 512 - ($-$$) DB 0

