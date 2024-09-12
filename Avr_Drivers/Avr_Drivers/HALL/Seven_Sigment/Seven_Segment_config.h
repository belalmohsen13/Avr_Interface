/*
 * Seven_Segment_config.h
 *
 *  Created on: Jul 31, 2024
 *      Author: Belal Mohsen Mosbah
 */

#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

#include "..\..\lib\STD_Types.h"

#define Seg_Num 2


typedef struct {
	u8 Seg_u8APort;
	u8 Seg_u8APin;

	u8 Seg_u8BPort;
	u8 Seg_u8BPin;

	u8 Seg_u8CPort;
	u8 Seg_u8CPin;

	u8 Seg_u8DPort;
	u8 Seg_u8DPin;

	u8 Seg_u8EPort;
	u8 Seg_u8EPin;

	u8 Seg_u8FPort;
	u8 Seg_u8FPin;

	u8 Seg_u8GPort;
	u8 Seg_u8GPin;

	u8 Seg_u8CMNPort;
	u8 Seg_u8CMNPin;

	u8 Seg_u8DotPort;
	u8 Seg_u8DotPin;

	u8 Seg_u8Type;

}SEG_t;

#endif /* SEVEN_SEGMENT_CONFIG_H_ */
