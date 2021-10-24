#include <xc.h> // include processor files - each processor file is guarded.  

#define CLAVIER_ADDRESS 0x180000

far unsigned char CLAVIER @ 0x180000;

unsigned char get_clav(void);
unsigned char clav_to_ascii(unsigned char val);