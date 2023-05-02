/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 8 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Delay/Delay_int.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "Wifi_int.h"

extern u8 E_ArrtoModify[];


u8   S_u8ArrRec[30] = {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
		               '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
					   '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'};

static UART_cfg UARTCfgConfig_Wifi = {.UARTClk = 4000000,
									  .baudRate = 115200,
									  .charLength = CHAR_8BIT,
									  .parity = NO_PARITY,
									  .stopBits = STP_BITS1
                                	 };


Bool HWifi_BoolInit(Wifi_cfg *A_WifiCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	for(u8 i = 0; i < 30; i++)
	{
		S_u8ArrRec[i] = '1';
	}


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

		//MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+RST\r\n", 8);

		MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"ATE0\r\n", 6);
		delay_us(1000000);

		MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT\r\n", 4);
		MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 9);



		if((S_u8ArrRec[7] == 'O') && (S_u8ArrRec[8] == 'K'))
		{

			MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CWMODE_DEF=1\r\n", 17);
			MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 22);






			if((S_u8ArrRec[20] != 'O') || (S_u8ArrRec[21] != 'K'))
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

	for(u8 i = 0; i < 30; i++)
	{
			S_u8ArrRec[i] = '1';
	}


	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CWJAP_CUR=", 13);

	MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\"');

	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)A_u8PtNetNamePtr, A_u8NetNameSize);

	MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\"');
	MUART_BoolSendByte(&UARTCfgConfig_Wifi,',');
	MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\"');

	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)A_u8PtNetPassPtr, A_u8NetPassSize);

	MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\"');
	MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\r');
	MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\n');

	delay_us(1000);


	MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 30);



	if((S_u8ArrRec[21] != 'G') || (S_u8ArrRec[22] != 'O') || (S_u8ArrRec[23] != 'T'))
	{

		L_BoolErrorState = 0;

	}




	return L_BoolErrorState;

}



//		if((S_u8ArrRec[0] == 'O') && (S_u8ArrRec[1] == 'K'))
//		{
//			/*Set the ESP8266 to work  in Mode1 (Station Mode),
//			  and set this mode as the default mode*/
//			MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CWMODE_DEF=1\r\n", 17);
//			MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 2);
//
//			S_u8ArrRec[0] = E_ArrtoModify[2];
//			S_u8ArrRec[1] = E_ArrtoModify[3];
//
//			if((S_u8ArrRec[0] != 'O') || (S_u8ArrRec[1] != 'K'))
//			{
//				L_BoolErrorState = 0;
//			}
//		}
//
//		else
//		{
//			L_BoolErrorState = 0;
//		}
//



/*******************************************************************/


//Bool HWIFI_BoolConnNetwork(u8 *A_u8PtNetNamePtr, u8 A_u8NetNameSize, u8 *A_u8PtNetPassPtr, u8 A_u8NetPassSize)
//{
//	Bool L_BoolErrorState = 1;
//
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CWJAP_CUR=\"", 14);
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)A_u8PtNetNamePtr, A_u8NetNameSize);
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"\",\"", 3);
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)A_u8PtNetPassPtr, A_u8NetPassSize);
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"\"\r\n", 3);
//
//	//delay_us(2000000);
//	MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 2);
//
//	E_ArrtoModify[2] = S_u8ArrRec[0];
//	E_ArrtoModify[3] = S_u8ArrRec[1];
//
//	if((S_u8ArrRec[0] != 'O') || (S_u8ArrRec[1] != 'K'))
//	{
//		L_BoolErrorState = 0;
//	}
//
//	return L_BoolErrorState;
//
//}
//
//
///*******************************************************************/
//
//
//Bool HWIFI_BoolDisconnNetwork(void)
//{
//	Bool L_BoolErrorState = 1;
//
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CWQAP", 8);
//	MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 2);
//
//	if((S_u8ArrRec[0] != 'O') || (S_u8ArrRec[1] != 'K'))
//	{
//		L_BoolErrorState = 0;
//	}
//
//	return L_BoolErrorState;
//
//}
//
//
///*******************************************************************/
//
//



Bool HWIFI_BoolConnServer(u8 *A_u8PtDomainNamePtr, u8 A_u8DomNameSize, u8 *A_u8PtPortNumPtr, u8 A_u8PortNumSize)
{
	Bool L_BoolErrorState = 1;

	for(u8 i = 0; i < 30; i++)
	{
		S_u8ArrRec[i] = '2';
	}


	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CIPMUX=0\r\n", 13);



/*




		MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CIPSTART=", 12);

		MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\"');
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"TCP", 3);
		MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\"');

		MUART_BoolSendByte(&UARTCfgConfig_Wifi,',');

		MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\"');
		MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)A_u8PtDomainNamePtr, A_u8DomNameSize);
		MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\"');

		MUART_BoolSendByte(&UARTCfgConfig_Wifi,',');

		MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)A_u8PtPortNumPtr, A_u8PortNumSize);

		MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\r');
		MUART_BoolSendByte(&UARTCfgConfig_Wifi,'\n');


		MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 30);



		for(u8 i = 0; i < 30; i++)
		{
			E_ArrtoModify[i] = S_u8ArrRec[i];
		}




*/



	return L_BoolErrorState;
}



///*******************************************************************/
//
//
//Bool HWIFI_BoolDisconnServer(void)
//{
//	Bool L_BoolErrorState = 1;
//
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CIPCLOSE", 11);
//	MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 2);
//
//	if((S_u8ArrRec[0] != 'C') || (S_u8ArrRec[1] != 'L'))
//	{
//		L_BoolErrorState = 0;
//	}
//
//	return L_BoolErrorState;
//}
//
//
///*******************************************************************/
//
//
//Bool HWIFI_BoolSendData(u8 *A_u8PtDataPtr, u8 *A_DataSizeStr, u8 A_DataSizeu8)
//{
//	Bool L_BoolErrorState = 1;
//
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"AT+CIPSEND=", 11);
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)A_DataSizeStr, 3);
//
//	MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)"\r\n", 2);
//	MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 2);
//
//	S_u8ArrRec[0] = E_ArrtoModify[10];
//	S_u8ArrRec[1] = E_ArrtoModify[11];
//
//	if((S_u8ArrRec[0] == 'O') && (S_u8ArrRec[1] == 'K'))
//	{
//
//		MUART_BoolSendArr(&UARTCfgConfig_Wifi, (u8*)A_u8PtDataPtr, A_DataSizeu8);
//		/*2 seconds delay*/
//		delay_us(2000000);
//		MUART_BoolRecArr(&UARTCfgConfig_Wifi, S_u8ArrRec, 7);
//
//		S_u8ArrRec[0] = E_ArrtoModify[12];
//		S_u8ArrRec[1] = E_ArrtoModify[13];
//		S_u8ArrRec[2] = E_ArrtoModify[14];
//		S_u8ArrRec[3] = E_ArrtoModify[15];
//		S_u8ArrRec[4] = E_ArrtoModify[16];
//		S_u8ArrRec[5] = E_ArrtoModify[17];
//		S_u8ArrRec[6] = E_ArrtoModify[18];
//
//
//		if((S_u8ArrRec[5] != 'O') || (S_u8ArrRec[6] != 'K'))
//		{
//			L_BoolErrorState = 0;
//		}
//	}
//
//	else
//	{
//		L_BoolErrorState = 0;
//	}
//
//
//
//	return L_BoolErrorState;
//
//}
//
//
//
//
//
