#include <xc.h>
#include "user.h"


void Init() {
    // Obligatoire : D�sactivation du bus externe ? Voir annexe 1
    MEMCON=0xA0; //ebdis=1 bus d�sactiv� (sauf en cas d'acc�s externe)

    // Obligatoire : D�sactivation des fonctions analogiques
    ANCON0=0x00;
    ANCON0bits.ANSEL0 = 1;  //Bit 0 en entr�e analogique pour lecture de V_POT
    ADCON0bits.ADON = 1;    //Bit alimentation convertisseur
    ADCON1bits.VNCFG = 0;   //VREF-
    ADCON1bits.VCFG = 0;    //VREF+
    ADCON2bits.ADFM = 1;    //Resultat Right Justified
    ANCON1=0x00;
    ANCON2=0x00;
     
    // D�finitions des E/S
    TRISB = 0x01;       //0B en entr�e pout INT0
    TRISA = 0x01;       //0A en entr�e pour V_POT
    PORTD = 0;
    PORTE = 0;
    PORTH = 0;
     
    //  Configuration des interuptions
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;   //2 niveaux d'int�rruption
    INTCONbits.INT0IE = 1;
    INTCON2bits.INTEDG0 = 0;
    INTCONbits.INT0F = 0;
}


void Tempo (int val)
{
    int i;
    for(i=0; i<val; i++)
    {
        __delay_ms(1);  // Utilisation de la fonction temporisation delay_ms d�finie dans � xc.h �
    }
}