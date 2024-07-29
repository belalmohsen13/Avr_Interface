/*
 * main.c
 *
 *  Created on: Jul 29, 2024
 *      Author: user
 */
#include "ErrorState.h"
#include "STD_Types.h"
#include "util/delay.h"

#include "DIO_int.h"
#include "Led_config.h"
#include "Led_int.h"

extern Led_t Led_AstrLedStatues[Led_num];

int main(void) {
	DIO_enuInit();
	Led_enuInt(Led_AstrLedStatues);
	while (1) {

		Led_enuLedTurnOn(&Led_AstrLedStatues[0]);
		_delay_ms(100);
		Led_enuLedTurnOff(&Led_AstrLedStatues[0]);
		_delay_ms(100);
		Led_enuLedTurnOn(&Led_AstrLedStatues[1]);
		_delay_ms(100);
		Led_enuLedTurnOff(&Led_AstrLedStatues[1]);
		_delay_ms(100);
	}
	return 0;
}
