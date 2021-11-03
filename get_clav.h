#include <xc.h> // include processor files - each processor file is guarded.  

#define ADRESSE_CLAVIER 0x180000

far unsigned char CLAVIER @ ADRESSE_CLAVIER;

unsigned char val_clavier = 0;

void get_clav(void);
unsigned char clav_to_ascii(void);