#include <xc.h>
#include "get_clav.h"

unsigned char get_clav(void) {
    unsigned char val = CLAVIER & 0x0F;
    return val;
}

unsigned char clav_to_ascii(unsigned char val) {
    //unsigned char val = get_clav();
    
    if (val >= 0 || val <= 9) {
        val = val + 0x30;
    }
    else if (val >= 10 || val <= 15) {
        val = val + 0x41;
    }
    
    return val;
}