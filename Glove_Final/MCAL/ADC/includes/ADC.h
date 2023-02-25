/*
 * ADC.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_ADC_INCLUDES_ADC_H_
#define MCAL_ADC_INCLUDES_ADC_H_


#include "ADC_Types.h"

void ADC_Init				(void);
void ADC_InitInterrupt		(void);

void ADC_SelectChannel				(ADC_Channel Channel);

u16 ADC_StartConv			(ADC_Channel Channel);
u16 ADC_StartConvInterrupt	(ADC_Channel Channel);

u16 ADC_Read		(void);

#endif /* MCAL_ADC_INCLUDES_ADC_H_ */
