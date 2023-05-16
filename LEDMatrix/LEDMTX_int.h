/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 May 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef HAL_LEDMTX_INT_H_
#define HAL_LEDMTX_INT_H_

#include "LEDMTX_prv.h"


#define     ROWS_NUM      8
#define     COLS_NUM      8
#define     LEDS_SETUP    COLS_ANODE

/*Please refer to LEDNumbers.jpg in order to understand the LED numbering I created in this driver*/
/*Please notice that the 64 bits for LEDs configuration must follow this order :
  LED64 LED63 LED62 ... LED3 LED2 LED1         where LED1 is the LSB and LED64 is the MSB*/


typedef union
{
	u32 LEDsCfg_arr[4];

	typedef struct
	{
		/*These 64 bits are used to configure which LEDS are ON and
		  which are OFF.
		  Bit value = 1 -----> LED is ON, bit value = 0 -----> LED is OFF*/
		u32 LED1  : 1;
		u32 LED2  : 1;
		u32 LED3  : 1;
		u32 LED4  : 1;
		u32 LED5  : 1;
		u32 LED6  : 1;
		u32 LED7  : 1;
		u32 LED8  : 1;
		u32 LED9  : 1;
		u32 LED10 : 1;
		u32 LED11 : 1;
		u32 LED12 : 1;
		u32 LED13 : 1;
		u32 LED14 : 1;
		u32 LED15 : 1;
		u32 LED16 : 1;
		u32 LED17 : 1;
		u32 LED18 : 1;
		u32 LED19 : 1;
		u32 LED20 : 1;
		u32 LED21 : 1;
		u32 LED22 : 1;
		u32 LED23 : 1;
		u32 LED24 : 1;
		u32 LED25 : 1;
		u32 LED26 : 1;
		u32 LED27 : 1;
		u32 LED28 : 1;
		u32 LED29 : 1;
		u32 LED30 : 1;
		u32 LED31 : 1;
		u32 LED32 : 1;
		u32 LED33 : 1;
		u32 LED34 : 1;
		u32 LED35 : 1;
		u32 LED36 : 1;
		u32 LED37 : 1;
		u32 LED38 : 1;
		u32 LED39 : 1;
		u32 LED40 : 1;
		u32 LED41 : 1;
		u32 LED42 : 1;
		u32 LED43 : 1;
		u32 LED44 : 1;
		u32 LED45 : 1;
		u32 LED46 : 1;
		u32 LED47 : 1;
		u32 LED48 : 1;
		u32 LED49 : 1;
		u32 LED50 : 1;
		u32 LED51 : 1;
		u32 LED52 : 1;
		u32 LED53 : 1;
		u32 LED54 : 1;
		u32 LED55 : 1;
		u32 LED56 : 1;
		u32 LED57 : 1;
		u32 LED58 : 1;
		u32 LED59 : 1;
		u32 LED60 : 1;
		u32 LED61 : 1;
		u32 LED62 : 1;
		u32 LED63 : 1;
		u32 LED64 : 1;

/***************************************************/
		/*These 64 bits are used to configure which LEDS are RED and
		  which are GREEN.
		  Bit value = 1 -----> LED is RED, bit value = 0 -----> LED is GREEN*/
		/*Notice that writing on these 64 bits has effect only if the corresponding bit
		 in the 64 bits above equals 1.*/
		u32 LED1Col  : 1;
		u32 LED2Col  : 1;
		u32 LED3Col  : 1;
		u32 LED4Col  : 1;
		u32 LED5Col  : 1;
		u32 LED6Col  : 1;
		u32 LED7Col  : 1;
		u32 LED8Col  : 1;
		u32 LED9Col  : 1;
		u32 LED10Col : 1;
		u32 LED11Col : 1;
		u32 LED12Col : 1;
		u32 LED13Col : 1;
		u32 LED14Col : 1;
		u32 LED15Col : 1;
		u32 LED16Col : 1;
		u32 LED17Col : 1;
		u32 LED18Col : 1;
		u32 LED19Col : 1;
		u32 LED20Col : 1;
		u32 LED21Col : 1;
		u32 LED22Col : 1;
		u32 LED23Col : 1;
		u32 LED24Col : 1;
		u32 LED25Col : 1;
		u32 LED26Col : 1;
		u32 LED27Col : 1;
		u32 LED28Col : 1;
		u32 LED29Col : 1;
		u32 LED30Col : 1;
		u32 LED31Col : 1;
		u32 LED32Col : 1;
		u32 LED33Col : 1;
		u32 LED34Col : 1;
		u32 LED35Col : 1;
		u32 LED36Col : 1;
		u32 LED37Col : 1;
		u32 LED38Col : 1;
		u32 LED39Col : 1;
		u32 LED40Col : 1;
		u32 LED41Col : 1;
		u32 LED42Col : 1;
		u32 LED43Col : 1;
		u32 LED44Col : 1;
		u32 LED45Col : 1;
		u32 LED46Col : 1;
		u32 LED47Col : 1;
		u32 LED48Col : 1;
		u32 LED49Col : 1;
		u32 LED50Col : 1;
		u32 LED51Col : 1;
		u32 LED52Col : 1;
		u32 LED53Col : 1;
		u32 LED54Col : 1;
		u32 LED55Col : 1;
		u32 LED56Col : 1;
		u32 LED57Col : 1;
		u32 LED58Col : 1;
		u32 LED59Col : 1;
		u32 LED60Col : 1;
		u32 LED61Col : 1;
		u32 LED62Col : 1;
		u32 LED63Col : 1;
		u32 LED64Col : 1;

	}LEDs_struct;

	LEDs_struct LEDsCfg_struct;

}LEDMTX_cfg;




#endif /* HAL_LEDMTX_INT_H_ */
