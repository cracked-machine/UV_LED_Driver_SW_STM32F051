/*
 * EventManager.c
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */

#include "EventManager.h"
#include "LedManager.h"


UVBOX_SystemStateTypedef eTheSystemState = UVBOX_LidOpen;


/*
 *
 *	@brief return the system lid status
 *
 *	@param None
 *	@retval UVBOX_SystemStateTypedef - 	UVBOX_LidOpen,
										UVBOX_LidClosed
 *
 */
UVBOX_SystemStateTypedef 	EM_getSystemState()
{
	return eTheSystemState;
}


/*
 *
 *	@brief	Process new event and update system state
 *
 *	@param 	UVBOX_SystemEventsTypedef - 	UVBOX_evLidOpened,
											UVBOX_evLidClosed,
 *	@retval None
 *
 */
void EM_ProcessEvent(UVBOX_SystemEventsTypedef newEvent)
{
	switch(eTheSystemState)
	{

		case UVBOX_LidOpen:

			switch(newEvent)
			{
				case UVBOX_evLidClosed:
					eTheSystemState = LM_EnableUVMode();
					break;

				default:
					break;
			}

			break;

		case UVBOX_LidClosed:

			switch(newEvent)
			{
				case UVBOX_evLidOpened:
					eTheSystemState = LM_DisableUVMode();
					break;

				default:
					break;
			}

			break;
	}
}

