#include "keybord.h"
#include "video.h"
#include "io.h"
#include "cmd.h"


static const char kbd_us[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0, 'a', 's',
    'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 'v',
    'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ', 0
    
};


#define buffer_size 256

static char buffer[buffer_size];
static int buffer_len = 0;

void keybord_init(void){
    buffer_len = 0;
}

void buffer_handler(unsigned char scancode){
    if (scancode & 0x80) return;
    char c =kbd_us[scancode];

    if(!c){
        return;
    }

    if(c == '\b'){
        if (buffer_len > 0){
        buffer_len--;
        kputchar('\b');}
        return;  

    }
    

    if(c == '\n'){
        buffer[buffer_len] = 0;
        kputchar('\n');
        handle_command(buffer);
        buffer_len = 0;
        return;
    }

    if(buffer_len < buffer_size - 1){
        buffer[buffer_len] = c;
        buffer_len++;
        kputchar(c);
    }



}

