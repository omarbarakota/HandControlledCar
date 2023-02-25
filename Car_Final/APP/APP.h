/*
 * APP.h
 *
 *  Created on: Feb 7, 2023
 *      Author: Barakat
 */

#ifndef APP_APP_H_
#define APP_APP_H_

typedef struct
{
	u16 POINTER;
	u16 MIDDLE;
	u16 RING;
	u16 PINKY;
	u16 THUMB;
}APP_GloveDataType;

void APP_init(void);
APP_GloveDataType APP_Read(void);
void APP_Control(APP_GloveDataType data);


#endif /* APP_APP_H_ */
