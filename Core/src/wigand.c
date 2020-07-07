/* INCLUDES ********************************************************************************/
/***********************************************************************************************/
#include "wigand.h"

/* FUNCTIONS ******************************************************************************/
/***********************************************************************************************/

void BitRecive(uint8_t tape)
{
	// Check if previous byte package converting is finish
	if(vWigandStart)
		{
			vWigandStart = 0; vBuffIndex = 0;
			vProcessing = 1;
			// Start TIM1 сountdown to launch byte package converting
			TIM1->CR1 |= TIM_CR1_CEN;
		}

	// Write input bite to aWigandBuff while vProcessing == 1
	if(vProcessing)		aWigandBuff[vBuffIndex++] = (tape == DATA_0) ? 0:1;
}
/****************************************************/
/****************************************************/

void BitePackageWaiting(void)
{
	//	 Waiting until vBitePackageReceipt flag is set
	while( ! vBitePackageReceipt);

	// Wigand tipe check and parity value set
	if(WigandTapeCheck())
	{
		WigandProcessing();
	}
	else
	{
		WigandTapeCheck_Error_Handler();
	}
}
/****************************************************/
/****************************************************/

uint8_t WigandTapeCheck(void)
{

// This block allows you to add other wigand types
	switch(vBuffIndex)
		{
			case 26:
				vParity = PARITY_2;
							return 1;
									break;
			/*case 40:
				vParity = PARITY_0;
							return 1;
								break;*/
			default:
				vParity = 0;
							return 0;
		}
}
/****************************************************/
/****************************************************/

void WigandProcessing(void)
	{
		// Convert aWigandBuff UID to HEX format and send byte package.

	// Finishing convert and send byte package clear flags
		vWigandStart = 1;
		vBitePackageReceipt = 0;

		// Looping code (because it demo)
		BitePackageWaiting();
	}
/****************************************************/
/****************************************************/

void WigandTapeCheck_Error_Handler(void)
	{
		// add your code here
	}
/****************************************************/
/****************************************************/
