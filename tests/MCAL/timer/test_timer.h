/*
 * test_timer.h
 *
 * Created: 08/10/2018 07:25:21 PM
 *  Author: Ramy Badr
 */ 


#ifndef TEST_TIMER_H_
#define TEST_TIMER_H_

#ifdef TEST_TIMER

#include "../../../HAL/LED/LED_config.h"
#include "../../../MCAL/interrupt/interrupt.h"
#include "../../../MCAL/register/Register.h"

void T0_delay_basic();
void T0_daly_ms();
void Init_timer0(U8 is_interrupt);
void T0_1ms_Interrupt();
volatile U16 interrupt_count = 0;
void main(){
	int i;
	Initialize_LEDS();
	T0_1ms_Interrupt();
	sei();
	//while (1){
		//
		//LED_on(LEDS_Arr+1);
		////28 us to 280 ms
		////for(i=0;i<10000;i++){
			////T0_delay_basic() ;	
		////}
		//for(i=0;i<1000;i++){
			//T0_daly_ms();
		//}
		//
	//}
	while(1){
		if(interrupt_count>=1000){
			LED_toggle(LEDS_Arr+1);
			interrupt_count = 0;
			//T0_1ms_Interrupt();
		}
		LED_on(LEDS_Arr+0);
	}
}
ISR (TIMER0_OVF_vect){
	interrupt_count++;
}

/*
use timer 0 to generate delay of 28 us
MCU frequency = 8 MHz
prescaler : 1
clock period = 1/8 MHz = 0.125 us
period_count = 28/0.125 = 224 = 0xE0 periods
to finish at 0xFF : start at initial = 0xFF - 0xE0 + 0x01 = 0x20
*/
void T0_delay_basic(){
	U8 overflow = 0 ;
	// Timer/counter0 content Register
	TCNT0 = 0x20;
	// Run Timer0, Normal mode, no pre-scaler
	//this could be done simply by setting 
	//TCCR0 = 0x01 ;
	//but used this to show all bits inside register :
	//on , no pre scaler
	TCCR0 |= 1<<CS00;
	TCCR0 &= ~(1<<FOC0|1<<WGM00|1<<COM01|1<<COM00|1<<WGM01|1<<CS01|1<<CS02);
	//loop till overflow flag TOV0 is set in TIFR
	do {
		overflow = READ_BIT(TIFR,TOV0);
	} while (overflow==0);
	// Stop Timer
	TCCR0 = 0x00;
	//clear flag by setting TOV0
	SET_BIT(TIFR,TOV0);
}

/*
use timer 0 to generate delay of 1 ms
MCU frequency = 8 MHz
prescaler : 64
frequency = 125000 HZ
clock period = 1/125000 = 0.000008 s = .008 ms
period_count = 1 ms/0.008 ms = 125 = 0x7D periods
to finish at 0xFF : start at initial = 0xFF - 0x7D + 0x01 = 0x83
*/

void T0_daly_ms(){
	U8 overflow = 0 ;
	// Timer/counter0 content Register
	TCNT0 = 0x83;
	// Run Timer0, Normal mode, pre-scaler = 64
	//first set all to 0 ;
	TCCR0 = 0x00; //off
	//on , pre scaler = 64 : CS02 CS01 CS00 : 0 1 1
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	//loop till overflow flag TOV0 is set in TIFR
	do {
		overflow = READ_BIT(TIFR,TOV0);
	} while (overflow==0);
	// Stop Timer
	TCCR0 = 0x00;
	//clear flag by setting TOV0
	SET_BIT(TIFR,TOV0);
}

void T0_1ms_Interrupt(){
	U8 scaler_mask = (1<<CS02)|(1<<CS01)|(1<<CS00) , scaler_val = 0x03 ;
	// Timer/counter0 content Register
	RegisterWrite(&TCNT0,0x83);
	//TCNT0 = 0x83;
	// Run Timer0, Normal mode, pre-scaler = 64
	//first set all to 0 ;
	TCCR0 = 0x00; //off
	// Enable Interrupt
	SET_BIT(TIMSK,TOIE0);
	//on , pre scaler = 64 : CS02 CS01 CS00 : 0 1 1
	RegisterMaskWrite(&TCCR0,scaler_mask,scaler_val);
}


#endif



#endif /* TEST_TIMER_H_ */