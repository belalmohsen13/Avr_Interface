/*
 * Keypad_config.h
 *
 *  Created on: Aug 7, 2024
 *      Author: user
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define Not_Pressed 0xff;

/*			Port and pins			*/

#define KDP_Port DIO_u8PORTD

#define ROW_NUM 4
#define COLUMN_NUM 4

#define KPD_Column0_pin DIO_u8PIN0
#define KPD_Column1_pin DIO_u8PIN1
#define KPD_Column2_pin DIO_u8PIN2
#define KPD_Column3_pin DIO_u8PIN3

#define KPD_Row0_pin    DIO_u8PIN4
#define KPD_Row1_pin    DIO_u8PIN5
#define KPD_Row2_pin    DIO_u8PIN6
#define KPD_Row3_pin    DIO_u8PIN7

#define KPD_ARR_Values { \
    {55, 56, 57, 47}, \
    {52, 53, 54, 42}, \
    {49, 50, 51, 45}, \
    {67, 48, 61, 43}  \
}

#endif /* KEYPAD_CONFIG_H_ */
