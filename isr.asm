
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
isr_noerr 1
isr_noerr 2
isr_noerr 3
isr_noerr 4
isr_noerr 5
isr_noerr 6
isr_noerr 7

isr_err   8 ; no print

isr_noerr 9
isr_err   10
isr_err   11
isr_err   12
isr_err   13
isr_err   14
isr_noerr 15
isr_noerr 16
isr_err   17
isr_noerr 18
isr_noerr 19
isr_noerr 20
isr_err   21
isr_noerr 22
isr_noerr 23
isr_noerr 24
isr_noerr 25
isr_noerr 26
isr_noerr 27
isr_noerr 28
isr_err   29
isr_err   30
isr_noerr 31
isr_noerr 32
isr_noerr 33
isr_noerr 34
isr_noerr 35
isr_noerr 36
isr_noerr 37
isr_noerr 38
isr_noerr 39
isr_noerr 40
isr_noerr 41
isr_noerr 42
isr_noerr 43
isr_noerr 44
isr_noerr 45
isr_noerr 46
isr_noerr 47




















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



