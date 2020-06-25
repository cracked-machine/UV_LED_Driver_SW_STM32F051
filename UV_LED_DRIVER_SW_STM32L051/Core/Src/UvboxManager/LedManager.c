/*
 * LedManager.c
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */


#include "LedManager.h"
#include "RotaryEncoder.h"
#include "UvboxManager.h"
#include "ILI9341_STM32_Driver.h"


uint32_t previous_encoder_value = 0;

void LM_SetStatusLed(UVBOX_StatusLedTypeDef new_status);

/*
 *
 *	@brief	Enable UV LEDs, disable Normal LEDs
 *
 *	@param 		None
 *	@retval 	UVBOX_SystemStateTypedef - 	UVBOX_LidOpen,
											UVBOX_LidClosed
 *
 */
UVBOX_SystemStateTypedef LM_EnableUVMode()
{
	LM_SetStatusLed(UVBOX_StatusLedGreen);

	UV_PWM_TIMER.Instance->CCR1 = MAX_UVLED_PWM_PERIOD;
	UV_PWM_TIMER.Instance->CCR2 = MAX_UVLED_PWM_PERIOD;
	UV_PWM_TIMER.Instance->CCR3 = MAX_UVLED_PWM_PERIOD;
	UV_PWM_TIMER.Instance->CCR4 = MAX_UVLED_PWM_PERIOD;
	LED_PWM_TIMER.Instance->CCR1 = 0;


	TM_StartTimer();

	return UVBOX_LidClosed;
}

/*
 *
 *	@brief Enable Normal LEDs, disable UV LEDs
 *
 *	@param 		None
 *	@retval 	UVBOX_SystemStateTypedef - 	UVBOX_LidOpen,
											UVBOX_LidClosed
 *
 */
UVBOX_SystemStateTypedef LM_DisableUVMode()
{
	LM_SetStatusLed(UVBOX_StatusLedRed);

	UV_PWM_TIMER.Instance->CCR1 = 0;
	UV_PWM_TIMER.Instance->CCR2 = 0;
	UV_PWM_TIMER.Instance->CCR3 = 0;
	UV_PWM_TIMER.Instance->CCR4 = 0;
	LED_PWM_TIMER.Instance->CCR1 = MAX_LED_PWM_PERIOD;

	TM_StopTimer();
	TM_ResetTimer();

	return UVBOX_LidOpen;
}


/*
 *
 *	@brief Enable Normal LEDs, disable UV LEDs
 *
 *	@param 		UVBOX_EncoderDirTypeDef - 	UVBOX_ENCODER_DOWN = 0x0,
											UVBOX_ENCODER_UP
 *	@retval 	None
 *
 */
void _UpdateUvPwm(UVBOX_EncoderDirTypeDef new_encoder_dir)
{
  	// encoder direction has changed from increasing to decreasing
	if( (RE_getPrevEncoderDir()) && (!new_encoder_dir) )
	{
		UV_PWM_TIMER.Instance->CCR1 -= ENCODER_STEP;
		UV_PWM_TIMER.Instance->CCR2 -= ENCODER_STEP;
		UV_PWM_TIMER.Instance->CCR3 -= ENCODER_STEP;
		UV_PWM_TIMER.Instance->CCR4 -= ENCODER_STEP;

		// clamp lower range integer overflow to
		// MAX_UVLED_PWM_PERIOD+1
		if(	(UV_PWM_TIMER.Instance->CCR1 > MAX_UVLED_PWM_PERIOD+1) ||
			(UV_PWM_TIMER.Instance->CCR2 > MAX_UVLED_PWM_PERIOD+1)	||
			(UV_PWM_TIMER.Instance->CCR3 > MAX_UVLED_PWM_PERIOD+1) ||
			(UV_PWM_TIMER.Instance->CCR4 > MAX_UVLED_PWM_PERIOD+1)
			)
		{
			UV_PWM_TIMER.Instance->CCR1 = 0;
			UV_PWM_TIMER.Instance->CCR2 = 0;
			UV_PWM_TIMER.Instance->CCR3 = 0;
			UV_PWM_TIMER.Instance->CCR4 = 0;
		}

		RE_setPrevEncoderDir( (ROTARY_ENCODER.Instance->CR1 & TIM_CR1_DIR) );
	}
	// encoder direction has changed from decreasing to increasing
	else if( (!RE_getPrevEncoderDir()) && (new_encoder_dir) )
	{
		UV_PWM_TIMER.Instance->CCR1 += ENCODER_STEP;
		UV_PWM_TIMER.Instance->CCR2 += ENCODER_STEP;
		UV_PWM_TIMER.Instance->CCR3 += ENCODER_STEP;
		UV_PWM_TIMER.Instance->CCR4 += ENCODER_STEP;

		// clamp upper range integer overflow to
		// MAX_UVLED_PWM_PERIOD
		if(	(UV_PWM_TIMER.Instance->CCR1 > MAX_UVLED_PWM_PERIOD) ||
			(UV_PWM_TIMER.Instance->CCR2 > MAX_UVLED_PWM_PERIOD)	||
			(UV_PWM_TIMER.Instance->CCR3 > MAX_UVLED_PWM_PERIOD) ||
			(UV_PWM_TIMER.Instance->CCR4 > MAX_UVLED_PWM_PERIOD)
			)
		{
			UV_PWM_TIMER.Instance->CCR1 = MAX_UVLED_PWM_PERIOD;
			UV_PWM_TIMER.Instance->CCR2 = MAX_UVLED_PWM_PERIOD;
			UV_PWM_TIMER.Instance->CCR3 = MAX_UVLED_PWM_PERIOD;
			UV_PWM_TIMER.Instance->CCR4 = MAX_UVLED_PWM_PERIOD;
		}

		RE_setPrevEncoderDir( (ROTARY_ENCODER.Instance->CR1 & TIM_CR1_DIR) );
	}
}


/*
 *
 *	@brief Enable Normal LEDs, disable UV LEDs
 *
 *	@param 		UVBOX_EncoderDirTypeDef - 	UVBOX_ENCODER_DOWN = 0x0,
											UVBOX_ENCODER_UP
 *	@retval 	None
 *
 */
void _UpdateLedPwm(UVBOX_EncoderDirTypeDef new_encoder_dir)
{
	uint16_t top_encoder_limit = 127;
	uint8_t encoder_dir = ((ROTARY_ENCODER.Instance->CR1 & TIM_CR1_DIR) == TIM_CR1_DIR);
	if(encoder_dir)
	{
		if(LED_PWM_TIMER.Instance->CCR1 > 0)
			LED_PWM_TIMER.Instance->CCR1 -= ENCODER_STEP;



	}
	else
	{

		if(LED_PWM_TIMER.Instance->CCR1 < top_encoder_limit)
			LED_PWM_TIMER.Instance->CCR1 += ENCODER_STEP;

	}


/*
	// encoder direction has changed from increasing to decreasing
	if( (RE_getPrevEncoderDir()) && (!new_encoder_dir) )
	{
		LED_PWM_TIMER.Instance->CCR1 -= ENCODER_STEP;

		// clamp lower range integer overflow to
		// MAX_UVLED_PWM_PERIOD+1
		if(	(LED_PWM_TIMER.Instance->CCR1 > MAX_LED_PWM_PERIOD+1) )
		{
			LED_PWM_TIMER.Instance->CCR1 = 0;
		}

		RE_setPrevEncoderDir( (ROTARY_ENCODER.Instance->CR1 & TIM_CR1_DIR) );
	}
	// encoder direction has changed from decreasing to increasing
	else if( (!RE_getPrevEncoderDir()) && (new_encoder_dir) )
	{
		LED_PWM_TIMER.Instance->CCR1 += ENCODER_STEP;

		// clamp upper range integer overflow to
		// MAX_UVLED_PWM_PERIOD
		if(	(LED_PWM_TIMER.Instance->CCR1 > MAX_LED_PWM_PERIOD) )
		{
			LED_PWM_TIMER.Instance->CCR1 = MAX_LED_PWM_PERIOD;
		}

		RE_setPrevEncoderDir( (ROTARY_ENCODER.Instance->CR1 & TIM_CR1_DIR) );
	}

	*/
}

/*
 *
 *	@brief Enable Normal LEDs, disable UV LEDs
 *
 *	@param 		None
 *	@retval 	None
 *
 */
void LM_UpdatePwm()
{
	if(EM_getSystemState())
	{
	  	_UpdateUvPwm( ROTARY_ENCODER.Instance->CR1 & TIM_CR1_DIR );
	}
	else
	{
		_UpdateLedPwm( ROTARY_ENCODER.Instance->CR1 & TIM_CR1_DIR );
	}
}

/*
 *
 *	@brief Set GPIO to sink status LED cathode
 *
 *	@param 		UVBOX_StatusLedTypeDef - 	UVBOX_StatusLedGreen = 0x0,
											UVBOX_StatusLedRed,
											UVBOX_StatusLedBlue
 *	@retval 	None
 *
 */
void LM_SetStatusLed(UVBOX_StatusLedTypeDef new_status)
{
/*
	switch(new_status)
	{
	case UVBOX_StatusLedGreen:
		  HAL_GPIO_WritePin(GPIOA, STATUS_GREEN_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, STATUS_RED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, STATUS_BLUE_Pin, GPIO_PIN_SET);
		break;
	case UVBOX_StatusLedRed:
		  HAL_GPIO_WritePin(GPIOA, STATUS_GREEN_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, STATUS_RED_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, STATUS_BLUE_Pin, GPIO_PIN_SET);
		break;
	case UVBOX_StatusLedBlue:
		  HAL_GPIO_WritePin(GPIOA, STATUS_GREEN_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, STATUS_RED_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA, STATUS_BLUE_Pin, GPIO_PIN_RESET);
		break;
	}
*/
}
