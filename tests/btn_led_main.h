/*
 * bt_led_main.c
 *
 * Created: 18/09/2018 05:12:06 PM
 *  Author: Ramy Badr
 */ 


#ifdef TEST_BTN_LED

#include "../HAL/BTN/BTN_config.h"
#include "../HAL/LED/LED_config.h""


int main(){
	Initialize_LEDS();
	Initialize_BTNS();
	LED_on(&LEDS_Arr[0]);
	 U8 pinVal ;
	 while(1){
		 _delay_ms(500);
		 LED_flash(&LEDS_Arr[1],1000);
		//BTN_getState(&BTNS_Arr[0],&pinVal);
		//if(pinVal==1){
			//LED_flash(&LEDS_Arr[1],200,200);
		//}else{
			//LED_off(&LEDS_Arr[1]);
		//}	 
	 }
}
#endif