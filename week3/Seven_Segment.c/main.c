/*
 * main.c
 *
 *  Created on: Jul 31, 2024
 *      Author: user
 */
#include "STD_Types.h"
#include "ErrorState.h"
#include"util/delay.h"

#include "Seven_Segment_config.h"

#include "DIO_int.h"
#include "Seven_Segment_int.h"
extern SEG_t Seven_Segment_enuAstrSegConfig[Seg_Num];

int main (void){
	u8 i=0;
	DIO_enuInit();
	Seven_SegmentenuInit(Seven_Segment_enuAstrSegConfig);
	while(1)
	{
		for(i=0;i<=9;i++)
		{
		 Seven_Segment_enuDisplayNumber(i,0);

		}

	}


}
