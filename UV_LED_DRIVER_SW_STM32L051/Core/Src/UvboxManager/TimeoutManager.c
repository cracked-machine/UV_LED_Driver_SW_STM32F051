/*
 * TimeoutManager.c
 *
 *  Created on: Jun 21, 2020
 *      Author: chris
 */

#include "TimeoutManager.h"
#include "UvboxManager.h"

#define DEFAULT_TIMEOUT 60
uint16_t user_defined_timeout = DEFAULT_TIMEOUT;		// seconds
uint16_t timer_count = DEFAULT_TIMEOUT;

void TM_ResetTimer()
{
	timer_count = DEFAULT_TIMEOUT;
}

void TM_UserIncrementTimer()
{
	user_defined_timeout += 10;
	timer_count += 10;
}

void TM_UserDecrementTimer()
{
	user_defined_timeout -= 10;
	timer_count -= 10;
}


void TM_DecrementTimer()
{
	timer_count--;

	TM_CheckTimer();
}

uint16_t TM_GetTimerCount()
{
	return timer_count;
}

void TM_CheckTimer()
{
	if(timer_count == 0)
	{
		EM_ProcessEvent(UVBOX_evLidOpened);
	}
}

void TM_StartTimer()
{
	EXPOSE_TIMER.Instance->SR &= ~(TIM_SR_UIF);	// reset
	HAL_TIM_Base_Start_IT(&EXPOSE_TIMER);
	UM_DisplayRunningMsg();
}

void TM_StopTimer()
{
	HAL_TIM_Base_Stop_IT(&EXPOSE_TIMER);
	UM_DisplayExpiredMsg();
}

