/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 May 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "LEDMTX_int.h"


void HLEDMTX_vInit(void)
{
	#if (LEDS_SETUP != COLS_ANODE) && (LEDS_SETUP != COLS_CATHODE)
		#error "Invalid LEDs setup, the columns of the LED matrix is either connected to Anode or Cathode"

	#else

	#endif
}


/*******************************************************************/


Bool HLEDMTX_BoolDispFrame(LEDMTX_cfg* LEDMTXCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	for(u8 L_u8LEDsIndex = 0; L_u8LEDsIndex < 128; L_u8LEDsIndex++)
	{
		if(((LEDMTXCfgPtConfigPtr->LEDsCfg_arr)[L_u8LEDsIndex]) != 0 && ((LEDMTXCfgPtConfigPtr->LEDsCfg_arr)[L_u8LEDsIndex]) != 1)
		{
			L_BoolErrorState = 0;
			L_u8LEDsIndex = 130;
		}

	}


	/*Col1 values
	delay 2.5ms

	Col2 values
	delay 2.5ms

	Col3 values
    delay 2.5ms

	Col4 values
	delay 2.5ms

	Col5 values
	delay 2.5ms

	Col6 values
	delay 2.5ms

	Col7 values
	delay 2.5ms

	Col8 values
	delay 2.5ms*/

	return L_BoolErrorState;
}
