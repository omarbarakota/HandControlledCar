/*
 * main.c
 *
 *  Created on: Feb 5, 2023
 *      Author: Lenovo
 */

#include "Types.h"
#include "APP.h"

/* For more information please check each functions in its own driver
 * You will find it fully simplified
 */

int main()
{
	/*
	 * This user defined data type will hold all the data from the glove
	 */
	APP_GloveDataType Data={};
	//This function initialize all the hardware used in this module
	APP_Init();
	while(1)
	{
		//This functions read the data from the glove
		Data=APP_ReadSensors();
		//this function sends the data to the other module "Car"
		APP_SendData(Data);
	}
	return 0;
}

