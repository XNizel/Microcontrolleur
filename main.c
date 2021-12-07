#include <xc.h>
#include "user.h"
#include "get_clav.h"
#include "LCD.h"
#include "system.h"
#include "Interrupt.h"
#include "CAN.h"
#include "I2C.h"
#include "EUSART.h"
#include "Timer.h"


void main(void) {
    Init();
    init_LCD();
    I2C_Init();
    
    int UART_Buffer[3];
    
    tx_data('S');
    tx_data('e');
    tx_data('r');
    tx_data('i');
    tx_data('a');
    tx_data('l');
    tx_data(0x0D);
    tx_data(0x0A);
    
    clear_LCD();
    home_LCD();
    set_cursor_line_2();
    LCD_DATA = 'S';
    Tempo(2);
    LCD_DATA = '_';
    Tempo(2);
    LCD_DATA = 'V';
    Tempo(2);
    LCD_DATA = 'E';
    Tempo(2);
    LCD_DATA = 'N';
    Tempo(2);
    LCD_DATA = 'T';
    Tempo(2);
    LCD_DATA = '=';
    Tempo(2);
    
    
    
    
    unsigned char data_test;

    
    while(1){       
//        if (char_recu) {
//            UART_Buffer[0] = RCREG2;
//            tx_data('R');
//            tx_data('e');
//            tx_data('c');
//            tx_data('u');
//            tx_data(':');
//            tx_data(UART_Buffer[0]);
//            tx_data(0x0D);
//            tx_data(0x0A);
//            char_recu = 0;
//        }
        
        // ---- TP3 ----
        //get_clav();
        //clear_LCD();
        //home_LCD();
        //INT_to_ASCII(get_CAN());
        
        if (clavier_a_traiter == 1) {
            
            //Trucs a faire pour l'interuption avec appui du clavier
            //clear_LCD();
            //home_LCD();
            //LCD_DATA = 'A';
            /*tx_data('H');
            tx_data('e');
            tx_data('l');
            tx_data('l');
            tx_data('o');
            tx_data(0x0D);
            tx_data(0x0A);*/
            //tx_data(resultat_CAN);
            //data_test = rx_data();
            //tx_data(data_test);
            //tx_data(0x0D);
            //tx_data(0x0A);
            //int test = 1234;
            //INT_to_ASCII(test);
            
            clear_LCD();
            home_LCD();
            valeur_test = get_Timer_Value();
            INT_to_ASCII(valeur_test, 4);
            TMR0H = 0;
            TMR0L = 0;
            clavier_a_traiter = 0; 
        }        
        
        
        
        //data_test = rx_data();
        //tx_data(data_test);
        
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
        
        
        
    // ---- TP5 ----
        LATCbits.LATC2 = 1;     //  Alimnenter le ventilateur        
        /*
        clear_LCD();
        home_LCD();
        valeur_test = get_Timer_Value();
        INT_to_ASCII(valeur_test);*/
        
        /*
        T0CONbits.TMR0ON = 0;
        while (PORTBbits.RB1 == 1) {
            
        }
        while (PORTBbits.RB1 == 0) { 
        }
        T0CONbits.TMR0ON = 1;
        
        while (PORTBbits.RB1 == 1) {
            
        }
        T0CONbits.TMR0ON = 0;*/
        
        TMR0H = 0;
        TMR0L = 0;
        
        T0CONbits.TMR0ON = 1;
        Tempo(1000);
        T0CONbits.TMR0ON = 0;
        
        //clear_LCD();
        //home_LCD();
        set_cursor_line_2();
        set_cursor_pos(7);
        valeur_test = (get_Timer_Value());
        INT_to_ASCII(valeur_test, 4);
        LCD_DATA = 'H';
        Tempo(2);
        LCD_DATA = 'z';
        Tempo(2);
        
        
        
        Tempo(25);
    }
    return;
}
