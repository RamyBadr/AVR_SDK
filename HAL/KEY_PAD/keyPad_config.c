/*
 * keyPad_init.c
 *
 * Created: 19/09/2018 03:09:44 PM
 *  Author: www
 */ 

#include "keyPad_config.h"

U8 keyPadConfig[ky_Pins_Num][2]={
	{ D , 0 },//R0
	{ D , 1 },//R1
	{ D , 2 },//R2
	{ D , 3 },//R3
	{ D , 4 },//C0
	{ D , 5 },//C1
	{ D , 6 },//C2
	{ D , 7 }//C3
};
KeyPAD_Type keyPad1;
U8 keyPad1Charset[Ky_Row_num][ky_Col_Num]={
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'?','0','=','+'},
};
void InitKeypads(){
	Keypad_init_config(&keyPad1,keyPadConfig,keyPad1Charset);
	Keypad_init(&keyPad1);
	//add other keypads here
}