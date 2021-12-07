#include <xc.h> // include processor files - each processor file is guarded. 
#include "CAN.h"

int get_CAN(void){
    int resultat_CAN;
    if(ADCON0bits.GODONE == 0){
        resultat_CAN = ADRESH;
        resultat_CAN = resultat_CAN << 8;
        resultat_CAN = resultat_CAN + ADRESL;
        ADCON0bits.GODONE = 1;
    }
    else{
        ADCON0bits.GODONE = 1;
    }
    return resultat_CAN;
}
