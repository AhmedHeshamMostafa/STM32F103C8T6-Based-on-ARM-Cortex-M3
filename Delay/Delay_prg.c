/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 10 Apr 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../STD_TYPES.h"
#include "../../MCAL/SysTick/SysTick_int.h"
#include "../../MCAL/RCC/RCC_cfg.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "Delay_int.h"



static SysTick_cfg STKCfgConfig = {.BoolSTKClkSrc = AHBCLK_OVER_8};



Bool delay_us(u32 A_u32MicroSeconds)
{
	f32 L_f32TimerTickTime_us;
	u32 L_u32DelayTicks;

	Bool L_BoolErrorState = 1;

	MSysTick_BoolInit(&STKCfgConfig);

	switch(AHB_CLK)
	{
	case AHB_SYSCLK:
	{
		L_f32TimerTickTime_us = ((f32)8000000.0)/F_CPU;
		break;
	}

	case AHB_SYSCLK_OVER2:
	{
		L_f32TimerTickTime_us = ((f32)16000000.0)/F_CPU;
		break;
	}

	case AHB_SYSCLK_OVER4:
	{
		L_f32TimerTickTime_us = ((f32)32000000.0)/F_CPU;
		break;
	}

	case AHB_SYSCLK_OVER8:
	{
		L_f32TimerTickTime_us = ((f32)64000000.0)/F_CPU;
		break;
	}

	case AHB_SYSCLK_OVER16:
	{
		L_f32TimerTickTime_us = ((f32)128000000.0)/F_CPU;
		break;
	}

	case AHB_SYSCLK_OVER64:
	{
		L_f32TimerTickTime_us = ((f32)512000000.0)/F_CPU;
		break;
	}

	case AHB_SYSCLK_OVER128:
	{
		L_f32TimerTickTime_us = ((f32)1024000000.0)/F_CPU;
		break;
	}

	case AHB_SYSCLK_OVER256:
	{
		L_f32TimerTickTime_us = ((f32)2048000000.0)/F_CPU;
		break;
	}

	case AHB_SYSCLK_OVER512:
	{
		L_f32TimerTickTime_us = ((f32)4096000000.0)/F_CPU;
		break;
	}
	}


	L_u32DelayTicks = (u32)(A_u32MicroSeconds / L_f32TimerTickTime_us);

	L_BoolErrorState = MSysTick_BoolWait(L_u32DelayTicks);

	return L_BoolErrorState;

}




