/*
 * HAL_MACROS.h
 *
 * Created: 10/09/2018 11:35:02 PM
 *  Author: Ramy Badr
	
 */ 


#ifndef HAL_MACROS_H_
#define HAL_MACROS_H_
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../UTILS/datatypes.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/avratmega32.h"


#define ACTIVE_HIGH 1 
#define ACTIVE_LOW 0
#define IS_STATE(state) ((state==ACTIVE_LOW)||(state==ACTIVE_HIGH))
#define REVERSE_STATE(state)	((state==ACTIVE_HIGH)?ACTIVE_LOW:ACTIVE_HIGH)



#endif /* HAL_MACROS_H_ */

