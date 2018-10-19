/*
 * Register.c
 *
 * Created: 10/9/2018 1:01:20 AM
 *  Author: Ramy Badr
 */ 

#include "Register.h"


//////////////////////////////////////////////////////////////////////////////////
//                    Writing to Register
//////////////////////////////////////////////////////////////////////////////////

U8 RegisterWrite(volatile U8 * reg, U8 val ){
	U8 changed_pins = 0;
	if(IS_REGISTER(reg)){
		*reg = val;	
		changed_pins = 8;
	}
	return changed_pins;
	
}

U8 RegisterBitWrite(volatile U8 * reg, U8 bit, U8 val){
	U8 changed_pins = 0;
	if(IS_REGISTER(reg)&&IS_PIN(bit)){
		SET_BIT(*reg,bit);
		changed_pins = 1;
	}
	return changed_pins;
}

U8 RegisterRangeWrite(volatile U8 * reg, U8 startRegisterBit, U8 endRegisterBit, U8 val){
	
}

U8 RegisterMaskWrite(volatile U8 * reg, U8 mask, U8 val){
	U8 changed_pins = 0;
	if(IS_REGISTER(reg)){		
		*reg = (mask & val) | ((~ mask ) & ( *reg ));
		changed_pins = 8;
	}
	return changed_pins;
}

//////////////////////////////////////////////////////////////////////////////////
//                   Reading Register value
//////////////////////////////////////////////////////////////////////////////////

U8 RegisterRead(volatile U8 * reg, U8 *portVal );

U8 RegisterBitRead(volatile U8 * reg, U8 bit, U8 *bitVal);

U8 RegisterRangeRead(volatile U8 * reg, U8 startRegisterBit, U8 endRegisterBit, U8 *rangeReadVal);

U8 RegisterMaskRead(volatile U8 * reg, U8 mask, U8 *val){
	U8 changed_pins = 0;
	if(IS_REGISTER(reg)){
		*val = (mask & (*reg)) | ((~ mask) & (*val));
		changed_pins = 8;
	}
	return changed_pins;
}

//////////////////////////////////////////////////////////////////////////////////
//                    Toggle Register Value
//////////////////////////////////////////////////////////////////////////////////

U8 RegisterToggle(volatile U8 * reg){
	U8 changed = 0 ;
	*reg = (*reg)^0xFF ;
	changed = 8 ;
	return changed ;
}

U8 RegisterBitToggle(volatile U8 * reg, U8 bit){
	U8 changed = 0 ;
	TOGGLE_BIT(*reg,bit);
	changed = 1 ;
	return changed ;
}

U8 RegisterRangeToggle(volatile U8 * reg, U8 startRegisterBit, U8 endRegisterBit);

U8 RegisterMaskToggle(volatile U8 * reg, U8 mask){
	U8 changed = 0 ;
	*reg = (*reg)^mask ;
	changed = 8 ;
	return changed ;
}




