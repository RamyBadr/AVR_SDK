/*
 * test_uart_intrupt.h
 *
 * Created: 10/11/2018 5:25:05 PM
 *  Author: Ramy Badr
 */ 


#ifndef TEST_UART_INTRUPT_H_
#define TEST_UART_INTRUPT_H_



#ifdef _TEST_UART_INT

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
void Tx( unsigned char data ){
	while ( !(UCSRA & (1<<UDRE)) ); // wait until UDR is empty
	UDR = data;
}
ISR (USART_RXC_vect){
	PORTB = UDR;
	Tx(++PORTB);
}
void init_s(){
	DDRD  = DDRD & 0xFE;
	UCSRB = (1<<RXEN )|(1<<TXEN )|(1<<RXCIE); // Rx, Tx and Receive Interrupt Enable
	UCSRC = (1<<UCSZ1)|(1<<UCSZ0);            // 8-bit data
	UBRRH = 415>>8; UBRRL = 415;			// For 8 MHz Crystal and 1200 baud rate

	sei();
}
int main(){
	DDRB = 0XFF;
	init_s();
	while(1);
}

#endif 



#endif /* TEST_UART_INTRUPT_H_ */