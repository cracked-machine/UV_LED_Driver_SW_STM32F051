/*
 * EventManager.h
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */

#ifndef SRC_UVBOXMANAGER_EVENTMANAGER_H_
#define SRC_UVBOXMANAGER_EVENTMANAGER_H_

typedef enum
{
	UVBOX_TimerReset = 0x0,
	UVBOX_TimerRunning,
	UVBOX_TimerExpired
			// timer has expired and lid has been lifted
} UVBOX_SystemStateTypedef;

typedef enum
{
	UVBOX_evStartTimer = 0x0,
	UVBOX_evStopTimer,
	UVBOX_evResetTimer

} UVBOX_SystemEventsTypedef;





UVBOX_SystemStateTypedef 	EM_getSystemState();

void EM_ProcessEvent(UVBOX_SystemEventsTypedef newEvent);

#endif /* SRC_UVBOXMANAGER_EVENTMANAGER_H_ */
