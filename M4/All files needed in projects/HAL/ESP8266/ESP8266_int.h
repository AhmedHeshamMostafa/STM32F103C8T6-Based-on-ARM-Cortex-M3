/*
 * ESP8266_int.h
 *
 *  Created on: Jun 12, 2023
 *      Author: Ahmed
 */

#ifndef HAL_ESP8266_INT_H_
#define HAL_ESP8266_INT_H_

Bool HESP_BoolTestModule(void);
Bool HESP_BoolDisableEcho(void);
Bool HESP_BoolEnableEcho(void);
Bool HESP_BoolResetModule(void);
Bool HESP_BoolConfigStationMode(void);
Bool HESP_BoolConnNetwork(u8 *Cpy_StrNetworkName, u8 Cpy_NetworkNameLen, u8 *Cpy_StrNetworkPassword, u8 Cpy_NetworkPWLen);
Bool HESP_BoolConnWebsite(u8 *Cpy_StrDomainName, u8 Cpy_u8DomainNameLen);
Bool HESP_BoolSendtoServer(u8 *Cpy_u8PtSentArr, u8* Cpy_u8PtSentArrLen, u8 Cpy_u8SentArrLen);



#endif /* HAL_ESP8266_INT_H_ */
