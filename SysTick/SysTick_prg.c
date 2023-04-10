/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 10 Apr 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

/* Notice that case MINRANGE ... MAXRANGE: is a feature available only in gcc.
   If you are willing to use a different compiler, you should refer to its documentation.*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SysTick_int.h"




/*S stands for static*/

static Bool S_BoolPeriodicityState;

static void(*S_vFunvPtSTKCAllBackPtr)(void);


/*******************************************************************/


Bool MSysTick_BoolInit(SysTick_cfg *STKCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	switch((STKCfgPtConfigPtr->BoolSTKClkSrc))
	{
	case AHBCLK_OVER_8:
	case AHBCLK:
	{
		/*Choose the clock source either AHB/8 or AHB according to user's configuration.*/
		ASSIGN_BIT(SYSTICK->CTRL, CLKSOURCE, STKCfgPtConfigPtr->BoolSTKClkSrc);
		/*Clear the flag, to avoid any unexpected set for the flag*/
		CLR_BIT(SYSTICK->CTRL, COUNTFLAG);
		/*Underflow interrupt is disabled*/
		CLR_BIT(SYSTICK->CTRL, TICKINT);
		/*Timer is disabled*/
		CLR_BIT(SYSTICK->CTRL, EN);
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}


	return L_BoolErrorState;
}


/*******************************************************************/


void MSysTick_vStop(void)
{
	/*Stop the SysTick timer*/
	CLR_BIT(SYSTICK->CTRL, EN);
}


/*******************************************************************/


Bool MSysTick_BoolWait(u32 A_u32WaitedTicks)
{
	Bool L_BoolErrorState = 1;

	switch(A_u32WaitedTicks)
	{
	case MIN_LOAD ... MAX_LOAD:
	{
		/*Load the wanted number of ticks into LOAD register*/
		SYSTICK->LOAD = A_u32WaitedTicks;
		/*Start the SysTick timer*/
		SET_BIT(SYSTICK->CTRL, EN);
		/*Wait for the COUNTFLAG to be set, indicating that A_u32WaitedTicks
		  counts has passed.*/
		while(((SYSTICK->CTRL)&(1<<COUNTFLAG)) == 0);
		/*After A_u32WaitedTicks number of ticks, clear the flag to
		  allow for using the timer safely at next times.*/
		CLR_BIT(SYSTICK->CTRL, COUNTFLAG);
		/*Stop the SysTick timer*/
		CLR_BIT(SYSTICK->CTRL, EN);

		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}


	return L_BoolErrorState;

}


/*******************************************************************/


Bool MSysTick_BoolSetIntervalSingle(u32 A_u32WaitedTicks)
{
	Bool L_BoolErrorState = 1;

	switch(A_u32WaitedTicks)
	{
	case MIN_LOAD ... MAX_LOAD:
	{
		S_BoolPeriodicityState = 0;
		/*Load the wanted number of ticks into LOAD register*/
		SYSTICK->LOAD = A_u32WaitedTicks;
		/*Enable the underflow interrupt*/
		SET_BIT(SYSTICK->CTRL, TICKINT);
		/*Start the SysTick timer*/
		SET_BIT(SYSTICK->CTRL, EN);

		break;
	}


	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}


	return L_BoolErrorState;
}


/*******************************************************************/


Bool MSysTick_BoolSetIntervalPeriodic(u32 A_u32Periodicity)
{
	Bool L_BoolErrorState = 1;

	switch(A_u32Periodicity)
	{
	case MIN_LOAD ... MAX_LOAD:
	{
		S_BoolPeriodicityState = 1;
		/*Load the wanted number of ticks into LOAD register*/
		SYSTICK->LOAD = A_u32Periodicity-1;
		/*Enable the underflow interrupt*/
		SET_BIT(SYSTICK->CTRL, TICKINT);
		/*Start the SysTick timer*/
		SET_BIT(SYSTICK->CTRL, EN);

		break;
	}


	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}


	return L_BoolErrorState;
}


/*******************************************************************/


u32 MSysTick_u32GetElapsedTime(void)
{
	return((SYSTICK->LOAD) - (SYSTICK->VAL));
}


/*******************************************************************/


u32 MSysTick_u32GetRemainingTime(void)
{
	return(SYSTICK->VAL);
}


/*******************************************************************/


void MSysTick_vSetCallBack(void(*A_vFunvPtCalledPtr)(void))
{
	if(A_vFunvPtCalledPtr != 0)
	{
		S_vFunvPtSTKCAllBackPtr = A_vFunvPtCalledPtr;
	}

}


/***********************************************************************************/
/**************************   The ISR for SysTick   ********************************/
/***********************************************************************************/


void SysTick_Handler(void)
{
	(*S_vFunvPtSTKCAllBackPtr)();

	if(S_BoolPeriodicityState == 0)
	{
		/*Underflow interrupt is disabled*/
		CLR_BIT(SYSTICK->CTRL, TICKINT);
	}

	else
	{
		/*After A_u32WaitedTicks number of ticks, clear the flag to
		  allow the ISR to execute over and over again.*/
		CLR_BIT(SYSTICK->CTRL, COUNTFLAG);
	}

}


