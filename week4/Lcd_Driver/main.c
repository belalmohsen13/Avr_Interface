/*
 * main.c
 *
 *  Created on: Aug 6, 2024
 *      Author: user
 */
#include "STD_Types.h"
#include "ErrorState.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "Lcd_int.h"

int main(void) {


	LCD_enuInit();

		LCD_enuDisplayChar('8');
	while(1){};
	return 0;
}
