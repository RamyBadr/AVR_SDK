/*
 * interuptmain.c
 *
 * Created: 21/09/2018 04:57:17 م
 *  Author: Ramy Badr
 */ 

#ifndef interuptmain_h__
#define interuptmain_h__

#ifdef TEST_INTERRUPT

#include "../HAL/LED/LED_config.h"
#include "../App/counter.h"
#include "../MCAL/interrupt/interrupt.h"
void main(){
	Initialize_LEDS();
	InitSevenSegs();
	SEVEN_SEG_Enable(&SEVEN_SEGs_Arr[0]);
	SEVEN_SEG_Disable(&SEVEN_SEGs_Arr[1]);
	LED_on(&LEDS_Arr[0]);
	LED_on(&LEDS_Arr[1]);
	EnableExInterrupt(EX_INTERRUPT0,RisingEdge);
	EnableExInterrupt(EX_INTERRUPT1,FallingEdge);
	while (1)
	{
		counterDownOneDigit(&SEVEN_SEGs_Arr[0],9,0,200);
	}
}


ISR (INT0_vect){
	LED_toggle(&LEDS_Arr[0]);
	
}
ISR (INT1_vect){
	LED_toggle(&LEDS_Arr[1]);
}
#endif
#endif // interuptmain_h__