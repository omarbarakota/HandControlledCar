/*
 * main.c
 *
 *  Created on: Feb 1, 2023
 *      Author: Lenovo
 */
//Types
#define F_CPU 16000000UL
#include "Types.h"
#include "APP.h"


/* To understand any functions please go to it's own driver
 * You will find it Fully simplified
 */

int main()
{
	//This variable will hold the data received from the glove
	APP_GloveDataType Data={};
	//We initialize the application
	APP_init();
	while(1)
	{
		//We read the data
		Data=APP_Read();
		//depending on the data we read the applications starts to work
		APP_Control(Data);
	}
	return 0;
}













//		x[1]=ADC_StartConv(ADC1);
//		x[2]=ADC_StartConv(ADC2);
//
//		if((x[0]<=(1024/3)) && (x[1]<=(1024/3)) && (x[2]<=(1024/3)))
//		{
//			GPIO_SetPinValue(GPIOC,PIN2,HIGH);
//			GPIO_SetPinValue(GPIOC,PIN7,LOW);
//			GPIO_SetPinValue(GPIOD,PIN3,LOW);
//
//		}
//		else if ((x[0]<=(1024*2/3)) && (x[1]<=(1024*2/3)) && (x[2]<=(1024*2/3)))
//		{
//			GPIO_SetPinValue(GPIOC,PIN7,LOW);
//			GPIO_SetPinValue(GPIOC,PIN7,HIGH);
//			GPIO_SetPinValue(GPIOD,PIN3,LOW);
//		}
//		else if((x[0]<(1024)) && (x[1]<(1024)) && (x[2]<(1024)))
//		{
//			GPIO_SetPinValue(GPIOC,PIN2,LOW);
//			GPIO_SetPinValue(GPIOC,PIN7,LOW);
//			GPIO_SetPinValue(GPIOD,PIN2,HIGH);
//		}
//		else
//		{
//			GPIO_SetPinValue(GPIOC,PIN2,LOW);
//			GPIO_SetPinValue(GPIOC,PIN7,LOW);
//			GPIO_SetPinValue(GPIOD,PIN2,LOW);
//		}
