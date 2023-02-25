/*
 * USART_HW.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Barakat
 */

#ifndef MCAL_USART_INCLUDES_USART_HW_H_
#define MCAL_USART_INCLUDES_USART_HW_H_
#include "USART_Types.h"

#define USART 	((volatile USART_Reg*)0x29)

#define ASYNCHRONOUS_MODE		0
#define SYNCHRONOUS_MODE		1

#define PARITY_DISABLED_MODE	0
#define PARITY_EVEN_MODE		1
#define PARITY_ODD_MODE			2

#define	ONE_STOP_BIT_MODE		1
#define TWO_STOP_BIT_MODE		2

#define DATA_5BITS			0
#define DATA_6BITS			1
#define DATA_7BITS			2
#define DATA_8BITS			3
#define DATA_9BITS			4

#endif /* MCAL_USART_INCLUDES_USART_HW_H_ */
