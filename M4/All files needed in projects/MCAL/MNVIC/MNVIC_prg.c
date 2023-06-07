/*
 * MNVIC_prg.c
 *
 *  Created on: May 30, 2023
 *      Author: Ahmed
 */




#include<LIB/STD_TYPES.h>
#include<MCAL/MNVIC/MNVIC_int.h>
#include<MCAL/MNVIC/MNVIC_prv.h>




Bool MNVIC_BoolEnablePerINT(perID_t Cpy_perIDPer)
{
	/*Successful return             : L_BoolErrorState = 0*/
	/*Invalid peripheral ID entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	if(Cpy_perIDPer<=SPIFOUR)
	{
		u8 L_u8RegNum = Cpy_perIDPer / 32;
		u8 L_u8bitNum = Cpy_perIDPer % 32;

		((NVIC->ISER)[L_u8RegNum]) = 1 << L_u8bitNum;

		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MNVIC_BoolDisablePerINT(perID_t Cpy_perIDPer)
{
	/*Successful return             : L_BoolErrorState = 0*/
	/*Invalid peripheral ID entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	if(Cpy_perIDPer<=SPIFOUR)
	{
		u8 L_u8RegNum = Cpy_perIDPer / 32;
		u8 L_u8bitNum = Cpy_perIDPer % 32;

		((NVIC->ICER)[L_u8RegNum]) = 1 << L_u8bitNum;

		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MNVIC_BoolSetPerPending(perID_t Cpy_perIDPer)
{
	/*Successful return             : L_BoolErrorState = 0*/
	/*Invalid peripheral ID entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	if(Cpy_perIDPer<=SPIFOUR)
	{
		u8 L_u8RegNum = Cpy_perIDPer / 32;
		u8 L_u8bitNum = Cpy_perIDPer % 32;

		((NVIC->ISPR)[L_u8RegNum]) = 1 << L_u8bitNum;

		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MNVIC_BoolClrPerPending(perID_t Cpy_perIDPer)
{
	/*Successful return             : L_BoolErrorState = 0*/
	/*Invalid peripheral ID entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	if(Cpy_perIDPer<=SPIFOUR)
	{
		u8 L_u8RegNum = Cpy_perIDPer / 32;
		u8 L_u8bitNum = Cpy_perIDPer % 32;

		((NVIC->ICPR)[L_u8RegNum]) = 1 << L_u8bitNum;

		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


u8 MNVIC_BoolIsISRExecut(perID_t Cpy_perIDPer)
{
	/*ISR for this interrupt source is currently executing    : L_u8ErrorState = 1*/
	/*ISR for this interrupt source is NOT executing currently: L_u8ErrorState = 0*/
	/*Invalid peripheral ID entered                           : L_u8ErrorState = 2*/

	u8 L_u8ErrorState = 2;

	if(Cpy_perIDPer<=SPIFOUR)
	{
		u8 L_u8RegNum = Cpy_perIDPer / 32;
		u8 L_u8bitNum = Cpy_perIDPer % 32;

		L_u8ErrorState = (((NVIC->IABR)[L_u8RegNum]) & (1<<L_u8bitNum)) >> L_u8bitNum;
	}


	return L_u8ErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/

Bool MNVIC_BoolSetPriorityMode(priorityMode_t Cpy_prModePriority)
{
	/*Successful return             : L_BoolErrorState = 0*/
	/*Invalid priority mode entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	if((Cpy_prModePriority>=SIXTEENGRPS) && (Cpy_prModePriority<=SIXTEENSUBGRPS))
	{
		GS_prModeSavedPrMode = Cpy_prModePriority;

		AIRCR = (u32)VECTKEY | (u32)Cpy_prModePriority;

		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


u8 MNVIC_u8SetPriorities(perID_t Cpy_perIDPer, priorityNum_t Cpy_prNumGrpPriority, priorityNum_t Cpy_prNumSubGrpPriority)
{
	/*Successful return                                           : L_u8ErrorState = 0*/
	/*Invalid peripheral ID entered                               : L_u8ErrorState = 2*/
	/*Invalid group priority and valid subgroup priority entered  : L_u8ErrorState = 3*/
	/*Valid group priority and invalid subgroup priority entered  : L_u8ErrorState = 4*/
	/*Invalid group priority and invalid subgroup priority entered: L_u8ErrorState = 5*/

	u8 L_u8ErrorState = 2;


	if(Cpy_perIDPer<=SPIFOUR)
	{
		if((Cpy_prNumGrpPriority<=PRIORITY_15) && (Cpy_prNumSubGrpPriority<=PRIORITY_15))
		{
			switch(GS_prModeSavedPrMode)
			{
			case SIXTEENGRPS      :	(NVIC->IPR[Cpy_perIDPer]) = PRIORITYMASK & (Cpy_prNumGrpPriority<<4);
				            	    break;
			case EIGHTGRPS_TWOSUBS:	(NVIC->IPR[Cpy_perIDPer]) = PRIORITYMASK & ((Cpy_prNumGrpPriority<<5)|(Cpy_prNumSubGrpPriority<<4));
									break;
			case FOURGRPS_FOURSUBS:	(NVIC->IPR[Cpy_perIDPer]) = PRIORITYMASK & ((Cpy_prNumGrpPriority<<6)|(Cpy_prNumSubGrpPriority<<4));
									break;
			case TWOGRPS_EIGHTSUBS:	(NVIC->IPR[Cpy_perIDPer]) = PRIORITYMASK & ((Cpy_prNumGrpPriority<<7)|(Cpy_prNumSubGrpPriority<<4));
									break;
			case SIXTEENSUBGRPS   :	(NVIC->IPR[Cpy_perIDPer]) = PRIORITYMASK & (Cpy_prNumSubGrpPriority<<4);
									break;
			}

			L_u8ErrorState = 0;

		}

		else if((!(Cpy_prNumGrpPriority<=PRIORITY_15)) && (Cpy_prNumSubGrpPriority<=PRIORITY_15))
		{

			L_u8ErrorState = 3;
		}

		else if((Cpy_prNumGrpPriority<=PRIORITY_15) && (!(Cpy_prNumSubGrpPriority<=PRIORITY_15)))
		{

			L_u8ErrorState = 4;
		}

		else
		{

			L_u8ErrorState = 5;
		}

	}


	return L_u8ErrorState;

}



