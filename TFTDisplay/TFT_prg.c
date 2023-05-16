/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 7 May 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Delay/Delay_int.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SPI/SPI_int.h"
#include "TFT_int.h"

static u16 Su16_xPixels;
static u16 Su16_yPixels;

/*L_u8RecData is not used, it's just created for consistency with the MSPI_BoolTransceiveFrame interface*/
static u8 L_u8RecData;

static SPI_cfg SPICfgConfig_TFT = {.mode = SPI_MASTER,
		                           .frameSize = EIGHTBIT_FRAME,
								   .dataOrder = MSB_FIRST,
								   .SPIClkPol = IDLE_HIGH,
								   .SPIClkPhase = SAMPLE_2ND_EDGE,
								   .APB2Freq = 4000000
								  };




Bool HTFT_BoolInit(TFT_cfg* A_TFTCfgPtrConfig)
{
	Bool L_BoolErrorState = 1;

	if(((A_TFTCfgPtrConfig->SPIChannel) != SPI_ONE) && ((A_TFTCfgPtrConfig->SPIChannel) != SPI_TWO_I2S) && ((A_TFTCfgPtrConfig->SPIChannel) != SPI_THREE_I2S))
	{
		L_BoolErrorState = 0;
	}


	if(((A_TFTCfgPtrConfig->colorMode) != RGB444ID) && ((A_TFTCfgPtrConfig->colorMode) != RGB565ID) && ((A_TFTCfgPtrConfig->colorMode) != RGB565ID))
	{
		L_BoolErrorState = 0;
	}


	switch((A_TFTCfgPtrConfig->RESPort))
	{
	case PA ... PG:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
	}
	}


	switch((A_TFTCfgPtrConfig->DCPort))
	{
	case PA ... PG:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
	}
	}


	switch((A_TFTCfgPtrConfig->RESPin))
	{
	case P0 ... P15:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
	}
	}


	switch((A_TFTCfgPtrConfig->DCPin))
	{
	case P0 ... P15:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
	}
	}


	switch (L_BoolErrorState)
	{
	case 1:
	{
		u32 L_u32SPIBRClkFreq = 0;
		u8  L_u8SPIBRClkPres = 0;
		u8 L_u8BRBitVal = 1;
		u8 L_u8divCount = 0;

		MRCC_vInit();
		MRCC_BoolEnableClock(APB2, AFIO);

		if((A_TFTCfgPtrConfig->SPIChannel) == SPI_ONE)
		{
			L_u32SPIBRClkFreq = (u32)((SPICfgConfig_TFT.APB2Freq) / 2);

			if(L_u32SPIBRClkFreq <= 12000000)
			{
				SPICfgConfig_TFT.SPIBaudRate = FPCLK_OVER2;
			}

			else
			{
				while((L_u32SPIBRClkFreq > 12000000) && (L_u8SPIBRClkPres <=6))
				{
					L_u8SPIBRClkPres++;

					for(L_u8divCount = 0; L_u8divCount <=  L_u8SPIBRClkPres; L_u8divCount++)
					{
						L_u8BRBitVal *= 2;
					}

					L_u32SPIBRClkFreq = (u32)((SPICfgConfig_TFT.APB2Freq) / L_u8divCount);
				}
			}

			MRCC_BoolEnableClock(APB2, SPI1);
		}


		else
		{
			L_u32SPIBRClkFreq = (u32)((SPICfgConfig_TFT.APB1Freq) / 2);

			if(L_u32SPIBRClkFreq <= 12000000)
			{
				SPICfgConfig_TFT.SPIBaudRate = FPCLK_OVER2;
			}

			else
			{
				while((L_u32SPIBRClkFreq > 12000000) && (L_u8SPIBRClkPres <=6))
				{
					L_u8SPIBRClkPres++;

					for(L_u8divCount = 0; L_u8divCount <=  L_u8SPIBRClkPres; L_u8divCount++)
					{
						L_u8BRBitVal *= 2;
					}

					L_u32SPIBRClkFreq = (u32)((SPICfgConfig_TFT.APB1Freq) / L_u8divCount);
				}
			}

			MRCC_BoolEnableClock(APB1, SPI2);
		}


		if(L_u8SPIBRClkPres !=7)
		{
			SPICfgConfig_TFT.SPIBaudRate = L_u8BRBitVal;
			SPICfgConfig_TFT.SPIChannel = A_TFTCfgPtrConfig->SPIChannel;
		}

		else
		{
			L_BoolErrorState = 0;
			break;
		}


		switch((A_TFTCfgPtrConfig->RESPort))
		{
		case PA:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			break;
		}

		case PB:
		{
			MRCC_BoolEnableClock(APB2, IOPB);
			break;
		}

		case PC:
		{
			MRCC_BoolEnableClock(APB2, IOPC);
			break;
		}

		case PD:
		{
			MRCC_BoolEnableClock(APB2, IOPD);
			break;
		}

		case PE:
		{
			MRCC_BoolEnableClock(APB2, IOPE);
			break;
		}

		case PF:
		{
			MRCC_BoolEnableClock(APB2, IOPF);
			break;
		}

		case PG:
		{
			MRCC_BoolEnableClock(APB2, IOPG);
			break;
		}
		}



		switch((A_TFTCfgPtrConfig->DCPort))
		{
		case PA:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			break;
		}

		case PB:
		{
			MRCC_BoolEnableClock(APB2, IOPB);
			break;
		}

		case PC:
		{
			MRCC_BoolEnableClock(APB2, IOPC);
			break;
		}

		case PD:
		{
			MRCC_BoolEnableClock(APB2, IOPD);
			break;
		}

		case PE:
		{
			MRCC_BoolEnableClock(APB2, IOPE);
			break;
		}

		case PF:
		{
			MRCC_BoolEnableClock(APB2, IOPF);
			break;
		}

		case PG:
		{
			MRCC_BoolEnableClock(APB2, IOPG);
			break;
		}
		}

		MGPIO_vInit();
		MGPIO_BoolSetPinDir(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->RESPin, OUTPUT_10M);
		MGPIO_BoolSetPinDir(A_TFTCfgPtrConfig->DCPort, A_TFTCfgPtrConfig->DCPin, OUTPUT_10M);

		MSPI_BoolInit(&SPICfgConfig_TFT);

		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->RESPin, 1);
		delay_us(100);
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->RESPin, 0);
		delay_us(1);
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->RESPin, 1);
		delay_us(100);
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->RESPin, 0);
		delay_us(100);
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->RESPin, 1);
		delay_us(120000);

		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->DCPort, A_TFTCfgPtrConfig->DCPin, 0);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)0x11, (u16*)(&L_u8RecData));
		delay_us(10000);
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->DCPort, A_TFTCfgPtrConfig->DCPin, 0);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)0x3A, (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)(A_TFTCfgPtrConfig->colorMode), (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->DCPort, A_TFTCfgPtrConfig->DCPin, 0);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)0x29, (u16*)(&L_u8RecData));

		/*Set the horizontal boundaries for the display*/
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->DCPort, A_TFTCfgPtrConfig->DCPin, 0);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)0x2A, (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, 0, (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, 0, (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)((((A_TFTCfgPtrConfig->horPixels)-1)&(0xFF00))>>8), (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)(((A_TFTCfgPtrConfig->horPixels)-1)&(0x00FF)), (u16*)(&L_u8RecData));
		Su16_xPixels = A_TFTCfgPtrConfig->horPixels;
		/*Set the vertical boundaries for the display*/
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->DCPort, A_TFTCfgPtrConfig->DCPin, 0);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)0x2B, (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, 0, (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)((((A_TFTCfgPtrConfig->verPixels)-1)&(0xFF00))>>8), (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, 0, (u16*)(&L_u8RecData));
		MGPIO_BoolWritePin(A_TFTCfgPtrConfig->RESPort, A_TFTCfgPtrConfig->DCPin, 1);
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (u16)(((A_TFTCfgPtrConfig->verPixels)-1)&(0x00FF)), (u16*)(&L_u8RecData));
		Su16_yPixels = A_TFTCfgPtrConfig->verPixels;

		break;
	}


	default:
	{
		break;
	}

	}


	return L_BoolErrorState;
}


/*******************************************************************/


void HTFT_BoolDisplayFrame(const u32* A_u32PtrFrameArr)
{
	u32  L_u32TotalPixelsNo = (u32)(Su16_xPixels*Su16_yPixels);

	for(u32 L_u32pixelDataCount = 0; L_u32pixelDataCount <  L_u32TotalPixelsNo; L_u32pixelDataCount++)
	{
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, ((A_u32PtrFrameArr[L_u32pixelDataCount])&(0xFF000000))>>24, (u16*)(&L_u8RecData));
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, ((A_u32PtrFrameArr[L_u32pixelDataCount])&(0x00FF0000))>>16, (u16*)(&L_u8RecData));
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, ((A_u32PtrFrameArr[L_u32pixelDataCount])&(0x0000FF00))>>8, (u16*)(&L_u8RecData));
		(void)MSPI_BoolTransceiveFrame(&SPICfgConfig_TFT, (A_u32PtrFrameArr[L_u32pixelDataCount])&(0x000000FF), (u16*)(&L_u8RecData));
	}
}

