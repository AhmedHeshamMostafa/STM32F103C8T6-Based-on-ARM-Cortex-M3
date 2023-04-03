/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/NVIC/NVIC_int.h"
#include "../../MCAL/EXTI/EXTI_int.h"
#include "SWInterrupt_int.h"

/*S stands for static*/
static void(*S_vEXTIAppvFunvPtr)(void);

EXTI_cfg  EXTICfgSwIntCfg = {.BoolPinType = INTERRUPT,
		                     .u8PinTrigger = RISING_EDGE,
							 .PortIDPort = PORTA,
							 .PinIDPin = P2
							};


void HSWInt_BoolInit(void)
{
	MNVIC_vInit();
	MEXTI_vInit();
	MEXTI_BoolEnableLine(&EXTICfgSwIntCfg);
	MNVIC_BoolDisableInterrupt(EXTI2);
}


/***********************************************************************************/


void HSWInt_BoolSetInterrupt(void)
{
	MEXTI_BoolSetSWInterrupt(LINE2);
	MNVIC_BoolEnableInterrupt(EXTI2);
}


/***********************************************************************************/


void HSWInt_BoolClearInterrupt(void)
{
	MEXTI_BoolClearSWInterrupt(LINE2);
	MNVIC_BoolDisableInterrupt(EXTI2);
}


void HSWInt_vSetCallBack(void(*vAppFunv)(void))
{
	S_vEXTIAppvFunvPtr = vAppFunv;
}


/***********************************************************************************/
/**************************   The ISR for EXTI2   **********************************/
/***********************************************************************************/


void EXTI2_IRQHandler(void)
{
	(*S_vEXTIAppvFunvPtr)();
	HSWInt_BoolClearInterrupt();
}
