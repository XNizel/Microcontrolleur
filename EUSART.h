#include <xc.h> // include processor files - each processor file is guarded. 

unsigned char data1;
unsigned char TX_BUFFER[20] = "abcde";
int TX_INDEX = 0;
unsigned char RX_BUFFER[20];
int RX_INDEX = 0;

void tx_data(unsigned char data);
unsigned char rx_data(void);
void tx_chaine (void);
void rx_chaine (void);