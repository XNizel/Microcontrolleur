#include <xc.h>
#include "EUSART.h"
#include "LCD.h"
#include "user.h"

void tx_data(unsigned char data){
    while(PIR3bits.RC2IF==0);
    TXREG2 = data;
    Tempo(5);
}

unsigned char rx_data(void){
    while(PIR3bits.TX2IF==0);
    return RCREG2;
    Tempo(5);
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