/*
 * SPI_prg.c
 *
 *  Created on: Jun 8, 2023
 *      Author: Ahmed
 */


#include"../../LIB/STD_TYPES.h"
#include"SPI_prv.h"
#include"SPI_int.h"


Bool MSPI_BoolInit(SPICfg_t*SPICfgPtConfigPtr)
{
	/*Successful return : L_BoolErrorState = 0*/
	/*Invalid configuration parameter entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState;

	switch(SPICfgPtConfigPtr->baudRate)
	{
	case FPCLK_OVER2 ... FPCLK_OVER256:
		L_BoolErrorState = 0;
		break;

	default:
		L_BoolErrorState = 1;
		break;
	}


	switch(SPICfgPtConfigPtr->channelID)
	{
	case SPI_CH1 ... SPI_CH4:
		L_BoolErrorState = 0;
		break;
	default:
		L_BoolErrorState = 1;
		break;
	}


	switch(SPICfgPtConfigPtr->clkPol)
	{
	case IDLE_LOW:
	case IDLE_HIGH:
		L_BoolErrorState = 0;
		break;
	default:
		L_BoolErrorState = 1;
		break;
	}


	switch(SPICfgPtConfigPtr->clkPhase)
	{
	case SAMPLE_1ST_EDGE:
	case SAMPLE_2ND_EDGE:
		L_BoolErrorState = 0;
		break;
	default:
		L_BoolErrorState = 1;
		break;
	}


	switch(SPICfgPtConfigPtr->dataOrder)
	{
	case LSB_FIRST:
	case MSB_FIRST:
		L_BoolErrorState = 0;
		break;
	default:
		L_BoolErrorState = 1;
		break;
	}


	switch(SPICfgPtConfigPtr->frameSize)
	{
	case EIGHTBIT_FRAME:
	case SIXTEENBIT_FRAME:
		L_BoolErrorState = 0;
		break;
	default:
		L_BoolErrorState = 1;
		break;
	}



	switch(SPICfgPtConfigPtr->nodeMode)
	{
	case MASTER:
	case SLAVE:
		L_BoolErrorState = 0;
		break;
	default:
		L_BoolErrorState = 1;
		break;
	}




	switch(L_BoolErrorState)
	{
	case 0:
		switch(SPICfgPtConfigPtr->channelID)
		{
		case SPI_CH1:
			(SPICHANNEL1->CR1) &= ~(BRMASK<<BR0);
			(SPICHANNEL1->CR1) |= (SPICfgPtConfigPtr->baudRate)<<BR0;

			(SPICHANNEL1->CR1) &= ~(CLKPOLMASK<<CPOL);
			(SPICHANNEL1->CR1) |= (SPICfgPtConfigPtr->clkPol)<<CPOL;

			(SPICHANNEL1->CR1) &= ~(CLKPHASEMASK<<CPHA);
			(SPICHANNEL1->CR1) |= (SPICfgPtConfigPtr->clkPhase)<<CPHA;

			(SPICHANNEL1->CR1) &= ~(DATAORDERMASK<<LSBFIRST);
			(SPICHANNEL1->CR1) |= (SPICfgPtConfigPtr->dataOrder)<<LSBFIRST;

			(SPICHANNEL1->CR1) &= ~(FRAMESIZEMASK<<DFF);
			(SPICHANNEL1->CR1) |= (SPICfgPtConfigPtr->frameSize)<<DFF;

			(SPICHANNEL1->CR1) &= ~(NODEMODEMASK<<MSTR);
			(SPICHANNEL1->CR1) |= (SPICfgPtConfigPtr->nodeMode)<<MSTR;

			break;

		case SPI_CH2:
			(SPICHANNEL2->CR1) &= ~(BRMASK<<BR0);
			(SPICHANNEL2->CR1) |= (SPICfgPtConfigPtr->baudRate)<<BR0;

			(SPICHANNEL2->CR1) &= ~(CLKPOLMASK<<CPOL);
			(SPICHANNEL2->CR1) |= (SPICfgPtConfigPtr->clkPol)<<CPOL;

			(SPICHANNEL2->CR1) &= ~(CLKPHASEMASK<<CPHA);
			(SPICHANNEL2->CR1) |= (SPICfgPtConfigPtr->clkPhase)<<CPHA;

			(SPICHANNEL2->CR1) &= ~(DATAORDERMASK<<LSBFIRST);
			(SPICHANNEL2->CR1) |= (SPICfgPtConfigPtr->dataOrder)<<LSBFIRST;

			(SPICHANNEL2->CR1) &= ~(FRAMESIZEMASK<<DFF);
			(SPICHANNEL2->CR1) |= (SPICfgPtConfigPtr->frameSize)<<DFF;

			(SPICHANNEL2->CR1) &= ~(NODEMODEMASK<<MSTR);
			(SPICHANNEL2->CR1) |= (SPICfgPtConfigPtr->nodeMode)<<MSTR;
			break;

		case SPI_CH3:
			(SPICHANNEL3->CR1) &= ~(BRMASK<<BR0);
			(SPICHANNEL3->CR1) |= (SPICfgPtConfigPtr->baudRate)<<BR0;

			(SPICHANNEL3->CR1) &= ~(CLKPOLMASK<<CPOL);
			(SPICHANNEL3->CR1) |= (SPICfgPtConfigPtr->clkPol)<<CPOL;

			(SPICHANNEL3->CR1) &= ~(CLKPHASEMASK<<CPHA);
			(SPICHANNEL3->CR1) |= (SPICfgPtConfigPtr->clkPhase)<<CPHA;

			(SPICHANNEL3->CR1) &= ~(DATAORDERMASK<<LSBFIRST);
			(SPICHANNEL3->CR1) |= (SPICfgPtConfigPtr->dataOrder)<<LSBFIRST;

			(SPICHANNEL3->CR1) &= ~(FRAMESIZEMASK<<DFF);
			(SPICHANNEL3->CR1) |= (SPICfgPtConfigPtr->frameSize)<<DFF;

			(SPICHANNEL3->CR1) &= ~(NODEMODEMASK<<MSTR);
			(SPICHANNEL3->CR1) |= (SPICfgPtConfigPtr->nodeMode)<<MSTR;
			break;

		default:
			(SPICHANNEL4->CR1) &= ~(BRMASK<<BR0);
			(SPICHANNEL4->CR1) |= (SPICfgPtConfigPtr->baudRate)<<BR0;

			(SPICHANNEL4->CR1) &= ~(CLKPOLMASK<<CPOL);
			(SPICHANNEL4->CR1) |= (SPICfgPtConfigPtr->clkPol)<<CPOL;

			(SPICHANNEL4->CR1) &= ~(CLKPHASEMASK<<CPHA);
			(SPICHANNEL4->CR1) |= (SPICfgPtConfigPtr->clkPhase)<<CPHA;

			(SPICHANNEL4->CR1) &= ~(DATAORDERMASK<<LSBFIRST);
			(SPICHANNEL4->CR1) |= (SPICfgPtConfigPtr->dataOrder)<<LSBFIRST;

			(SPICHANNEL4->CR1) &= ~(FRAMESIZEMASK<<DFF);
			(SPICHANNEL4->CR1) |= (SPICfgPtConfigPtr->frameSize)<<DFF;

			(SPICHANNEL4->CR1) &= ~(NODEMODEMASK<<MSTR);
			(SPICHANNEL4->CR1) |= (SPICfgPtConfigPtr->nodeMode)<<MSTR;
			break;
		}

		break;


		default:
			break;

	}




	return L_BoolErrorState;

}




void MSPI_vEnableSPI(SPICfg_t*SPICfgPtConfigPtr)
{
	switch(SPICfgPtConfigPtr->channelID)
	{
	case SPI_CH1:
		(SPICHANNEL1->CR1) |= (1<<SPE);
		break;

	case SPI_CH2:
		(SPICHANNEL2->CR1) |= (1<<SPE);
		break;

	case SPI_CH3:
		(SPICHANNEL3->CR1) |= (1<<SPE);
		break;

	default:
		(SPICHANNEL4->CR1) |= (1<<SPE);
		break;
	}
}




void MSPI_vTransceiveFrame(SPICfg_t*SPICfgPtConfigPtr,u16 u16SentData, u16 *u16PtRecDataPtr)
{
	switch(SPICfgPtConfigPtr->channelID)
	{
	case SPI_CH1:
		while(((SPICHANNEL1->SR)&(1<<TXE)) == 0);
		SPICHANNEL1->DR = u16SentData;
		while(((SPICHANNEL1->SR)&(1<<RXNE)) == 0);
		*u16PtRecDataPtr = SPICHANNEL1->DR;
		while(((SPICHANNEL1->SR)&(1<<TXE)) == 0);

		break;

	case SPI_CH2:
		while(((SPICHANNEL2->SR)&(1<<TXE)) == 0);
		SPICHANNEL2->DR = u16SentData;
		while(((SPICHANNEL2->SR)&(1<<RXNE)) == 0);
		*u16PtRecDataPtr = SPICHANNEL2->DR;
		while(((SPICHANNEL2->SR)&(1<<TXE)) == 0);
		break;

	case SPI_CH3:
		while(((SPICHANNEL3->SR)&(1<<TXE)) == 0);
		SPICHANNEL3->DR = u16SentData;
		while(((SPICHANNEL3->SR)&(1<<RXNE)) == 0);
		*u16PtRecDataPtr = SPICHANNEL3->DR;
		while(((SPICHANNEL3->SR)&(1<<TXE)) == 0);
		break;

	default:
		while(((SPICHANNEL4->SR)&(1<<TXE)) == 0);
		SPICHANNEL4->DR = u16SentData;
		while(((SPICHANNEL4->SR)&(1<<RXNE)) == 0);
		*u16PtRecDataPtr = SPICHANNEL4->DR;
		while(((SPICHANNEL4->SR)&(1<<TXE)) == 0);
		break;
	}
}

