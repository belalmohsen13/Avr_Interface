/*
 * main.c
 *
 *  Created on: Jul 17, 2024
 *      Author: user
 */

#include "STD_Types.h"
#include <util/delay.h>
#include <avr/io.h>

int main(void) {
	DDRA |= (1 << 0); //LED 1 is output ,low at start (default)
	DDRA |= (1 << 1); //LED 2 is output ,low at start (default)

	DDRB &= ~(1 << 0); //sw is input
	PORTB |= (1 << 0); // sw is pulled up

	DDRB &= ~(1 << 1); //sw is input
	PORTB |= (1 << 1); // sw is pulled up

	DDRB &= ~(1 << 2); //sw is input
	PORTB |= (1 << 2); // sw is pulled up

	while (1) {
		if ((PINB & 1) == 0) {
			PORTA = 0;
			PORTA |= (1 << 0);  //sw1 is pushed so led 1 will be on
		} else if (((PINB >> 1) & 1) == 0) {
			PORTA = 0;
			PORTA |= (1 << 1);  //sw2 is pushed so led 2 will be on
		} else if (((PINB >> 2) & 1) == 0) {
			PORTA = 0;
			PORTA |= (1 << 0);  //sw3 is pushed so led 1 will be on
			PORTA |= (1 << 1);  //sw3 is pushed so led 2 will be on
		} else {
			PORTA &= ~(1 << 0);  //sw3 is pushed so led 1 will be off
			PORTA &= ~(1 << 1);  //sw3 is pushed so led 2 will be off

		}

	}
}
