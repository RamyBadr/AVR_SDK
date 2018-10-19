/*
 * counter.h
 *
 * Created: 17/09/2018 03:04:20 PM
 *  Author: Ramy Badr
 */ 


#ifndef COUNTER_H_
#define COUNTER_H_

#include "../HAL/SEVEN_SEG/SEVEN_SEG_config.h"


/*
one digit counter up
start num , end num : 0 to 9 : U8
delay : up to 0xFFFF : U32
*/
void counterUpOneDigit(SEVEN_SEG * SEVEN_SEG_ptr, U8 start_num,U8 end_num,U32 step_delay_ms);

/*
two digits counter up
start number , end number : 0 to 99 : U8 "FF=255"
delay : up to 0xFFFF : U32
*/
void counterUpTwoDigit(SEVEN_SEG * SEVEN_SEG_ones_ptr,SEVEN_SEG * SEVEN_SEG_tens_ptr, U8 start_num,U8 end_num,U32 step_delay_ms);


void counterDownOneDigit(SEVEN_SEG * SEVEN_SEG_ptr, U8 start_num,U8 end_num,U32 step_delay_ms);
void counterDownTwoDigit(SEVEN_SEG * SEVEN_SEG_ones_ptr,SEVEN_SEG * SEVEN_SEG_tens_ptr, U8 start_num,U8 end_num,U32 step_delay_ms);



#endif /* COUNTER_H_ */