/*
 * Led_config.c
 *
 *  Created on: Jul 29, 2024
 *      Author: user
 */
#include "ErrorState.h"
#include "STD_Types.h"

#include "Led_priv.h"
#include "Led_config.h"


#include "DIO_int.h"

Led_t Led_AstrLedStatues[Led_num]={
		{DIO_u8PORTA,DIO_u8PIN0,Led_sink,Led_on},
		{DIO_u8PORTB,DIO_u8PIN1,Led_sink,Led_off},
		{DIO_u8PORTC,DIO_u8PIN2,Led_source,Led_on},
};
