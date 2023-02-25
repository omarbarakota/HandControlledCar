/*
 * ADC_HW.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_ADC_INCLUDES_ADC_HW_H_
#define MCAL_ADC_INCLUDES_ADC_HW_H_

#include "ADC_Types.h"
#define ADC 	((volatile ADC_Reg*)0x24)

#define INTERNAL_AREF			0
#define AVCC_WITH_EXT_CAP		1
#define INTERNAL_2_56_WITH_CAP	3

#define	RIGHT_ADJUST	0
#define LEFT_ADJUST		1

#define	ADC_PRESCALER_2		1
#define	ADC_PRESCALER_4		2
#define	ADC_PRESCALER_8		3
#define	ADC_PRESCALER_16	4
#define	ADC_PRESCALER_32	5
#define	ADC_PRESCALER_64	6
#define	ADC_PRESCALER_128	7
#endif /* MCAL_ADC_INCLUDES_ADC_HW_H_ */
