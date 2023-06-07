

#ifndef MCAL_UART_UART_PRV_H_
#define MCAL_UART_UART_PRV_H_


#define    UART1_BASE_ADDRESS         0x40011000
#define    UART2_BASE_ADDRESS         0x40004400
#define    UART6_BASE_ADDRESS         0x40011400 




typedef struct
{
	u32   SR;
	u32   DR;
	u32   BRR;
	u32   CR1;
	u32   CR2;
	u32   CR3;
	u32   GTPR;

}UART_MemMap_t;

typedef volatile UART_MemMap_t* UARTChID_t;




#define     CH1           (volatile UART_MemMap_t*)UART1_BASE_ADDRESS
#define     CH2           (volatile UART_MemMap_t*)UART2_BASE_ADDRESS
#define     CH6           (volatile UART_MemMap_t*)UART6_BASE_ADDRESS




/*********************************************************************************/
/*                 USART_SR register bits needed in UART_prg.c                   */
/*********************************************************************************/
#define        TXE        7
#define        TC         6
#define        RXNE       5

#define        ORERR      3
#define        NERR       2
#define        FERR       1
#define        PERR       0



/*********************************************************************************/
/*                 USART_CR1 register bits needed in UART_prg.c                  */
/*********************************************************************************/
#define        UE         13
#define        M          12

#define        PCE        10
#define        PS         9

#define        TE         3
#define        RE         2



/*********************************************************************************/
/*                 USART_CR2 register bits needed in UART_prg.c                  */
/*********************************************************************************/
#define        STOP1      13
#define        STOP0      12



/*********************************************************************************/

#endif /* MCAL_UART_UART_PRV_H_ */
