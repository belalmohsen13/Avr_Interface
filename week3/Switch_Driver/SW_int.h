/*
 * SW_int.h
 *
 *  Created on: Jul 27, 2024
 *      Author: user
 */

#ifndef SW_INT_H_
#define SW_INT_H_

#include "STD_Types.h"
#include "ErrorState.h"

ES_T SW_enuInt(SW_t *Copy_AstrSwitch);
ES_T SW_enuGetstatus(u8 * Copy_pu8SWStatus,SW_t *Copy_AstrSwitch);

#endif /* SW_INT_H_ */
