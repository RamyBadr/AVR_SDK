/*
 * test_T0.h
 *
 * Created: 10/9/2018 4:01:41 PM
 *  Author: Ramy Badr
 */ 


#ifndef TEST_T0_H_
#define TEST_T0_H_
#ifdef _Test_T0



#include "../../../HAL/LED/LED_config.h"
#include "../../../MCAL/interrupt/interrupt.h"
#include "../t0/timer0.h"
#include "../config/T0config.h"
volatile U16 interrupt_count = 0;
void main(){
	int i;
	Initialize_LEDS();
	LED_on(LEDS_Arr+0);
	sei();
	
	//T0InitCTCMode(CTC_Set);
	Timer0Config(NORMAL,0x20,0xFF,INT_OFF,T0_PRESCALER_64);
	
	while(1){
		//delay polling
		for(i=0;i<500;i++){
			Timer0Delay();
		}
		LED_toggle(LEDS_Arr+0);
		
		////interupt
		//if(interrupt_count>=500){
			//LED_toggle(LEDS_Arr+0);
			//interrupt_count = 0;
		//}
		//
	}
}
ISR (TIMER0_OVF_vect){
	interrupt_count++;
}

#endif // _DEBUG




#endif /* TEST_T0_H_ */