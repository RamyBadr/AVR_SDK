/*
 * SEVEN_SEG.h
 *
 * Created: 11/09/2018 11:45:23 AM
 *  Author: Ramy Badr
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "../HAL_macros.h"


//pins indices
#define		SG_A	0
#define		SG_B	1
#define		SG_C	2
#define		SG_D	3
#define		SG_E	4

//active states
#define		COMMON_CATHODE		ACTIVE_HIGH
#define		COMMON_ANODE		ACTIVE_LOW

typedef struct{
	PinType SG_pins[5];
	U8 active_state;
}SEVEN_SEG;

U8 SEVEN_SEG_Init(SEVEN_SEG * this_ptr , PinType configPins[5], U8 active_state );
void SEVEN_SEG_Enable(SEVEN_SEG * this_ptr);
void SEVEN_SEG_Disable(SEVEN_SEG * this_ptr);
U8 SEVEN_SEG_Is_Enabled(SEVEN_SEG * this_ptr);
U8 SEVEN_SEG_Show_Num(SEVEN_SEG * this_ptr,U8 number);
U8 SEVEN_SEG_Get_Num(SEVEN_SEG * this_ptr);
U8 SEVEN_SEG_Increment(SEVEN_SEG * this_ptr);
U8 SEVEN_SEG_Decrement(SEVEN_SEG * this_ptr);

#endif /* SEVEN_SEG_H_ */