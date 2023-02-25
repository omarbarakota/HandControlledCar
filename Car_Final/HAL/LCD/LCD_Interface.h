/*
 * LCD_Interface.h
 *
 *  Created on: feb2 , 2023
 *      Author:Barakat
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "Types.h"

#define FRIST_LINE  1
#define SECOND_LINE 2
#define CLEAR_DISPLAY    0b00000001


void LCD_voidInit(void);
void LCD_voidSendCommand(u8 Copy_u8Instruction);
void LCD_voidPortControl(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidSetPosition(u8 Copy_u8Y_Position,u8 Copy_u8X_Position);
void LCD_voidSendString(u8* PtrToString);
void LCD_voidSendNumber(u32 Copy_u32Number);

#endif /* LCD_INTERFACE_H_ */
