/*
 * TimeoutManager.h
 *
 *  Created on: Jun 21, 2020
 *      Author: chris
 */

#ifndef SRC_UVBOXMANAGER_TIMEOUTMANAGER_H_
#define SRC_UVBOXMANAGER_TIMEOUTMANAGER_H_

#include <stdint.h>

void TM_ResetTimer();
void TM_DecrementTimer();
uint16_t TM_GetTimerCount();
void TM_CheckTimer();
void TM_StartTimer();
void TM_StopTimer();

void TM_UserIncrementTimer();
void TM_UserDecrementTimer();

#endif /* SRC_UVBOXMANAGER_TIMEOUTMANAGER_H_ */
