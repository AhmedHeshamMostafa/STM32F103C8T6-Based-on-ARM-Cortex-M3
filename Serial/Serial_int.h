/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 2 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef HAL_SERIAL_SERIAL_INT_H_
#define HAL_SERIAL_SERIAL_INT_H_

#include "../../MCAL/UART/UART_int.h"




typedef struct
{
	UARTChID_t UARTChIDChannel;
	u32 u32baudRate;

}Serial_cfg;





Bool HSerial_BoolInit(Serial_cfg *A_SerCfgPtConfigPtr);
void HSerial_vSendByte(u8 A_u8SentData);
void HSerial_vSendArr(u8 *A_u8PtFirstBytePtr, u8 A_u8BytesNo);



#endif /* HAL_SERIAL_SERIAL_INT_H_ */
