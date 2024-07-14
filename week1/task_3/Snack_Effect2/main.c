/*
 * main.c
 *
 *  Created on: Jul 14, 2024
 *      Author: Belal Mohsen
 */

#include "STD_Types.h"
#include <util/delay.h>
#include <avr/io.h>

int main(void) {
	DDRA = 255;
	PORTA = 0;

	while (1) {
		for (int i = 0; i <= 7; i++) {
			PORTA |= (1 << i);
			_delay_ms(500);
		}
		for (int i = 0; i <= 7; i++) {
			PORTA &= ~(1 << i);
			_delay_ms(500);
		}
	}
	return 0;
}
