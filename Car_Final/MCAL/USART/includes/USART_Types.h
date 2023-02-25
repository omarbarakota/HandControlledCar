/*
 * USART_Types.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Barakat
 */

#ifndef MCAL_USART_INCLUDES_USART_TYPES_H_
#define MCAL_USART_INCLUDES_USART_TYPES_H_


typedef struct
{
	u8 TXB8:1;
	u8 RXB8:1;
	u8 UCSZ2:1;
	u8 TXEN:1;
	u8 RXEN:1;
	u8 UDRIE:1;
	u8 TXCIE:1;
	u8 RXCIE:1;

}USART_UCSRBBits;
typedef struct
{
	u8 MPCM:1;
	u8 U2X:1;
	u8 PE:1;
	u8 DOR:1;
	u8 FE:1;
	u8 UDRE:1;
	u8 TXC:1;
	u8 RXC:1;
}USART_UCSRABits;

typedef struct
{
	u8 UCPOL:1;
	u8 UCSZ0:1;
	u8 UCSZ1:1;
	u8 USBS:1;
	u8 UPM0:1;
	u8 UPM1:1;
	u8 UMSEL:1;
	u8 URSEL:1;
}USART_UCSRCBits;

typedef union
{
	u8 ALLREG;
	USART_UCSRBBits BITS;
}USART_UCSRBType;
typedef union
{
	u8 ALLREG;
	USART_UCSRABits BITS;
}USART_UCSRAType;
typedef union
{
	u8 ALLREG;
	USART_UCSRCBits BITS;
}USART_UCSRCType;
typedef struct
{
	u8				UBRRL;
	USART_UCSRBType UCSRB;
	USART_UCSRAType UCSRA;
	u8 				UDR;
	u8 				RESERVED[20];
	USART_UCSRCType UCSRC;
}USART_Reg;


#endif /* MCAL_USART_INCLUDES_USART_TYPES_H_ */
