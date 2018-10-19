/*
 * timer.h
 *
 * Created: 08/10/2018 07:20:08 PM
 *  Author: www
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../avratmega32.h"
#include "../timers_basic.h"



// Timer functions 
void T0InitMode(WGModeT0 mode);
void T0InitCTCMode(CTC_ModeT0 mode);
void T0InitStartCount(U8 start_count);
void T0InitEndCount(U8 end_count);
void T0InitInterrupt(U8 is_interrupt);
void T0Start(ClkSrcT0 prescaler);

U8 T0GetMode();
U8 T0GetCTCMode();
U8 T0GetCount();
U8 T0GetEndCount();
U8 T0GetClckSource();	


//use Timer to delay using polling
void Timer0Delay();


#endif /* TIMER_H_ */