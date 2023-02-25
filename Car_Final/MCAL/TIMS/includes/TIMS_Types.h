/*
 * TIM0_Types.h
 *
 *  Created on: Feb 5, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_TIMS_INCLUDES_TIMS_TYPES_H_
#define MCAL_TIMS_INCLUDES_TIMS_TYPES_H_

#include "Types.h"
#include "TIMS_Config.h"

typedef struct{
	u8 TOIE0:1;
	u8 OCIE0:1;
	u8 TOIE1:1;
	u8 OCIE1B:1;
	u8 OCIE1A:1;
	u8 TICIE1:1;
	u8 TOIE2:1;
	u8 OCIE2:1;
}TIMSK_Reg;

#if TIMER0==ON

typedef struct{
	u8 CS00:1;
	u8 CS01:1;
	u8 CS02:1;
	u8 WGM01:1;
	u8 COM00:1;
	u8 COM01:1;
	u8 WGM00:1;
	u8 FOC0:1;
}TCCR0_Bits;

typedef union{
	TCCR0_Bits	BITS;
	u8 	 		ALLREG;
}TCCR0_Type;
typedef struct{

	u8		   TCNT0;
	TCCR0_Type TCCR0;
	u8 		   RESERVED[8];
	u8 		   OCR0;
}TIM0_Reg;
#endif

#if TIMER1==ON

typedef struct
{
	u8 CS10:1;
	u8 CS11:1;
	u8 CS12:1;
	u8 WGM12:1;
	u8 WGM13:1;
	u8 RESERVED:1;
	u8 ICES1:1;
	u8 ICNC1:1;
}TCCR1B_Bits;
typedef struct
{
	u8 WGM10:1;
	u8 WGM11:1;
	u8 FOC1B:1;
	u8 FOC1A:1;
	u8 COM1B0:1;
	u8 COM1B1:1;
	u8 COM1A0:1;
	u8 COM1A1:1;
}TCCR1A_Bits;
typedef union
{
	u8 ALLREG;
	TCCR1B_Bits Bits;
}TCCR1B_Type;
typedef union
{
	u8 ALLREG;
	TCCR1A_Bits Bits;
}TCCR1A_Type;
typedef struct{
	TCCR1B_Type B;
	TCCR1A_Type A;
}TCCR1_Type;
typedef struct{

	u16		    ICR1;
	u16 		OCR1B;
	u16 		OCR1A;
	u16 		TCNT1;
	TCCR1_Type  TCCR1;
}TIM1_Reg;

#endif
#if TIMER2==ON

typedef struct{
	u8 CS20:1;
	u8 CS21:1;
	u8 CS22:1;
	u8 WGM21:1;
	u8 COM20:1;
	u8 COM21:1;
	u8 WGM20:1;
	u8 FOC2:1;
}TCCR2_Bits;

typedef union{
	TCCR2_Bits	BITS;
	u8 	 		ALLREG;
}TCCR2_Type;
typedef struct{
	u8 		   OCR2;
	u8		   TCNT2;
	TCCR2_Type TCCR2;
}TIM2_Reg;

#endif
#endif /* MCAL_TIMS_INCLUDES_TIMS_TYPES_H_ */
