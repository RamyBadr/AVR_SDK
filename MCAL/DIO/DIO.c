/*
 * DIO.c
 *
 * Created: 09/09/2018 10:21:18 PM
 *  Author: Ramy Badr
 */ 

#include "DIO.h"

//////////////////////////////////////////////////////////////////////////////////
//                   Port Direction
//////////////////////////////////////////////////////////////////////////////////
U8 DIO_PortDir(U8 portBase, U8 dir){
	U8 changed_pins = 0 ;
	if(IS_DIR(dir)&&IS_PORT(portBase)){
		DDR(portBase) = (dir==INPUT) ? 0x00	: 0xff ;
		changed_pins = 0x08;	
	}
	return changed_pins;	
}

U8 DIO_PinDir(U8 portBase, U8 pin, U8 dir){
	U8 changed_pins = 0;
	if (IS_DIR(dir)&&IS_PORT(portBase)&&IS_PIN(pin)){
		if (dir==INPUT){
			CLR_BIT(DDR(portBase),pin);
			changed_pins = 1;
		}else{
			SET_BIT(DDR(portBase),pin);
			changed_pins = 0x01;
		}
	}
	return changed_pins;
}

U8 DIO_PortRangeDir(U8 portBase, U8 startPin, U8 endPin, U8 dir){
	U8 changed_pins = 0 , i ;
	if(IS_PIN(startPin)&&IS_PIN(endPin)&&
		IS_PORT(portBase)&&IS_DIR(dir)){
		if (startPin > endPin){
			startPin += endPin;
			endPin = startPin - endPin ;
			startPin -= endPin ;
		}
		if(dir==INPUT){
			for (i=startPin;i<=endPin;i++){
				CLR_BIT(DDR(portBase),i);
				changed_pins++	;
			}
		}else{
			for (i=startPin;i<=endPin;i++){
				SET_BIT(DDR(portBase),i);
				changed_pins ++;
			}
		}
	}
	return changed_pins;
}

U8 DIO_PortMaskDir(U8 portBase, U8 mask, U8 pinsDir){
	U8 changedPins = 0, pin;
	if(IS_PORT(portBase)&&mask>0){
		//using logic:
		//DDR(portBase) = ((mask&pinsDir)|(~(mask)&DDR(portBase)));
		//return 0x8 ;
		
		//using loop:
		for( pin= 0 ; pin< 8 ; pin++ ) {
			if(READ_BIT(mask,pin)){
				if(READ_BIT(pinsDir,pin)) {
					SET_BIT(DDR(portBase),pin) ;
					changedPins++ ;
				}
				else{
					CLR_BIT(DDR(portBase),pin) ;
					changedPins++ ;
				}
			}
			
		}
	}
	return changedPins;
	
}



//////////////////////////////////////////////////////////////////////////////////
//                    Writing to Port
//////////////////////////////////////////////////////////////////////////////////

U8 DIO_PortWrite(U8 portBase, U8 val ){
	
	U8 changed_pins = 0 ;
	if(IS_PORT(portBase)&&val<=0xff){
		PORT(portBase) = val ;
		changed_pins = 0x08;
	}
	return changed_pins;
	
}

U8 DIO_PinWrite(U8 portBase, U8 pin, U8 val){
	U8 changed_pins = 0;
	if(IS_PORT(portBase)&&IS_PIN(pin)&&(val==0||val==1)){
		if(val==1){
			SET_BIT(PORT(portBase),pin);
			changed_pins++;
		}else{
			CLR_BIT(PORT(portBase),pin);
			changed_pins++;
		}
	}
	return changed_pins;
}

U8 DIO_PortRangeWrite(U8 portBase, U8 startPin, U8 endPin, U8 val){
	U8 changed_pins = 0 , i , shift_val = 0x01;
	if(IS_PIN(startPin)&&IS_PIN(endPin)&&
	IS_PORT(portBase)){
		if (startPin > endPin){
			startPin += endPin;
			endPin = startPin - endPin ;
			startPin -= endPin ;
		}
		
		for (i=startPin;i<=endPin;i++,shift_val<<=1){
			if(val&shift_val){
				SET_BIT(PORT(portBase),i);
			}else{
				CLR_BIT(PORT(portBase),i);
			}
			changed_pins++	;
		}
		
	}
	return changed_pins;
}

U8 DIO_PortMaskWrite(U8 portBase, U8 mask, U8 val){
	U8 changedPins = 0, pin;
	if(IS_PORT(portBase)&&mask>=0){
		//using logic:
		//
		//
		
		//using loop:
		for( pin= 0 ; pin< 8 ; pin++ ) {
			if(READ_BIT(mask,pin)){
				if(READ_BIT(val,pin)) {
					SET_BIT(PORT(portBase),pin) ;
					changedPins++ ;
				}
				else {
					CLR_BIT(PORT(portBase),pin) ;
					changedPins++ ;
				}
			}			
		}
	}
	return changedPins;
}

//////////////////////////////////////////////////////////////////////////////////
//                   Reading Port value
//////////////////////////////////////////////////////////////////////////////////

U8 DIO_PortRead(U8 portBase, U8 *portVal ){
	U8 changed_pins = 0 ;
	if(IS_PORT(portBase)){
		*portVal = PIN(portBase);
		changed_pins = 0x08;
	}
	return changed_pins;
	
}

U8 DIO_PinRead(U8 portBase, U8 pin, U8 *pinVal){
	U8 changed_pin = 0 ;
	if(IS_PORT(portBase)&&IS_PIN(pin)){
		*pinVal = READ_BIT(PIN(portBase),pin);
		changed_pin =1;
	}
	return pinVal ;
	
}

U8 DIO_PortRangeRead(U8 portBase, U8 startPin, U8 endPin, U8 *rangeReadVal){
	int changed_pins =0 , i ;
	if(IS_PORT(portBase)&&IS_PIN(startPin)&&IS_PIN(endPin)){
		if (startPin > endPin){
			startPin += endPin;
			endPin = startPin - endPin ;
			startPin -= endPin ;
		}
		*rangeReadVal = 0x00;
		for(i=startPin;i<=endPin;i++){
			*rangeReadVal|= PIN(portBase)&(1<<i) ;
			changed_pins++;
		}
		(*rangeReadVal)>>=startPin;
	}
	return changed_pins ;
}

U8 DIO_PortMaskRead(U8 portBase, U8 mask, U8 *binaryIndividuals_readVal){
	U8 changedPins= 0, pin ;
	if( IS_PORT(portBase) && mask > 0x00 ) {
		*binaryIndividuals_readVal= 0x00;
		for( pin= 0 ; pin< 8 ; pin++ ) {
			if( READ_BIT(mask,pin) ) {
				*binaryIndividuals_readVal|= PIN(portBase)&(1<<pin) ;
				changedPins++ ;
			}
		}
	}
	return changedPins;
}

//////////////////////////////////////////////////////////////////////////////////
//                    Toggle Port Value
//////////////////////////////////////////////////////////////////////////////////

U8 DIO_PortToggle(U8 portBase){
	
	U8 changed_pins = 0 ;
	if(IS_PORT(portBase)){
		PORT(portBase) ^= 0xff ;
		changed_pins = 0x08;
	}
	return changed_pins;
	
}

U8 DIO_PinToggle(U8 portBase, U8 pin){
	U8 changed_pins = 0;
	if(changed_pins = IS_PORT(portBase)&&IS_PIN(pin)){
		TOGGLE_BIT(PORT(portBase),pin);
		
	}
	return changed_pins;
}

U8 DIO_PortRangeToggle(U8 portBase, U8 startPin, U8 endPin){
	U8 changed_pins = 0 , i ;
	if(IS_PIN(startPin)&&IS_PIN(endPin)&&
	IS_PORT(portBase)){
		if (startPin > endPin){
			startPin += endPin;
			endPin = startPin - endPin ;
			startPin -= endPin ;
		}
		
		for (i=startPin;i<=endPin;i++){
			TOGGLE_BIT(PORT(portBase),i);
			changed_pins++	;
		}
		
	}
	return changed_pins;
}

U8 DIO_PortMaskToggle(U8 portBase, U8 mask){
	U8 changedPins= 0, pin ;
	if(IS_PORT(portBase)&& mask> 0x00 ) {
		for( pin= 0 ; pin< 8 ; pin++ ) {
			if( READ_BIT(mask,pin) ) {
				TOGGLE_BIT(PORT(portBase),pin) ;
				changedPins++ ;
			}
		}
	}
	return changedPins;
}



