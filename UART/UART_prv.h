/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 18 Mar 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_UART_UART_PRV_H_
#define MCAL_UART_UART_PRV_H_


#define    UART1_BASE_ADDR         0x40013800
#define    UART2_BASE_ADDR         0x40004400
#define    UART3_BASE_ADDR         0x40004800
#define    UART4_BASE_ADDR         0x40004C00
#define    UART5_BASE_ADDR         0x40005000




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




#define     CH1           (volatile UART_MemMap_t*)UART1_BASE_ADDR
#define     CH2           (volatile UART_MemMap_t*)UART2_BASE_ADDR
#define     CH3           (volatile UART_MemMap_t*)UART3_BASE_ADDR
#define     CH4           (volatile UART_MemMap_t*)UART4_BASE_ADDR
#define     CH5           (volatile UART_MemMap_t*)UART5_BASE_ADDR



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
