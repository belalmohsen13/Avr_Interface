/*
 * Lcd_prog.c
 *
 *  Created on: Aug 6, 2024
 *      Author: user
 */
#include "STD_Types.h"
#include "ErrorState.h"

#include "DIO_int.h"

#include "Lcd_config.h"
#include "Lcd_priv.h"

#include "util/delay.h"

ES_T LCD_enuInit(void) {
	ES_T Local_enuErrorState = ES_NOK;


	DIO_enuSetPinDirection(RS_PORT, RS_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT, RW_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT, EN_PIN, DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT, D7_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT, D6_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT, D5_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT, D4_PIN, DIO_u8OUTPUT);
_delay_ms(35);
#if LCD_MODE==EIGHT_BIT

	DIO_enuSetPinDirection(D3_PORT, D3_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT, D2_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT, D1_PIN, DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT, D0_PIN, DIO_u8OUTPUT);
// function set
	LCD_InvidSendCommend(0x38);
#elif LCD_MODE==FOUR_BIT
	LCD_InvidSendCommend(0x28);
#endif
	_delay_ms(1);
	LCD_InvidSendCommend(0x0f);

	_delay_ms(1);
	LCD_InvidSendCommend(0x01);

	_delay_ms(2);
	LCD_InvidSendCommend(0x06);

	return Local_enuErrorState;
}
ES_T LCD_enuDisplayChar(u8 Copy_u8Data) {
	ES_T Local_enuErrorState = ES_NOK;
	//set rs as data

	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8HIGH);

	Lcd_vidLatch(Copy_u8Data);

	return Local_enuErrorState;
}
ES_T LCD_enuSendCommend(u8 Copy_u8Commend) {
	ES_T Local_enuErrorState = ES_NOK;
	//set rs as commend

	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);

	Lcd_vidLatch(Copy_u8Commend);

	return Local_enuErrorState;
}

static void Lcd_vidLatch(u8 Copy_u8Data) {

	//set rw as write& EN IS LOW

	DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

	//write data

	DIO_enuSetPinValue(D7_PORT, D7_PIN, ((Copy_u8Data >> 7) & 1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN, ((Copy_u8Data >> 6) & 1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN, ((Copy_u8Data >> 5) & 1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN, ((Copy_u8Data >> 4) & 1));
#if LCD_MODE==EIGHT_BIT
	DIO_enuSetPinValue(D3_PORT, D3_PIN, ((Copy_u8Data >> 3) & 1));
	DIO_enuSetPinValue(D2_PORT, D2_PIN, ((Copy_u8Data >> 2) & 1));
	DIO_enuSetPinValue(D1_PORT, D1_PIN, ((Copy_u8Data >> 1) & 1));
	DIO_enuSetPinValue(D0_PORT, D0_PIN, ((Copy_u8Data >> 0) & 1));
#elif LCD_MODE==FOUR_BIT
#endif
	//enable latch
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);
	_delay_ms(10);
}

static inline void LCD_InvidSendCommend(u8 Copy_u8Commend) {
//set rs as common

	DIO_enuSetPinValue(RS_PORT, RS_PIN, DIO_u8LOW);

//set rw as write& EN IS LOW

	DIO_enuSetPinValue(RW_PORT, RW_PIN, DIO_u8LOW);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

//write data

	DIO_enuSetPinValue(D7_PORT, D7_PIN, ((Copy_u8Commend >> 7) & 1));
	DIO_enuSetPinValue(D6_PORT, D6_PIN, ((Copy_u8Commend >> 6) & 1));
	DIO_enuSetPinValue(D5_PORT, D5_PIN, ((Copy_u8Commend >> 5) & 1));
	DIO_enuSetPinValue(D4_PORT, D4_PIN, ((Copy_u8Commend >> 4) & 1));
#if LCD_MODE==EIGHT_BIT
	DIO_enuSetPinValue(D3_PORT, D3_PIN, ((Copy_u8Commend >> 3) & 1));
	DIO_enuSetPinValue(D2_PORT, D2_PIN, ((Copy_u8Commend >> 2) & 1));
	DIO_enuSetPinValue(D1_PORT, D1_PIN, ((Copy_u8Commend >> 1) & 1));
	DIO_enuSetPinValue(D0_PORT, D0_PIN, ((Copy_u8Commend >> 0) & 1));
#elif LCD_MODE==FOUR_BIT
#endif
//enable latch
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT, EN_PIN, DIO_u8LOW);

}
