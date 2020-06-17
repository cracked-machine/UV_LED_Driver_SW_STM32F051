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
	UVBOX_LidOpen = 0x0,
	UVBOX_LidClosed

} UVBOX_SystemStateTypedef;

typedef enum
{
	UVBOX_evLidOpened = 0x0,
	UVBOX_evLidClosed,
} UVBOX_SystemEventsTypedef;





UVBOX_SystemStateTypedef 	EM_getSystemState();

void EM_ProcessEvent(UVBOX_SystemEventsTypedef newEvent);

#endif /* SRC_UVBOXMANAGER_EVENTMANAGER_H_ */
