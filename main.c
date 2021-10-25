#include <xc.h>
#include "user.h"
#include "get_clav.h"
#include "LCD.h"
#include "system.h"
#include "Interrupt.h"
#include "CAN.h"
#include "I2C.h"

unsigned char test = 0;
unsigned char test1 = 0;

#define _XTAL_FREQ 11059200 

void main(void) {
    Init();
    init_LCD();
    I2C_Init();
      
    while(1){       
        get_clav();
        clear_LCD();
        home_LCD();
        INT_to_ASCII(resultat_CAN);   
        if (clavier_a_traiter == 1) {
                  
            clavier_a_traiter = 0; 
        }        
        get_CAN();
        I2C_Write(map(resultat_CAN, 0, 4096, 0, 255));
        if(resultat_CAN > 2867){
            PORTG = 1;
        }
        else PORTG = 0;
        
        Tempo(200);
    }
    return;
}
