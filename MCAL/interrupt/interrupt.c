
/*
 * interrupt.c
 *
 * Created: 21/09/2018 02:47:01 PM
 *  Author: www
 */ 
#include "interrupt.h"

void EnableExInterrupt(U8 ex_interrupt_index, InterSenseControlStatus status){
	if (IS_EX_INTERRUPT(ex_interrupt_index)){
		//Global Interrupt Enable
		SET_BIT(SREG,I);
		switch(ex_interrupt_index){
			case EX_INTERRUPT0:
			//General Interrupt Control Register : External Interrupt Request 0 Enable
			SET_BIT(GICR,INT0);
			//ISC0n: Interrupt Sense Control 0 Bit 1 and Bit 0 [n = 1:0]
			switch(status){
				case LowLevel:
				// low level sense control 00
				CLR_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				break;
				case LogicChange:
				// logic change sense control 01
				SET_BIT(MCUCR,ISC00);
				CLR_BIT(MCUCR,ISC01);
				break;
				case FallingEdge:
				// falling edge sense control 10
				CLR_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
				break;
				case RisingEdge:
				// rising edge sense control 11
				SET_BIT(MCUCR,ISC00);
				SET_BIT(MCUCR,ISC01);
				break;
			}
			case EX_INTERRUPT1:
			//General Interrupt Control Register : External Interrupt Request 1 Enable
			SET_BIT(GICR,INT1);
			switch(status){
				case LowLevel:
				// low level sense control 00
				CLR_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
				break;
				case LogicChange:
				// logic change sense control 01
				SET_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
				break;
				case FallingEdge:
				// falling edge sense control 10
				CLR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
				case RisingEdge:
				// rising edge sense control 11
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
			}
			case EX_INTERRUPT2:
			//General Interrupt Control Register : External Interrupt Request 1 Enable
			SET_BIT(GICR,INT2);
			break;
		}
	}
}