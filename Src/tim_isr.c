#include "stm32l0xx_hal.h"
#include "config.h"
#include "cmsis_os.h"
#include "thread_push.h"
#include "drv_motor.h"

/**
* @brief static global var count tim interrupt
*/
extern uint32_t CNT_TIM_0;/*count tim2--push & sw 0*/
extern uint32_t CNT_TIM_1;/*count tim3--push & sw 1*/
extern uint32_t CNT_TIM_2;/*count tim4--push & sw 2*/

/**
* @brief This func handles tim callback
* @note  will be called more than one times when multi channel be active!
*/
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim){
	switch((uint32_t)htim->Instance){
		case (uint32_t)TIM2:		
		 /* 
		  if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
				CNT_Test_CH1++;
			if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
				CNT_Test_CH2++;
		 */
		  if(CNT_TIM_0 == MAX_SW0_PWM_CNT){ 
				SW0_PWM_Stop();
			}
			if(CNT_TIM_0 == MAX_PUSH0_PWM_CNT){
				PUSH0_PWM_Stop();
				osSignalSet(thread_push_id,signal_push_back);
			}
			if(CNT_TIM_0 == MAX_PUSH0_PWM_CNT*2){
				PUSH0_PWM_Stop();
				osSignalSet(thread_push_id,signal_sw_open);
			}
			if(CNT_TIM_0 == MAX_SW0_PWM_CNT + MAX_PUSH0_PWM_CNT*2){
				CNT_TIM_0 = 0;
				SW0_PWM_Stop();
			}	
		/*
			switch(CNT_TIM_0){
				case MAX_SW0_PWM_CNT:
					SW0_PWM_Stop();
					break;
				case MAX_PUSH0_PWM_CNT:
					PUSH0_PWM_Stop();
				  osSignalSet(thread_push_id,signal_push_back);
					break;
				case MAX_PUSH0_PWM_CNT*2:
					PUSH0_PWM_Stop();
			  	osSignalSet(thread_push_id,signal_sw_open);
					break;
				case MAX_SW0_PWM_CNT + MAX_PUSH0_PWM_CNT*2:
					CNT_TIM_0 = 0;
				  SW0_PWM_Stop();
					break;
			}
			*/
			break;/*end of case TIM2*/
		
		case (uint32_t)TIM3:		
		  if(CNT_TIM_1 == MAX_SW1_PWM_CNT){
				SW1_PWM_Stop();
			}
			if(CNT_TIM_1 == MAX_SW1_PWM_CNT + MAX_PUSH1_PWM_CNT*2){
				CNT_TIM_1 = 0;
				SW1_PWM_Stop();
			}
			if(CNT_TIM_1 == MAX_PUSH1_PWM_CNT){
				PUSH1_PWM_Stop();
				osSignalSet(thread_push_id,signal_push_back);
			}
			if(CNT_TIM_1 == MAX_PUSH1_PWM_CNT*2){
				
				PUSH1_PWM_Stop();
				osSignalSet(thread_push_id,signal_sw_open);
			}
			break;/*end of case TIM3*/
		
		case (uint32_t)TIM21:
		  if(CNT_TIM_2 == MAX_SW2_PWM_CNT){
				SW2_PWM_Stop();
			}
			if(CNT_TIM_2 == MAX_SW2_PWM_CNT + MAX_PUSH2_PWM_CNT*2){
				CNT_TIM_2 = 0;
				SW2_PWM_Stop();
			}	
			if(CNT_TIM_2 == MAX_PUSH2_PWM_CNT){
				PUSH2_PWM_Stop();
				osSignalSet(thread_push_id,signal_push_back);
			}
			if(CNT_TIM_2 == MAX_PUSH2_PWM_CNT*2){
				
				PUSH2_PWM_Stop();
				osSignalSet(thread_push_id,signal_sw_open);
			}
			break;/*end of case TIM4*/
	}
}
