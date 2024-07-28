/*
 * SW_config.h
 *
 *  Created on: Jul 27, 2024
 *      Author: user
 */

#ifndef SW_CONFIG_H_
#define SW_CONFIG_H_
#include "STD_Types.h"
#define Num_Switches 3

typedef struct {
	u8 SW_PortID;
	u8 SW_PinID;
	u8 SW_StatusID;

} SW_t;

#endif /* SW_CONFIG_H_ */
