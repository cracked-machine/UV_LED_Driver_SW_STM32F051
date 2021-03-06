/*
 * LedManager.h
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */

#ifndef SRC_UVBOXMANAGER_LEDMANAGER_H_
#define SRC_UVBOXMANAGER_LEDMANAGER_H_


#include "EventManager.h"
#include <stdint.h>

#define MAX_UVLED_PWM_PERIOD	160
#define MAX_LED_PWM_PERIOD		0xFFFF

typedef enum
{
	UVBOX_StatusLedGreen = 0x0,
	UVBOX_StatusLedRed,
	UVBOX_StatusLedBlue

} UVBOX_StatusLedTypeDef;

UVBOX_SystemStateTypedef LM_DisableUVMode();
UVBOX_SystemStateTypedef LM_EnableUVMode();
void LM_SetStatusLed(UVBOX_StatusLedTypeDef new_status);

void LM_UpdatePwm();

#endif /* SRC_UVBOXMANAGER_LEDMANAGER_H_ */
