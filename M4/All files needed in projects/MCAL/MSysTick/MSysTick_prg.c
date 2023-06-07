/*
 * MSysTick_prg.c
 *
 *  Created on: Jun 1, 2023
 *      Author: Ahmed
 */

#include<LIB/STD_TYPES.h>
#include<MCAL/MSysTick/MSystick_prv.h>
#include<MCAL/MSysTick/MSystick_int.h>



static Bool GS_BoolPeriodicityState;

 void (*S_vFunvPtSTKCAllBackPtr)(void);



Bool MSysTick_BoolWait(u32 Cpy_u32WaitedTicks)
{
	Bool L_BoolErrorState = 0;

	switch(Cpy_u32WaitedTicks)
	{
	case MIN_LOAD ... MAX_LOAD:
	{
		/*Load the wanted number of ticks into LOAD register*/
		SYSTICK->LOAD = Cpy_u32WaitedTicks;
		SYSTICK->VAL = 0;
		(SYSTICK->CTRL) &= ~(1<<COUNTFLAG);
		(SYSTICK->CTRL) |= (1<<CLKSOURCE);
		/*Start the SysTick timer*/
		(SYSTICK->CTRL) |= (1<<EN);
		/*Wait for the COUNTFLAG to be set, indicating that Cpy_u32WaitedTicks*/
		/*counts has passed.*/
		while(((SYSTICK->CTRL)&(1<<COUNTFLAG)) == 0);
		/*After Cpy_u32WaitedTicks number of ticks, clear the flag to*/
		/*allow for using the timer safely at next times.*/
		(SYSTICK->CTRL) &= ~(1<<COUNTFLAG);
		/*Stop the SysTick timer*/
		(SYSTICK->CTRL) &= ~(1<<EN);

		break;
	}

	default:
	{
		L_BoolErrorState = 1;
		break;
	}
	}


	return L_BoolErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/


u32 MSysTick_u32GetElapsedTime(void)
{
	return((SYSTICK->LOAD) - (SYSTICK->VAL));
}


/*****************************************************************************************************/
/*****************************************************************************************************/


u32 MSysTick_u32GetRemainingTime(void)
{
	return(SYSTICK->VAL);
}


/*****************************************************************************************************/
/*****************************************************************************************************/


void MSysTick_vStop(void)
{
	/*Stop the SysTick timer*/
	(SYSTICK->CTRL) &= ~(1<<EN);
}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MSysTick_BoolSetIntervalSingle(u32 Cpy_u32WaitedTicks)
{
	Bool L_BoolErrorState = 0;

	switch(Cpy_u32WaitedTicks)
	{
	case MIN_LOAD ... MAX_LOAD:
	{
		GS_BoolPeriodicityState = 0;
		/*Load the wanted number of ticks into LOAD register*/
		SYSTICK->LOAD = Cpy_u32WaitedTicks;
		SYSTICK->VAL = 0x00000000;
		/*Enable the underflow interrupt*/
		(SYSTICK->CTRL) |= (1<<TICKINT);
		/*Start the SysTick timer*/
		(SYSTICK->CTRL) |= (1<<EN);

		break;
	}


	default:
	{
		L_BoolErrorState = 1;
		break;
	}
	}


	return L_BoolErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MSysTick_BoolSetIntervalPeriodic(u32 Cpy_u32Periodicity)
{
	Bool L_BoolErrorState = 0;

	switch(Cpy_u32Periodicity)
	{
	case MIN_LOAD ... MAX_LOAD:
	{
		GS_BoolPeriodicityState = 1;
		/*Load the wanted number of ticks into LOAD register*/
		SYSTICK->LOAD = Cpy_u32Periodicity-1;
		SYSTICK->VAL = 0x00000000;
		(SYSTICK->CTRL) |= (1<<CLKSOURCE);
		/*Enable the underflow interrupt*/
		(SYSTICK->CTRL) |= (1<<TICKINT);
		/*Start the SysTick timer*/
		(SYSTICK->CTRL) |= (1<<EN);

		break;
	}


	default:
	{
		L_BoolErrorState = 1;
		break;
	}
	}


	return L_BoolErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


void MSysTick_vSetCallBack(void(*Cpy_vFunvPtCalledPtr)(void))
{
	if(Cpy_vFunvPtCalledPtr != NULL)
	{
		S_vFunvPtSTKCAllBackPtr = Cpy_vFunvPtCalledPtr;
	}

}


/*****************************************************************************************************/
/*****************************************************************************************************/


void SysTick_Handler(void)
{
	//RTOS_vScheduler();

	(S_vFunvPtSTKCAllBackPtr)();
//
	if(GS_BoolPeriodicityState == 0)
	{
		/*Underflow interrupt is disabled*/
		(SYSTICK->CTRL) &= ~(1<<TICKINT);
	}

	else
	{
		/*After Cpy_u32WaitedTicks number of ticks, clear the flag to
		  allow the ISR to execute over and over again.*/
		(SYSTICK->CTRL) &= ~(1<<COUNTFLAG);
	}

}
