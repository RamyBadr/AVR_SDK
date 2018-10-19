/*
 * RamyBadr.c
 *
 * Created: 10/09/2018 11:20:13 PM
 *  Author: Ramy Badr
 */ 
//#define TEST_LCD 
#ifdef TEST_LCD

#include "../HAL/LCD/LCD_config.h"

void main(void) {
	S32 fVal = 12.0345 ;
	InitLCDs();
	//LCD_Write_Character(&LCD1,'x');
	LCD_Write_String(&LCD1,"Embedded Sys Course");
	LCD_Go_To_X_Y(&LCD1,LCD_ROW_2,LCD_POSITION_2);
	
	//LCD_Write_Float(&LCD1,fVal,4);
	//LCD_Write_String(&LCD1,"***Ramy Badr***");
	//while (1) {
		  	//LCD_Write_Command(&LCD1,LCD_SHIFT_LEFT_CMD);
		  	//_delay_ms(1000);
	//}
}
#endif