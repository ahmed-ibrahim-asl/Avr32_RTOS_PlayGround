/*
 * btn_interface.h
 *
 *  Created on: Jul 27, 2024
 *      Author: ad
 */

#ifndef HAL_BTN_BTN_INTERFACE_H_
#define HAL_BTN_BTN_INTERFACE_H_

/******************************************* Include  Section *******************************************/
#include "../../MCAL/DIO/DIO_interface.h"
/********************************************************************************************************/






#define BTN_voidInit(Copy_u8BTNPortID, Copy_u8BTNPinID) \
    DIO_enuSetPinDirection(Copy_u8BTNPortID, Copy_u8BTNPinID, DIO_u8INPUT);




uint8_t BTN_u8Read(uint8_t Copy_u8BTNPortID,uint8_t Copy_u8BTNPinID);


#endif /* HAL_BTN_BTN_INTERFACE_H_ */
