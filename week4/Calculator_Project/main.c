#include "STD_Types.h"
#include "ErrorState.h"
#include "util/delay.h"
#include "math.h"

#include "DIO_int.h"
#include "Lcd_int.h"
#include "Keypad_init.h"
#include "Calc.h"

#define ASCII_0             '0'
#define ASCII_9             '9'
#define ASCII_PLUS          '+'
#define ASCII_MINUS         '-'
#define ASCII_MULTIPLY      '*'
#define ASCII_DIVIDE        '/'
#define ASCII_EQUALS        '='
#define ASCII_C             'C'
#define Not_Pressed         0xff

int main(void) {
    Calc_Start();
    s32 Num1 = 0, Num2 = 0, op = 0, res = 0;
    s32 Num_Check = 0;
    u8 	Neg_Flag1=0;
    u8 	Neg_Flag2=0;
    u8  Op_Flag=0;
    u8  Num1_End=0;


    while (1) {
        s32 Local_u8key = KPD_enuGetStatues();

        if (Local_u8key != Not_Pressed) { // Check if a key is pressed

            if (Local_u8key == ASCII_C) { // Clear
                LCD_enuClear();
                Calc_VoidClearCalc(&Num1, &Num2, &op, &res, &Num_Check);


            }
            else if((Local_u8key==ASCII_MINUS)&&(Op_Flag==0)&&(Num1_End==0)){
            	LCD_enuDisplayChar(ASCII_MINUS);
				Neg_Flag1 = 1;

			} else if ((Local_u8key >= ASCII_0 && Local_u8key <= ASCII_9)
					&& Num_Check == 0) { // Enter Num1
				Num1 = (Num1 * 10) + (Local_u8key - ASCII_0);
				LCD_enuDisplayChar(Local_u8key);
				//Num1_End = 1;

			} else if ((Local_u8key == ASCII_MINUS) && (Op_Flag == 1)) {
				LCD_enuDisplayChar(ASCII_MINUS);
				Neg_Flag2 = 1;

               }else if ((Local_u8key >= ASCII_0 && Local_u8key <= ASCII_9) && Num_Check == 1) { // Enter Num2
                Num2 = (Num2 * 10) + (Local_u8key - ASCII_0);
                LCD_enuDisplayChar(Local_u8key);

            } else if (Local_u8key == ASCII_PLUS || Local_u8key == ASCII_MINUS || Local_u8key == ASCII_MULTIPLY || Local_u8key == ASCII_DIVIDE) { // Operator
                Num_Check = 1;
                op = Local_u8key;
                LCD_enuDisplayChar(Local_u8key);

			} else if (Local_u8key == ASCII_EQUALS) { // Perform operation
				LCD_enuClear();
				switch (op) {
				case ASCII_PLUS:
					if ((Neg_Flag1 == 0) && (Neg_Flag2 == 0)) {
						res = (Num1) + (Num2);
					} else if (Neg_Flag1 == 1 && Neg_Flag2 == 0) {
						res = (-Num1) + (Num2);
					} else if (Neg_Flag1 == 0 && Neg_Flag2 == 1) {
						res = (Num1) - (Num2);
					} else if (Neg_Flag1 == 1 && Neg_Flag2 == 1) {
						res = -(Num1) - (Num2);
					}
					break;
				case ASCII_MINUS:
					if ((Neg_Flag1 == 0) && (Neg_Flag2 == 0)) {
						res = (Num1) + (-Num2);
					} else if (Neg_Flag1 == 1 && Neg_Flag2 == 0) {
						res = -(Num1) + -(Num2);
					} else if (Neg_Flag1 == 0 && Neg_Flag2 == 1) {
						res = (Num1) + (Num2);
					} else if (Neg_Flag1 == 1 && Neg_Flag2 == 1) {
						res = -(Num1) + (Num2);
					}
					break;

				case ASCII_MULTIPLY:
					res = Num1 * Num2;
					if ((Neg_Flag1 ^ Neg_Flag2) == 1) {
						res = -res;
					}
					break;

					break;
				case ASCII_DIVIDE:
					if (Num2 != 0) {
						res = Num1 / Num2;
						if ((Neg_Flag1 ^ Neg_Flag2) == 1) {
							res = -res;
						}
					} else {
						// Handle division by zero error
						Calc_Error();
						Calc_VoidClearCalc(&Num1, &Num2, &op, &res, &Num_Check);
						continue;  // Skip the display of the result
					}
					break;
				default:
					res = Num1;
					break;
				}

				// Display the result
				s32 temp = res;
				if (temp < 0) {
					LCD_enuDisplayChar(ASCII_MINUS);  // Display the minus sign
					temp = -temp;
				}

                if (temp==0) {
                    LCD_enuDisplayChar('0');
                } else {
                    // For Multi-digit results
                    s32 digits[10];
                    u8 index = 0;


                    while (temp > 0) {
                        digits[index] = temp % 10;
                        temp /= 10;
                        index++;
                    }

                    for (s32 i = index - 1; i >= 0; i--) {
                        LCD_enuDisplayChar(digits[i] + ASCII_0);
                    }
                }

                // Reset for new calculation
                Num1 = res;
                Num2 = 0;
                op = 0;
                res = 0;
                Num_Check = 0;
            }
        }
    }
    return 0;
}
