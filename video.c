#include "video.h"
#define VIDEO_MEMORY 0xB8000
#define WHITE_ON_BLACK 0x0F

static int cursor = 0;
static void draw_cursor(void) {
    char *video = (char *)VIDEO_MEMORY;
    video[cursor * 2]     = '_';
    video[cursor * 2 + 1] = WHITE_ON_BLACK;
}

static void erase_cursor(void) {
    char *video = (char *)VIDEO_MEMORY;
    video[cursor * 2]     = ' ';
    video[cursor * 2 + 1] = WHITE_ON_BLACK;
}
void clear_screen(void){
    char *video = (char *)VIDEO_MEMORY;
    for(int i =0; i < 25 * 80;i++){
        video[i*2] = ' ';
        video[i*2 + 1] = WHITE_ON_BLACK;
    }
    cursor = 0;
}
void kputchar(char c){
    erase_cursor();     

    if(c == '\n'){
        cursor = (cursor / 80 + 1)*80;
        draw_cursor();  
        return;
    }
    char *video = (char *)VIDEO_MEMORY;
    if(c == '\b'){
        if (cursor > 0){
                    

        cursor--;
        video[cursor  * 2 ] = ' ';
        video[cursor * 2 + 1] = WHITE_ON_BLACK;
        draw_cursor();  
        

        return;
    }}




    
    video[cursor  * 2 ] = c;
    video[cursor * 2 + 1] = WHITE_ON_BLACK;
    cursor ++;
draw_cursor();  
    return;
}



void print(const char *str){

    while(*str){
        kputchar(*str++);
        
    }
}

