/*
 * BTN_config.c
 *
 * Created: 11/09/2018 08:53:04 AM
 *  Author: Ramy Badr
 */ 

#include "BTN_config.h"


const BTN_Type BTNS_Arr[BTN_COUNT] ={
{	D	,	0	,	ACTIVE_HIGH	},
{	D	,	1	,	ACTIVE_HIGH	},
{	D	,	2	,	ACTIVE_HIGH	}
};

void Initialize_BTNS(void){
	int i;
	for (i=0;i<BTN_COUNT;i++){
		BTN_init((BTNS_Arr+i),BTNS_Arr[i].portBase,BTNS_Arr[i].pin,BTNS_Arr[i].active_state);
	}
}

