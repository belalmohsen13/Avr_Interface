/*
 * Calc.c

 *
 *  Created on: Aug 8, 2024
 *      Author: user
 */
#include "STD_Types.h"
#include "ErrorState.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "Lcd_int.h"
#include "Keypad_init.h"

void Calc_Start(void){

	DIO_enuInit();
	LCD_enuInit();
		LCD_enuDisplayChar('W');
		LCD_enuDisplayChar('e');
		LCD_enuDisplayChar('l');
		LCD_enuDisplayChar('c');
		LCD_enuDisplayChar('o');
		LCD_enuDisplayChar('m');
		LCD_enuDisplayChar('e');
		LCD_enuDisplayChar('!');
		_delay_ms(1000);
		LCD_enuClear();
}
void Calc_Error(void){

	DIO_enuInit();
	LCD_enuInit();
		LCD_enuDisplayChar('E');
		LCD_enuDisplayChar('r');
		LCD_enuDisplayChar('r');
		LCD_enuDisplayChar('o');
		LCD_enuDisplayChar('r');
		LCD_enuDisplayChar(' ');
		LCD_enuDisplayChar('d');
		LCD_enuDisplayChar('i');
		LCD_enuDisplayChar('v');
		LCD_enuDisplayChar('i');
		LCD_enuDisplayChar('s');
		LCD_enuDisplayChar('o');
		LCD_enuDisplayChar('n');
		LCD_enuDisplayChar('!');
		_delay_ms(1000);
		LCD_enuClear();
}
void Calc_VoidClearCalc(s32 *num1, s32 *num2, s32 *op, s32 *res, s32 *Num_Check ){
	*num1 = 0;*num2 = 0, *op = 0,* Num_Check = 0, *res = 0;
}
