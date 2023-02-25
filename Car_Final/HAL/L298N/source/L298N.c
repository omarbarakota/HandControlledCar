/*
 * L298N.C
 *
 *  Created on: Feb 10, 2023
 *      Author: Barakat
 */

#include "Types.h"
#include "GPIO.h"
#include "TIMS.h"
#include "L298N_Config.h"
#include "L298N.h"

/* This function initialize All pins needed for the driver
 * You can configure these pins from "L298N_Config.h' File
 * It also configures Timer1 since it has 2 Output Compare "OC" pins
 */
void L298N_Init(void)
{
	GPIO_SetPinDirection(Hen1_Port,Hen1_Pin,OUTPUT);
	GPIO_SetPinDirection(Hen2_Port,Hen2_Pin,OUTPUT);
	GPIO_SetPinDirection(HA_Port,HA1_Pin,OUTPUT);
	GPIO_SetPinDirection(HA_Port,HA2_Pin,OUTPUT);
	GPIO_SetPinDirection(HA_Port,HA3_Pin,OUTPUT);
	GPIO_SetPinDirection(HA_Port,HA4_Pin,OUTPUT);
	TIMER1_Init();
	TIMER1_SetTopValue(255);
}
/* This function is responsible to take actions for the motors
 * since it controls the speed and the directions
 */
void L298N_Move(L298N_DirType Direction,u32 Speed)
{
	TIMER1_SetCompareA(Speed);
	TIMER1_SetCompareB(Speed);
	switch(Direction)
	{
	case Forward:
		GPIO_SetPinValue(HA_Port,HA1_Pin,HIGH);
		GPIO_SetPinValue(HA_Port,HA2_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA3_Pin,HIGH);
		GPIO_SetPinValue(HA_Port,HA4_Pin,LOW);
		break;
	case Backward:
		GPIO_SetPinValue(HA_Port,HA1_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA2_Pin,HIGH);
		GPIO_SetPinValue(HA_Port,HA3_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA4_Pin,HIGH);
		break;
	case Left:
		GPIO_SetPinValue(HA_Port,HA1_Pin,HIGH);
		GPIO_SetPinValue(HA_Port,HA2_Pin,HIGH);
		GPIO_SetPinValue(HA_Port,HA3_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA4_Pin,LOW);
		break;
	case Right:
		GPIO_SetPinValue(HA_Port,HA1_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA2_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA3_Pin,HIGH);
		GPIO_SetPinValue(HA_Port,HA4_Pin,HIGH);
		break;
	case Stop:
		GPIO_SetPinValue(HA_Port,HA1_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA2_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA3_Pin,LOW);
		GPIO_SetPinValue(HA_Port,HA4_Pin,LOW);
		break;
	}
}
