#include "pic.h"
#include "io.h"

void pic_remap(void){

    outb(0x20,0b00010001); io_wait();  //icw1 (check archi 2 course chapter 4)
    outb(0xA0,0b00010001); io_wait();

    outb(0x21,0b00100000); io_wait(); //icw2
    outb(0xA1,0b00101000); io_wait();
    
    outb(0x21,0b00000100); io_wait();  //icw3
    outb(0xA1,0b00000010); io_wait();

    outb(0x21,0b00000001); io_wait();  //icw4
    outb(0xA1,0b00000001); io_wait();

    outb(0x21,0x0);io_wait();  //ocw1
    outb(0xA1,0x1);io_wait();
   
}




void pic_eoi(unsigned char irq){

    if(irq >= 8){
        outb(0xA0,0b00100000);  //ocw2
    }
    outb(0x20,0b00100000);
}