/*
 * APP.c
 *
 *  Created on: Feb 7, 2023
 *      Author: Barakat
 */

#include "BLUETOOTH.h"
#include "L298N.h"
#include "LCD_Interface.h"
#include "APP.h"

//this function initialize all the Hardware being used in this application
void APP_init(void)
{
	BLUETOOTH_Init();
	LCD_voidInit();
	L298N_Init();
}
//This function is responsible to read all the data coming from the glove
APP_GloveDataType APP_Read(void)
{
	APP_GloveDataType data={};
	data.POINTER=BLUETOOTH_Receive();
	data.MIDDLE=BLUETOOTH_Receive();
	data.RING=BLUETOOTH_Receive();
	data.PINKY=BLUETOOTH_Receive();
	data.THUMB=BLUETOOTH_Receive();
	return data;
}
//This function does all the logic depending on the data coming from the glove
void APP_Control(APP_GloveDataType data)
{
	//Convert Thumb from ascii to equivalent value to motors
	data.THUMB=(data.THUMB-48)*255/10;
	if((data.POINTER=='1') && (data.MIDDLE=='1')&& (data.RING=='1')&& (data.PINKY=='1'))
	{
		L298N_Move(Forward,data.THUMB);
		LCD_voidSendCommand(CLEAR_DISPLAY);
		LCD_voidSetPosition(FRIST_LINE,0);
		LCD_voidSendString("Forward");
	}
	else if((data.POINTER=='1') && (data.MIDDLE=='1')&& (data.RING=='0')&& (data.PINKY=='0'))
	{
		L298N_Move(Right,data.THUMB);
		LCD_voidSendCommand(CLEAR_DISPLAY);
		LCD_voidSetPosition(FRIST_LINE,0);
		LCD_voidSendString("Right");
	}
	else if((data.POINTER=='0') && (data.MIDDLE=='0')&& (data.RING=='1')&& (data.PINKY=='1'))
	{
		L298N_Move(Left,data.THUMB);
		LCD_voidSendCommand(CLEAR_DISPLAY);
		LCD_voidSetPosition(FRIST_LINE,0);
		LCD_voidSendString("Left");
	}
	else if((data.POINTER=='1') && (data.MIDDLE=='0')&& (data.RING=='0')&& (data.PINKY=='1'))
	{
		L298N_Move(Backward,data.THUMB);
		LCD_voidSendCommand(CLEAR_DISPLAY);
		LCD_voidSetPosition(FRIST_LINE,0);
		LCD_voidSendString("Backward");
	}
	else if((data.POINTER=='0') && (data.MIDDLE=='0')&& (data.RING=='0')&& (data.PINKY=='0'))
	{
		L298N_Move(Stop,data.THUMB);
		LCD_voidSendCommand(CLEAR_DISPLAY);
		LCD_voidSetPosition(FRIST_LINE,0);
		LCD_voidSendString("Stop");
	}
}
