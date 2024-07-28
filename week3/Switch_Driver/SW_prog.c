/*
 * SW_prog.c
 *
 *  Created on: Jul 27, 2024
 *      Author: user
 */
#include "STD_Types.h"
#include "ErrorState.h"

#include "SW.priv.h"
#include "SW_config.h"

#include "DIO_int.h"

ES_T SW_enuInt(SW_t *Copy_AstrSwitch) {
	ES_T Local_enuErrorState = ES_NOK;
	if (Copy_AstrSwitch != NULL) {
		u8 Local_u8iteration = 0;
		for (Local_u8iteration = 0; Local_u8iteration < Num_Switches;
				Local_u8iteration++) {
			Local_enuErrorState = DIO_enuSetPinDirection(
					Copy_AstrSwitch[Local_u8iteration].SW_PortID,
					Copy_AstrSwitch[Local_u8iteration].SW_PinID, DIO_u8INPUT);
			Local_enuErrorState = DIO_enuSetPinValue(
					Copy_AstrSwitch[Local_u8iteration].SW_PortID,
					Copy_AstrSwitch[Local_u8iteration].SW_PinID,
					Copy_AstrSwitch[Local_u8iteration].SW_StatusID);
		}

	} else {
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
ES_T SW_enuGetstatus(u8 * Copy_pu8SWStatus, SW_t *Copy_AstrSwitch) {
	ES_T Local_enuErrorState = ES_NOK;
	if (Copy_AstrSwitch != NULL && Copy_pu8SWStatus != NULL) {
		Local_enuErrorState = DIO_enuGetPinValue(Copy_AstrSwitch->SW_PortID,
				Copy_AstrSwitch->SW_PinID, Copy_pu8SWStatus);

	} else {
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

