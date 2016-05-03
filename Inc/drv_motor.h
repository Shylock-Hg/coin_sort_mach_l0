#ifndef _DRV_MOTOR_H_
#define _DRV_MOTOR_H_

#include "stm32l0xx_hal.h"
#include "tim.h"

/**
* @addtogroup drv_motor
* @{
*/


/**
* @brief PART 1
*/

/**
* @brief close sw0
* @step  enable drv  of steper motor,
*				 mesure dir  of steper motor,
*        start  step of steper motor, 
*/
#define SW0_Close() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir0_Pin,GPIO_PIN_SET);\
	HAL_TIM_PWM_Start_IT(&htim2,TIM_CHANNEL_1);\
}while(0)

#define SW0_Open() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir0_Pin,GPIO_PIN_RESET);\
	HAL_TIM_PWM_Start_IT(&htim2,TIM_CHANNEL_1);\
}while(0)

/**
* @brief stop sw0 pwm
* @step  disalble drv  of stepper motor,
*        stop     step of stepper motor
*/
#define SW0_PWM_Stop() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);\
	HAL_TIM_PWM_Stop_IT(&htim2,TIM_CHANNEL_1);\
}while(0)

#define PUSH0_Forward() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir1_Pin,GPIO_PIN_SET);\
	HAL_TIM_PWM_Start_IT(&htim2,TIM_CHANNEL_2);\
}while(0)

#define PUSH0_Back() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir1_Pin,GPIO_PIN_RESET);\
	HAL_TIM_PWM_Start_IT(&htim2,TIM_CHANNEL_2);\
}while(0)

#define PUSH0_PWM_Stop() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);\
	HAL_TIM_PWM_Stop_IT(&htim2,TIM_CHANNEL_2);\
}while(0)

	

/**
* @brief PART 1
*/
#define SW1_Close() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir2_Pin,GPIO_PIN_SET);\
	HAL_TIM_PWM_Start_IT(&htim3,TIM_CHANNEL_1);\
}while(0)

#define SW1_Open() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir2_Pin,GPIO_PIN_RESET);\
	HAL_TIM_PWM_Start_IT(&htim3,TIM_CHANNEL_1);\
}while(0)

#define SW1_PWM_Stop() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET);\
	HAL_TIM_PWM_Stop_IT(&htim3,TIM_CHANNEL_1);\
}while(0)

#define PUSH1_Forward() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir3_Pin,GPIO_PIN_SET);\
	HAL_TIM_PWM_Start_IT(&htim3,TIM_CHANNEL_2);\
}while(0)

#define PUSH1_Back() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir3_Pin,GPIO_PIN_RESET);\
	HAL_TIM_PWM_Start_IT(&htim3,TIM_CHANNEL_2);\
}while(0)

#define PUSH1_PWM_Stop() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);\
	HAL_TIM_PWM_Stop_IT(&htim3,TIM_CHANNEL_2);\
}while(0)


	
/**
* @brief PART 2
*/
#define SW2_Close() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir4_Pin,GPIO_PIN_SET);\
	HAL_TIM_PWM_Start_IT(&htim21,TIM_CHANNEL_1);\
}while(0)

#define SW2_Open() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir4_Pin,GPIO_PIN_RESET);\
	HAL_TIM_PWM_Start_IT(&htim21,TIM_CHANNEL_1);\
}while(0)

#define SW2_PWM_Stop() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);\
	HAL_TIM_PWM_Stop_IT(&htim21,TIM_CHANNEL_1);\
}while(0)

#define PUSH2_Forward() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir5_Pin,GPIO_PIN_SET);\
	HAL_TIM_PWM_Start_IT(&htim21,TIM_CHANNEL_2);\
}while(0)

#define PUSH2_Back() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);\
	HAL_GPIO_WritePin(GPIOA,dir5_Pin,GPIO_PIN_RESET);\
	HAL_TIM_PWM_Start_IT(&htim21,TIM_CHANNEL_2);\
}while(0)

#define PUSH2_PWM_Stop() do{\
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);\
	HAL_TIM_PWM_Stop_IT(&htim21,TIM_CHANNEL_2);\
}while(0)

	
/**
* @}
*/

#endif

