#include "idt.h"
#include "video.h"
#include "keybord.h"
#include "timer.h"




void kmain(void){
    clear_screen();
    print("Booting MyOS\n");
    print("Hello from C \n");       
    idt_init();     
    print("[OK] IDT\n");
    keybord_init();
    print("[OK] Keyboard\n");

    asm volatile ("sti");
    print("[OK] Interrupts enabled\n");
  
        


        print("NO EXCEPTION\n");
        while (1) { }    
}






