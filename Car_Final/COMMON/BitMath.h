/*
 * BitMath.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Lenovo
 */

#ifndef COMMON_BITMATH_H_
#define COMMON_BITMATH_H_

#define SET_BIT(VAR,BIT_NO)			((VAR)|=(1<<(BIT_NO)))
#define CLR_BIT(VAR,BIT_NO)			((VAR) &= (~(1<<(BIT_NO))))
#define TOGGLE_BIT(VAR,BIT_NO)		((VAR) ^= (1<<(BIT_NO)))
#define GET_BIT(VAR,BIT_NO)			(((VAR)>>(BIT_NO))&1)

#endif /* BITMATH_H_ */
