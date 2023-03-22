/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 18 Mar 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_

#include "UART_prv.h"




typedef struct
{

	UARTChID_t channel;
	u32 UARTClk;
	u32 baudRate;
	u8 charLength;
	u8 parity;
	u8 stopBits;

}UART_cfg;


/*********************************************************************************/
/*     Configuration parameters for that basic UART supports in the family
 *     (No multiprocessor communication, No LIN mode, No synchronous mode,
 *     No single-wire half-duplex mode, No smartcard mode, No IrDA mode,
 *     No continuous communication.                                              */
/*********************************************************************************/



/* Character Length is 8 bits */
#define       CHAR_8BIT          0
/* Character Length is 9 bits */
#define       CHAR_9BIT          1

#define       EVEN_PARITY        0b10
#define       ODD_PARITY         0b11
#define       NO_PARITY          0b00

/* One Stop Bit  */
#define       STP_BITS1          0b00
/* Two Stop Bits */
#define       STP_BITS2          0b10





Bool MUART_BoolInit(UART_cfg *A_UARTCfgPtConfigPtr);
Bool MUART_BoolSendChar(UART_cfg *A_UARTCfgPtConfigPtr, u16 A_u16SentData);
u8 MUART_BoolRecChar(UART_cfg *A_UARTCfgPtConfigPtr, u16 *A_u16PtRecCharPtr);
Bool MUART_BoolSendArr(UART_cfg *A_UARTCfgPtConfigPtr, u16 *A_u16PtSentData, u16 A_u16SentDataSize);
u8 MUART_BoolRecArr(UART_cfg *A_UARTCfgPtConfigPtr, u16 *A_u16PtRecArrPtr, u16 A_u16RecDataSize);




#endif /* MCAL_UART_UART_INT_H_ */
