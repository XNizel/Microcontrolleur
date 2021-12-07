#include <xc.h>

#define _XTAL_FREQ 11059200 // Quartz 11,0592 MHz nécessaires à

int valeur_test;
unsigned int periode = 100;  //  100us = 10kHz
unsigned int duty_cycle = 10; // en %

void Init(void);
void Tempo(int val);
long map(long x, long in_min, long in_max, long out_min, long out_max);