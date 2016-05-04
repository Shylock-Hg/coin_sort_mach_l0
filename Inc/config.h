#ifndef _CONFIG_H_
#define _CONFIG_H_


/**
* @brief def pwm priority
* @note  tim clock 2.097MHz
*/
#define PWM_Period 418
#define PWM_Pulse  209

#define MesQ_Size 10

#define MAX_Coin_CNT 5


/**
* @note SW_PWM <= PUSH_PWM
*/
#define MAX_SW0_PWM_CNT   450
#define MAX_PUSH0_PWM_CNT 4988

#define MAX_SW1_PWM_CNT   900
#define MAX_PUSH1_PWM_CNT 1000

#define MAX_SW2_PWM_CNT   900
#define MAX_PUSH2_PWM_CNT 1000
/**********************signal def***********************/
typedef enum {signal_push_back, //push back start
							signal_sw_open    //sw open start
						 } signal;

/**********************footprint map********************/
/*
TIM2
	CH1--SW0    dir0--PA8  EN--PB0
	CH2--PUSH0  dir1--PA9  EN--PB1
TIM3
	CH1
	CH2
TIM4
  CH1
  CH2
DIR
	PA8 9 10 11 12 15
EN
	PB0 1 2  3  4  5
EXTI 0 1 2
	 PC0 1 2
  
*/
						 
#endif
