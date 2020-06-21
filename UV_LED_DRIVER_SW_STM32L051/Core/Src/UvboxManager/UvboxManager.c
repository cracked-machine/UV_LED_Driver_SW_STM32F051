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

#define BGCOLOUR		BLACK
#define	SYSTEXT			WHITE
#define TIMETEXT		BLUE
#define RUNTEXT			GREEN
#define	STOPTEXT		RED

//UVBOX_LidStatusTypedef eLidStatus = UVBOX_LIDOPEN;
uint16_t debounce_last_interrupt_time = 0;


void UM_DisplayRunningMsg()
{
	ILI9341_Fill_Screen(BLACK);
	ILI9341_Draw_Text("RUNNING", 10, 120, RUNTEXT, 7, BGCOLOUR);
}

void UM_DisplayExpiredMsg()
{
	ILI9341_Fill_Screen(BLACK);
	ILI9341_Draw_Text("STOPPED", 10, 120, STOPTEXT, 7, BGCOLOUR);
}

/*
 *
 *	@brief
 *
 *	@param None
 *	@retval None
 *
 */
void UM_UpdateDisplay()
{
	UM_DisplayAsMinutesAndSeconds(TM_GetTimerCount());

}

/*
 *
 *	@brief	Display seconds as MM::SS formatted string
 *
 *	@param pSeconds
 *	@retval None
 *
 */
void UM_DisplayAsMinutesAndSeconds(uint16_t pSeconds)
{
	uint8_t minutes = 0;
	uint8_t seconds = 0;

	minutes = pSeconds / 60;
	seconds = pSeconds % 60;

	char timer_count[30];
	snprintf(timer_count, sizeof(timer_count), "%02d:%02d", minutes, seconds);
	ILI9341_Draw_Text(timer_count, 30, 50, TIMETEXT, 9, BGCOLOUR);
}


/*
 *
 *	@brief	Init System
 *
 *	@param None
 *	@retval None
 *
 */
void UM_Setup()
{
	  // enable TFT ILI9341 driver
	  ILI9341_Init();
	  ILI9341_Set_Rotation(SCREEN_HORIZONTAL_2);
	  ILI9341_Fill_Screen(BLACK);
	  ILI9341_Draw_Text("INITIALISING...", 10, 10, SYSTEXT, 1, BGCOLOUR);

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
	  LED_PWM_TIMER.Instance->CCR1 	= MAX_LED_PWM_PERIOD;

	  // debounce timer
	  HAL_TIM_Base_Start( &DEBOUNCE_TIMER );

	  // status output LED
	  LM_SetStatusLed(UVBOX_StatusLedBlue);

	  // rotary encoder
	  RE_Setup();


	  HAL_Delay(100);
	  ILI9341_Draw_Text("READY!", 100, 10, SYSTEXT, 1, BGCOLOUR);



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
		if(EM_getSystemState())	// LID CLOSED
		{
			//EM_ProcessEvent(UVBOX_evLidOpened);
		}
		else
		{
			TM_UserIncrementTimer();
		}
	}
	UM_SetLastDebounceTime(debounce_interrupt_time);
}

/*
 *
 *	@brief	wrapper for lid button external interrupt line 0 (EXT0)
 *
 *	@param None
 *	@retval None
 *
 */
void UM_EXTI2_3_IRQHandler()
{
	uint16_t debounce_interrupt_time = DEBOUNCE_TIMER.Instance->CNT;
	if ((debounce_interrupt_time - UM_getLastDebounceTime()) > MAX_DEBOUNCE_DELAY)
	{
		if(EM_getSystemState())	// LID CLOSED
		{
			EM_ProcessEvent(UVBOX_evLidOpened);
		}
		else
		{
			EM_ProcessEvent(UVBOX_evLidClosed);
		}
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


