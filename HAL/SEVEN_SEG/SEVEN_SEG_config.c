/*
 * SEVEN_SEG_config.c
 *
 * Created: 11/09/2018 11:46:52 AM
 *  Author: Ramy Badr
 */ 
#include "SEVEN_SEG_config.h"

const PinType config_All_SgPins[SG_NUM][5]={
	{
		{C,4},
		{C,5},
		{C,6},
		{C,7},
		{C,3}
	},
	{
		{C,4},
		{C,5},
		{C,6},
		{C,7},
		{C,2}
	}
};


const SEVEN_SEG SEVEN_SEGs_Arr[SG_NUM];

void InitSevenSegs(){
	int i ;
	for (i=0;i<SG_NUM;i++){
		SEVEN_SEG_Init(&SEVEN_SEGs_Arr[i],config_All_SgPins[i],ACTIVE_HIGH);
	}
	
}

