/*
 * GPIO.h
 *
 *  Created on: Feb 2, 2023
 *      Author: Barakat
 */

#ifndef MCAL_GPIO_INCLUDES_GPIO_H_
#define MCAL_GPIO_INCLUDES_GPIO_H_
//Types
#include "Types.h"

//GPIO Types
#include "GPIO_Types.h"


void GPIO_SetPinDirection		(GPIO_GPIONum PortNum ,GPIO_PINNum PinNum, GPIO_DDRxValue DDR_Value);
void GPIO_SetPinValue	 		(GPIO_GPIONum PortNum ,GPIO_PINNum PinNum, GPIO_PINxValue PIN_Value);

GPIO_PINxValue GPIO_GetPinValue	(GPIO_GPIONum PortNum ,GPIO_PINNum PinNum);
void GPIO_TogglePinValue	    (GPIO_GPIONum PortNum ,GPIO_PINNum PinNum);

void GPIO_SetPortDirection		(GPIO_GPIONum PortNum ,GPIO_PORTxDir PortDir);
void GPIO_SetPortValue			(GPIO_GPIONum PortNum ,GPIO_PORTxValue PortValue);

void GPIO_SetMSB		(GPIO_GPIONum PortNum ,u8 Value);
void GPIO_SetNibble			(GPIO_GPIONum PortNum ,GPIO_NibbleValue NibbleValue,u8 Value);


#endif /* MCAL_GPIO_INCLUDES_GPIO_H_ */
