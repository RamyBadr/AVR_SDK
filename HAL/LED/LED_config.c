/*
 * LED_config.c
 *
 * Created: 10/09/2018 11:39:29 PM
 *  Author: Ramy Badr
 */ 

#include "LED_config.h"

const LED_Type LEDS_Arr[LED_COUNT] ={
	{	D	,	7	,	ACTIVE_HIGH	},
	{	D	,	6	,	ACTIVE_HIGH	},
	{	D	,	5	,	ACTIVE_HIGH	}
};


void Initialize_LEDS(void){
	int i;
	for (i=0;i<LED_COUNT;i++){
		LED_init((LEDS_Arr+i),LEDS_Arr[i].portBase,LEDS_Arr[i].pin,LEDS_Arr[i].active_state);
	}
}
