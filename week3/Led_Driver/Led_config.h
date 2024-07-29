/*
 * Led_config.h
 *
 *  Created on: Jul 29, 2024
 *      Author: user
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define Led_num 3

typedef struct {
	u8 Led_PortID;
	u8 Led_pinID;
	u8 Led_Connection;
	u8 Led_Statue;

} Led_t;

#endif /* LED_CONFIG_H_ */
