#include <xc.h> // include processor files - each processor file is guarded. 
#include "CAN.h"

void get_CAN(void){
    if(ADCON0bits.GODONE == 0){
        resultat_CAN = ADRESH;
        resultat_CAN = resultat_CAN << 8;
        resultat_CAN = resultat_CAN + ADRESL;
        ADCON0bits.GODONE = 1;
    }
    else{
        ADCON0bits.GODONE = 1;
    }
}
