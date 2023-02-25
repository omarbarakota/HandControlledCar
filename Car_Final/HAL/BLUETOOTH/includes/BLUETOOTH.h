/*
 * BLUETOOTH.h
 *
 *  Created on: Feb 4, 2023
 *      Author: Barakat
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "Types.h"

void BLUETOOTH_Init(void);
void BLUETOOTH_Send(u8 Char);
u8 BLUETOOTH_Receive(void);

void BLUETOOTH_RxIntEnable(void);
void BLUETOOTH_TxIntEnable(void);
void BLUETOOTH_DataIntEnable(void);

#endif /* BLUETOOTH_H_ */
