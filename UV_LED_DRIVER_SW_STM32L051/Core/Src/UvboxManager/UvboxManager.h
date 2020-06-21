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

#include "TimeoutManager.h"
#include "EventManager.h"

#include "ILI9341_STM32_Driver.h"
#include "ILI9341_GFX.h"

// application peripherals
#define UV_PWM_TIMER 	htim1
#define LED_PWM_TIMER 	htim14
#define ROTARY_ENCODER 	htim2
#define DEBOUNCE_TIMER 	htim17
#define EXPOSE_TIMER	htim3

#define MAX_DEBOUNCE_DELAY 175

void UM_Setup();
void UM_EXTI0_1_IRQHandler();
void UM_EXTI2_3_IRQHandler();

void UM_SetLastDebounceTime(uint16_t pDebounceTime);
uint16_t UM_getLastDebounceTime();

void UM_UpdateDisplay();
void UM_DisplayAsMinutesAndSeconds(uint16_t seconds);

void UM_DisplayRunningMsg();
void UM_DisplayExpiredMsg();

#endif /* SRC_UVBOX_MANAGER_UVBOX_MANAGER_H_ */
