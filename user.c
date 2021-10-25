#include <xc.h>
#include "user.h"


void Init() {
    // Obligatoire : Désactivation du bus externe ? Voir annexe 1
    MEMCON=0xA0; //ebdis=1 bus désactivé (sauf en cas d'accès externe)

    // Obligatoire : Désactivation des fonctions analogiques
    ANCON0=0x00;
    ANCON1=0x00;
    ANCON2=0x00;
     
    // Définitions des E/S
    TRISB = 0x01;       //0B en entrée
    PORTD = 0;
    PORTE = 0;
    PORTH = 0;
     
    //  Configuration des interuptions
    RCONbits.IPEN = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;   //2 niveaux d'intérruption
    INTCONbits.INT0IE = 1;
    INTCON2bits.INTEDG0 = 0;
    INTCONbits.INT0F = 0;
}


void Tempo (int val)
{
    int i;
    for(i=0; i<val; i++)
    {
        __delay_ms(1);  // Utilisation de la fonction temporisation delay_ms définie dans « xc.h »
    }
}