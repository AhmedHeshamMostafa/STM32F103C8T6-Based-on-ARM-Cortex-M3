/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 Apr 2023                                             */
/*             VERSION  : V02                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_int.h"


void MEXTI_vInit(void)
{
	/*Mask all interrupts*/
	EXTI->IMR = 0x00000000;
	/*Mask all events*/
	EXTI->EMR = 0x00000000;
	/*Clear all pending bits*/
	EXTI->PR = 0xFFFFFFFF;

}


/***********************************************************************************/


Bool MEXTI_BoolEnableLine(EXTI_cfg *EXTICfgPtConfigPtr)
{
	volatile u32 *L_u32PtTargetAFIOPtr;
	u8   Lu8TargetPin;
	Bool L_BoolErrorState = 1;

	switch((EXTICfgPtConfigPtr->BoolPinType))
	{
	case INTERRUPT:
	case EVENT:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		return L_BoolErrorState;
		break;
	}
	}


	switch((EXTICfgPtConfigPtr->u8PinTrigger))
	{
	case RISING_EDGE:
	case FALLING_EDGE:
	case CHANGE:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		return L_BoolErrorState;
		break;
	}
	}


	switch((EXTICfgPtConfigPtr->PortIDPort))
	{
	case PORTA ... PORTG:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		return L_BoolErrorState;
		break;
	}
	}


	switch((EXTICfgPtConfigPtr->PinIDPin))
	{
	case P0 ... P15:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		return L_BoolErrorState;
		break;
	}
	}


	switch((EXTICfgPtConfigPtr->PinIDPin))
	{
	case P0 ... P3:
	{
		L_u32PtTargetAFIOPtr = &(AFIO_BLOCK->EXTICR1);
		Lu8TargetPin = (EXTICfgPtConfigPtr->PinIDPin)*4;
		break;
	}

	case P4 ... P7:
	{
		L_u32PtTargetAFIOPtr = &(AFIO_BLOCK->EXTICR2);
		Lu8TargetPin = ((EXTICfgPtConfigPtr->PinIDPin)-4)*4;
		break;
	}

	case P8 ... P11:
	{
		L_u32PtTargetAFIOPtr = &(AFIO_BLOCK->EXTICR3);
		Lu8TargetPin = ((EXTICfgPtConfigPtr->PinIDPin)-8)*4;
		break;
	}

	default:
	{
		L_u32PtTargetAFIOPtr = &(AFIO_BLOCK->EXTICR4);
		Lu8TargetPin = ((EXTICfgPtConfigPtr->PinIDPin)-12)*4;
		break;
	}
	}


	ASSIGN_BIT(*L_u32PtTargetAFIOPtr, Lu8TargetPin, ((EXTICfgPtConfigPtr->PortIDPort)&1));
	ASSIGN_BIT(*L_u32PtTargetAFIOPtr, Lu8TargetPin, ((EXTICfgPtConfigPtr->PortIDPort) & 2)>>1);
	ASSIGN_BIT(*L_u32PtTargetAFIOPtr, Lu8TargetPin, ((EXTICfgPtConfigPtr->PortIDPort) & 4)>>2);
	ASSIGN_BIT(*L_u32PtTargetAFIOPtr, Lu8TargetPin, ((EXTICfgPtConfigPtr->PortIDPort) & 8)>>3);

	switch((EXTICfgPtConfigPtr->BoolPinType))
	{
	case INTERRUPT:
	{
		SET_BIT(EXTI->IMR, (EXTICfgPtConfigPtr->PinIDPin));
		CLR_BIT(EXTI->EMR, (EXTICfgPtConfigPtr->PinIDPin));
		break;
	}
	case EVENT:
	{
		SET_BIT(EXTI->EMR, (EXTICfgPtConfigPtr->PinIDPin));
		CLR_BIT(EXTI->IMR, (EXTICfgPtConfigPtr->PinIDPin));
		break;
	}
	}

	ASSIGN_BIT(EXTI->RTSR, (EXTICfgPtConfigPtr->PinIDPin), ((EXTICfgPtConfigPtr->u8PinTrigger)&1));
	ASSIGN_BIT(EXTI->FTSR, (EXTICfgPtConfigPtr->PinIDPin), ((EXTICfgPtConfigPtr->u8PinTrigger)&2)>>1);


	return L_BoolErrorState;
}


/***********************************************************************************/


Bool MEXTI_BoolDisableLine(LineID_t A_LineIDLine)
{
	Bool L_BoolErrorState = 1;

	switch(A_LineIDLine)
	{
	case LINE0 ... LINE15:
	{
		CLR_BIT(EXTI->IMR, A_LineIDLine);
		CLR_BIT(EXTI->EMR, A_LineIDLine);
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


/***********************************************************************************/


Bool MEXTI_BoolSetSWInterrupt(LineID_t A_LineIDLine)
{
	Bool L_BoolErrorState = 1;

	switch(A_LineIDLine)
	{
	case LINE0 ... LINE15:
	{
		SET_BIT(EXTI->SWIER, A_LineIDLine);
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


/***********************************************************************************/


Bool MEXTI_BoolClearSWInterrupt(LineID_t A_LineIDLine)
{
	Bool L_BoolErrorState = 1;

	switch(A_LineIDLine)
	{
	case LINE0 ... LINE15:
	{
		SET_BIT(EXTI->PR, A_LineIDLine);
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
