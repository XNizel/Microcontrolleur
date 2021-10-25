#include <xc.h>
#include "user.h"
#include "get_clav.h"
#include "LCD.h"
#include "system.h"
#include "Interrupt.h"
#include "CAN.h"

unsigned char test = 0;
unsigned char test1 = 0;

#define _XTAL_FREQ 11059200 

void main(void) {
    Init();
    init_LCD();
    __delay_ms(50);
    __delay_ms(50);
    __delay_ms(50);
    int test_int = 12345;
    //LCD_DATA = test_int;

      
    while(1){
        
        get_clav();
        clear_LCD();
        home_LCD();
        INT_to_ASCII(resultat_CAN);   
        if (clavier_a_traiter == 1) {
                  
            clavier_a_traiter = 0; 
        }        
        get_CAN();
        Tempo(200);
    }
    return;
}
