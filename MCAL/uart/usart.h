/*
 * uart.h
 *
 * Created: 10/10/2018 2:22:31 AM
 *  Author: www
 */ 


#ifndef USART_H_
#define USART_H_

#include "../register/Register.h"

//operation modes
typedef enum{
	URTASync = 0,
	URTSync = 1
	}usart_mode;
//parity modes
typedef enum{
	URTP_Disabled		=	(0<<UPM1)|(0<<UPM0),
	URTP_Even			=	(1<<UPM1)|(0<<UPM0),
	URTP_Odd			=	(1<<UPM1)|(1<<UPM0),
	}usart_parity_mode;
#define USART_P_MASK (1<<UPM1)|(1<<UPM0)

//symbol size
typedef enum{
	URT5Bit =	0x0,
	URT6Bit =	0x1,
	URT7Bit =	0x2,
	URT8Bit =	0x3,
	URT9Bit =	0x7
	}usart_sy_size;


void USART_InitMode(usart_mode mode);
void USART_InitParity(usart_parity_mode p_mode);
void USART_InitSymbolSize(usart_sy_size size);
void USART_InitBaudRate(U16 rate);

#endif /* UART_H_ */