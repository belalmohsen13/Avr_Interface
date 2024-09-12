/*
 * Keypad_prog.c
 *
 *  Created on: Aug 7, 2024
 *      Author: user
 */
#include "STD_Types.h"
#include "ErrorState.h"

#include "DIO_int.h"
#include "Keypad_config.h"
#include "Keypad_priv.h"

u8 KPD_enuGetStatues(void) {
	u8 Local_PressedKey = Not_Pressed;
	u8 Local_ColumnIndex;
	u8 Local_Pinstatue;
	u8 Local_RowIndex;
	static u8 Local_KPDARR[ROW_NUM][COLUMN_NUM] = KPD_ARR_Values;
	static u8 KPD_ColumnARR[COLUMN_NUM] = { KPD_Column0_pin, KPD_Column1_pin,KPD_Column2_pin, KPD_Column3_pin };
	static u8 KPD_ROWARR[ROW_NUM] = { KPD_Row0_pin, KPD_Row1_pin, KPD_Row2_pin,KPD_Row3_pin };

	for (Local_ColumnIndex = 0; Local_ColumnIndex < COLUMN_NUM;
			Local_ColumnIndex++) {

		//Activate Current Column

		DIO_enuSetPinValue(KDP_Port, KPD_ColumnARR[Local_ColumnIndex],DIO_u8LOW);

		for (Local_RowIndex = 0; Local_RowIndex < ROW_NUM; Local_RowIndex++) {

			//Read from row which is low

			DIO_enuGetPinValue(KDP_Port, KPD_ROWARR[Local_RowIndex], &Local_Pinstatue);

			//check if switch is pressed

			if (DIO_u8LOW == Local_Pinstatue)
			{
				Local_PressedKey =Local_KPDARR[Local_RowIndex][Local_ColumnIndex];
				while (DIO_u8LOW == Local_Pinstatue)
				{
					DIO_enuGetPinValue(KDP_Port, KPD_ROWARR[Local_RowIndex], &Local_Pinstatue);
				}

				return Local_PressedKey;
			}
		}
		//deactivate the current column
		DIO_enuSetPinValue(KDP_Port, KPD_ColumnARR[Local_ColumnIndex],DIO_u8HIGH);
	}
	return Local_PressedKey;
}

