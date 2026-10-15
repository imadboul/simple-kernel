#include "idt.h"
#include "video.h"
#include "pic.h"
#include "timer.h"
#include "keybord.h"
#include "io.h"
#include "keybord.h"

struct idt_ptr{
    unsigned short limit;
    unsigned int base;
}__attribute__((packed));

void panic(const char *msg) {
    clear_screen();
    print("PANIC: ");
    print(msg);
    print("\nSystem halted.");
    while (1) { asm volatile ("cli; hlt"); }
}



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
extern void isr1(void);
extern void isr2(void);
extern void isr3(void);
extern void isr4(void);
extern void isr5(void);
extern void isr6(void);
extern void isr7(void);
extern void isr8(void);
extern void isr9(void);
extern void isr10(void);
extern void isr11(void);
extern void isr12(void);
extern void isr13(void);
extern void isr14(void);
extern void isr15(void);
extern void isr16(void);
extern void isr17(void);
extern void isr18(void);
extern void isr19(void);
extern void isr20(void);
extern void isr21(void);
extern void isr22(void);
extern void isr23(void);
extern void isr24(void);
extern void isr25(void);
extern void isr26(void);
extern void isr27(void);
extern void isr28(void);
extern void isr29(void);
extern void isr30(void);
extern void isr31(void);
extern void isr32(void);
extern void isr33(void);
extern void isr34(void);
extern void isr35(void);
extern void isr36(void);
extern void isr37(void);
extern void isr38(void);
extern void isr39(void);
extern void isr40(void);
extern void isr41(void);
extern void isr42(void);
extern void isr43(void);
extern void isr44(void);
extern void isr45(void);
extern void isr46(void);
extern void isr47(void);

void idt_init(void) {
    pic_remap();
    set_idt(0, (unsigned int) isr0);
    set_idt(1,  (unsigned int)isr1);
    set_idt(2,  (unsigned int)isr2);
    set_idt(3,  (unsigned int)isr3);
    set_idt(4,  (unsigned int)isr4);
    set_idt(5,  (unsigned int)isr5);
    set_idt(6,  (unsigned int)isr6);
    set_idt(7,  (unsigned int)isr7);
    set_idt(8,  (unsigned int)isr8);
    set_idt(9,  (unsigned int)isr9);
    set_idt(10, (unsigned int)isr10);
    set_idt(11, (unsigned int)isr11);
    set_idt(12, (unsigned int)isr12);
    set_idt(13, (unsigned int)isr13);
    set_idt(14, (unsigned int)isr14);
    set_idt(15, (unsigned int)isr15);
    set_idt(16, (unsigned int)isr16);
    set_idt(17, (unsigned int)isr17);
    set_idt(18, (unsigned int)isr18);
    set_idt(19, (unsigned int)isr19);
    set_idt(20, (unsigned int)isr20);
    set_idt(21, (unsigned int)isr21);
    set_idt(22, (unsigned int)isr22);
    set_idt(23, (unsigned int)isr23);
    set_idt(24, (unsigned int)isr24);
    set_idt(25, (unsigned int)isr25);
    set_idt(26, (unsigned int)isr26);
    set_idt(27, (unsigned int)isr27);
    set_idt(28, (unsigned int)isr28);
    set_idt(29, (unsigned int)isr29);
    set_idt(30, (unsigned int)isr30);
    set_idt(31, (unsigned int)isr31);
    set_idt(32, (unsigned int)isr32);
    set_idt(33, (unsigned int)isr33);
    set_idt(34, (unsigned int)isr34);
    set_idt(35, (unsigned int)isr35);
    set_idt(36, (unsigned int)isr36);
    set_idt(37, (unsigned int)isr37);
    set_idt(38, (unsigned int)isr38);
    set_idt(39, (unsigned int)isr39);
    set_idt(40, (unsigned int)isr40);
    set_idt(41, (unsigned int)isr41);
    set_idt(42, (unsigned int)isr42);
    set_idt(43, (unsigned int)isr43);
    set_idt(44, (unsigned int)isr44);
    set_idt(45, (unsigned int)isr45);
    set_idt(46, (unsigned int)isr46);
    set_idt(47, (unsigned int)isr47);
    




    idtp.limit = sizeof(idt)-1;
    idtp.base = (unsigned int) &idt;
    asm volatile("lidt %0"::"m"(idtp));  // dont forget to learn more abt asmbly in c


}


void int_cummon_handler_c(unsigned int int_no,unsigned int error_code){
if (int_no >= 32 && int_no <= 47) {
        unsigned char irq = int_no - 32;

        switch (irq) {
        case 0:   // timer
           timer_tick();
           int x = get_ticks();
          
            break;
        case 1:{
            unsigned char raw = inb(0x60);
            buffer_handler(raw);

        }
            

            break;
        default:
            print("Unknown interrupt\n");
        }

        

        pic_eoi(irq);
        return;
    }

switch (int_no)
{
case 0:
        {
            print("dException 0: divide by 0\n");
            while(1){

            }
        }
   
  
case 1:
    panic("Exception 1: Debug\n");

case 2:
    panic("Exception 2: Non-Maskable Interrupt\n");

case 3:
    panic("Exception 3: Breakpoint\n");

case 4:
    panic("Exception 4: Overflow\n");

case 5:
    panic("Exception 5: BOUND Range Exceeded\n");

case 6:
    panic("Exception 6: Invalid Opcode\n");

case 7:
    panic("Exception 7: Device Not Available\n");

case 8:
    while (1) {}

case 9:
    panic("Exception 9: Coprocessor Segment Overrun\n");

case 10:
    panic("Exception 10: Invalid TSS\n");

case 11:
    panic("Exception 11: Segment Not Present\n");

case 12:
    panic("Exception 12: Stack-Segment Fault\n");

case 13:
    panic("Exception 13: General Protection Fault\n");

case 14:
    panic("Exception 14: Page Fault\n");
    
    while (1) {}

case 15:
    panic("Exception 15: Reserved\n");

case 16:
    panic("Exception 16: x87 Floating-Point Exception\n");

case 17:
    panic("Exception 17: Alignment Check\n");

case 18:
    panic("Exception 18: Machine Check\n");

case 19:
    panic("Exception 19: SIMD Floating-Point Exception\n");

case 20:
    panic("Exception 20: Virtualization Exception\n");

case 21:
    panic("Exception 21: Control Protection Exception\n");

case 22:
    panic("Exception 22: Reserved\n");

case 23:
    panic("Exception 23: Reserved\n");

case 24:
    panic("Exception 24: Reserved\n");

case 25:
    panic("Exception 25: Reserved\n");

case 26:
    panic("Exception 26: Reserved\n");

case 27:
    panic("Exception 27: Reserved\n");

case 28:
    panic("Exception 28: Hypervisor Injection Exception\n");

case 29:
    panic("Exception 29: VMM Communication Exception\n");

case 30:
    panic("Exception 30: Security Exception\n");

case 31:
    panic("Exception 31: Reserved\n");

default:
    print("Unknown interrupt\n");
}  



}