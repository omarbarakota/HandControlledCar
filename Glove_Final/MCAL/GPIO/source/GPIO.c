/*
 * GPIO.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Lenovo
 */

			/*COMMON*/
//TypesGPIO
#include "Types.h"
#include "BitMath.h"
			/*MCAL*/
//GPIO Types
#include "GPIO.h"
//GPIO HW
#include "GPIO_HW.h"

void GPIO_SetPinDirection		(GPIO_GPIONum PortNum ,GPIO_PINNum PinNum, GPIO_DDRxValue DDR_Value)
{
	switch(PortNum)
	{
	case GPIOA:
		if(DDR_Value!=INPUT)
		{SET_BIT(GPIO->GPIOA.DDR.ALLREG,PinNum);}
		else
		{CLR_BIT(GPIO->GPIOA.DDR.ALLREG,PinNum);}
		break;
	case GPIOB:
		if(DDR_Value!=INPUT)
		{SET_BIT(GPIO->GPIOB.DDR.ALLREG,PinNum);}
		else
		{CLR_BIT(GPIO->GPIOB.DDR.ALLREG,PinNum);}
		break;
	case GPIOC:
		if(DDR_Value!=INPUT)
		{SET_BIT(GPIO->GPIOC.DDR.ALLREG,PinNum);}
		else
		{CLR_BIT(GPIO->GPIOC.DDR.ALLREG,PinNum);}
		break;
	case GPIOD:
		if(DDR_Value!=INPUT)
		{SET_BIT(GPIO->GPIOD.DDR.ALLREG,PinNum);}
		else
		{CLR_BIT(GPIO->GPIOD.DDR.ALLREG,PinNum);}
		break;
	}
}
void GPIO_SetPinValue	 		(GPIO_GPIONum PortNum ,GPIO_PINNum PinNum, GPIO_PINxValue PIN_Value)
{
	switch(PortNum)
	{
	case GPIOA:
		if(PIN_Value!=LOW)
		{SET_BIT(GPIO->GPIOA.PORT.ALLREG,PinNum);}
		else
		{CLR_BIT(GPIO->GPIOA.PORT.ALLREG,PinNum);}
		break;
	case GPIOB:
		if(PIN_Value!=LOW)
		{SET_BIT(GPIO->GPIOB.PORT.ALLREG,PinNum);}
		else
		{CLR_BIT(GPIO->GPIOB.PORT.ALLREG,PinNum);}
		break;
	case GPIOC:
		if(PIN_Value!=LOW)
		{SET_BIT(GPIO->GPIOC.PORT.ALLREG,PinNum);}
		else
		{CLR_BIT(GPIO->GPIOC.PORT.ALLREG,PinNum);}
		break;
	case GPIOD:
		if(PIN_Value!=LOW)
		{SET_BIT(GPIO->GPIOD.PORT.ALLREG,PinNum);}
		else
		{CLR_BIT(GPIO->GPIOD.PORT.ALLREG,PinNum);}
		break;
	}
}

GPIO_PINxValue GPIO_GetPinValue	(GPIO_GPIONum PortNum ,GPIO_PINNum PinNum)
{
	GPIO_PINxValue Value=0;
	switch(PortNum)
	{
	case GPIOA:
		Value=GET_BIT(GPIO->GPIOA.PIN.ALLREG,PinNum);break;
	case GPIOB:
		Value=GET_BIT(GPIO->GPIOB.PIN.ALLREG,PinNum);break;
	case GPIOC:
		Value=GET_BIT(GPIO->GPIOC.PIN.ALLREG,PinNum);break;
	case GPIOD:
		Value=GET_BIT(GPIO->GPIOD.PIN.ALLREG,PinNum);break;
	}
	return Value;
}

void GPIO_TogglePinValue	    (GPIO_GPIONum PortNum ,GPIO_PINNum PinNum)
{
	switch(PortNum)
	{
	case GPIOA:
		TOGGLE_BIT(GPIO->GPIOA.PORT.ALLREG,PinNum);break;
	case GPIOB:
		TOGGLE_BIT(GPIO->GPIOB.PORT.ALLREG,PinNum);break;
	case GPIOC:
		TOGGLE_BIT(GPIO->GPIOC.PORT.ALLREG,PinNum);break;
	case GPIOD:
		TOGGLE_BIT(GPIO->GPIOD.PORT.ALLREG,PinNum);break;
	}

}

void GPIO_SetPortDirection		(GPIO_GPIONum PortNum ,GPIO_PORTxDir PortDir)
{
	switch(PortNum)
	{
	case GPIOA:
			GPIO->GPIOA.DDR.ALLREG=PortDir;break;
	case GPIOB:
			GPIO->GPIOB.DDR.ALLREG=PortDir;break;
	case GPIOC:
			GPIO->GPIOC.DDR.ALLREG=PortDir;break;
	case GPIOD:
			GPIO->GPIOD.DDR.ALLREG=PortDir;break;
	}
}
void GPIO_SetPortValue			(GPIO_GPIONum PortNum ,GPIO_PORTxValue PortValue)
{
	switch(PortNum)
	{
	case GPIOA:
			GPIO->GPIOA.PORT.ALLREG=PortValue;break;
	case GPIOB:
			GPIO->GPIOB.PORT.ALLREG=PortValue;break;
	case GPIOC:
			GPIO->GPIOC.PORT.ALLREG=PortValue;break;
	case GPIOD:
			GPIO->GPIOD.PORT.ALLREG=PortValue;break;
	}
}

void GPIO_SetNibble			(GPIO_GPIONum PortNum ,GPIO_NibbleValue NibbleValue)
{
	if(NibbleValue==LOWNIBBLE)
	{
		switch(PortNum)
		{
		case GPIOA:
			GPIO->GPIOA.PORT.ALLREG &=0x0f;break;
		case GPIOB:
			GPIO->GPIOB.PORT.ALLREG &=0x0f;break;
		case GPIOC:
			GPIO->GPIOC.PORT.ALLREG &=0x0f;break;
		case GPIOD:
			GPIO->GPIOD.PORT.ALLREG &=0x0f;break;
		}
	}
	else//HIGHNIBBLE
	{
		switch(PortNum)
		{
		case GPIOA:
			GPIO->GPIOA.PORT.ALLREG &=0xf0;break;
		case GPIOB:
			GPIO->GPIOB.PORT.ALLREG &=0xf0;break;
		case GPIOC:
			GPIO->GPIOC.PORT.ALLREG &=0xf0;break;
		case GPIOD:
			GPIO->GPIOD.PORT.ALLREG &=0xf0;break;		}
	}
}


