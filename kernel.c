#include "idt.h"
#define VIDEO_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x0F

static int cursor = 0;
void clear_screen(void){
    char *video = (char *)VIDEO_MEMORY;
    for(int i =0; i < 25 * 80;i++){
        video[i*2] = ' ';
        video[i*2 + 1] = WHITE_ON_BLACK;
    }
    cursor = 0;
}
void kputchar(char c){

    if(c == '\n'){
        cursor = (cursor / 80 + 1)*80;
        return;
    }
    char *video = (char *)VIDEO_MEMORY;
    video[cursor  * 2 ] = c;
    video[cursor * 2 + 1] = WHITE_ON_BLACK;
    cursor ++;
    return;
}

void print(const char *str){

    while(*str){
        kputchar(*str++);
        
    }
}

void kmain(void){
       
        clear_screen();
        print("Hello from C \n");
        idt_init();
        print("IDT ready \n");

        int x = 1 / 0;
        print("NO EXCEPTION\n");
        while (1) { }    
}






