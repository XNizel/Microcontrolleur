#include <xc.h>
#include "Interrupt.h"
#include "system.h"
#include "get_clav.h"
#include "EUSART.h"

void high_priority interrupt clavier_appuyer (void){
    if (INTCONbits.INT0IF == 1){
        clavier_a_traiter = 1;
        INTCONbits.INT0IF = 0;
    }
    
    if(PIR3bits.RC2IF == 1){
        PIR3bits.RC2IF = 0;
        char_recu = 1;
        RCIF = 0; // Clear The Flag
    }
    
    if(PIR3bits.TX2IF == 1){
        char_transmis = 1;
        PIR3bits.TX2IF = 0;
    }
}

void low_priority interrupt UART (void){
   
}