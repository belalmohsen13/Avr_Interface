/*
 * SW_config.c
 *
 *  Created on: Jul 27, 2024
 *      Author: Belal Mohsen Mosbah
 */
#include "..\..\lib\STD_Types.h"
#include "..\..\lib\ErrorState.h"

#include "SW.priv.h"
#include "SW_config.h"

#include "../../MCAL/DIO/DIO_int.h"

SW_t SW_AstrSwitchStates[Num_Switches]={
{DIO_u8PORTA,DIO_u8PIN0,DIO_u8FLOAT},
{DIO_u8PORTB,DIO_u8PIN1,DIO_u8PULLUP},
{DIO_u8PORTC,DIO_u8PIN2,DIO_u8PULLUP}
};
