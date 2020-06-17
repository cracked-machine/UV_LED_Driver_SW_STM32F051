/*
 * UVBOX_Manager.h
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */

#ifndef SRC_UVBOX_MANAGER_UVBOX_MANAGER_H_
#define SRC_UVBOX_MANAGER_UVBOX_MANAGER_H_

// STM32Cube-generated HAL declarations
#include "tim.h"
#include "gpio.h"

// application peripherals
#define UV_PWM_TIMER htim1
#define LED_PWM_TIMER htim14
#define ROTARY_ENCODER htim2
#define DEBOUNCE_TIMER htim17

#define MAX_DEBOUNCE_DELAY 175

void UM_Setup();
void UM_EXTI0_1_IRQHandler();

void UM_SetLastDebounceTime(uint16_t pDebounceTime);
uint16_t UM_getLastDebounceTime();

#endif /* SRC_UVBOX_MANAGER_UVBOX_MANAGER_H_ */
