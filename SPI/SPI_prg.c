/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 4 May 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SPI_int.h"
#include "SPI_prv.h"



Bool MSPI_BoolInit(SPI_cfg *A_SPICfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;


	if(((A_SPICfgPtConfigPtr->SPIChannel) != SPI_ONE) && ((A_SPICfgPtConfigPtr->SPIChannel) != SPI_TWO_I2S) && ((A_SPICfgPtConfigPtr->SPIChannel) != SPI_THREE_I2S))
	{
		L_BoolErrorState = 0;
	}



	switch(A_SPICfgPtConfigPtr->mode)
	{
	case SPI_SLAVE:
	case SPI_MASTER:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}



	switch(A_SPICfgPtConfigPtr->frameSize)
	{
	case EIGHTBIT_FRAME:
	case SIXTEENBIT_FRAME:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}



	switch(A_SPICfgPtConfigPtr->dataOrder)
	{
	case LSB_FIRST:
	case MSB_FIRST:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}



	switch(A_SPICfgPtConfigPtr->SPIClkPol)
	{
	case IDLE_LOW:
	case IDLE_HIGH:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}



	switch(A_SPICfgPtConfigPtr->SPIClkPhase)
	{
	case SAMPLE_1ST_EDGE:
	case SAMPLE_2ND_EDGE:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}


	switch(A_SPICfgPtConfigPtr->SPIBaudRate)
	{
	case FPCLK_OVER2 ... FPCLK_OVER256:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}


	switch (L_BoolErrorState)
	{
	case 1:
	{
		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, BAUD0, (A_SPICfgPtConfigPtr->SPIBaudRate) & 1);
		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, BAUD1, ((A_SPICfgPtConfigPtr->SPIBaudRate) & 2)>>1);
		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, BAUD2, ((A_SPICfgPtConfigPtr->SPIBaudRate) & 4)>>2);
		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, CPOL, A_SPICfgPtConfigPtr->SPIClkPol);
		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, CPHA, A_SPICfgPtConfigPtr->SPIClkPhase);
		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, DFF, A_SPICfgPtConfigPtr->frameSize);
		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, LSBFIRST , A_SPICfgPtConfigPtr->dataOrder);
		CLR_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, SSM);
		CLR_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, BIDIMODE);
		CLR_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, RXONLY);
		CLR_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, CRCE);
		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, MSTR , A_SPICfgPtConfigPtr->mode);

		ASSIGN_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR2, SSOE , A_SPICfgPtConfigPtr->mode);
		/*Now start the SPI Peripheral*/
		SET_BIT(A_SPICfgPtConfigPtr->SPIChannel->CR1, SPE );

		break;
	}


	default:
	{
		return L_BoolErrorState;
		break;
	}
	}



	return L_BoolErrorState;

}


/*********************************************************************************************/


Bool MSPI_BoolTransceiveFrame(SPI_cfg *A_UARTCfgPtConfigPtr, u16 A_u16FrameSent, u16* A_u16PtFrameRecPtr)
{
	Bool L_BoolErrorState = 1;
	/*Wait for the Tx buffer to be empty, then write onto it to start the sending process*/
	while(((A_UARTCfgPtConfigPtr->SPIChannel->SR)&(1<<TXE)) == 0);
	A_UARTCfgPtConfigPtr->SPIChannel->DR = A_u16FrameSent;
	/*Wait for the Rx buffer to be full, then read its value to start the reception process*/
	while(((A_UARTCfgPtConfigPtr->SPIChannel->SR)&(1<<RXNE)) == 0);
	*A_u16PtFrameRecPtr = A_UARTCfgPtConfigPtr->SPIChannel->DR;
	/*Wait for the Tx buffer to be empty, which means the sent frame already left the node*/
	while(((A_UARTCfgPtConfigPtr->SPIChannel->SR)&(1<<TXE)) == 0);
	/*Check of either a master-mode fault or and overrun error occurred due to data exchange*/
	if((((A_UARTCfgPtConfigPtr->SPIChannel->SR)&(1<<OVR)) != 0) || (((A_UARTCfgPtConfigPtr->SPIChannel->SR)&(1<<MODF)) != 0))
	{
		L_BoolErrorState = 0;
	}



	return L_BoolErrorState;
}


