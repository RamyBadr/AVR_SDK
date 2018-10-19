/*
 * Register.h
 *
 * Created: 10/9/2018 1:01:02 AM
 *  Author: Ramy Badr
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
#include "../avratmega32.h"

//define basic range addresses for registers
#define START_ADDRESS			0x00
#define END_ADDRESS				0xFF
#define IS_REGISTER(address)	(address>=START_ADDRESS&&address<=END_ADDRESS)


//////////////////////////////////////////////////////////////////////////////////
//                    Writing to Register
//////////////////////////////////////////////////////////////////////////////////

U8 RegisterWrite(volatile U8 * reg, U8 val );

U8 RegisterBitWrite(volatile U8 * reg, U8 bit, U8 val);

U8 RegisterRangeWrite(volatile U8 * reg, U8 startRegisterBit, U8 endRegisterBit, U8 val);

U8 RegisterMaskWrite(volatile U8 * reg, U8 mask, U8 val);

//////////////////////////////////////////////////////////////////////////////////
//                   Reading Register value
//////////////////////////////////////////////////////////////////////////////////

U8 RegisterRead(volatile U8 * reg, U8 *portVal );

U8 RegisterBitRead(volatile U8 * reg, U8 bit, U8 *bitVal);

U8 RegisterRangeRead(volatile U8 * reg, U8 startRegisterBit, U8 endRegisterBit, U8 *rangeReadVal);

U8 RegisterMaskRead(volatile U8 * reg, U8 mask, U8 *val);

//////////////////////////////////////////////////////////////////////////////////
//                    Toggle Register Value
//////////////////////////////////////////////////////////////////////////////////

U8 RegisterToggle(volatile U8 * reg);

U8 RegisterBitToggle(volatile U8 * reg, U8 bit);

U8 RegisterRangeToggle(volatile U8 * reg, U8 startRegisterBit, U8 endRegisterBit);

U8 RegisterMaskToggle(volatile U8 * reg, U8 mask);





#endif /* REGISTER_H_ */