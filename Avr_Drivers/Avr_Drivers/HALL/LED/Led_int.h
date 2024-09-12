/*
 * Led_int.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Belal Mohsen Mosbah
 */

#ifndef LED_INT_H_
#define LED_INT_H_

//#include "ErrorState.h"
//#include "STD_Types.h"

ES_T Led_enuInt(Led_t * copy_PAstrLedConfig);
ES_T Led_enuLedTurnOn(Led_t * copy_PAstrLedID);
ES_T Led_enuLedTurnOff(Led_t * copy_PAstrLedID);
#endif /* LED_INT_H_ */
