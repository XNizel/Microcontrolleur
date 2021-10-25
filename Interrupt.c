#include <xc.h>
#include "Interrupt.h"
#include "system.h"
#include "get_clav.h"

void high_priority interrupt clavier_appuyer (void){
    if (INTCONbits.INT0IF == 1){
        clavier_a_traiter = 1;
        INTCONbits.INT0IF = 0;
    }
}