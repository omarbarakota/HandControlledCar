/*
 * APP.h
 *
 *  Created on: Feb 4, 2023
 *      Author: Lenovo
 */

#ifndef APP_APP_H_
#define APP_APP_H_
//Types
#include "Types.h"
#include "ADC.h"

typedef struct
{
	u16 POINTER;
	u16 MIDDLE;
	u16 RING;
	u16 PINKY;
	u16 THUMB;
}APP_GloveDataType;


void 			  APP_Init			(void);
APP_GloveDataType APP_ReadSensors	(void);
void 			  APP_SendData		(APP_GloveDataType Data);
u16 			  POT_Read			(ADC_Channel Channel);

#endif /* APP_APP_H_ */
