extern printf

section .data
    source db "ex.txt",0
    fo db "%s",10,0
    msg db "imad is the goat",0

section .bss
    buffer resb 17

section .text
    global main


main:

    mov eax, 5
    mov ebx, source
    mov ecx, 2
    int 80h

    mov esi,eax

    mov ebx,esi
    mov eax,19
    mov ecx,26
    mov edx,0
    push ebx
    int 80h

    pop ebx
    
    mov eax, 4
    mov ecx, msg
    mov edx, 16
    int 0x80

    mov ebx,esi
    mov eax,19
    mov ecx,26
    mov edx,0
    push ebx
    int 80h

    pop ebx
    mov eax, 3
    mov ecx, buffer
    mov edx, 16
    int 0x80

    mov byte [buffer + eax], 0 

    push buffer
    push fo
    call printf
    add esp, 8
    

    mov eax,1
    mov ebx,0
    int 80h










    


  