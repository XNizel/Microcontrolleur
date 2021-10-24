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
    //LCD_DATA;
    
    while(1){
        //get_clav();
        //test = CLAVIER;
        //LCD_DATA = 0b01001000; // H
        //test1 = test + 0x30;
        
        home_LCD();
        clear_LCD();
        test = get_clav();
        test1 = clav_to_ascii(test);
        
        LCD_DATA = test1;
        //LCD_DATA = clav_to_ascii(3);
        //LCD_DATA = clav_to_ascii(get_clav());
        
        /*LCD_FUNC = RETURN_HOME;
        Tempo(2);
        LCD_FUNC = DISPLAY_CLEAR;
        Tempo(2);
        LCD_DATA = CLAVIER + 0x30;*/
        /*if(clavier_a_traiter == 1){
            LCD_DATA = clav_to_ascii(get_clav());
            clavier_a_traiter = 0;
        }*/
        Tempo(250);
    }
}
