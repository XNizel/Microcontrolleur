#include <xc.h>

int clav_a_traiter = 0;
int char_recu = 0;
int char_transmis = 0;



void high_priority interrupt clavier_appuyer (void);

void low_priority interrupt UART (void);