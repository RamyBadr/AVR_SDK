/*
 * uart.h
 *
 * Created: 10/11/2018 5:00:11 PM
 *  Author: www
 */ 


#ifndef T_UART_POLL_H_
#define T_UART_POLL_H_

#ifdef _TEST_UART_POLL
#include "../../../HAL/LED/LED_config.h"
#include "../../../MCAL/interrupt/interrupt.h"
#include "../../../MCAL/register/Register.h"
#include "../../../MCAL/uart/usart.h"
void Tx( U8 data ){
	while ( !(UCSRA & (1<<UDRE)) ); 	// wait until UDR is empty
	UDR = data;                      // Putting data into UDR, sends the data
}
U8 Rx(){
	while ( !(UCSRA & (1<<RXC)) ); 	// wait for the Receive Complete (RXC) Flag
	return UDR;                      // Get and return received data from buffer
}
void init_s(){
	UCSRB = (1<<RXEN) |(1<<TXEN);    // Enable USART Receiver and Transmitter
	USART_InitSymbolSize(URT8Bit);
	//UCSRC = (1<<UCSZ1)|(1<<UCSZ0);   // Mode3: Use 8-bit data
	USART_InitBaudRate(51);
	//UBRRL = 51;                      // For 1 MHz Crystal and 1200 baud rate
}
int main(){
	DDRB = 0XFF; DDRD = 0XFE;
	init_s();
	while(1){
		PORTB = Rx(); Tx(++PORTB);
	}
}
#endif //_TEST_UART_H_



#endif /* T_UART_H_ */