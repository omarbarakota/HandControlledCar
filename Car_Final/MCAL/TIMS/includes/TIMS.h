/*
 * TIM0.h
 *
 *  Created on: Feb 5, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMS_INCLUDES_TIMS_H_
#define MCAL_TIMS_INCLUDES_TIMS_H_
#include "TIMS_Config.h"

/* I used the configuration here since i don't want to let anyone by mistake use
 * any timers' functions without configuring it first
 */

#if TIMER0==ON
void TIMER0_Init(void);
void TIMER0_SetPreloadValue(u8 Copy_u8Preload);
void TIMER0_SetOCValue(u8 Copy_u8CTCValue);

void TIMER0_OVFSetCBF(void (*OVF_Fun)(void));
void TIMER0_COMPSetCBF(void (*COMP_Fun)(void));

#endif
#if TIMER1==ON
void TIMER1_Init(void);
void TIMER1_SetCompareA(u16 Copy_u16CTCValue);
void TIMER1_SetCompareB(u16 Copy_u16CTCValue);
void TIMER1_SetTopValue(u16 Copy_u16TopValue);

void TIMER1_OVFSetCBF(void (*OVF_Fun)(void));
void TIMER1_COMPBSetCBF(void (*COMPB_Fun)(void));
void TIMER1_COMPASetCBF(void (*COMPA_Fun)(void));
void TIMER1_ICUSetCBF(void (*ICU_Fun)(void));

#endif
#if TIMER2==ON
void TIMER2_voidInit(void);
void TIMER2_voidSetPreloadValue(u8 Copy_u8Preload);
void TIMER2_voidSetCTCValue(u8 Copy_u8CTCValue);

void TIMER2_OVFSetCBF(void (*OVF_Fun)(void));
void TIMER2_COMPSetCBF(void (*COMP_Fun)(void));
#endif


#endif /* MCAL_TIMS_INCLUDES_TIMS_H_ */
