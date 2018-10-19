/*
 * keypad.h
 *
 * Created: 10/11/2016 11:42:05 AM
 *  Author: Master
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

//#include<util/delay.h>
#include "../HAL_macros.h"
//#include "../LCD/LCD_config.h"

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define ky_Col_Num 4
#define Ky_Row_num 4
#define ky_Pins_Num (ky_Col_Num+Ky_Row_num)

typedef struct{
	PinType		pins[ky_Pins_Num];
	U8			charset[Ky_Row_num][ky_Col_Num];
}KeyPAD_Type;


//Keypad functions and global variables




void Keypad_init_config(KeyPAD_Type * this_ptr,U8 keyPadConfig[ky_Pins_Num][2],U8 charset[Ky_Row_num][ky_Col_Num]);
void Keypad_init(KeyPAD_Type * this_ptr);
char Keypad_getkey(KeyPAD_Type * this_ptr);

#endif /* KEYPAD_H_ */