#include <xc.h>

#define DISPLAY_CLEAR 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE_SET_CI_DNS 0x06
#define ENTRY_MODE_SET_CI_DS 0x07
#define DISPLAY_ON_CUR_ON_BLINK_ON 0x0F
#define DISPLAY_ON_CUR_ON_BLINK_OFF 0x0E
#define SHIFT_DISPLAY_RIGHT 0x1C
#define SHIFT_DISPLAY_LEFT 0x18
#define SHIFT_CURSOR_RIGHT 0x14
#define SHIFT_CURSOR_LEFT 0x10
#define SET_FUNC_8BIT_2LINE_5x10 0x3C
#define SET_FUNC_8BIT_2LINE_5x7 0x38


extern far unsigned char LCD_DATA @ 0x1A0002;
extern far unsigned char LCD_FUNC @ 0x1A0000;

int buffer_ASCII[5];

void init_LCD(void);
void clear_LCD (void);
void home_LCD (void);
void shift_cursor_right (void);
void shift_cursor_left (void);
void set_cursor_pos (int position);
void INT_to_ASCII (int valeur_a_conv);
