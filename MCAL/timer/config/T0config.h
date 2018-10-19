/*
 * T0config.h
 *
 * Created: 10/9/2018 9:33:11 PM
 *  Author: www
 */ 


#ifndef T0CONFIG_H_
#define T0CONFIG_H_

#include "../t0/timer0.h"

// Timer 0 configuration
void Timer0Config(WGModeT0 mode,U8 start_count,U8 end_count,U8 is_interrupt,ClkSrcT0 source){
	T0InitMode(mode);
	T0InitStartCount(start_count);
	if(mode!=NORMAL){
		T0InitEndCount(end_count);
	}
	T0InitInterrupt(is_interrupt);
	RegisterMaskWrite(&TCCR0,PRESCALER_MASK_T0,source);
	SET_BIT(TIFR,TOV0);
}

#endif /* T0CONFIG_H_ */