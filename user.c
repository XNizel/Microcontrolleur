#include <xc.h>
#include "user.h"


void Init() {
    // Obligatoire : D�sactivation du bus externe ? Voir annexe 1
    MEMCON=0xA0; //ebdis=1 bus d�sactiv� (sauf en cas d'acc�s externe)

    
    // Gestion des sorties Analogique
    ANCON0=0x00;
    ANCON0bits.ANSEL0 = 1;  //Bit 0 en entr�e analogique pour lecture de V_POT
    ADCON0bits.ADON = 1;    //Bit alimentation convertisseur
    ADCON1bits.VNCFG = 0;   //VREF-
    ADCON1bits.VCFG = 0;    //VREF+
    ADCON2bits.ADFM = 1;    //Resultat Right Justified
    ANCON1=0x00;
    ANCON2=0x00;
    
    
    // Configuration de EUSART
    RCSTA2bits.SPEN = 1;    //EUSART2
    TRISGbits.TRISG2 = 1;
    TRISGbits.TRISG1 = 0;
    TXSTA2bits.SYNC = 0;    //Asynchronous mode
    SPBRG2 = 17;    // Baud Rate 9600
    TXSTA2bits.TXEN = 1;     //Activer la transmission
    RCSTA2bits.CREN = 1;     //Reception continue
    
    
    // D�finitions des E/S
    //TRISA = 0x01;       //  0A en entr�e pour V_POT
    TRISA = 0xFF;
    TRISB = 0xFF;       //  0B en entr�e pout INT0 - 1B en entr�e pour S_VENT
    TRISBbits.TRISB1 = 1;
    
    // Ports UART1
    TRISCbits.TRISC7 = 1; // RX1 en entr�e 
    TRISCbits.TRISC6 = 0; // TX1 en sortie
    
    TRISCbits.TRISC2 = 0; // configuration du port RC2 en sortie
    
    TRISG = 0x00;       //  0G en sortie pour la LED du VUMETER
    TRISGbits.TRISG1 = 1;
    TRISAbits.TRISA4 = 1;
    
    TRISJ = 0x00;
    
    /*
    PORTD = 0;
    PORTE = 0;
    PORTH = 0;*/
     
    // Configuration des interuptions
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;        //2 niveaux d'int�rruption
    INTCONbits.INT0IE = 1;
    INTCON2bits.INTEDG0 = 0;
    INTCONbits.INT0F = 0;
    /*
    PIE3bits.RC2IE = 1;     //Interuption RX UART
    PIE3bits.TX2IE = 1;     //Interuption TX UART
    IPR3bits.RC2IP = 1;     //Basse priorit�e
    IPR3bits.TX2IP = 1;     //Basse priorit�e*/
    
    //  Configuration du timer
    
    T0CONbits.T08BIT = 0;     //   Timer en 16bits
    T0CONbits.T0CS = 1;       //  Clk interne FOSC/4
    T0CONbits.T0SE = 0;       //  Detction de front montant
    T0CONbits.PSA = 1;
    T0CONbits.T0PS = 0x6;     //  Div par 128  1 tick toutes les 46,3us  //2,89us
    
}


void Tempo (int val) {
    int i;
    for(i=0; i<val; i++){
        __delay_ms(1);          // Utilisation de la fonction temporisation __delay_ms d�finie dans � xc.h �
    }
}


/*
x: la valeur a mapper
in_min: valeur minimale de l'intervalle actuelle
in_max: valeur maximale de l'intervalle actuelle
out_min: valeur minimale de l'intervalle souhait�
out_max: valeur maximale l'intervalle souhait�
*/

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}