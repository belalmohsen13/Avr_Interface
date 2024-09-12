/*
 * Seven_Segment_int.h
 *
 *  Created on: Jul 31, 2024
 *      Author: user
 */

#ifndef SEVEN_SEGMENT_INT_H_
#define SEVEN_SEGMENT_INT_H_

ES_T Seven_SegmentenuInit(SEG_t * Seven_Segment_pAstr_SegConfig);
ES_T Seven_Segment_enuDisplayNumber(u8 Copy_u8_SegNumber,u8 Copy_u8SegID);
ES_T Seven_Segment_enuEnableCommon(u8 Copy_u8SegID);
ES_T Seven_Segment_enuDisableCommon(u8 Copy_u8SegID);
ES_T Seven_Segment_enuEnableDot(u8 Copy_u8SegID);
ES_T Seven_Segment_enuDisableDot(u8 Copy_u8SegID);
ES_T Seven_Segment_enuClearoff(u8 Copy_u8SegID);

#endif /* SEVEN_SEGMENT_INT_H_ */
