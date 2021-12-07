#include <xc.h>
#include "user.h"
#include "Timer.h"

int get_Timer_Value(void){
    int timer_valueL = 0;
    int timer_value = 0;
    timer_valueL = TMR0L;
    
    timer_value = TMR0H;
    timer_value = timer_value << 8;
    timer_value = timer_value + timer_valueL;
    return timer_value;
}

