/*
 * timer0.c
 *
 * Created: 10/9/2018 2:43:26 AM
 *  Author: Ramy BAdr
 */ 
#include "timer0.h"
// Timer functions
void T0InitMode(WGModeT0 mode){
	TCCR0 = 0;
	//TCCR0 = (WGM_MASK_T0 & mode) | ((~ WGM_MASK_T0 ) & ( TCCR0 ));
	RegisterMaskWrite(&TCCR0,WGM_MASK_T0,mode);
}
void T0InitCTCMode(CTC_ModeT0 mode){
	RegisterMaskWrite(&TCCR0,CTC_MODE_MASK_T0,mode);
}
void T0InitStartCount(U8 start_count){
	TCNT0 = start_count ;
}
void T0InitEndCount(U8 end_count){
	OCR0 = end_count;
}
void T0InitInterrupt(U8 is_interrupt){
	WGModeT0 mode = T0GetMode();
	if (is_interrupt)
	{
		
		if (mode==NORMAL){
			SET_BIT(TIMSK,TOIE0);
		}else{
			SET_BIT(TIMSK,OCIE0);
		}
	}else{
		if (mode==NORMAL){
			CLR_BIT(TIMSK,TOIE0);
		}else{
			CLR_BIT(TIMSK,OCIE0);
		}
	}
}
void T0Start(ClkSrcT0 prescaler){
	RegisterMaskWrite(&TCCR0,PRESCALER_MASK_T0,prescaler);
	SET_BIT(TIFR,TOV0);
}

U8 T0GetMode(){
	U8 mode = (READ_BIT(TCCR0,WGM00)<<WGM00)|(READ_BIT(TCCR0,WGM01)<<WGM01) ;
	return mode;
}
U8 T0GetCTCMode(){
	U8 mode = (READ_BIT(TCCR0,COM00)<<COM00)|(READ_BIT(TCCR0,COM01)<<COM01) ;
	return mode;
}
U8 T0GetCount(){
	return TCNT0;
}
U8 T0GetEndCount(){
	U8 mode = T0GetMode();
	if (mode==NORMAL){
		return 0xFF;
	}else if (mode==CTC){
		return OCR0;
	}else{
		//check others modes
		return OCR0;
	}
}
U8 T0GetClckSource(){
	U8 src = (READ_BIT(TCCR0,CS00)<<0)|(READ_BIT(TCCR0,CS01)<<1)|(READ_BIT(TCCR0,CS02)<<2) ;
	return src;
}

U8 Timer0Stop(){
	RegisterMaskWrite(&TCCR0,PRESCALER_MASK_T0,T0_OFF);
}


void Timer0Delay(){
	U8 overflow = 0 ;
	U8 mode = T0GetMode();
	do {
		
		if (mode==NORMAL){
			overflow = READ_BIT(TIFR,TOV0);
		}else if (mode==CTC){
			overflow = READ_BIT(TIFR,OCF0);
		}else{
			//check other modes
			overflow = READ_BIT(TIFR,OCF0);
		}		
	} while (overflow==0);
	
	// Stop Timer
	Timer0Stop();
	//clear flag by setting TOV0
	if (mode==NORMAL){
		SET_BIT(TIFR,TOV0);
	}else{
		SET_BIT(TIFR,OCF0);
	}
	
	
	
}
