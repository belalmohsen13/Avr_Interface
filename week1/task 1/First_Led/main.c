/*
 * main.c
 *
 *  Created on: Jul 12, 2024
 *      Author: user
 */
#include "STD_Types.h"
#include <util/delay.h>
#include <avr/io.h>

int main(void) {

	while (1) {
		DDRA |= (1 << 4); //pin 4 is output
		PORTA |= (1 << 4); //pin 4 is high
		_delay_ms(1000);

		DDRA |= (1 << 4); //pin 4 is output
		PORTA &= ~(1 << 4); //pin 4 is low
		_delay_ms(1000);
	}
	return 0;
}
