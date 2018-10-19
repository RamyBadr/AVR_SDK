/*
 * counter.c
 *
 * Created: 17/09/2018 03:05:42 PM
 *  Author: Ramy Badr
 */ 
#include "counter.h"


/*
one digit counter up 
start num , end num : 0 to 9 : U8
delay : up to 0xFFFF : U32
*/
void counterUpOneDigit(SEVEN_SEG * SEVEN_SEG_ptr,U8 start_num,U8 end_num,U32 step_delay_ms){
	U8 num_counter;
	U32 delay_counter;
	if(start_num>=0&&start_num<=9&&end_num>=0&&end_num<=9){
		if (start_num>end_num){
			start_num += end_num ;
			end_num = start_num - end_num ;
			start_num -= end_num ;
		}
		
		for (num_counter=start_num;num_counter<=end_num;num_counter++){
			for (delay_counter=1;delay_counter<=step_delay_ms;delay_counter++)
			{
				SEVEN_SEG_Show_Num(SEVEN_SEG_ptr,num_counter);
				_delay_ms(1);
			}
			
		}
	}
	
}


/*
two digits counter up
start number , end number : 0 to 99 : U8 "FF=255"
delay : up to 0xFFFF : U32
*/
void counterUpTwoDigit(SEVEN_SEG * SEVEN_SEG_ones_ptr,SEVEN_SEG * SEVEN_SEG_tens_ptr, U8 start_num,U8 end_num,U32 step_delay_ms){
	U8	num_counter,ones,tens;
	U32 delay_counter;
	
	SEVEN_SEG_Disable(SEVEN_SEG_ones_ptr);
	SEVEN_SEG_Disable(SEVEN_SEG_tens_ptr);
	if(start_num>=0&&start_num<=99&&end_num>=0&&end_num<=99){
		if (start_num>end_num){
			start_num += end_num ;
			end_num = start_num - end_num ;
			start_num -= end_num ;
		}
		
		
		for (num_counter=start_num;num_counter<=end_num;num_counter++){
			ones =(U8) (num_counter % 10) ;
			tens = (U8) (num_counter / 10 );			
			for (delay_counter=1;delay_counter<=(U32) (step_delay_ms / 2) ;delay_counter++)
			{
				SEVEN_SEG_Enable(SEVEN_SEG_ones_ptr);
				SEVEN_SEG_Show_Num(SEVEN_SEG_ones_ptr,ones);
				_delay_ms(1);
				SEVEN_SEG_Disable(SEVEN_SEG_ones_ptr);
				SEVEN_SEG_Enable(SEVEN_SEG_tens_ptr);
				SEVEN_SEG_Show_Num(SEVEN_SEG_tens_ptr,tens);
				_delay_ms(1);
 				SEVEN_SEG_Disable(SEVEN_SEG_tens_ptr);
			}
			
		}
	}
	
}



/*
one digit counter down
start num , end num : 0 to 9 : U8
delay : up to 0xFFFF : U32
*/
void counterDownOneDigit(SEVEN_SEG * SEVEN_SEG_ptr,U8 start_num,U8 end_num,U32 step_delay_ms){
	U8 num_counter;
	U32 delay_counter;
	if(start_num>=0&&start_num<=9&&end_num>=0&&end_num<=9){
		if (start_num<end_num){
			start_num += end_num ;
			end_num = start_num - end_num ;
			start_num -= end_num ;
		}
		
		for (num_counter=start_num;num_counter>=end_num;num_counter--){
			for (delay_counter=1;delay_counter<=step_delay_ms;delay_counter++)
			{
				SEVEN_SEG_Show_Num(SEVEN_SEG_ptr,num_counter);
				_delay_ms(1);
			}
			
		}
	}
	
}



/*
two digits counter down
start number , end number : 0 to 99 : U8 "FF=255"
delay : up to 0xFFFF : U32
*/
void counterDownTwoDigit(SEVEN_SEG * SEVEN_SEG_ones_ptr,SEVEN_SEG * SEVEN_SEG_tens_ptr, U8 start_num,U8 end_num,U32 step_delay_ms){
	U8	num_counter,ones,tens;
	U32 delay_counter;
	
	SEVEN_SEG_Disable(SEVEN_SEG_ones_ptr);
	SEVEN_SEG_Disable(SEVEN_SEG_tens_ptr);
	if(start_num>=0&&start_num<=99&&end_num>=0&&end_num<=99){
		if (start_num<end_num){
			start_num += end_num ;
			end_num = start_num - end_num ;
			start_num -= end_num ;
		}
		
		
		for (num_counter=start_num;num_counter>=end_num;num_counter--){
			ones =(U8) (num_counter % 10) ;
			tens = (U8) (num_counter / 10 );
			for (delay_counter=1;delay_counter<=(U32) (step_delay_ms / 2) ;delay_counter++)
			{
				SEVEN_SEG_Enable(SEVEN_SEG_ones_ptr);
				SEVEN_SEG_Show_Num(SEVEN_SEG_ones_ptr,ones);
				_delay_ms(1);
				SEVEN_SEG_Disable(SEVEN_SEG_ones_ptr);
				SEVEN_SEG_Enable(SEVEN_SEG_tens_ptr);
				SEVEN_SEG_Show_Num(SEVEN_SEG_tens_ptr,tens);
				_delay_ms(1);
				SEVEN_SEG_Disable(SEVEN_SEG_tens_ptr);
			}
			
		}
	}
}