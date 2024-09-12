/*
 * Seven_Segment_config.c
 *
 *  Created on: Jul 31, 2024
 *      Author: Belal Mohsen Mosbah
 */

#include "..\..\lib\STD_Types.h"
#include "..\..\lib\ErrorState.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "Seven_Segment_config.h"
#include "Seven_Segment_priv.h"


SEG_t Seven_Segment_enuAstrSegConfig[Seg_Num] =
{
    {DIO_u8PORTA, DIO_u8PIN0, // Pin A
     DIO_u8PORTA, DIO_u8PIN1, // Pin B
     DIO_u8PORTA, DIO_u8PIN2, // Pin C
     DIO_u8PORTA, DIO_u8PIN3, // Pin D
     DIO_u8PORTA, DIO_u8PIN4, // Pin E
     DIO_u8PORTA, DIO_u8PIN5, // Pin F
     DIO_u8PORTA, DIO_u8PIN6, // Pin G
     Not_Connected, Not_Connected, // COMMON
     Common_Cathode
   }, // TYPE

    {
     DIO_u8PORTB, DIO_u8PIN0, // Pin A
     DIO_u8PORTB, DIO_u8PIN1, // Pin B
     DIO_u8PORTB, DIO_u8PIN2, // Pin C
     DIO_u8PORTB, DIO_u8PIN3, // Pin D
     DIO_u8PORTB, DIO_u8PIN4, // Pin E
     DIO_u8PORTB, DIO_u8PIN5, // Pin F
     DIO_u8PORTB, DIO_u8PIN6, // Pin G
     Not_Connected, Not_Connected, // COMMON
     Common_Cathode} // TYPE
};
