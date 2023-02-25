/*
 * L298N.h
 *
 *  Created on: Feb 10, 2023
 *      Author: Barakat
 */

#ifndef HAL_L298N_INCLUDES_L298N_H_
#define HAL_L298N_INCLUDES_L298N_H_

typedef enum{
	Forward,
	Backward,
	Right,
	Left,
	Stop
}L298N_DirType;

void L298N_Init(void);
void L298N_Move(L298N_DirType Direction,u32 Speed);

#endif /* HAL_L298N_L298N_H_ */
