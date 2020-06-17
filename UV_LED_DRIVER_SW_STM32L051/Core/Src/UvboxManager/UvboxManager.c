/*
 * UVBOX_Manager.c
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */


#include "UvboxManager.h"
#include "RotaryEncoder.h"
#include "EventManager.h"
#include "LedManager.h"

//UVBOX_LidStatusTypedef eLidStatus = UVBOX_LIDOPEN;
uint16_t debounce_last_interrupt_time = 0;


/*
 *
 *	@brief
 *
 *	@param None
 *	@retval None
 *
 */
void UM_Setup()
{

	  // PWM OUTPUTS

	  HAL_TIM_PWM_Start( &UV_PWM_TIMER, TIM_CHANNEL_1 );
	  HAL_TIM_PWM_Start( &UV_PWM_TIMER, TIM_CHANNEL_2 );
	  HAL_TIM_PWM_Start( &UV_PWM_TIMER, TIM_CHANNEL_3 );
	  HAL_TIM_PWM_Start( &UV_PWM_TIMER, TIM_CHANNEL_4 );
	  HAL_TIM_PWM_Start( &LED_PWM_TIMER, TIM_CHANNEL_1 );

	  UV_PWM_TIMER.Instance->ARR	= 0xFF;		// 	255
	  UV_PWM_TIMER.Instance->CCR1 	= 0x00;
	  UV_PWM_TIMER.Instance->CCR2 	= 0x00;
	  UV_PWM_TIMER.Instance->CCR3 	= 0x00;
	  UV_PWM_TIMER.Instance->CCR4 	= 0x00;

	  LED_PWM_TIMER.Instance->ARR  	= 0xFF;		// 	255
	  LED_PWM_TIMER.Instance->CCR1 	= MAX_ENCODER_LIMIT;

	  // debounce timer
	  HAL_TIM_Base_Start( &DEBOUNCE_TIMER );

	  // status output LED
	  LM_SetStatusLed(UVBOX_StatusLedBlue);

	  // rotary encoder
	  RE_Setup();

}

/*
 *
 *	@brief	wrapper for lid button external interrupt line 0 (EXT0)
 *
 *	@param None
 *	@retval None
 *
 */
void UM_EXTI0_1_IRQHandler()
{
	uint16_t debounce_interrupt_time = DEBOUNCE_TIMER.Instance->CNT;
	if ((debounce_interrupt_time - UM_getLastDebounceTime()) > MAX_DEBOUNCE_DELAY)
	{
		if(EM_getSystemState())
			EM_ProcessEvent(UVBOX_evLidOpened);
		else
			EM_ProcessEvent(UVBOX_evLidClosed);
	}
	UM_SetLastDebounceTime(debounce_interrupt_time);
}

/*
 *
 *	@brief set debounce last time
 *
 *	@param pDebounceTime
 *	@retval None
 *
 */
void UM_SetLastDebounceTime(uint16_t pDebounceTime)
{
	debounce_last_interrupt_time = pDebounceTime;
}

/*
 *
 *	@brief get debounce last time
 *
 *	@param None
 *	@retval debounce_last_interrupt_time
 *
 */
uint16_t UM_getLastDebounceTime()
{
	return debounce_last_interrupt_time;
}

