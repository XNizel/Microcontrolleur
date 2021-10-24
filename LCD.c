#include <xc.h>
#include "user.h"
#include "LCD.h"


void init_LCD(void){
    Tempo(100);
    LCD_FUNC = 0x38;
    Tempo(5);
    LCD_FUNC = 0x38;
    Tempo(1);
    LCD_FUNC = 0x38;
    Tempo(1);
    LCD_FUNC = SET_FUNC_8BIT_2LINE_5x7;
    Tempo(1);
    LCD_FUNC = 0x14;
    Tempo(1);
    LCD_FUNC = DISPLAY_ON_CUR_ON_BLINK_OFF;
    Tempo(1);
    LCD_FUNC = ENTRY_MODE_SET_CI_DNS;
    Tempo(2);
    LCD_FUNC = RETURN_HOME;
    Tempo(2);
    LCD_FUNC = DISPLAY_CLEAR;             
}

void clear_LCD (void) {
    LCD_FUNC = DISPLAY_CLEAR;
    Tempo(2);
}

void home_LCD (void) {
    LCD_FUNC = RETURN_HOME;
    Tempo(2);
}

void shift_cursor_right (void) {
    LCD_FUNC = SHIFT_CURSOR_RIGHT;
    Tempo(2);
}

void shift_cursor_left (void) {
    LCD_FUNC = SHIFT_CURSOR_LEFT;
    Tempo(2);
}

void set_cursor_pos (int pos) {
    LCD_FUNC = RETURN_HOME;
    Tempo(2);
}

void busy(void){
    while(LCD_FUNC & 0x80 == 0x80){
        
    }
}