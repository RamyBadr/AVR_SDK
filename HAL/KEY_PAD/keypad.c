/*
 * keypad.c
 *
 * Created: 10/11/2016 11:42:21 AM
 *  Author: Master
 */ 
 #include "keypad.h"
 
int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//column d

void Keypad_init_config(KeyPAD_Type * this_ptr,U8 keyPadConfig[ky_Pins_Num][2],U8 charset[Ky_Row_num][ky_Col_Num]){
	U8 i , j;
	for(i=0;i<ky_Pins_Num;i++){
		if(IS_PORT(keyPadConfig[i][0])&&IS_PIN(keyPadConfig[i][1])){
			this_ptr->pins[i].port_base = keyPadConfig[i][0];
			this_ptr->pins[i].pin_no = keyPadConfig[i][1];	
		}
	}
	for(i=0;i<Ky_Row_num;i++){
		for (j=0;j<ky_Col_Num;j++){
			this_ptr->charset[i][j] = charset[i][j];
		}
	}
	
}
void Keypad_init(KeyPAD_Type * this_ptr)
{
	U8 i ;
	
	//set upper part of keypad port as input
	//this will be required for scanning the rows
	DIO_PinDir(this_ptr->pins[R0].port_base,this_ptr->pins[R0].pin_no,INPUT);
	DIO_PinDir(this_ptr->pins[R1].port_base,this_ptr->pins[R1].pin_no,INPUT);
	DIO_PinDir(this_ptr->pins[R2].port_base,this_ptr->pins[R2].pin_no,INPUT);
	DIO_PinDir(this_ptr->pins[R3].port_base,this_ptr->pins[R3].pin_no,INPUT);
	
	//set lower part of keypad port as output.
	//This is the part of the keypad port where the columns are connected.
	DIO_PinDir(this_ptr->pins[C0].port_base,this_ptr->pins[C0].pin_no,OUTPUT);
	DIO_PinDir(this_ptr->pins[C1].port_base,this_ptr->pins[C1].pin_no,OUTPUT);
	DIO_PinDir(this_ptr->pins[C2].port_base,this_ptr->pins[C2].pin_no,OUTPUT);
	DIO_PinDir(this_ptr->pins[C3].port_base,this_ptr->pins[C3].pin_no,OUTPUT);
	
	for (i=0;i<ky_Pins_Num;i++){
		DIO_PinWrite(this_ptr->pins[i].port_base,this_ptr->pins[i].pin_no,1);
	}
}

char Keypad_getkey(KeyPAD_Type * this_ptr)
{
	int i, j ;
	U8  pinVal ;
	for(i = 0; i < 4; i++)
	{
		DIO_PinWrite(this_ptr->pins[Key_padCol[0]].port_base,this_ptr->pins[Key_padCol[0]].pin_no,1);
		DIO_PinWrite(this_ptr->pins[Key_padCol[1]].port_base,this_ptr->pins[Key_padCol[1]].pin_no,1);
		DIO_PinWrite(this_ptr->pins[Key_padCol[2]].port_base,this_ptr->pins[Key_padCol[2]].pin_no,1);
		DIO_PinWrite(this_ptr->pins[Key_padCol[3]].port_base,this_ptr->pins[Key_padCol[3]].pin_no,1);
		
		DIO_PinWrite(this_ptr->pins[Key_padCol[i]].port_base,this_ptr->pins[Key_padCol[i]].pin_no,0);
		

		for(j = 0; j < 4; j++)
		{
			DIO_PinRead(this_ptr->pins[Key_padRow[j]].port_base,this_ptr->pins[Key_padRow[j]].pin_no,&pinVal);
			if(pinVal == 0){
				//wait for key to be released  (Single press)
				do{
					DIO_PinRead(this_ptr->pins[Key_padRow[j]].port_base,this_ptr->pins[Key_padRow[j]].pin_no,&pinVal);
				}while(pinVal==0);
				return this_ptr->charset[j][i];
			}
		}
	}
	return 'A';//Return 'A' if no key is pressed.
}