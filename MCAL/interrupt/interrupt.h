/*
 * interrupt.h
 *
 * Created: 21/09/2018 02:47:17 PM
 *  Author: www
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../avratmega32.h"
#include "avr/interrupt.h"

//define gneral index for available external interrupts
#define  EX_INTERRUPT0 0
#define  EX_INTERRUPT1 1
#define  EX_INTERRUPT2 2
#define IS_EX_INTERRUPT(intr_index)		((intr_index==EX_INTERRUPT0)||(intr_index==EX_INTERRUPT1)||(intr_index==EX_INTERRUPT1))

typedef enum{
	LowLevel		= 0x00,
	LogicChange		= 0x01,
	FallingEdge		= 0x02,
	RisingEdge		=0x03,
}InterSenseControlStatus;

/***
** External Interrupts control
** Ext interrupt2 INT2 controlled from ISC2 in MCUCSR Bit6.
****
** ISC0n: Interrupt Sense Control 0 Bit 1 and Bit 0 [n = 1:0]
** ISC01, ISC00 = { 00: The low level of INT0 generates an interrupt request,
**					01: Any logical change on INT0 generates an interrupt request,
**					10: The falling edge of INT0 generates an interrupt request,
**					11: The rising edge of INT0 generates an interrupt request  }
*/

/*
** ISC1n: Interrupt Sense Control 1 Bit 1 and Bit 0 [n = 1:0]
** ISC11, ISC10 = { 00: The low level of INT1 generates an interrupt request,
**					01: Any logical change on INT1 generates an interrupt request,
**					10: The falling edge of INT1 generates an interrupt request,
**					11: The rising edge of INT1 generates an interrupt request }
*/

void EnableExInterrupt(U8 ex_interrupt_index, InterSenseControlStatus status);


#endif /* INTERRUPT_H_ */