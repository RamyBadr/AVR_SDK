/*
 * seven_se_main.h
 *
 * Created: 18/09/2018 05:20:43 PM
 *  Author: Ramy Badr
 */ 
//#define TEST_SEVEN_SEG
#ifdef TEST_SEVEN_SEG
#include "../App/counter.h"

int main(void){
	
	
	Initialize_LEDS();
	Initialize_BTNS();
	InitSevenSegs();
	InitLCDs() ;
	U8 pinVal , i , ones, tens;
	while (1){
		SEVEN_SEG_Enable(&SEVEN_SEGs_Arr[0]);
		SEVEN_SEG_Disable(&SEVEN_SEGs_Arr[1]);
		counterUpOneDigit(&SEVEN_SEGs_Arr[0],0,9,1000);
		//counterUpTwoDigit(&SEVEN_SEGs_Arr[0],&SEVEN_SEGs_Arr[1],0,60,200);
		//counterDownOneDigit(&SEVEN_SEGs_Arr[0],9,0,1000);
		//SEVEN_SEG_Show_Num(&SEVEN_SEGs_Arr[0],0);
		//counterDownTwoDigit(&SEVEN_SEGs_Arr[0],&SEVEN_SEGs_Arr[1],20,0,20);
	}
}

#endif
