/*
 * LCD.c
 *
 * Created: 17/09/2018 10:26:08 PM
 *  Author: Ramy Badr
 */ 
#include "LCD.h"
U8 LCD_Init_config(LCD_Type * this_ptr , U8 configPins[LCD_PINS_NUM][2] ){
	U8 i ,changed_pins = 0 ;
	
	this_ptr->LCD_pins[LCD_RS].port_base=configPins[LCD_RS][0];
	this_ptr->LCD_pins[LCD_RS].pin_no=configPins[LCD_RS][1];
	changed_pins ++ ;
	
	this_ptr->LCD_pins[LCD_RW].port_base=configPins[LCD_RW][0];
	this_ptr->LCD_pins[LCD_RW].pin_no=configPins[LCD_RW][1];
	changed_pins ++ ;
	
	this_ptr->LCD_pins[LCD_EN].port_base=configPins[LCD_EN][0];
	this_ptr->LCD_pins[LCD_EN].pin_no=configPins[LCD_EN][1];
	changed_pins ++ ;
	
	this_ptr->LCD_pins[LCD_D4].port_base=configPins[LCD_D4][0];
	this_ptr->LCD_pins[LCD_D4].pin_no=configPins[LCD_D4][1];
	changed_pins ++ ;
	
	this_ptr->LCD_pins[LCD_D5].port_base=configPins[LCD_D5][0];
	this_ptr->LCD_pins[LCD_D5].pin_no=configPins[LCD_D5][1];
	changed_pins ++ ;
	
	this_ptr->LCD_pins[LCD_D6].port_base=configPins[LCD_D6][0];
	this_ptr->LCD_pins[LCD_D6].pin_no=configPins[LCD_D6][1];
	changed_pins ++ ;
	
	this_ptr->LCD_pins[LCD_D7].port_base=configPins[LCD_D7][0];
	this_ptr->LCD_pins[LCD_D7].pin_no=configPins[LCD_D7][1];
	changed_pins ++ ;
	//for (i=0;i<LCD_PINS_NUM;i++){
		//if(IS_PORT(configPins[i][0])&&IS_PIN(configPins[i][1])){
			//this_ptr->LCD_pins[i].port_base=configPins[i][0];
			//this_ptr->LCD_pins[i].pin_no=configPins[i][1];
			//changed_pins ++ ;
		//}
	//}
	return changed_pins ;
}
U8 LCD_IsConfigured(LCD_Type * this_ptr ){
	U8 i = 0 , is_configured = 0;
	do{
		is_configured = (IS_PORT(this_ptr->LCD_pins[i].port_base)) && (IS_PIN(this_ptr->LCD_pins[i].pin_no));
		i++;
	}while((i<LCD_PINS_NUM)&&is_configured);
	return is_configured ;
}

 void static LCD_READ(LCD_Type * this_ptr)
 {
	 /* LCD enable pin high */
	 DIO_PinWrite(this_ptr->LCD_pins[LCD_EN].port_base,this_ptr->LCD_pins[LCD_EN].pin_no,1);  
	 
	 /* delay to let the LCD read the command/data */
	 _delay_us(2U);
	 
	 /* LCD enable pin low */
	 DIO_PinWrite(this_ptr->LCD_pins[LCD_EN].port_base,this_ptr->LCD_pins[LCD_EN].pin_no,0);  
	 
	 /* delay to let the LCD execute the command or show the data */
	 _delay_ms(5U);
 }

 /**********************************************/

void static LCD_Write_4bit_mode(LCD_Type * this_ptr, S8 value) { 
	/* write each bit of the high nibbles to its place */	
	DIO_PinWrite(this_ptr->LCD_pins[LCD_D7].port_base,this_ptr->LCD_pins[LCD_D7].pin_no,READ_BIT(value,7));    	 
	DIO_PinWrite(this_ptr->LCD_pins[LCD_D6].port_base,this_ptr->LCD_pins[LCD_D6].pin_no,READ_BIT(value,6));
	DIO_PinWrite(this_ptr->LCD_pins[LCD_D5].port_base,this_ptr->LCD_pins[LCD_D5].pin_no,READ_BIT(value,5));
	DIO_PinWrite(this_ptr->LCD_pins[LCD_D4].port_base,this_ptr->LCD_pins[LCD_D4].pin_no,READ_BIT(value,4));
	 
	/* LCD read */
	LCD_READ(this_ptr);
	
	/* write each bit of the low nibbles to its place */
	DIO_PinWrite(this_ptr->LCD_pins[LCD_D7].port_base,this_ptr->LCD_pins[LCD_D7].pin_no,READ_BIT(value,3));
	DIO_PinWrite(this_ptr->LCD_pins[LCD_D6].port_base,this_ptr->LCD_pins[LCD_D6].pin_no,READ_BIT(value,2));
	DIO_PinWrite(this_ptr->LCD_pins[LCD_D5].port_base,this_ptr->LCD_pins[LCD_D5].pin_no,READ_BIT(value,1));
	DIO_PinWrite(this_ptr->LCD_pins[LCD_D4].port_base,this_ptr->LCD_pins[LCD_D4].pin_no,READ_BIT(value,0));
	
	/* LCD read */
	LCD_READ(this_ptr);
	
 }
 /**********************************************/
 void LCD_Write_Command(LCD_Type * this_ptr, S8 command){

	 /* RS pin low */
	 DIO_PinWrite(this_ptr->LCD_pins[LCD_RS].port_base,this_ptr->LCD_pins[LCD_RS].pin_no,0x00);
	 
	 /* RW pin low */
	 DIO_PinWrite(this_ptr->LCD_pins[LCD_RW].port_base,this_ptr->LCD_pins[LCD_RW].pin_no,0x00);

	 /* write command with 4 bit mode */
	 LCD_Write_4bit_mode(this_ptr , command);
 }
 
 /**********************************************/

 void LCD_Go_To_X_Y(LCD_Type * this_ptr ,U8 row,U8 position) {
	 // send the position to the LCD
	 if (row==LCD_ROW_1)
	 {
		 LCD_Write_Command(this_ptr , 127+position);
		 
	 }
	 
	 else if(row==LCD_ROW_2)
	 {
		 LCD_Write_Command(this_ptr , 191+position);
		 
	 }

 }
 
 /**********************************************/

 void LCD_Write_Character(LCD_Type * this_ptr, S8 character) {
	 /* RS pin high */
	 DIO_PinWrite(this_ptr->LCD_pins[LCD_RS].port_base,this_ptr->LCD_pins[LCD_RS].pin_no,1);
	 
	 /* RW pin low */
	 DIO_PinWrite(this_ptr->LCD_pins[LCD_RW].port_base,this_ptr->LCD_pins[LCD_RW].pin_no,0);

	 /* write character with 4 bit mode */
	 LCD_Write_4bit_mode(this_ptr , character);
 }
  /**********************************************/

  void LCD_Write_String(LCD_Type * this_ptr, S8 * str){
	  while(*str)
	  {
		  LCD_Write_Character(this_ptr ,*str++);
	  }
  }
  
  void LCD_Write_Float(LCD_Type * this_ptr, S32 fvalue,U8 percision) {
	  S8 str[STR_SIZE];
	  fltostr(fvalue,str,percision);
	  LCD_Write_String(this_ptr,str);
	  
  }
  
  
   void LCD_Initialization(LCD_Type * this_ptr){
	   U8 i ;
	   if(LCD_IsConfigured(this_ptr)){
			/* delay for 15 ms for the LCD to power up */
			_delay_ms(15);
			/* set the direction for the LCD pins */
			for (i=0;i<LCD_PINS_NUM;i++){
				DIO_PinDir(this_ptr->LCD_pins[i].port_base,this_ptr->LCD_pins[i].pin_no,OUTPUT);
			}
			
			/* send the initialization values as in data sheet (as commands) */
			/* send the initialization values as in data sheet (as commands) */
			LCD_Write_Command(this_ptr,0x33U);  /* Initialization */
			LCD_Write_Command(this_ptr,0x32U);	/* Initialization */
			LCD_Write_Command(this_ptr,0x28U);	/* Function Set: 4-bit, 2 Line, 5x7 Dots */
			LCD_Write_Command(this_ptr,0x0CU);	/* Display on ,cursor off */
			LCD_Write_Command(this_ptr,0x01U);  /* Clear display , Cursor home */
		   
	   }
	   
	   
  }