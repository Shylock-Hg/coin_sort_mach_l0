#ifndef _LOWP_H_
#define _LOWP_H_

#include "stm32f4xx_hal.h"

extern void PreSleepProcessing(uint32_t * ulExpectedIdleTime);

extern void PostSleepProcessing(uint32_t * ulExpectedIdleTime);
	
#endif