/*
 * BTN_program.c
 *
 *  Created on: Jul 27, 2024
 *      Author: ad
 */


/******************************************* Include  Section *******************************************/
#include "BTN_interface.h"
/********************************************************************************************************/





uint8_t BTN_u8Read(uint8_t Copy_u8BTNPortID,uint8_t Copy_u8BTNPinID){


	uint8_t value = 0;


	DIO_enuGetPinValue(Copy_u8BTNPortID, Copy_u8BTNPinID, &value);

	return value;
}


