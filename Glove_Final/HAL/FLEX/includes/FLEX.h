/*
 * FLEX.h
 *
 *  Created on: Feb 4, 2023
 *      Author: Lenovo
 */

#ifndef FLEX_H_
#define FLEX_H_

#include "Types.h"
#include "ADC.h"

void FLEX_Init(void);

u16 FLEX_Read(ADC_Channel Channel);

#endif /* FLEX_H_ */
