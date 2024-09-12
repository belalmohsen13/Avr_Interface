/*
 * Led_prog.c
 *
 *  Created on: Jul 29, 2024
 *      Author: Belal Mohsen Mosbah
 */

#include "..\..\lib\STD_Types.h"
#include "..\..\lib\ErrorState.h"

#include "Led_priv.h"
#include "Led_config.h"

#include "../../MCAL/DIO/DIO_int.h"
ES_T Led_enuInt(Led_t * copy_PAstrLedConfig) {
	ES_T Local_ErrorStatue = ES_NOK;
	if (copy_PAstrLedConfig != NULL) {
		u8 Local_Iteration;
		for (Local_Iteration = 0; Local_Iteration < Led_num;Local_Iteration++) {
			Local_ErrorStatue = DIO_enuSetPinDirection(copy_PAstrLedConfig[Local_Iteration].Led_PortID,copy_PAstrLedConfig[Local_Iteration].Led_PortID,DIO_u8OUTPUT);
			if (copy_PAstrLedConfig[Local_Iteration].Led_Connection == Led_sink) {
				if (copy_PAstrLedConfig[Local_Iteration].Led_Statue == Led_on) {
					Local_ErrorStatue=DIO_enuSetPinValue(copy_PAstrLedConfig[Local_Iteration].Led_PortID,copy_PAstrLedConfig[Local_Iteration].Led_PortID,DIO_u8LOW);
				} else if (copy_PAstrLedConfig[Local_Iteration].Led_Statue== Led_off) {
					Local_ErrorStatue=DIO_enuSetPinValue(copy_PAstrLedConfig[Local_Iteration].Led_PortID,copy_PAstrLedConfig[Local_Iteration].Led_PortID,DIO_u8HIGH);
				}
			} else if (copy_PAstrLedConfig->Led_Connection == Led_source) {
				if (copy_PAstrLedConfig[Local_Iteration].Led_Statue == Led_on) {
					Local_ErrorStatue=DIO_enuSetPinValue(copy_PAstrLedConfig[Local_Iteration].Led_PortID,copy_PAstrLedConfig[Local_Iteration].Led_PortID,DIO_u8HIGH);
				} else if (copy_PAstrLedConfig[Local_Iteration].Led_Statue== Led_off) {
					Local_ErrorStatue=DIO_enuSetPinValue(copy_PAstrLedConfig[Local_Iteration].Led_PortID,copy_PAstrLedConfig[Local_Iteration].Led_PortID,DIO_u8LOW);
				}

			}
			else{
				Local_ErrorStatue=ES_OUT_OF_RANGE;
			}
		}
	} else {
		Local_ErrorStatue = ES_NULL_POINTER;
	}
	return Local_ErrorStatue;
}
ES_T Led_enuLedTurnOn(Led_t * copy_PAstrLedID) {
	ES_T Local_ErrorStatue = ES_NOK;
	if (copy_PAstrLedID != NULL) {
		if (copy_PAstrLedID->Led_Connection == Led_sink) {
			Local_ErrorStatue = DIO_enuSetPinValue(copy_PAstrLedID->Led_PortID,
					copy_PAstrLedID->Led_PortID, DIO_u8LOW);
		} else if (copy_PAstrLedID->Led_Connection == Led_source) {
			Local_ErrorStatue = DIO_enuSetPinValue(copy_PAstrLedID->Led_PortID,
					copy_PAstrLedID->Led_PortID, DIO_u8HIGH);
		} else {
			Local_ErrorStatue = ES_OUT_OF_RANGE;

		}
	} else {
		Local_ErrorStatue = ES_NULL_POINTER;
	}

	return Local_ErrorStatue;
}
ES_T Led_enuLedTurnOff(Led_t * copy_PAstrLedID) {
	ES_T Local_ErrorStatue = ES_NOK;
if (copy_PAstrLedID != NULL) {
	if (copy_PAstrLedID->Led_Connection == Led_sink) {
		Local_ErrorStatue = DIO_enuSetPinValue(copy_PAstrLedID->Led_PortID,
				copy_PAstrLedID->Led_PortID, DIO_u8HIGH);
	} else if (copy_PAstrLedID->Led_Connection == Led_source) {
		Local_ErrorStatue = DIO_enuSetPinValue(copy_PAstrLedID->Led_PortID,
				copy_PAstrLedID->Led_PortID, DIO_u8LOW);
	} else {
		Local_ErrorStatue = ES_OUT_OF_RANGE;

	}
} else {
	Local_ErrorStatue = ES_NULL_POINTER;
}

return Local_ErrorStatue;
}
