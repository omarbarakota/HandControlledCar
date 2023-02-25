/*
 * UART_Program.c
 *
 *  Created on: Sep 28, 2021
 *      Author: Barakat
 */

#include "Types.h"

#include "GPIO_Types.h"

#include "USART_Types.h"
#include "USART_HW.h"
#include "USART_Config.h"

/* Call back function pointers
 * these pointers helps us to maintain isolation between layers
 * and also to hand any USART interrupts
 */
void (*USART_RX_CBF)(void);
void (*USART_TX_CBF)(void);
void (*USART_UDR_CBF)(void);


//This function disable the Receiver "RX" pin
void USART_DisableReciver(void)
{
	USART->UCSRB.BITS.RXEN=LOW;
}
//This function disable the Transmitter "TX" pin
void USART_DisableTransmitter(void)
{
	USART->UCSRB.BITS.TXEN=LOW;
}
//This function Enable the Receiver "RX" pin
void USART_EnableReciver(void)
{
	USART->UCSRB.BITS.RXEN=HIGH;
}
//This function Enable the Transmitter "TX" pin
void USART_EnableTransmitter(void)
{
	USART->UCSRB.BITS.TXEN=HIGH;
}
/* This function initialize the USART communication protocol
 * You can configure this communication from "USART_Config.h" File
 */
void USART_Init(void)
{
	//Choose which mood you want
	#if MODE_SELECT==ASYNCHRONOUS_MODE
		USART->UCSRC.BITS.UMSEL=LOW;
	#elif MODE_SELECT==SYNCHRONOUS_MODE
		USART->UCSRC.BITS.UMSEL=HIGH;
	#else
		#error"ERROR in SET MODE setting"
	#endif

	//Choose the parity mood
	#if PARITY_MODE==PARITY_DISABLED_MODE
		USART->UCSRC.BITS.UPM0=LOW;
		USART->UCSRC.BITS.UPM1=LOW;
	#elif PARITY_MODE==PARITY_EVEN_MODE
		USART->UCSRC.BITS.UPM0=LOW;
		USART->UCSRC.BITS.UPM0=HIGH;
	#elif PARITY_MODE==PARITY_ODD_MODE
		USART->UCSRC.BITS.UPM0=HIGH;
		USART->UCSRC.BITS.UPM1=HIGH;
	#else
		#error"ERROR in SET PARITY MODE setting"
	#endif

	//Set the stop bit
	#if STOP_BIT_MODE==ONE_STOP_BIT_MODE
		USART->UCSRC.BITS.USBS=LOW;
	#elif STOP_BIT_MODE==TWO_STOP_BIT_MODE
		USART->UCSRC.BITS.USBS=HIGH;
	#else
		#error"ERROR in SET PARITY MODE setting"
	#endif

	//Set the Data
	#if DATA_MODE==DATA_5BITS
		USART->UCSRC.BITS.UCSZ0=LOW;
		USART->UCSRC.BITS.UCSZ1=LOW;
		USART->UCSRB.BITS.UCSZ2=LOW;
	#elif DATA_MODE==DATA_6BITS
		USART->UCSRC.BITS.UCSZ0=HIGH;
		USART->UCSRC.BITS.UCSZ1=LOW;
		USART->UCSRB.BITS.UCSZ2=LOW;
	#elif DATA_MODE==DATA_7BITS
		USART->UCSRC.BITS.UCSZ0=LOW;
		USART->UCSRC.BITS.UCSZ1=HIGH;
		USART->UCSRB.BITS.UCSZ2=LOW;
	#elif DATA_MODE==DATA_8BITS
		USART->UCSRC.BITS.UCSZ0=HIGH;
		USART->UCSRC.BITS.UCSZ1=HIGH;
		USART->UCSRB.BITS.UCSZ2=LOW;
	#elif DATA_MODE==DATA_9BITS
		USART->UCSRC.BITS.UCSZ0=HIGH;
		USART->UCSRC.BITS.UCSZ1=HIGH;
		USART->UCSRB.BITS.UCSZ2=HIGH;
	#else
		#error"ERROR in Char size setting"
	#endif
	//Select the Baud rate
	USART->UBRRL=BAUD_RATE;
	//Enable Reciever & Transmitter
	USART_EnableTransmitter();
	USART_EnableReciver();

}

/* This functions sends a character "data From the UDR"
 * To the connected module "Controller "
 */
void USART_SendChar(u8 Copy_u8Charachter)
{
	while(USART->UCSRA.BITS.UDRE==LOW);//Wait till the UDR is empty (Sends the data)
	USART->UDR=Copy_u8Charachter;
}
/* This functions Receives a character "data to the UDR"
 * From the connected module "Controller "
 */
u8 USART_RecieveChar(void)
{
	while(USART->UCSRA.BITS.RXC==LOW);//Wait till the RXC is set (There's data to receive)
	return USART->UDR;//Return the received value in the UDR
}
/* This function enables the USART receive interrupt
 * This makes an interrupt when receiving data
 * only *if global interrupt in enabled*
 * for more info check the USART Driver
 */
void USART_RX_INT(void)
{
	USART->UCSRB.BITS.RXCIE=HIGH;
}
/* This function enables the USART Transmit interrupt
 * This makes an interrupt when transmitting data
 * only *if global interrupt in enabled*
 * for more info check the USART Driver
 */
void USART_TX_INT(void)
{
	USART->UCSRB.BITS.TXCIE=HIGH;
}
/* This function enables the USART Data interrupt
 * This makes an interrupt when the data register is empty
 * only *if global interrupt in enabled*
 * for more info check the USART Driver
 */
void USART_UDR_INT(void)
{
	USART->UCSRB.BITS.UDRIE=HIGH;
}

/* These functions are used to set the call back functions for the interrupts
 */
void USART_RXSetCBF(void (*RX_Fun)(void))
{
	USART_RX_CBF=RX_Fun;
}
void USART_UDRXSetCBF(void (*UDR_Fun)(void))
{
	USART_UDR_CBF=UDR_Fun;
}
void USART_TXSetCBF(void (*TX_Fun)(void))
{
	USART_TX_CBF=TX_Fun;
}

//These are the interrupts vectors
void __vector_13(void)	__attribute__((signal));
void __vector_13(void)
{
	USART_RX_CBF();
}
void __vector_14(void)	__attribute__((signal));
void __vector_14(void)
{
	USART_UDR_CBF();
}
void __vector_15(void)	__attribute__((signal));
void __vector_15(void)
{
	USART_TX_CBF();
}







