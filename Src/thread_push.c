#include "cmsis_os.h"
#include "config.h"
#include "stm32l0xx_hal.h"
#include "tim.h"

#include "drv_motor.h"
/**
* @brief def thread_push_id
*/
osThreadId thread_push_id;

/**
* @brief def mesq_id
*/
osMessageQId mesq_id;

/**
* @brief def thread_push func
*/
void thread_push_entry(void const * arg){
	while(1){
		osEvent e = osMessageGet(mesq_id,osWaitForever);
		switch(e.value.v){
			case GPIO_PIN_0:
				//SW0 closed
			  SW0_Close();
			  PUSH0_Forward();
			  //HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);/*test ok! reached!*/
			
			  //wait to push back
			  osSignalWait(signal_push_back,osWaitForever);
				PUSH0_Back();
				//HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);/*test ok! reached!*/
			
			  //wait to sw open
				osSignalWait(signal_sw_open,osWaitForever);
				SW0_Open();
        //HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);/*test ok! reached!*/
				break;

			case GPIO_PIN_1:
				//SW1 closed
			  SW1_Close();
			  PUSH1_Forward();
			  
			  //wait to push back
			  osSignalWait(signal_push_back,osWaitForever);
				PUSH1_Back();
			
			  //wait to sw open
				osSignalWait(signal_sw_open,osWaitForever);
				SW1_Open();
				break;
			
			case GPIO_PIN_2:
				//SW2 closed
			  SW2_Close();
			  PUSH2_Forward();
			  
			  //wait to push back
			  osSignalWait(signal_push_back,osWaitForever);
				PUSH2_Back();
			
			  //wait to sw open
				osSignalWait(signal_sw_open,osWaitForever);
				SW2_Open();
				break;
			
			case GPIO_PIN_13:
				break;
		}/*end of switch*/
		
	}
}
