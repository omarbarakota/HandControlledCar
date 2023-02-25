/*
 * APP.c
 *
 *  Created on: Feb 4, 2023
 *      Author: Lenovo
 */

#include "Types.h"

#include "FLEX.h"
#include "FLEX_Config.h"
#include "BLUETOOTH.h"

#include "APP_Config.h"
#include "APP.h"


//This function initialize bluetooth module and the flex sensors
void APP_Init(void)
{
	FLEX_Init();
	BLUETOOTH_Init();
}
APP_GloveDataType APP_ReadSensors(void)
{
	APP_GloveDataType Data;
	Data.POINTER=POT_Read(F_POINTER);
	Data.MIDDLE=POT_Read(F_MIDDLE);
	Data.RING=POT_Read(F_RING);
	Data.PINKY=POT_Read(F_PINKY);
	Data.THUMB=FLEX_Read(F_THUMB);
	return Data;
}
void APP_SendData(APP_GloveDataType Data)
{
	if(Data.POINTER<=(AngleMax/2))//POINTER is Flat
	{
		BLUETOOTH_Send('1');
	}
	else//POINTER is Bended
	{
		BLUETOOTH_Send('0');
	}
	if(Data.MIDDLE<=(AngleMax/2))//MIDDLE is Flat
	{
		BLUETOOTH_Send('1');
	}
	else//MIDDLE is Bended
	{
		BLUETOOTH_Send('0');
	}
	if(Data.RING<=(AngleMax/2))//RING is Flat
	{
		BLUETOOTH_Send('1');
	}
	else//RING is Bended
	{
		BLUETOOTH_Send('0');
	}
	if(Data.PINKY<=(AngleMax/2))//PINKY is Flat
	{
		BLUETOOTH_Send('1');
	}
	else//PINKY is Bended
	{
		BLUETOOTH_Send('0');
	}
	switch(Data.THUMB)
	{
	case 0 ... 10:
	BLUETOOTH_Send('1');break;
	case 11 ... 20:
	BLUETOOTH_Send('2');break;
	case 21 ... 30:
	BLUETOOTH_Send('3');break;
	case 31 ... 40:
	BLUETOOTH_Send('4');break;
	case 41 ... 50:
	BLUETOOTH_Send('5');break;
	case 51 ... 60:
	BLUETOOTH_Send('6');break;
	case 61 ... 70:
	BLUETOOTH_Send('7');break;
	case 71 ... 80:
	BLUETOOTH_Send('8');break;
	case 81 ... 90:
	BLUETOOTH_Send('9');break;
	default:
	BLUETOOTH_Send('0');break;

	}

}

