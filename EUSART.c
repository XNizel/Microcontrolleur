#include <xc.h>
#include "EUSART.h"
#include "LCD.h"

void tx_data(unsigned char data){
    TXREG2 = data;
}

unsigned char rx_data(void){
    return RCREG2;    
}

void rx_chaine (void){
    do{
        RX_BUFFER[RX_INDEX] = rx_data;
        RX_INDEX += 1;
    }while(RX_BUFFER[RX_INDEX - 1] != 'e');
}

void tx_chaine (void){
    for(TX_INDEX = 0; TX_INDEX < 9; TX_INDEX++){
        tx_data(RX_BUFFER[TX_INDEX]);
        LCD_DATA = RX_BUFFER[TX_INDEX];
        shift_cursor_right();
    }
}