/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 8 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "Wifi_int.h"


static u8   L_u8ArrSent[20];
u8   L_u8ArrRec[2];

static UART_cfg UARTCfgConfig_Wifi = {.UARTClk = 4000000,
									  .baudRate = 115200,
									  .charLength = CHAR_9BIT,
									  .parity = ODD_PARITY,
									  .stopBits = STP_BITS1
                                	 };


Bool HWifi_BoolInit(Wifi_cfg *A_WifiCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;


	if(((A_WifiCfgPtConfigPtr->UARTChIDChannel) == CH1) || ((A_WifiCfgPtConfigPtr->UARTChIDChannel) == CH2) || ((A_WifiCfgPtConfigPtr->UARTChIDChannel) == CH3))
	{
		UARTCfgConfig_Wifi.channel = (A_WifiCfgPtConfigPtr->UARTChIDChannel);
		MRCC_vInit();

		if((A_WifiCfgPtConfigPtr->UARTChIDChannel) == CH1)
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P9, OUTPUT_10M);
			MGPIO_BoolSetOutCfg(PA, P9, OUT_AF_PUSH_PULL);
			MRCC_BoolEnableClock(APB2, AFIO);
			MRCC_BoolEnableClock(APB2, USART1);
		}

		else if((A_WifiCfgPtConfigPtr->UARTChIDChannel) == CH2)
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


		MUART_BoolInit(&UARTCfgConfig_Wifi);

		L_u8ArrSent = "ATE0\r\n";
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 6);

		L_u8ArrSent = "AT\r\n";
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 4);
		MUART_BoolRecArr(&UARTCfgConfig_Wifi, L_u8ArrRec, 2);

		if((L_u8ArrRec[0] == 'O') && (L_u8ArrRec[1] == 'K'))
		{
			/*Set the to work ESP8266 in Mode1 (Station Mode),
			  and set this mode as the default mode*/
			L_u8ArrSent = "AT+CWMODE_DEF=1\r\n";
			MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 17);
			MUART_BoolRecArr(&UARTCfgConfig_Wifi, L_u8ArrRec, 2);

			if((L_u8ArrRec[0] != 'O') || (L_u8ArrRec[1] != 'K'))
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


	return L_BoolErrorState;

}


/*******************************************************************/


Bool HWIFI_BoolConnNetwork(u8 *A_u8PtNetNamePtr, u8 A_u8NetNameSize, u8 *A_u8PtNetPassPtr, u8 A_u8NetPassSize)
{
	Bool L_BoolErrorState = 1;

	L_u8ArrSent = "AT+CWJAP_CUR=\"";
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 14);
	L_u8ArrSent = A_u8PtNetNamePtr;
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, A_u8NetNameSize);
	L_u8ArrSent = "\",\"";
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 3);
	L_u8ArrSent = A_u8PtNetPassPtr;
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, A_u8NetPassSize);
	L_u8ArrSent = "\"\r\n";
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 3);

	MUART_BoolRecArr(&UARTCfgConfig_Wifi, L_u8ArrRec, 2);

	if((L_u8ArrRec[0] != 'O') || (L_u8ArrRec[1] != 'K'))
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;

}


/*******************************************************************/


Bool HWIFI_BoolDisconnNetwork(void)
{
	Bool L_BoolErrorState = 1;

	L_u8ArrSent = "AT+CWQAP";
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 8);
	MUART_BoolRecArr(&UARTCfgConfig_Wifi, L_u8ArrRec, 2);

	if((L_u8ArrRec[0] != 'O') || (L_u8ArrRec[1] != 'K'))
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;

}


/*******************************************************************/


Bool HWIFI_BoolConnServer(u8 *A_u8PtDomainNamePtr, u8 A_u8DomNameSize, u8 *A_u8PtPortNumPtr, u8 A_u8PortNumSize)
{
	Bool L_BoolErrorState = 1;

	L_u8ArrSent = "AT+CIPMUX=1";
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 11);
	MUART_BoolRecArr(&UARTCfgConfig_Wifi, L_u8ArrRec, 2);

	if((L_u8ArrRec[0] == 'O') && (L_u8ArrRec[1] == 'K'))
	{
		L_u8ArrSent = "AT+CIPSTART=\"TCP\",\"";
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 19);
		L_u8ArrSent = A_u8PtDomainNamePtr;
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, A_u8DomNameSize);
		L_u8ArrSent = "\",";
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 2);
		L_u8ArrSent = A_u8PtPortNumPtr;
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, A_u8PortNumSize);
		L_u8ArrSent = "\r\n";
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 2);

		MUART_BoolRecArr(&UARTCfgConfig_Wifi, L_u8ArrRec, 2);

		if((L_u8ArrRec[0] != 'O') || (L_u8ArrRec[1] != 'K'))
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


/*******************************************************************/


Bool HWIFI_BoolDisconnServer(void)
{
	Bool L_BoolErrorState = 1;

	L_u8ArrSent = "AT+CIPCLOSE";
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 11);
	MUART_BoolRecArr(&UARTCfgConfig_Wifi, L_u8ArrRec, 2);

	if((L_u8ArrRec[0] != 'O') || (L_u8ArrRec[1] != 'K'))
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;
}


/*******************************************************************/


Bool HWIFI_BoolSendData(u8 *A_u8PtDataPtr, u8 *A_DataSizeStr, u8 A_DataSizeu8)
{
	Bool L_BoolErrorState = 1;

	L_u8ArrSent = "AT+CIPSEND=";
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 11);
	L_u8ArrSent = A_DataSizeStr;
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, 3);
	L_u8ArrSent = A_u8PtDataPtr;
	MUART_BoolSendArr(&UARTCfgConfig_Wifi, L_u8ArrSent, A_DataSizeu8);

	MUART_BoolRecArr(&UARTCfgConfig_Wifi, L_u8ArrRec, 2);

	if((L_u8ArrRec[0] != 'S') || (L_u8ArrRec[1] != 'E'))
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}





