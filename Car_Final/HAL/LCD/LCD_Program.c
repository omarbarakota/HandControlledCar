/*
 * LCD_Program.c
 *
 *  Created on: Sep 7, 2021
 *      Author: gerges
 */

#include "D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\HandControlled_Car\COMMON\Types.h"
#include "D:\Online Courses\AMIT AVR Diploma\Sessions\Microcontroller & Microprocessor (AVR - ARM) interfacing\HandControlled_Car\COMMON\BitMath.h"

#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"LCD_Private.h"
#include"LCD_Config.h"
#include<util/delay.h>

void LCD_voidSendCommand(u8 Copy_u8Instruction)
{
	/*Select Command Register*/
	DIO_u8SetPinValue(RS,CONTROL_PORT,PIN_LOW);
	/*set write mode*/
	DIO_u8SetPinValue(RW,CONTROL_PORT,PIN_LOW);
	/*Send 4 most bits*/
	DIO_u8Set4MSB_BitsValue(DATA_PORT,Copy_u8Instruction);
	/*Enable*/
	DIO_u8SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(E,CONTROL_PORT,PIN_LOW);
	/*Send 4 Least bits*/
	Copy_u8Instruction<<=4;
	DIO_u8Set4MSB_BitsValue(DATA_PORT,Copy_u8Instruction);
	/*Enable*/
	DIO_u8SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(E,CONTROL_PORT,PIN_LOW);
}

void LCD_voidInit(void)
{

	DIO_u8SetPinDirection(DATA_PIN1,DATA_PORT,PIN_OUTPUT);
	DIO_u8SetPinDirection(DATA_PIN2,DATA_PORT,PIN_OUTPUT);
	DIO_u8SetPinDirection(DATA_PIN3,DATA_PORT,PIN_OUTPUT);
	DIO_u8SetPinDirection(DATA_PIN4,DATA_PORT,PIN_OUTPUT);
	/*Register Select Options
	 * 1-Command Register 0
	 * 2-Data Register 1
	*/
	DIO_u8SetPinDirection(RS,CONTROL_PORT,PIN_OUTPUT);
	/*Read & Write Options
		 * 1-Write 0
		 * 2-Read 1
	*/
	DIO_u8SetPinDirection(RW,CONTROL_PORT,PIN_OUTPUT);
	/* Enable "Pulse" */
	DIO_u8SetPinDirection(E,CONTROL_PORT,PIN_OUTPUT);
	_delay_ms(30);
	LCD_voidSendCommand(FUNCTION_SET);
	_delay_ms(1);
	LCD_voidSendCommand(DISPLAY_ON_OFF);
	_delay_ms(2);
	LCD_voidSendCommand(CLEAR_DISPLAY);
	_delay_ms(2);
	LCD_voidSendCommand(ENTRY_MODE_SET);
}
void LCD_voidPortControl(void)
{
	DIO_u8SetPortDirection(DATA_PORT,255);
	/*Register Select Options
	 * 1-Command Register 0
	 * 2-Data Register 1
	*/
	DIO_u8SetPinDirection(RS,CONTROL_PORT,PIN_OUTPUT);
	/*Read & Write Options
		 * 1-Write 0
		 * 2-Read 1
	*/
	DIO_u8SetPinDirection(RW,CONTROL_PORT,PIN_OUTPUT);
	/* Enable "Pulse" */
	DIO_u8SetPinDirection(E,CONTROL_PORT,PIN_OUTPUT);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
	/*Select Data Register*/
	DIO_u8SetPinValue(RS,CONTROL_PORT,PIN_HIGH);
	/*set write mode*/
	DIO_u8SetPinValue(RW,CONTROL_PORT,PIN_LOW);
	/*Send 4 most bits*/
	DIO_u8Set4MSB_BitsValue(DATA_PORT,Copy_u8Data);
	/*Enable*/
	DIO_u8SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(E,CONTROL_PORT,PIN_LOW);
	/*Send 4 Least bits*/
	Copy_u8Data<<=4;
	DIO_u8Set4MSB_BitsValue(DATA_PORT,Copy_u8Data);
	/*Enable*/
	DIO_u8SetPinValue(E,CONTROL_PORT,PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(E,CONTROL_PORT,PIN_LOW);
}
void LCD_voidSetPosition(u8 Copy_u8Y_Position,u8 Copy_u8X_Position)
{
	if(Copy_u8Y_Position==FRIST_LINE)
	{
		LCD_voidSendCommand(128+Copy_u8X_Position);
	}
	else if(Copy_u8Y_Position==SECOND_LINE)
	{
		LCD_voidSendCommand(192+Copy_u8X_Position);
	}
	else
	{
		/*Nothing*/
	}
}
void LCD_voidSendString(u8* PtrToString)
{
	u8 i=0;
	u8 j=0;
	while(PtrToString[i]!='\0')
	{
		LCD_voidSendData(PtrToString[i]);
		i++;
		if((i>=16)&&(j<16))
		{
			LCD_voidSetPosition(1,j);
			j++;
		}
		if(j>=16)
		{
			LCD_voidSetPosition(0,j-16);
			j++;
		}
	}
}
void LCD_voidSendNumber(u32 Copy_u32Number)
{
	u8 ArrOfDigit[10];
	u8 i=0;
	while(Copy_u32Number!=0)
	{
		ArrOfDigit[i]=Copy_u32Number%10;
		Copy_u32Number/=10;
		i++;
	}
	for(s8 j=i-1;j>=0;j--)
	{
		LCD_voidSendData(ArrOfDigit[j]+48);
	}
}

