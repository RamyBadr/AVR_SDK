/*
 * keypadmain.c
 *
 * Created: 9/8/2018 7:10:27 AM
 * Author : Ramy Badr
 */ 

#ifdef KEYPAD_TEST
#include "../HAL/LCD/LCD_config.h"
#include "../HAL/KEY_PAD/keyPad_config.h"

int main(void) {
	char key;
	InitLCDs();
	InitKeypads();
	
	while (1) {
		key = Keypad_getkey(&keyPad1);
		if (key != 'A') {
			LCD_Write_Character(&LCD1,key);
			key = Keypad_getkey(&keyPad1);
		}
    }
	return 0;
}
#endif