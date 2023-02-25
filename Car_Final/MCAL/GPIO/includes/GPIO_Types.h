/*
 * GPIO_Types.h
 *
 *  Created on: Feb 2, 2023
 *      Author: Barakat
 */

#ifndef MCAL_GPIO_INCLUDES_GPIO_TYPES_H_
#define MCAL_GPIO_INCLUDES_GPIO_TYPES_H_
//port ddr pin
#include "Types.h"

typedef enum//PinValue
{
	NOK,
	OK
}Error_Value;


typedef enum//PinValue
{
	LOW,
	HIGH
}GPIO_PINxValue;
typedef enum//DDRValue
{
	INPUT,
	OUTPUT
}GPIO_DDRxValue;

typedef enum//PortValue
{
	PortLow,
	PortHigh=255
}GPIO_PORTxValue;
typedef enum//PortDir
{
	PortIn,
	PortOut=255
}GPIO_PORTxDir;
typedef enum//Pin bits
{
	 PIN0,
	 PIN1,
	 PIN2,
	 PIN3,
	 PIN4,
	 PIN5,
	 PIN6,
	 PIN7
}GPIO_PINNum;
typedef enum//GPIOValue
{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD
}GPIO_GPIONum;

typedef enum//Nibble
{
	LOWNIBBLE,
	HIGHNIBBLE
}GPIO_NibbleValue;

typedef struct//Pin bits
{
	GPIO_PINxValue PINx0:1;
	GPIO_PINxValue PINx1:1;
	GPIO_PINxValue PINx2:1;
	GPIO_PINxValue PINx3:1;
	GPIO_PINxValue PINx4:1;
	GPIO_PINxValue PINx5:1;
	GPIO_PINxValue PINx6:1;
	GPIO_PINxValue PINx7:1;
}GPIO_PINxBits;
typedef struct//DDR bits
{
	GPIO_DDRxValue DDRx0:1;
	GPIO_DDRxValue DDRx1:1;
	GPIO_DDRxValue DDRx2:1;
	GPIO_DDRxValue DDRx3:1;
	GPIO_DDRxValue DDRx4:1;
	GPIO_DDRxValue DDRx5:1;
	GPIO_DDRxValue DDRx6:1;
	GPIO_DDRxValue DDRx7:1;
}GPIO_DDRxBits;
typedef struct//Port bits
{
	GPIO_PINxValue PORTx0:1;
	GPIO_PINxValue PORTx1:1;
	GPIO_PINxValue PORTx2:1;
	GPIO_PINxValue PORTx3:1;
	GPIO_PINxValue PORTx4:1;
	GPIO_PINxValue PORTx5:1;
	GPIO_PINxValue PORTx6:1;
	GPIO_PINxValue PORTx7:1;
}GPIO_PORTxBits;

typedef union//Pin
{
	GPIO_PINxBits BITS;
	u8 		      ALLREG;
}GPIO_PINxTypes;
typedef union//DDR
{
	GPIO_DDRxBits BITS;
	u8 		  	  ALLREG;
}GPIO_DDRxTypes;
typedef union//PORT
{
	GPIO_PORTxBits	  BITS;
	u8				  ALLREG;
}GPIO_PortxTypes;
typedef struct//GPIOx
{
	GPIO_PINxTypes  PIN;
	GPIO_DDRxTypes  DDR;
	GPIO_PortxTypes PORT;
}GPIOx_Types;

typedef struct//GPIO
{
	GPIOx_Types  GPIOD;
	GPIOx_Types  GPIOC;
	GPIOx_Types  GPIOB;
	GPIOx_Types  GPIOA;
}GPIO_Reg;



#endif /* MCAL_GPIO_INCLUDES_GPIO_TYPES_H_ */
