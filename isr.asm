
BITS 32

section .text


extern int_cummon_handler_c

%macro isr_noerr 1
global isr%1
isr%1:
    push dword 0
    push dword %1
    jmp isr_cummon
%endmacro
%macro isr_err 1
global isr%1
isr%1:
    push dword %1
    jmp isr_cummon
%endmacro

isr_noerr 0




















isr_cummon:
    pusha ; 8 * 4 = 32 bytes 
    push ds
    push es
    push fs 
    push gs ; 32 + (4)*4 =48


    mov ax, 0x10         ; we dont where came from
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    push dword [esp + 52]  ; error code
    push dword [esp + 52]
    call int_cummon_handler_c

    add esp,8
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp,8  ;remove the originals

    iret



