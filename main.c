#include <xc.h>
#include "user.h"
#include "get_clav.h"
#include "LCD.h"
#include "system.h"
#include "Interrupt.h"

unsigned char test = 0;
unsigned char test1 = 0;


void main(void) {
    Init();
    init_LCD();  
    
    //LCD;
    
    while(1){
        
        get_clav();
        if (clavier_a_traiter == 1) {
            LCD_DATA = val_clavier;
            clavier_a_traiter = 0; 
        }
        
    }
    return;
}
