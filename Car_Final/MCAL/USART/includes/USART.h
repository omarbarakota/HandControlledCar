/*
 * USART.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_USART_INCLUDES_USART_H_
#define MCAL_USART_INCLUDES_USART_H_



void USART_Init(void);
void USART_SendChar(u8 Copy_u8Charachter);
u8 USART_RecieveChar(void);

void USART_EnableReciver(void);
void USART_EnableTransmitter(void);

void USART_DisableReciver(void);
void USART_voidDisableTransmitter(void);

void USART_RX_INT(void);
void USART_TX_INT(void);
void USART_UDR_INT(void);


#endif /* MCAL_USART_INCLUDES_USART_H_ */
