/*
 * BTN.h
 *
 * Created: 11/09/2018 08:52:10 AM
 *  Author: Ramy Badr
 */ 


#ifndef BTN_H_
#define BTN_H_


#include "../../MCAL/DIO/DIO.h"
#include "../HAL_macros.h"

typedef struct{
	U8 			portBase;
	U8			pin;
	U8			active_state;
} BTN_Type;


void BTN_init(BTN_Type * this_ptr,U8 port_base,U8 pin,U8 active_state);
U8 BTN_Validate_Config(BTN_Type * this_ptr);
void BTN_getState(const BTN_Type const * this_ptr, U8 * stateVal);




#endif /* BTN_H_ */