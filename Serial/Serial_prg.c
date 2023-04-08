/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 2 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "Serial_int.h"



static UART_cfg UARTCfgConfig = {.UARTClk = 4000000,
		                         .charLength = CHAR_9BIT,
		                         .parity = ODD_PARITY,
		                         .stopBits = STP_BITS1
                                };



Bool HSerial_BoolInit(Serial_cfg *A_SerCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	if(((A_SerCfgPtConfigPtr->UARTChIDChannel) == CH1) || ((A_SerCfgPtConfigPtr->UARTChIDChannel) == CH2) || ((A_SerCfgPtConfigPtr->UARTChIDChannel) == CH3))
	{
		UARTCfgConfig.channel = (A_SerCfgPtConfigPtr->UARTChIDChannel);
		UARTCfgConfig.baudRate = (A_SerCfgPtConfigPtr->u32baudRate);
		MRCC_vInit();

		if((A_SerCfgPtConfigPtr->UARTChIDChannel) == CH1)
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P9, OUTPUT_10M);
			MGPIO_BoolSetOutCfg(PA, P9, OUT_AF_PUSH_PULL);
			MRCC_BoolEnableClock(APB2, AFIO);
			MRCC_BoolEnableClock(APB2, USART1);
		}

		else if((A_SerCfgPtConfigPtr->UARTChIDChannel) == CH2)
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P2, OUTPUT_10M);
			MGPIO_BoolSetOutCfg(PA, P2, OUT_AF_PUSH_PULL);
			MRCC_BoolEnableClock(APB2, AFIO);
			MRCC_BoolEnableClock(APB1, USART2);
		}

		else
		{
			MRCC_BoolEnableClock(APB2, IOPB);
			MGPIO_BoolSetPinDir(PB, P10, OUTPUT_10M);
			MGPIO_BoolSetOutCfg(PB, P10, OUT_AF_PUSH_PULL);
			MRCC_BoolEnableClock(APB2, AFIO);
			MRCC_BoolEnableClock(APB1, USART3);
		}
		
		
		MUART_BoolInit(&UARTCfgConfig);

	}


	else
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}


/***********************************************************************************/


void HSerial_vSendByte(u8 A_u8SentData)
{
	MUART_BoolSendByte(&UARTCfgConfig, A_u8SentData);
}


/***********************************************************************************/


void HSerial_vSendArr(u8 *A_u8PtFirstBytePtr, u8 A_u8BytesNo)
{

	MUART_BoolSendArr(&UARTCfgConfig, A_u8PtFirstBytePtr, A_u8BytesNo);
}




