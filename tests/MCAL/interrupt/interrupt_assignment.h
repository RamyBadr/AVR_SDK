/*
 * interrupt_assignment.c
 *
 * Created: 21/09/2018 05:15:56 PM
 *  Author: www
 */ 
/*
 * interuptmain.c
 *
 * Created: 21/09/2018 04:57:17 ã
 *  Author: Ramy Badr
 */
 
#ifdef INTERRUPT_ASSIGN
#include "../../../HAL/LED/LED_config.h"
#include "../../../HAL/BTN/BTN_config.h"
#include "../../../MCAL/interrupt/interrupt.h"


volatile U8 state = 0;
volatile U8 switchVal ;
void main(){
	Initialize_BTNS();
	Initialize_LEDS();
	LED_off(&LEDS_Arr[0]);
	EnableExInterrupt(EX_INTERRUPT1,FallingEdge);
	//LED_flash(&LEDS_Arr[0],100,100);
	while(1){
		while(state==0){
			LED_off(&LEDS_Arr[0]);
		}
		while(state==1){
			LED_flash(&LEDS_Arr[0],100,100);
		}
		while(state==2){
			LED_on(&LEDS_Arr[0]);
		}
		while(state==3){
			LED_off(&LEDS_Arr[0]);
			state = 0;
		}
	}
}

ISR (INT1_vect){
	if(state!=1){
		state ++; 	
	}
	else{
		BTN_getState(&BTNS_Arr[0],&switchVal);
		if (switchVal==0){
			state++;
		}
	}
	
}
#endif