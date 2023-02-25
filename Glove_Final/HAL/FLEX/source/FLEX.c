/*
 * FLEX.c
 *
 *  Created on: Feb 4, 2023
 *      Author: Lenovo
 */

#include "Types.h"
#include "ADC.h"
#include "FLEX_Config.h"

//This function initialize the Flexible sensor
void FLEX_Init(void)
{
	ADC_Init();
}
/* This function does the following
 * 1-Select the channel
 * 2-Read data coming to the channel
 * 3-Calculate the angle of turning
 */
u16 FLEX_Read(ADC_Channel Channel)
{
	u16 data=0;
	f32 Vflex=0,Rflex=0,angle=0;
	data=ADC_StartConv(Channel);
	Vflex=data*VCC/1023;
	Rflex=R_dev*VCC/(Vflex-1);
	angle=(((Rflex-Rflex_Min)/(Rflex_Max-Rflex_Min))*(AngleMax-AngleMin));
	/*vo=vcc*10/rf+10
	rf=(vcc*10/vo)-10*/
	return angle;

}
u16 POT_Read(ADC_Channel Channel)
{
	return ADC_StartConv(Channel);
}
