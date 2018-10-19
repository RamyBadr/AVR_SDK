/*
 * SEVEN_SEG.c
 *
 * Created: 11/09/2018 11:46:33 AM
 *  Author: Ramy Badr
 */ 

#include "SEVEN_SEG.h"

U8 SEVEN_SEG_Init(SEVEN_SEG * this_ptr , PinType configPins[5] , U8 active_state ){
	U8 i, changed_pins = 0;
	for(i=0;i<5;i++){
		if (IS_PORT(configPins[i].port_base)&&IS_PIN(configPins[i].pin_no)){
			this_ptr->SG_pins[i].port_base = configPins[i].port_base;
			this_ptr->SG_pins[i].pin_no = configPins[i].pin_no ;
			DIO_PinDir(this_ptr->SG_pins[i].port_base , this_ptr->SG_pins[i].pin_no,OUTPUT);
			changed_pins++;
		}
	}
	return changed_pins;
}

void SEVEN_SEG_Enable(SEVEN_SEG * this_ptr){
	U8 pinVal ;
	if (this_ptr->active_state==COMMON_CATHODE){
		pinVal = 1;
	}else{
		pinVal = 0;
	}
	DIO_PinWrite(this_ptr->SG_pins[SG_E].port_base,this_ptr->SG_pins[SG_E].pin_no,pinVal);
}
void SEVEN_SEG_Disable(SEVEN_SEG * this_ptr){
	U8 pinVal;
	if (this_ptr->active_state==COMMON_CATHODE){
		pinVal = 0;
	}else{
		pinVal = 1;
	}
	DIO_PinWrite(this_ptr->SG_pins[SG_E].port_base,this_ptr->SG_pins[SG_E].pin_no,pinVal);
}
U8 SEVEN_SEG_Is_Enabled(SEVEN_SEG * this_ptr){
	U8 pinVal;
	DIO_PinRead(this_ptr->SG_pins[SG_E].port_base,this_ptr->SG_pins[SG_E].pin_no,&pinVal);
	return (pinVal == (this_ptr->active_state));
}
U8 SEVEN_SEG_Show_Num(SEVEN_SEG * this_ptr,U8 number){
	int bit,i;
	if (!(number>=0x00 && number<=9))
	{
		return 0;
	}else{
		if(!SEVEN_SEG_Is_Enabled(this_ptr)){
			SEVEN_SEG_Enable(this_ptr);
		}
		for(i=SG_A;i<=SG_D;i++){			
			DIO_PinWrite(this_ptr->SG_pins[i].port_base,this_ptr->SG_pins[i].pin_no,READ_BIT(number,i));
		}
		
	}
	return 1;
	
}