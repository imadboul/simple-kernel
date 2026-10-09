BITS 16
extern kmain   
global start

section .text




  
start:
    jmp main  

gdt_start:

null_desc:
    dd  0
    dd  0
code_desc:
    dw 0xffff
    dw 0x0000
    db 0x00
    db 0b10011010
    db 0b11001111
    db 0x0
data_desc:
    dw 0xffff
    dw 0x0000
    db 0x00
    db 0b10010010
    db 0b11001111
    db 0x0
gdt_end:

gdt_desc:
    dw gdt_end - gdt_start - 1
    dd gdt_start
    
main:
    cli

    lgdt [gdt_desc]

    MOV eax,cr0
    or eax ,1
    MOV cr0, eax

    jmp 0x08:protected_start


BITS 32

protected_start:
    

    MOV ax,0x10
    MOV ds,ax
    MOV es,ax
    MOV ss,ax
    MOV fs, ax
    MOV gs, ax
    MOV esp, 0x90000



    call kmain

halt:
    jmp halt


