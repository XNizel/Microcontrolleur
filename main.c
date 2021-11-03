#include <xc.h>
#include "user.h"
#include "get_clav.h"
#include "LCD.h"
#include "system.h"
#include "Interrupt.h"
#include "CAN.h"
#include "I2C.h"
#include "EUSART.h"


void main(void) {
    Init();
    init_LCD();
    I2C_Init();
    
    while(1){       
    // ---- TP3 ----
        get_clav();
        //clear_LCD();
        //home_LCD();
        //INT_to_ASCII(resultat_CAN);
        
        if (clavier_a_traiter == 1) {
            //Trucs a faire pour l'interuption avec appui du clavier
            clear_LCD();
            home_LCD();
            LCD_DATA = 'A';
            clavier_a_traiter = 0; 
        }
        if (char_recu == 1){
            RX_BUFFER[RX_INDEX] = rx_data();
            RX_INDEX += 1;
            char_recu = 0;
        }
        
        if (RX_BUFFER[RX_INDEX - 1] == 'e'){
            if (char_transmis == 1){
                tx_data(RX_BUFFER[TX_INDEX]);
                TX_INDEX += 1;
            }
        }
        /*
        get_CAN();
        I2C_Write(map(resultat_CAN, 0, 4096, 0, 255));
        if(resultat_CAN > 2867){
            PORTG = 1;
        }
        else PORTG = 0;

         */
        
    // ---- TP4 ----
        //data1 = rx_data();
        //tx_data(0x0D);
        //tx_data(0x0A);
        //tx_data(data1);
        //LCD_DATA = data1;
        
        
        
        Tempo(50);
    }
    return;
}
