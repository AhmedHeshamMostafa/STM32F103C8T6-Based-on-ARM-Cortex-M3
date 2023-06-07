/*
 * Delay_prg.c
 *
 *  Created on: Jun 1, 2023
 *      Author: Ahmed
 */

#include<LIB/STD_TYPES.h>
#include<MCAL/MSysTick/MSysTick_int.h>
#include"Delay_cfg.h"
#include<LIB/Delay_int.h>


Bool BoolDelay_us(u32 Cpy_u32Microseconds)
{
	/*Successful return                            : L_BoolErrorState = 0*/
	/*Invalid value for Cpy_u32Microseconds entered: L_BoolErrorState = 1*/

	 Bool L_BoolErrorState = 1;

	 f32 L_f32STKTickTime_us = (f32)((f32)1/F_CPU_MHZ);

	 u32 L_u32NoOfTicks = (u32)(Cpy_u32Microseconds/L_f32STKTickTime_us);

	 L_BoolErrorState = MSysTick_BoolWait(L_u32NoOfTicks);

	 return L_BoolErrorState;
}

