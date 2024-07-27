/*
 * main.c
 *
 *  Created on: Jul 27, 2024
 *      Author: ad
 */
/**
 *	[ AMIT LEDs PINOUT ]
 *
 *  RIGHT	(PORTC) (2)
 *	CENTER	(PORTC) (7)
 *	LEFT 	(PORTD)	(2)
 * */

/******************************************* Include  Section *******************************************/
#include "HAL/LED/LED_Interface.h"
#include "HAL/BTN/BTN_interface.h"
#include "HAL/LCD/LCD_HAL_interface.h"


#include "FREE_RTOS/Header/FreeRTOS.h"
#include "FREE_RTOS/Header/task.h"
#include "FREE_RTOS/Header/semphr.h"
/********************************************************************************************************/



/***************************************** Task Handler Section *****************************************/
TaskHandle_t* Initialize_Task = NULL;

TaskHandle_t* LED0_On_Task = NULL;
TaskHandle_t* LED0_Off_Task = NULL;
TaskHandle_t* LED0_Toggle_Task = NULL;

TaskHandle_t* LED1_On_Task = NULL;
TaskHandle_t* LED1_Off_Task = NULL;
TaskHandle_t* LED1_Toggle_Task = NULL;

TaskHandle_t* LED2_On_Task = NULL;
TaskHandle_t* LED2_Off_Task = NULL;
TaskHandle_t* LED2_Toggle_Task = NULL;



SemaphoreHandle_t LCD_Key;
TaskHandle_t * LCD_Write_Task1 = NULL;
TaskHandle_t * LCD_Write_Task2 = NULL;


TaskHandle_t* BTN_Press_Task = NULL;
/********************************************************************************************************/



void vTask0_Init(void *ptr){
	while(1){

		LED_voidInit(DIO_u8PortC, DIO_u8PIN2);
		LED_voidInit(DIO_u8PortC, DIO_u8PIN7);
		LED_voidInit(DIO_u8PortD, DIO_u8PIN3);
		LCD_enuInit();
		BTN_voidInit(DIO_u8PortB, DIO_u8PIN0);

		LED_voidON(DIO_u8PortC, DIO_u8PIN2);
		LED_voidON(DIO_u8PortC, DIO_u8PIN7);
		LED_voidON(DIO_u8PortD, DIO_u8PIN3);



		vSemaphoreCreateBinary(LCD_Key);
		vTaskSuspend( (TaskHandle_t*) Initialize_Task );
	}
}

/************************************************* LED0 *************************************************/
void vTask1_LED0_ON(void *ptr){
	while(1){

	}
}

void vTask2_LED0_OFF(void *ptr){
	while(1){

	}
}


void vTask3_LED0_TOGGLE(void *ptr){
	while(1){
		LED_voidTOGGLE(DIO_u8PortC, DIO_u8PIN2);
		vTaskDelay(1000);
	}
}
/********************************************************************************************************/



/************************************************* LED1 *************************************************/
void vTask4_LED1_ON(void *ptr){
	while(1){

	}
}

void vTask5_LED1_OFF(void *ptr){
	while(1){

	}
}


void vTask6_LED1_TOGGLE(void *ptr){
	while(1){
		LED_voidTOGGLE(DIO_u8PortC, DIO_u8PIN7);

		/*
		 * vTaskDelay(arg1)
		 *
		 * 	arg1: The number of ticks to delay the task.
		 *
		 * Note:
		 * The delay time in milliseconds can be calculated using the formula:
		 * Delay Time (ms) = (Number of Ticks / configTICK_RATE_HZ) * 1000
		 *
		 *
		 * [ This formula is derived from ]
		 *
		 * 		Tick Period (s)  =  1 / configTICK_RATE_HZ
		 * 		Tick Period (ms) =  1000 / configTICK_RATE_HZ
		 * 		Delay Time (ms)  =  Number of Ticks * Tick Period (ms)
		 * 		Delay Time (ms)  =  (Number of Ticks / configTICK_RATE_HZ) * 1000
		 *
		 *
		 * If configTICK_RATE_HZ is 1000, then vTaskDelay(2000) equals 2000 ms (2 seconds).
		 * If configTICK_RATE_HZ is 2000, then vTaskDelay(2000) equals 1000 ms (1 second).
		 */

		vTaskDelay(1000);
	}
}
/********************************************************************************************************/


/************************************************* LED2 *************************************************/
void vTask7_LED2_ON(void *ptr){
	while(1){

	}
}

void vTask8_LED2_OFF(void *ptr){
	while(1){

	}
}


void vTask9_LED2_TOGGLE(void *ptr){
	while(1){
		LED_voidTOGGLE(DIO_u8PortD, DIO_u8PIN3);
		vTaskDelay(1000);
	}
}
/********************************************************************************************************/
void vTask10_LCD_Write_1(void* ptr){
	while(1){



		if(pdTRUE == xSemaphoreTake(LCD_Key, 0)){

			LCD_enuClearDisplay();
			LCD_u8SendString((uint8_t*)"LCD Task 1");
			xSemaphoreGive(LCD_Key);
		}
		vTaskDelay(1000);
	}

}

void vTask11_LCD_Write_2(void* ptr){
	while(1){

		if(pdTRUE == xSemaphoreTake(LCD_Key, 0)){

			LCD_enuClearDisplay();
			LCD_u8SendString((uint8_t*)"LCD Task 2");
			xSemaphoreGive(LCD_Key);
		}
		vTaskDelay(1000);
	}
}





int main(){
	/*
	 * xTaskCreate(arg1, arg2, arg3, arg4, arg5, arg6)
	 *
	 * 	arg1:   Name of the function that contains the task code.
	 * 	arg2:	Task name in memory (optional parameter, useful for debugging).
	 * 	arg3:	Stack size allocated for the task (specified in words, not bytes).
	 * 	arg4:	Arguments to be passed to the task (use NULL if no parameters).
	 * 	arg5:	Task priority (higher numbers indicate higher priority).
	 * 	arg6:	Task Handle
	 *
	 *
	 *
	 *
	 *	Total SRAM for ATmega32 = 2048 bytes
	 *	used memory for other parts rather than RTOS let's say 512bytes
	 *	the left is 2048-512=1536 bytes
	 *
	 *	stack size per task 1536/{number of tasks} = 384
	 *
	 * */

	xTaskCreate(vTask0_Init, "Initialize Task", configMINIMAL_STACK_SIZE, NULL, 4, &Initialize_Task);
//	xTaskCreate(vTask3_LED0_TOGGLE, "LED0 Toggle", configMINIMAL_STACK_SIZE, NULL, 3, &LED0_Toggle_Task);
//	xTaskCreate(vTask6_LED1_TOGGLE, "LED1 Toggle", configMINIMAL_STACK_SIZE, NULL, 2, &LED1_Toggle_Task);
//	xTaskCreate(vTask9_LED2_TOGGLE, "LED2 Toggle", configMINIMAL_STACK_SIZE, NULL, 1, &LED2_Toggle_Task);

	xTaskCreate(vTask10_LCD_Write_1, "LCD Write Task 1", configMINIMAL_STACK_SIZE, NULL, 3, &LCD_Write_Task1);
//	xTaskCreate(vTask11_LCD_Write_2, "LCD Write Task 2", configMINIMAL_STACK_SIZE, NULL, 3, &LCD_Write_Task2);
	// Uncomment these one at a time to test memory usage

	vTaskStartScheduler();






	while(1){


	}


	return 0;
}

