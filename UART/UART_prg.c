/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 2 Apr 2023                                             */
/*             VERSION  : V02                                                    */
/*********************************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "UART_int.h"
#include "UART_prv.h"



static void MUART_vWriteBRR(u32 *A_u32PtUARTClkPtr, u32 *A_u32PtUARTBaudPtr, UARTChID_t A_UARTChID)
{
	Bool L_BoolBitVal = 0;
	f32 L_f32UARTDIV;
	u32 L_u32UARTDIVMantissa;
	f32 L_f32UARTDIVFraction;
	u32 L_u32UARTDIVFracRounded;
	u32 L_u32UARTDIVMantissaFinal;

	L_f32UARTDIV = (f32)(*A_u32PtUARTClkPtr)/((u32)16*(*A_u32PtUARTBaudPtr));
	L_u32UARTDIVMantissa = (u32)L_f32UARTDIV;
	L_f32UARTDIVFraction = (f32)(16*(L_f32UARTDIV - (f32)L_u32UARTDIVMantissa));
	L_u32UARTDIVFracRounded = (u32)(L_f32UARTDIVFraction + 0.5);

	if(L_u32UARTDIVFracRounded > 15)
	{
		L_u32UARTDIVMantissaFinal = L_u32UARTDIVMantissa + (L_u32UARTDIVFracRounded-15);
	}

	else
	{
		L_u32UARTDIVMantissaFinal = L_u32UARTDIVMantissa;
	}

/*********************************************************************************************/

	for(u8 L_u8FracBitCount = 0; L_u8FracBitCount <= 3; L_u8FracBitCount++)
	{
		GET_BIT(L_u32UARTDIVFracRounded, L_u8FracBitCount, L_BoolBitVal);
		ASSIGN_BIT(A_UARTChID->BRR, L_u8FracBitCount, L_BoolBitVal);
	}

	for(u8 L_u8MantissaBitCount = 0; L_u8MantissaBitCount <= 11; L_u8MantissaBitCount++)
	{
		GET_BIT(L_u32UARTDIVMantissaFinal, L_u8MantissaBitCount, L_BoolBitVal);
		ASSIGN_BIT(A_UARTChID->BRR, L_u8MantissaBitCount+4, L_BoolBitVal);
	}
}


/*******************************************************************/


Bool MUART_BoolInit(UART_cfg *A_UARTCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	if( ((A_UARTCfgPtConfigPtr->channel) == CH1) || ((A_UARTCfgPtConfigPtr->channel) == CH2) || ((A_UARTCfgPtConfigPtr->channel) == CH3)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH4)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH5))

		if( ((A_UARTCfgPtConfigPtr->charLength) == CHAR_8BIT) || ((A_UARTCfgPtConfigPtr->charLength) == CHAR_9BIT) )
		{
			if( ((A_UARTCfgPtConfigPtr->parity) == EVEN_PARITY) || ((A_UARTCfgPtConfigPtr->parity) == ODD_PARITY) || ((A_UARTCfgPtConfigPtr->parity) == NO_PARITY) )
			{

				if( ((A_UARTCfgPtConfigPtr->stopBits) == STP_BITS1) || ((A_UARTCfgPtConfigPtr->stopBits) == STP_BITS2) )
				{
					MUART_vWriteBRR(&(A_UARTCfgPtConfigPtr->UARTClk), &(A_UARTCfgPtConfigPtr->baudRate), A_UARTCfgPtConfigPtr->channel);

					ASSIGN_BIT(A_UARTCfgPtConfigPtr->channel->CR1, M, A_UARTCfgPtConfigPtr->charLength);

					ASSIGN_BIT(A_UARTCfgPtConfigPtr->channel->CR1, PCE, ((A_UARTCfgPtConfigPtr->parity)&2)>>1);
					ASSIGN_BIT(A_UARTCfgPtConfigPtr->channel->CR1, PS, (A_UARTCfgPtConfigPtr->parity)&1);

					ASSIGN_BIT(A_UARTCfgPtConfigPtr->channel->CR2, STOP1, ((A_UARTCfgPtConfigPtr->stopBits)&2)>>1);
					ASSIGN_BIT(A_UARTCfgPtConfigPtr->channel->CR2, STOP0, (A_UARTCfgPtConfigPtr->stopBits)&1);
				}

				else
				{
				L_BoolErrorState = 0;
				}
			}

			else
			{
				L_BoolErrorState = 0;
			}

		}

		else
		{
			L_BoolErrorState = 0;
		}


	else
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}


/*******************************************************************/


/*
Bool MUART_BoolSetTx(UART_cfg *A_UARTCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	if( ((A_UARTCfgPtConfigPtr->channel) == CH1) || ((A_UARTCfgPtConfigPtr->channel) == CH2) || ((A_UARTCfgPtConfigPtr->channel) == CH3)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH4)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH5))
	{
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, TE);
	}

	else
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;

}
*/

/*******************************************************************/

/*
Bool MUART_BoolSetRx(UART_cfg *A_UARTCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	if( ((A_UARTCfgPtConfigPtr->channel) == CH1) || ((A_UARTCfgPtConfigPtr->channel) == CH2) || ((A_UARTCfgPtConfigPtr->channel) == CH3)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH4)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH5))
	{
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, RE);
	}

	else
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;

}
*/

/*******************************************************************/


Bool MUART_BoolSendByte(UART_cfg *A_UARTCfgPtConfigPtr, u8 A_u8SentByte)
{
	Bool L_BoolErrorState = 1;

	if( ((A_UARTCfgPtConfigPtr->channel) == CH1) || ((A_UARTCfgPtConfigPtr->channel) == CH2) || ((A_UARTCfgPtConfigPtr->channel) == CH3)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH4)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH5))
	{
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, UE);
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, TE);
		while(((A_UARTCfgPtConfigPtr->channel->SR)&(1<<TXE)) == 0);
		//A_UARTCfgPtConfigPtr->channel->DR = (u8)A_u16SentData;

		A_UARTCfgPtConfigPtr->channel->DR = (u16)A_u8SentByte;

		while(((A_UARTCfgPtConfigPtr->channel->SR)&(1<<TC)) == 0);
		CLR_BIT(A_UARTCfgPtConfigPtr->channel->CR1, UE);
		CLR_BIT(A_UARTCfgPtConfigPtr->channel->CR1, TE);
	}

	else
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;
}


/*******************************************************************/


u8 MUART_BoolRecByte(UART_cfg *A_UARTCfgPtConfigPtr, u8 *A_u8PtRecBytePtr)
{
	u8 L_u8ErrorState = 0b0000;

	if( ((A_UARTCfgPtConfigPtr->channel) == CH1) || ((A_UARTCfgPtConfigPtr->channel) == CH2) || ((A_UARTCfgPtConfigPtr->channel) == CH3)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH4)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH5))
	{
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, UE);
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, RE);
		while(((A_UARTCfgPtConfigPtr->channel->SR)&(1<<RXNE)) == 0);
		ASSIGN_BIT(L_u8ErrorState, 3, ORERR);
		ASSIGN_BIT(L_u8ErrorState, 2, NERR);
		ASSIGN_BIT(L_u8ErrorState, 1, FERR);
		ASSIGN_BIT(L_u8ErrorState, 0, PERR);
		*A_u8PtRecBytePtr = (u8)(A_UARTCfgPtConfigPtr->channel->DR);
		CLR_BIT(A_UARTCfgPtConfigPtr->channel->CR1, UE);
		CLR_BIT(A_UARTCfgPtConfigPtr->channel->CR1, RE);
	}

	else
	{
		L_u8ErrorState = 0b10000;
	}


	return L_u8ErrorState;
}


/*******************************************************************/


Bool MUART_BoolSendArr(UART_cfg *A_UARTCfgPtConfigPtr, u8 *A_u8PtSFirstBytePtr, u16 A_u16BytesNum)
{
	Bool L_BoolErrorState = 1;

	if( ((A_UARTCfgPtConfigPtr->channel) == CH1) || ((A_UARTCfgPtConfigPtr->channel) == CH2) || ((A_UARTCfgPtConfigPtr->channel) == CH3)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH4)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH5))
	{
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, UE);
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, TE);

		for(u16 L_u16SentByteCount = 0; L_u16SentByteCount < A_u16BytesNum; L_u16SentByteCount++)
		{
			while(((A_UARTCfgPtConfigPtr->channel->SR)&(1<<TXE)) == 0);
			A_UARTCfgPtConfigPtr->channel->DR = (u16)(A_u8PtSFirstBytePtr[L_u16SentByteCount]);
		}

		while(((A_UARTCfgPtConfigPtr->channel->SR)&(1<<TC)) == 0);
		CLR_BIT(A_UARTCfgPtConfigPtr->channel->CR1, UE);
		CLR_BIT(A_UARTCfgPtConfigPtr->channel->CR1, TE);
	}

	else
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;
}


/*******************************************************************/


u8 MUART_BoolRecArr(UART_cfg *A_UARTCfgPtConfigPtr, u8 *A_u8PtRFirstBytePtr, u16 A_u16RecBytesNum)
{
	u16 L_u16RecByteCount = 0;
	u8 *L_u8PtRecBytePtr = A_u8PtRFirstBytePtr;
	u8 L_u8ErrorState = 0b0000;

	if( ((A_UARTCfgPtConfigPtr->channel) == CH1) || ((A_UARTCfgPtConfigPtr->channel) == CH2) || ((A_UARTCfgPtConfigPtr->channel) == CH3)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH4)  ||  ((A_UARTCfgPtConfigPtr->channel) == CH5))
	{
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, UE);
		SET_BIT(A_UARTCfgPtConfigPtr->channel->CR1, RE);

		while((L_u8ErrorState == 0b0000) && (L_u16RecByteCount < A_u16RecBytesNum))
		{
			while(((A_UARTCfgPtConfigPtr->channel->SR)&(1<<RXNE)) == 0);
			ASSIGN_BIT(L_u8ErrorState, 3, ORERR);
			ASSIGN_BIT(L_u8ErrorState, 2, NERR);
			ASSIGN_BIT(L_u8ErrorState, 1, FERR);
			ASSIGN_BIT(L_u8ErrorState, 0, PERR);
			L_u8PtRecBytePtr  = A_u8PtRFirstBytePtr + L_u16RecByteCount;
			*L_u8PtRecBytePtr = (u16)(A_UARTCfgPtConfigPtr->channel->DR);
			L_u16RecByteCount++;
		}

		CLR_BIT(A_UARTCfgPtConfigPtr->channel->CR1, UE);
		CLR_BIT(A_UARTCfgPtConfigPtr->channel->CR1, RE);
	}

	else
	{
		L_u8ErrorState = 0b10000;
	}

	return L_u8ErrorState;
}



