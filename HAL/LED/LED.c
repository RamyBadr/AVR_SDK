/*
 * LED.c
 *
 * Created: 10/09/2018 11:33:32 PM
 *  Author: Ramy Badr
 */ 

#include "LED.h"



//extern const ledConfigType ledConfig [LED_NUM];


void LED_init(LED_Type* this_ptr,U8 port_base,U8 pin,U8 active_state){
	if(IS_PORT(port_base)&&IS_PIN(pin)&&IS_STATE(active_state)){
		this_ptr->portBase = port_base;
		this_ptr->pin = pin ;
		this_ptr->active_state = active_state ;
		DIO_PinDir(this_ptr->portBase,this_ptr->pin,OUTPUT);
		
	}
	
}

U8 LED_Validate_Config(LED_Type * this_ptr){
	return ((IS_PORT(this_ptr->portBase))&&(IS_PIN(this_ptr->pin))&&(READ_BIT(DDR(this_ptr->portBase),this_ptr->pin)==OUTPUT));
}
void LED_on(LED_Type * this_ptr){
	if(LED_Validate_Config(this_ptr)){
		DIO_PinWrite(this_ptr->portBase,this_ptr->pin,this_ptr->active_state);
	}
}
void LED_off(LED_Type * this_ptr){
	
	if(LED_Validate_Config(this_ptr)){
		
		DIO_PinWrite(this_ptr->portBase,this_ptr->pin,REVERSE_STATE(this_ptr->active_state));
	}
}

void LED_toggle(LED_Type * this_ptr){
	
	if(LED_Validate_Config(this_ptr)){
		if(LED_Validate_Config(this_ptr)){
			DIO_PinToggle(this_ptr->portBase,this_ptr->pin);	
		}
		
	}
}

void LED_flash(LED_Type* this_ptr,U16 flash_interval){
	U8 i , j;
	for(i=0;i<2;i++){
		LED_toggle(this_ptr);
		//half interval on, half off , interval can be divided by 10
		for (j=0;j<flash_interval/20;j++){
			_delay_ms(10);
		}	
	}
}

U8 LED_IS_ON(LED_Type * this_ptr){
	U8 pinVal ;
	DIO_PinRead(this_ptr->portBase,this_ptr->pin,&pinVal);
	return (pinVal==this_ptr->active_state);
}



/*



void LED_allOFF(void)
{
	volatile int i;

	for (i=0; i<LED_NUM; i++)
	{
		LED_off(i);
	}
}
void LED_allON(void)
{
	volatile int i;

	for (i=0; i<LED_NUM; i++)
	{
		LED_on(i);
	}
}

void LED_toggle(uint8_t ledID)
{
	switch ( LED_state(ledID) )
	{
		case LED_ON:
		LED_off(ledID);
		break;
		case LED_OFF:
		LED_on(ledID);
		break;
	}
}


ledStateType LED_state(uint8_t ledID)
{
	if ( (DIO_read(ledConfig[ledID].portBase, 1<<ledConfig[ledID].pinNumber)) == ( (1 << ledConfig[ledID].pinNumber) & ledConfig[ledID].mode ) )
	return LED_ON;
	else
	return LED_OFF;

}
*/