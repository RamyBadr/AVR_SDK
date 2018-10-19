/*
 * LCD_config.h
 *
 * Created: 17/09/2018 10:25:55 PM
 *  Author: Ramy Badr
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#include "LCD.h"



#define LCDs_Num = 1;
extern LCD_Type LCD1 ;
extern const U8 config_LCD_Pins[7][2];
void InitLCDs(void);



#endif /* LCD_CONFIG_H_ */