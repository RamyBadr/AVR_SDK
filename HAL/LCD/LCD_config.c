/*
 * LCD_config.c
 *
 * Created: 17/09/2018 10:26:41 PM
 *  Author: Ramy Badr
 */ 

#include "LCD_config.h"

/*
 any change in config pins order please change associated LCD_xn macro index in LCD.h file
*/

const U8 config_LCD_Pins[LCD_PINS_NUM][2]={
	{ B , 1	}, // LCD_RS
	{ B , 2	}, //LCD_RW
	{ B , 3	}, //LCD_EN
	{ A , 4	}, //LCD_D4
	{ A , 5	}, //LCD_D5
	{ A , 6	}, //LCD_D6
	{ A , 7	}, //LCD_D7
};
LCD_Type LCD1 ;


void InitLCDs(void){
	LCD_Init_config(&LCD1,config_LCD_Pins);
	LCD_Initialization(&LCD1);
}


