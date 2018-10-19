/*
 * timers_basic.h
 *
 * Created: 10/9/2018 11:29:09 PM
 *  Author: www
 */ 


#ifndef TIMERS_BASIC_H_
#define TIMERS_BASIC_H_


#define INT_OFF 0
#define INT_ON  1

//timer0 wave form generation mask
#define WGM_MASK_T0 ((1<<WGM00)|(1<<WGM01))
//timer0 wave form generation mask
#define CTC_MODE_MASK_T0 ((1<<COM00)|(1<<COM01))

//timer0 prescaler mask
#define PRESCALER_MASK_T0	((1<<CS02)|(1<<CS01)|(1<<CS00))


//timer0 wave form generation modes
typedef enum{
	NORMAL  = ((0<<WGM01)|(0<<WGM00))	,
	PWM		= ((0<<WGM01)|(1<<WGM00))	,
	CTC		= ((1<<WGM01)|(0<<WGM00))	,
	F_PWM	= ((1<<WGM01)|(1<<WGM00))
}WGModeT0;


typedef enum{
	CTC_NORMAL		= ((0<<COM01)|(0<<COM00))	,
	CTC_Toggle		= ((0<<COM01)|(1<<COM00))	,
	CTC_Clear		= ((1<<COM01)|(0<<COM00))	,
	CTC_Set			= ((1<<COM01)|(1<<COM00))
}CTC_ModeT0;

//8 bit timers T0 :
//clock source , prescalers
typedef enum{
	T0_OFF				= 0	,
	T0_PRESCALER_1		= 1	,
	T0_PRESCALER_8		= 2 ,
	T0_PRESCALER_64		= 3	,
	T0_PRESCALER_256	= 4	,
	T0_PRESCALER_1024	= 5	,
	T0_External_clock	= 6	,
	T0_External_clock2 = 7
}ClkSrcT0;



//----------------------------------------------------------------------------------------------

//////8 bit timers T2 :
////
//////timer2 wave form generation modes
////typedef enum{
	////NORMAL_T2  = ((0<<WGM21)|(0<<WGM20))	,
	////PWM_T2		= ((0<<WGM21)|(1<<WGM20))	,
	////CTC_T2		= ((1<<WGM21)|(0<<WGM20))	,
	////F_PWM_T2	= ((1<<WGM21)|(1<<WGM20))
////}WGModeT2;
////
////
//////clock source , prescalers
////typedef enum{
	////T2_OFF				= 0	,
	////T2_PRESCALER_1		= 1	,
	////T2_PRESCALER_8		= 2 ,
	////T2_PRESCALER_32		= 3	,
	////T2_PRESCALER_64		= 4	,
	////T2_PRESCALER_128	= 5	,
	////T2_PRESCALER_256	= 6	,
	////T2_PRESCALER_1024	= 7	
////}ClkSrcT2;
//////timer0 prescaler mask
////#define PRESCALER_MASK_T2	((1<<CS22)|(1<<CS21)|(1<<CS20))
////
////
//////timer0 wave form generation mask
////#define WGM_MASK_T2 ((1<<WGM20)|(1<<WGM21))
////

#endif /* TIMERS_BASIC_H_ */