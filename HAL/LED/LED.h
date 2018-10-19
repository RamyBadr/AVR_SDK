/*
 * LED.h
 *
 * Created: 10/09/2018 11:32:39 PM
 *  Author: Ramy Badr
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"
#include "../HAL_macros.h"



typedef struct{
	U8 			portBase;
	U8			pin;
	U8			active_state;
	
}LED_Type;


void LED_init(LED_Type * this_ptr,U8 port_base,U8 pin,U8 active_state);
U8 LED_Validate_Config(LED_Type * this_ptr);
void LED_on(LED_Type * this_ptr);
void LED_off(LED_Type * this_ptr);
void LED_toggle(LED_Type * this_ptr);
void LED_flash(LED_Type* this_ptr,U16 flash_interval);
U8 LED_IS_ON(LED_Type * this_ptr);



#endif /* LED_H_ */