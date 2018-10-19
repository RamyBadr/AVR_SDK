/*
 * BTN.c
 *
 * Created: 11/09/2018 08:52:50 AM
 *  Author: Ramy Badr
 */ 

#include "BTN.h"

void BTN_init(BTN_Type * this_ptr,U8 port_base,U8 pin,U8 active_state){
	if(IS_PORT(port_base)&&IS_PIN(pin)&&IS_STATE(active_state)){
		this_ptr->portBase = port_base;
		this_ptr->pin = pin ;
		this_ptr->active_state = active_state ;
		DIO_PinDir(this_ptr->portBase,this_ptr->pin,INPUT);		
	}
}

U8 BTN_Validate_Config(BTN_Type * this_ptr){
	return ((IS_PORT(this_ptr->portBase))&&(IS_PIN(this_ptr->pin))&&(READ_BIT(DDR(this_ptr->portBase),this_ptr->pin)==INPUT));
}

void BTN_getState(const BTN_Type const * this_ptr, U8 * stateVal){

	DIO_PinRead(this_ptr->portBase,this_ptr->pin,stateVal);
	
}