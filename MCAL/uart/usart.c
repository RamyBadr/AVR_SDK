/*
 * uart.c
 *
 * Created: 10/10/2018 2:22:42 AM
 *  Author: www
 */ 
#include "usart.h"

void USART_InitMode(usart_mode mode){
	RegisterBitWrite(&UCSRC,UMSEL,mode);
}

void USART_InitParity(usart_parity_mode p_mode){
	RegisterMaskWrite(&UCSRC,USART_P_MASK,p_mode);
}
void USART_InitSymbolSize(usart_sy_size size){
	RegisterBitWrite(&UCSRC,UCSZ0,READ_BIT(size,0));
	RegisterBitWrite(&UCSRC,UCSZ1,READ_BIT(size,1));
	RegisterBitWrite(&UCSRB,UCSZ2,READ_BIT(size,2));
}

void USART_InitBaudRate(U16 rate){
	
	U8 LSB = (U8)(rate), MSB = (U8)((rate>>8));
	//write low byte to UBRRL
	RegisterWrite(&UBRRL,LSB);
	if(MSB!=0){
		//write high byte to UBRRH
		//clr URSEL to write on  UBRRH
		RegisterWrite(&UBRRH,MSB);
	}
}