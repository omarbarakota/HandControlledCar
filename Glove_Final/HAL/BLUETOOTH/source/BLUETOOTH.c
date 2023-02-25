/*
 * BLUETOOTH.c
 *
 *  Created on: Feb 4, 2023
 *      Author: Barakat
 */

#include "Types.h"
#include "USART.h"

/* this function initializes the 'UART' communication protocol
 * that is needed for The bluetooth module
 */
void BLUETOOTH_Init(void)
{
	USART_Init();
}
//This function sends a character to the other module
void BLUETOOTH_Send(u8 Char)
{
	USART_SendChar(Char);
}
//This function Receives a character from the other module
u8 BLUETOOTH_Receive(void)
{
	return USART_RecieveChar();
}
/* This function enables the bluetooth receive interrupt
 * This makes an interrupt when receiving data
 * only *if global interrupt in enabled*
 * for more info check the USART Driver
 */
void BLUETOOTH_RxIntEnable(void)
{
	USART_RX_INT();
}
/* This function enables the bluetooth Transmit interrupt
 * This makes an interrupt when transmitting data
 * only *if global interrupt in enabled*
 * for more info check the USART Driver
 */
void BLUETOOTH_TxIntEnable(void)
{
	USART_TX_INT();
}
/* This function enables the bluetooth Data interrupt
 * This makes an interrupt when the data register is empty
 * only *if global interrupt in enabled*
 * for more info check the USART Driver
 */
void BLUETOOTH_DataIntEnable(void)
{
	USART_UDR_INT();
}

