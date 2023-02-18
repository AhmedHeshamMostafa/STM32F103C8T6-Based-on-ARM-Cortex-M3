/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 16 Feb 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../SCB/SCB_prv.h"
#include "NVIC_prv.h"
#include "NVIC_int.h"
#include "NVIC_cfg.h"


void MNVIC_vInit(void)
{
	SCB->AIRCR = ((u32)(0x05FA << 16)) | ((u32)(PRIORITY_MODE << 8));
}


Bool MNVIC_BoolSetPriority(s8 A_s8InterruptID, u8 A_u8Priority)
{
	Bool L_BoolErrorState = 1;

	if((A_s8InterruptID >= MEM_FAULT) && (A_s8InterruptID <= USAGE_FAULT))
	{
		SCB->SHPR1 = A_u8Priority << ((A_s8InterruptID + 6) * 8 + 4);
	}

	else if(A_s8InterruptID == SVCALL)
	{
		SCB->SHPR2 = A_u8Priority << 28;
	}

	else if((A_s8InterruptID == PENDSV) || (A_s8InterruptID == SYSTICK))
	{
		SCB->SHPR3 = A_u8Priority << ((A_s8InterruptID + 2) * 8 + 20);
	}

	else if (A_s8InterruptID <= DMA2_Channel4_5)
	{
		NVIC->IPR[A_s8InterruptID] = A_u8Priority << 4;
	}

	else
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;
}


Bool MNVIC_BoolEnableInterrupt(u8 A_u8InterruptID)
{
	Bool L_BoolErrorState = 1;
	Bool L_BoolBitVal;

	if (A_u8InterruptID <= DMA2_Channel4_5)
	{
		SET_BIT(NVIC->ISER[A_u8InterruptID/32], A_u8InterruptID % 32);
		GET_BIT(NVIC->ISER[A_u8InterruptID/32], A_u8InterruptID % 32, L_BoolBitVal);

		if(!L_BoolBitVal)
		{
			L_BoolErrorState = 0;
		}
	}

	else
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}


Bool MNVIC_BoolDisableInterrupt(u8 A_u8InterruptID)
{
	Bool L_BoolErrorState = 1;
	Bool L_BoolBitVal;

	if (A_u8InterruptID <= DMA2_Channel4_5)
	{
		SET_BIT(NVIC->ICER[A_u8InterruptID/32], A_u8InterruptID % 32);
		GET_BIT(NVIC->ICER[A_u8InterruptID/32], A_u8InterruptID % 32, L_BoolBitVal);

		if(L_BoolBitVal)
		{
			L_BoolErrorState = 0;
		}
	}

	else
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;

}


Bool MNVIC_BoolSetPending(u8 A_u8InterruptID)
{
	Bool L_BoolErrorState = 1;
	Bool L_BoolBitVal;

	if (A_u8InterruptID <= DMA2_Channel4_5)
	{
		SET_BIT(NVIC->ISPR[A_u8InterruptID/32], A_u8InterruptID % 32);
		GET_BIT(NVIC->ISPR[A_u8InterruptID/32], A_u8InterruptID % 32, L_BoolBitVal);

		if(!L_BoolBitVal)
		{
			L_BoolErrorState = 0;
		}
	}

	else
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}


Bool MNVIC_BoolClearPending(u8 A_u8InterruptID)
{
	Bool L_BoolErrorState = 1;
	Bool L_BoolBitVal;

	if (A_u8InterruptID <= DMA2_Channel4_5)
	{
		SET_BIT(NVIC->ICPR[A_u8InterruptID/32], A_u8InterruptID % 32);
		GET_BIT(NVIC->ICPR[A_u8InterruptID/32], A_u8InterruptID % 32, L_BoolBitVal);

		if(L_BoolBitVal)
		{
			L_BoolErrorState = 0;
		}
	}

	else
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}


Bool MNVIC_BoolReadActiveState(u8 A_u8InterruptID, Bool* A_BoolPtrState)
{
	Bool L_BoolErrorState = 1;

	if (A_u8InterruptID <= DMA2_Channel4_5)
	{
		GET_BIT(NVIC->IABR[A_u8InterruptID/32], A_u8InterruptID % 32, *A_BoolPtrState);
	}

	else
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;

}




