#include "stm32l0xx_hal.h"
#include "config.h"
#include "cmsis_os.h"
#include "thread_push.h"
#include "drv_motor.h"

/**
* @brief static global var count tim interrupt
*/
static uint32_t CNT_TIM_0 = 0;/*count tim2--push & sw 0*/
static uint32_t CNT_TIM_1 = 0;/*count tim3--push & sw 1*/
static uint32_t CNT_TIM_2 = 0;/*count tim4--push & sw 2*/

/**
* @brief This func handles tim callback
*/
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim){
	switch((uint32_t)htim->Instance){
		case (uint32_t)TIM2:		
			CNT_TIM_0++;
			if(CNT_TIM_0 == MAX_SW0_PWM_CNT){ /*happen 0*/
				SW0_PWM_Stop();
			}
			if(CNT_TIM_0 == MAX_SW0_PWM_CNT + MAX_PUSH0_PWM_CNT*2){/*happen 3*/
				CNT_TIM_0 = 0;
				SW0_PWM_Stop();
			}
			if(CNT_TIM_0 == MAX_PUSH0_PWM_CNT){/*happen 1*/
				PUSH0_PWM_Stop();
				osSignalSet(thread_push_id,signal_push_back);
			}
			if(CNT_TIM_0 == MAX_PUSH0_PWM_CNT*2){/*happen 2*/
				PUSH0_PWM_Stop();
				osSignalSet(thread_push_id,signal_sw_open);
			}
			break;/*end of case TIM2*/
		
		case (uint32_t)TIM3:		
			CNT_TIM_1++;
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
			CNT_TIM_2++;
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
