/*
 * RotaryEncoder.h
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */

#ifndef SRC_UVBOXMANAGER_ROTARYENCODER_H_
#define SRC_UVBOXMANAGER_ROTARYENCODER_H_

#include <stdint.h>

typedef enum
{
	UVBOX_ENCODER_DOWN = 0x0,
	UVBOX_ENCODER_UP

} UVBOX_EncoderDirTypeDef;

// step increment/decrement value for PWM registers
#define ENCODER_STEP	128

void RE_Setup();

UVBOX_EncoderDirTypeDef RE_getPrevEncoderDir();
void RE_setPrevEncoderDir(UVBOX_EncoderDirTypeDef direction);

#endif /* SRC_UVBOXMANAGER_ROTARYENCODER_H_ */
