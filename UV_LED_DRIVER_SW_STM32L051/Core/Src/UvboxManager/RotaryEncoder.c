/*
 * RotaryEncoder.c
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */


#include "RotaryEncoder.h"
#include "UvboxManager.h"

uint8_t RE_getPrevEncoderDir();


UVBOX_EncoderDirTypeDef previous_encoder_dir;

/*
 *
 *	@brief	Rotary encoder timer setup
 *
 *	@param 	None
 *	@retval None
 *
 */
void RE_Setup()
{
	HAL_TIM_Encoder_Start_IT(&ROTARY_ENCODER, TIM_CHANNEL_ALL);
	ROTARY_ENCODER.Instance->CNT = 32767;
}

/*
 *
 *	@brief accessor for encoder direction
 *
 *	@param		None
 *	@retval 	UVBOX_EncoderDirTypeDef - 	UVBOX_ENCODER_DOWN = 0x0,
											UVBOX_ENCODER_UP
 *
 */
UVBOX_EncoderDirTypeDef RE_getPrevEncoderDir()
{
	return previous_encoder_dir;
}

/*
 *
 *	@brief
 *
 *	@param		UVBOX_EncoderDirTypeDef - 	UVBOX_ENCODER_DOWN = 0x0,
											UVBOX_ENCODER_UP
 *	@retval 	None
 *
 */
void RE_setPrevEncoderDir(UVBOX_EncoderDirTypeDef direction)
{
	previous_encoder_dir = direction;
}
