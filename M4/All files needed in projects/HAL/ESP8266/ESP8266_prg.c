/*
 * ESP8266_prg.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Ahmed
 */

#include"../../LIB/STD_TYPES.h"
#include"../../MCAL/UART/UART_int.h"
#include"ESP8266_int.h"

UART_cfg ESPCfgStruct = {.channel = CH1,
				         .UARTClk = 16000000,
                         .baudRate = 115200,
                         .charLength = CHAR_9BIT,
                         .parity = ODD_PARITY,
                         .stopBits = STP_BITS1};

//static char L_SentArr[20];
static u8 SG_RecArr[20];



Bool HESP_BoolTestModule(void)
{
	/*Successful return : L_ErrorState = 0*/
	/*Module is not working properly : L_ErrorState = 1*/


	Bool L_ErrorState = 1;

	u8 L_SentArr[] = "AT\r\n";

	MUART_BoolSendArr(&ESPCfgStruct, L_SentArr, 4);

	MUART_BoolRecArr(&ESPCfgStruct, SG_RecArr, 20);

	for(u8 L_u8RecIndex=0;  L_u8RecIndex<19; L_u8RecIndex++)
	{
		if((SG_RecArr[L_u8RecIndex] == 'O') && (SG_RecArr[L_u8RecIndex+1] == 'K'))
		{
			L_ErrorState = 0;
			L_u8RecIndex = 20;
		}
	}


	return L_ErrorState;

}





Bool HESP_BoolDisableEcho(void)
{
	/*Successful return : L_ErrorState = 0*/
	/*Echo did not get disabled correctly : L_ErrorState = 1*/


	Bool L_ErrorState = 1;

	u8 L_SentArr[] = "ATE0\r\n";

	MUART_BoolSendArr(&ESPCfgStruct, L_SentArr, 6);

	MUART_BoolRecArr(&ESPCfgStruct, SG_RecArr, 20);

	for(u8 L_u8RecIndex=0;  L_u8RecIndex<19; L_u8RecIndex++)
	{
		if((SG_RecArr[L_u8RecIndex] == 'O') && (SG_RecArr[L_u8RecIndex+1] == 'K'))
		{
			L_ErrorState = 0;
			L_u8RecIndex = 20;
		}
	}


	return L_ErrorState;

}





Bool HESP_BoolEnableEcho(void)
{
	/*Successful return : L_ErrorState = 0*/
	/*Echo did not get enabled correctly : L_ErrorState = 1*/


	Bool L_ErrorState = 1;

	u8 L_SentArr[] = "ATE1\r\n";

	MUART_BoolSendArr(&ESPCfgStruct, L_SentArr, 6);

	MUART_BoolRecArr(&ESPCfgStruct, SG_RecArr, 20);

	for(u8 L_u8RecIndex=0; L_u8RecIndex<19; L_u8RecIndex++)
	{
		if((SG_RecArr[L_u8RecIndex] == 'O') && (SG_RecArr[L_u8RecIndex+1] == 'K'))
		{
			L_ErrorState = 0;
			L_u8RecIndex = 20;
		}
	}


	return L_ErrorState;

}





Bool HESP_BoolResetModule(void)
{
	/*Successful return : L_ErrorState = 0*/
	/*Reset is not performed correctly : L_ErrorState = 1*/


	Bool L_ErrorState = 1;

	u8 L_SentArr[] = "AT+RST\r\n";

	MUART_BoolSendArr(&ESPCfgStruct, L_SentArr, 8);

	MUART_BoolRecArr(&ESPCfgStruct, SG_RecArr, 20);

	for(u8 L_u8RecIndex=0;  L_u8RecIndex<19; L_u8RecIndex++)
	{
		if((SG_RecArr[L_u8RecIndex] == 'O') && (SG_RecArr[L_u8RecIndex+1] == 'K'))
		{
			L_ErrorState = 0;
			L_u8RecIndex = 20;
		}
	}


	return L_ErrorState;

}





Bool HESP_BoolConfigStationMode(void)
{
	/*Successful return : L_ErrorState = 0*/
	/*Station mode is not configured correctly : L_ErrorState = 1*/


	Bool L_ErrorState = 1;

	u8 L_SentArr[] = "AT+CWMODE\r\n";

	MUART_BoolSendArr(&ESPCfgStruct, L_SentArr, 11);

	MUART_BoolRecArr(&ESPCfgStruct, SG_RecArr, 20);

	for(u8 L_u8RecIndex=0;  L_u8RecIndex<19; L_u8RecIndex++)
	{
		if((SG_RecArr[L_u8RecIndex] == 'O') && (SG_RecArr[L_u8RecIndex+1] == 'K'))
		{
			L_ErrorState = 0;
			L_u8RecIndex = 20;
		}
	}


	return L_ErrorState;

}






Bool HESP_BoolConnNetwork(u8 *Cpy_StrNetworkName, u8 Cpy_NetworkNameLen, u8 *Cpy_StrNetworkPassword, u8 Cpy_NetworkPWLen)
{
	/*Successful return : L_ErrorState = 0*/
	/*Could not connect to the network correctly : L_ErrorState = 1*/


	Bool L_ErrorState = 1;



	MUART_BoolSendArr(&ESPCfgStruct, (u8 *)"AT+CWJAP_CUR=\"", 13);
	MUART_BoolSendArr(&ESPCfgStruct, Cpy_StrNetworkName, Cpy_NetworkNameLen);


	MUART_BoolSendArr(&ESPCfgStruct, (u8 *)"\",", 2);
	MUART_BoolSendArr(&ESPCfgStruct, Cpy_StrNetworkPassword, Cpy_NetworkPWLen);


	MUART_BoolSendArr(&ESPCfgStruct, (u8 *)"\"\r\n", 3);


	/*Now the Network name and password are sent to the ESP8266*/
	MUART_BoolRecArr(&ESPCfgStruct, SG_RecArr, 20);

	for(u8 L_u8RecIndex=0;  L_u8RecIndex<19; L_u8RecIndex++)
	{
		if((SG_RecArr[L_u8RecIndex] == 'O') && (SG_RecArr[L_u8RecIndex+1] == 'K'))
		{
			L_ErrorState = 0;
			L_u8RecIndex = 20;
		}
	}


	return L_ErrorState;

}





Bool HESP_BoolConnWebsite(u8 *Cpy_StrDomainName, u8 Cpy_u8DomainNameLen)
{
	/*Successful return : L_ErrorState = 0*/
	/*Could not connect to the website correctly : L_ErrorState = 1*/


	Bool L_ErrorState = 1;


	MUART_BoolSendArr(&ESPCfgStruct, (u8 *)"AT+CIPSTART=\"TCP\",\"", 19);
	MUART_BoolSendArr(&ESPCfgStruct, Cpy_StrDomainName, Cpy_u8DomainNameLen);


	MUART_BoolSendArr(&ESPCfgStruct, (u8 *)"\",80\r\n", 6);




	MUART_BoolSendArr(&ESPCfgStruct, (u8 *)"\"\r\n", 3);


	/*Now the domain name has been sent to the ESP8266*/
	MUART_BoolRecArr(&ESPCfgStruct, SG_RecArr, 20);

	for(u8 L_u8RecIndex=0;  L_u8RecIndex<19; L_u8RecIndex++)
	{
		if((SG_RecArr[L_u8RecIndex] == 'O') && (SG_RecArr[L_u8RecIndex+1] == 'K'))
		{
			L_ErrorState = 0;
			L_u8RecIndex = 20;
		}
	}


	return L_ErrorState;

}






Bool HESP_BoolSendtoServer(u8 *Cpy_u8PtSentArr, u8* Cpy_u8PtSentArrLen, u8 Cpy_u8SentArrLen)
{
	/*Successful return : L_ErrorState = 0*/
	/*Data cannot be sent to the server correctly : L_ErrorState = 1*/


	Bool L_ErrorState = 1;


	MUART_BoolSendArr(&ESPCfgStruct, (u8 *)"AT+CIPSEND=", 11);
	MUART_BoolSendArr(&ESPCfgStruct, Cpy_u8PtSentArrLen, Cpy_u8SentArrLen);


	MUART_BoolSendArr(&ESPCfgStruct, (u8 *)"\r\n", 2);

	MUART_BoolSendArr(&ESPCfgStruct, Cpy_u8PtSentArr, Cpy_u8SentArrLen);


	/*Now the data has been sent to the server*/
	MUART_BoolRecArr(&ESPCfgStruct, SG_RecArr, 20);

	for(u8 L_u8RecIndex=0;  L_u8RecIndex<19; L_u8RecIndex++)
	{
		if((SG_RecArr[L_u8RecIndex] == 'O') && (SG_RecArr[L_u8RecIndex+1] == 'K'))
		{
			L_ErrorState = 0;
			L_u8RecIndex = 20;
		}
	}


	return L_ErrorState;

}








