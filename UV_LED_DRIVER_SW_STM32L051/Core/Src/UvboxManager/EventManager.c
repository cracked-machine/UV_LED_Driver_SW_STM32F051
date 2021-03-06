/*
 * EventManager.c
 *
 *  Created on: Jun 17, 2020
 *      Author: chris
 */

#include "EventManager.h"
#include "LedManager.h"


UVBOX_SystemStateTypedef eTheSystemState = UVBOX_TimerExpired;


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

	case UVBOX_TimerRunning:


			switch(newEvent)
			{
				case UVBOX_evStopTimer:
					eTheSystemState = LM_DisableUVMode();	//UVBOX_TimerExpired
					break;

				case UVBOX_evResetTimer:
					eTheSystemState = LM_DisableUVMode(0);	//UVBOX_TimerExpired
					eTheSystemState = UVBOX_TimerReset;	//UVBOX_TimerReset
					break;

				case UVBOX_evStartTimer:
					// do nothing
					break;
			}

		break;

	case UVBOX_TimerExpired:

		switch(newEvent)
		{
			case UVBOX_evStopTimer:
				eTheSystemState = LM_DisableUVMode();	//UVBOX_TimerExpired
				break;

			case UVBOX_evResetTimer:
				eTheSystemState = UVBOX_TimerReset;	//UVBOX_TimerReset

				break;

			case UVBOX_evStartTimer:
				// do nothing, locked out until reset
				break;
		}

		break;

	case UVBOX_TimerReset:

		switch(newEvent)
		{
			case UVBOX_evStopTimer:
				eTheSystemState = LM_DisableUVMode();	//UVBOX_TimerExpired
				break;

			case UVBOX_evResetTimer:
				//eTheSystemState = LM_DisableUVMode(1);	//UVBOX_TimerReset

				break;

			case UVBOX_evStartTimer:
				eTheSystemState = LM_EnableUVMode();	//UVBOX_TimerRunning
				break;
		}

		break;
/*
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

		case UVBOX_TimerExpired:

			switch(newEvent)
			{
				case UVBOX_evLidOpened:
					eTheSystemState = LM_DisableUVMode();
					break;

				case UVBOX_evTimerExpired:
					eTheSystemState = UVBOX_TimerExpired;
					break;

				default:
					break;
			}

			break;
*/

	}
}

