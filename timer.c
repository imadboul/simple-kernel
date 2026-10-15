#include "timer.h"


static unsigned int ticks = 0 ;

void timer_tick(void){
    ticks++;
}

unsigned int get_ticks(void){
    return ticks;
}