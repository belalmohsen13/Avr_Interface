/*
 * Lcd_int.h
 *
 *  Created on: Aug 6, 2024
 *      Author: user
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_T LCD_enuInit(void);
ES_T LCD_enuDisplayChar(u32 Copy_u8Data);
ES_T LCD_enuSendCommend(u8 Copy_u8Common);
void LCD_enuClear(void);
void LCD_voidSendString(const char* Copy_pcString);

#endif /* LCD_INT_H_ */
