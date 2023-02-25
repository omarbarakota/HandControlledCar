/*
 * GPIO.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Barakat
 */


#include "Types.h"
#include "BitMath.h"
#include "GPIO_Types.h"

#include "GPIO_HW.h"

//This function is used to make the pin input or output
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

/* This function is used to set a value whether high or low to output the pin
 * Its can also be used to generate the internal pull up resistor to the
 * input pin
 */
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
//This function is used to read the data on the pin wheter high or low
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
//this function is used to toggle the value of the output pin
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
//this function is used to set a full port's direction
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
//This function is used to set a full port's value
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
void GPIO_SetMSB		(GPIO_GPIONum PortNum ,u8 Value)
{
	switch(PortNum)
	{
	case GPIOA:
		GPIO->GPIOA.PORT.ALLREG&=0x0F;
		Value&=0xF0;
		GPIO->GPIOA.PORT.ALLREG|=Value;
		break;
	case GPIOB:
		GPIO->GPIOB.PORT.ALLREG&=0x0F;
		Value&=0xF0;
		GPIO->GPIOB.PORT.ALLREG|=Value;
		break;
	case GPIOC:
		GPIO->GPIOC.PORT.ALLREG&=0x0F;
		Value&=0xF0;
		GPIO->GPIOC.PORT.ALLREG|=Value;
		break;
	case GPIOD:
		GPIO->GPIOD.PORT.ALLREG&=0x0F;
		Value&=0xF0;
		GPIO->GPIOD.PORT.ALLREG|=Value;
		break;
	}
}
void GPIO_SetNibble			(GPIO_GPIONum PortNum ,GPIO_NibbleValue NibbleValue,u8 Value)
{
	if(NibbleValue==HIGHNIBBLE)
	{
		switch(PortNum)
		{
		case GPIOA:
			GPIO->GPIOA.PORT.ALLREG &=0x0f;
			Value&=0xf0;
			GPIO->GPIOA.PORT.ALLREG|=Value;
			break;
		case GPIOB:
			GPIO->GPIOB.PORT.ALLREG &=0x0f;
			Value&=0xf0;
			GPIO->GPIOB.PORT.ALLREG|=Value;
			break;
		case GPIOC:
			GPIO->GPIOC.PORT.ALLREG &=0x0f;
			Value&=0xf0;
			GPIO->GPIOC.PORT.ALLREG|=Value;
			break;
		case GPIOD:
			GPIO->GPIOD.PORT.ALLREG &=0x0f;
			Value&=0xf0;
			GPIO->GPIOD.PORT.ALLREG|=Value;
			break;
		}
	}
	else//LOWNIBBLE
	{
		switch(PortNum)
		{
		case GPIOA:
			GPIO->GPIOA.PORT.ALLREG &=0xf0;
			Value&=0x0f;
			GPIO->GPIOA.PORT.ALLREG|=Value;
			break;
		case GPIOB:
			GPIO->GPIOB.PORT.ALLREG &=0xf0;
			Value&=0x0f;
			GPIO->GPIOB.PORT.ALLREG|=Value;
			break;
		case GPIOC:
			GPIO->GPIOC.PORT.ALLREG &=0xf0;
			Value&=0x0f;
			GPIO->GPIOC.PORT.ALLREG|=Value;
			break;
		case GPIOD:
			GPIO->GPIOD.PORT.ALLREG &=0xf0;
			Value&=0x0f;
			GPIO->GPIOD.PORT.ALLREG|=Value;
			break;

		}
	}
}

