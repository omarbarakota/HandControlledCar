/*
 * ADC_Types.h
 *
 *  Created on: Feb 3, 2023
 *      Author: Lenovo
 */

#ifndef MCAL_ADC_INCLUDES_ADC_TYPES_H_
#define MCAL_ADC_INCLUDES_ADC_TYPES_H_
#include "Types.h"


typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}ADC_Channel;


//ACSR
//Goz2 l sifor aly m4 tb3na t2semt l data register

typedef struct
{
	u8 ADPS0:1;
	u8 ADPS1:1;
	u8 ADPS2:1;
	u8 ADIE:1;
	u8 ADIF:1;
	u8 ADATE:1;
	u8 ADSC:1;
	u8 ADEN:1;

}ADC_ADCSRABits;
typedef struct
{
	u8 MUX0:1;
	u8 MUX1:1;
	u8 MUX2:1;
	u8 MUX3:1;
	u8 MUX4:1;
	u8 ADLAR:1;
	u8 REFS0:1;
	u8 REFS1:1;

}ADC_ADMUXBits;
typedef struct
{
	u8 PSR10:1;
	u8 PSR2:1;
	u8 PUD:1;
	u8 ACME:1;
	u8 RESERVED:1;
	u8 ADTS0:1;
	u8 ADTS1:1;
	u8 ADTS2:1;

}ADC_SIFORBits;
typedef union
{
	ADC_ADCSRABits    BITS;
	u8 			      ALLREG;
}ADC_ADCSRATypes;
typedef union
{
	ADC_ADMUXBits	  BITS;
	u8 			 	  ALLREG;
}ADC_ADMUXTypes;
typedef union
{
	ADC_SIFORBits 	  BITS;
	u8 			  	  ALLREG;
}ADC_SIFORTypes;
typedef struct
{
	u16				  ADCDR;
	ADC_ADCSRATypes   ADCSRA;
	ADC_ADMUXTypes 	  ADMUX;
	u8 				  RESERVRED[40];
	ADC_SIFORTypes	  SIFOR;
}ADC_Reg;

#endif /* MCAL_ADC_INCLUDES_ADC_TYPES_H_ */
