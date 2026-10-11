#include "idt.h"
#include "video.h"

struct idt_ptr{
    unsigned short limit;
    unsigned int base;
}__attribute__((packed));

static struct idt_entry idt[256];
static struct idt_ptr idtp;

static void set_idt(int n, unsigned int handler){
    idt[n].offset_low = handler & 0xffff;
    idt[n].offset_high = (handler >> 16) &  0xffff;
    idt[n].zero = 0;
    idt[n].type_attr = 0x8E;
    idt[n].selector = 0x08;
}


extern void isr0(void);
void idt_init(void) {
    set_idt(0, (unsigned int) isr0);
    




    idtp.limit = sizeof(idt)-1;
    idtp.base = (unsigned int) &idt;
    asm volatile("lidt %0"::"m"(idtp));  // dont forget to learn more abt asmbly in c


}


void int_cummon_handler_c(unsigned int int_no,unsigned int error_code){
switch (int_no)
{
case 0:
        {
            print("Exception 0: divide by 0");
            while(1){

            }
        }
   
    break;

default:
    break;
}  


}