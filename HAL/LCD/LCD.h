/*
 * LCD.h
 *
 * Created: 17/09/2018 10:25:40 PM
 *  Author: Ramy Badr
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../HAL_macros.h"
#include "../../UTILS/utils.h"

#define LCD_PINS_NUM	7
//general index of LCD pins
#define		LCD_RS		(0)
#define		LCD_RW		(1)
#define		LCD_EN		(2)
#define		LCD_D4		(3)
#define		LCD_D5		(4)
#define		LCD_D6		(5)
#define		LCD_D7		(6)

typedef struct{
	PinType LCD_pins[LCD_PINS_NUM];
}LCD_Type;

/*****************************************************************/

#define  LCD_CLEAR_CMD					(0x01U)
#define  LCD_RETURN_HOME_CMD			(0x80U)
#define  LCD_CURSOR_OFF_CMD       		(0x0CU)
#define  LCD_UNDERLINE_ON_CMD			(0x0EU)
#define  LCD_BLINK_CURSOR_ON_CMD   		(0x0FU)
#define  LCD_TURN_ON_CMD				(0x0CU)
#define  LCD_TURN_OFF_CMD				(0x08U)
#define  LCD_SHIFT_LEFT_CMD				(0x18U)
#define  LCD_SHIFT_RIGHT_CMD			(0x1CU)
#define  LCD_CURSOR_SHIFT_LIFT_CMD		(0x10U)
#define  LCD_CURSOR_SHIFT_RIGHT_CMD		(0x14U)
#define  LCD_ROW_1						(0U)
#define  LCD_ROW_2						(1U)
#define  LCD_POSITION_1					(0U)
#define  LCD_POSITION_2					(1U)
#define  LCD_POSITION_3					(2U)
#define  LCD_POSITION_4					(3U)
#define  LCD_POSITION_5					(4U)
#define  LCD_POSITION_6					(5U)
#define  LCD_POSITION_7					(6U)
#define  LCD_POSITION_8					(7U)
#define  LCD_POSITION_9					(8U)
#define  LCD_POSITION_10				(9U)
#define  LCD_POSITION_11				(10U)
#define  LCD_POSITION_12				(11U)
#define  LCD_POSITION_13				(12U)
#define  LCD_POSITION_14				(13U)
#define  LCD_POSITION_15				(14U)
#define  LCD_POSITION_16				(15U)



U8 LCD_Init_config(LCD_Type * this_ptr , U8 configPins[LCD_PINS_NUM][2] );

U8 LCD_IsConfigured(LCD_Type * this_ptr );


void LCD_Write_Command(LCD_Type * this_ptr, S8 command);

void LCD_Go_To_X_Y(LCD_Type * this_ptr ,U8 row,U8 position);

void LCD_Write_Character(LCD_Type * this_ptr, S8 character) ;

void LCD_Write_String(LCD_Type * this_ptr, S8 * str) ;
void LCD_Write_Float(LCD_Type * this_ptr, S32 fvalue,U8 percision) ;

void LCD_Initialization(LCD_Type * this_ptr) ;
#endif /* LCD_H_ */