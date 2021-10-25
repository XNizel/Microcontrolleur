#include <xc.h>
#include "get_clav.h"

/*
  Fonction qui retourne la valeur du clavier
  INPUT : void
  OUTPUT : val -> valeur du clavier
*/
void get_clav(void) {
    //val_clavier = CLAVIER & 0x0F;
    val_clavier = (CLAVIER + 0x30);
}


/*
  Fonction qui converti la valeur   du clavier 
  en charactere ASCII pour l'affichage
  INPUT : val -> char a convertir
  OUTPUT : val -> char converti en ASCII
*/
unsigned char clav_to_ascii(void) {
    unsigned char val = 1;
    
    if (val >= 0 || val <= 9) {
        val = val + 0x30;
    }
    else if (val >= 10 || val <= 15) {
        val = val + 0x41;
    }
    
    return val;
}