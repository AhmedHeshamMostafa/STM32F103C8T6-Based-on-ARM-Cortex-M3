/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 8 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef HAL_WIFI_WIFI_INT_H_
#define HAL_WIFI_WIFI_INT_H_

#include "../../MCAL/UART/UART_int.h"


typedef struct
{
	UARTChID_t UARTChIDChannel;

}Wifi_cfg;



Bool HWifi_BoolInit(Wifi_cfg *A_WifiCfgPtConfigPtr);
Bool HWIFI_BoolConnNetwork(u8 *A_u8PtNetNamePtr, u8 A_u8NetNameSize, u8 *A_u8PtNetPassPtr, u8 A_u8NetPassSize);
Bool HWIFI_BoolDisconnNetwork(void);
Bool HWIFI_BoolConnServer(u8 *A_u8PtDomainNamePtr, u8 A_u8DomNameSize, u8 *A_u8PtPortNumPtr, u8 A_u8PortNumSize);
Bool HWIFI_BoolDisconnServer(void);
Bool HWIFI_BoolSendData(u8 *A_u8PtDataPtr, u8 *A_DataSizeStr, u8 A_DataSizeu8);



#endif /* HAL_WIFI_WIFI_INT_H_ */
