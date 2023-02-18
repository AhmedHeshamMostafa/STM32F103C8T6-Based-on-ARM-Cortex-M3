/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 10 Feb 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

#include "RCC_prv.h"



/*********************************************************************************/
/*  Configuration parameters for clock sources that RCC supports in the family   */
/*********************************************************************************/

#define      HSE_BYP              0
#define      HSE_NBYP             1
#define      HSI                  2
#define      PLL_HSE     	      3
#define      PLL_HSE_OVER2        4
#define      PLL_HSI_OVER2        5

#define      PLL_IN_X2            0b0000
#define      PLL_IN_X3            0b0001
#define      PLL_IN_X4            0b0010
#define      PLL_IN_X5            0b0011
#define      PLL_IN_X6            0b0100
#define      PLL_IN_X7            0b0101
#define      PLL_IN_X8     		  0b0110
#define      PLL_IN_X9            0b0111
#define      PLL_IN_X10           0b1000
#define      PLL_IN_X11           0b1001
#define      PLL_IN_X12           0b1010
#define      PLL_IN_X13           0b1011
#define      PLL_IN_X14           0b1100
#define      PLL_IN_X15           0b1101
#define      PLL_IN_X16           0b1110




/*********************************************************************************/
/*        Configuration parameters for prescalers of APB1, APB2, and AHB         */
/*********************************************************************************/

#define      APB_HCLK             0b000
#define      APB_HCLK_OVER2       0b100
#define      APB_HCLK_OVER4       0b101
#define      APB_HCLK_OVER8       0b110
#define      APB_HCLK_OVER16      0b111

#define      AHB_SYSCLK           0b0000
#define      AHB_SYSCLK_OVER2     0b1000
#define      AHB_SYSCLK_OVER4     0b1001
#define      AHB_SYSCLK_OVER8     0b1010
#define      AHB_SYSCLK_OVER16    0b1011
#define      AHB_SYSCLK_OVER64    0b1100
#define      AHB_SYSCLK_OVER128   0b1101
#define      AHB_SYSCLK_OVER256   0b1110
#define      AHB_SYSCLK_OVER512   0b1111




/*********************************************************************************/
/*                         IDs for peripherals in AHB                            */
/*********************************************************************************/

#define         DMA1              DMA1EN
#define         DMA2              DMA2EN
#define         SRAM              SRAMEN
/*********************************/
#define         FLITF             FLITFEN
/*********************************/
#define         CRC               CRCEN
/*********************************/
#define         FSMC              FSMCEN
/*********************************/
#define         SDIO              SDIOEN
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/




/*********************************************************************************/
/*                         IDs for peripherals in APB2                           */
/*********************************************************************************/

#define         AFIO              AFIOEN
/*********************************/
#define         IOPA              IOPAEN
#define         IOPB              IOPBEN
#define         IOPC              IOPCEN
#define         IOPD              IOPDEN
#define         IOPE              IOPEEN
#define         IOPF              IOPFEN
#define         IOPG              IOPGEN
#define         ADC1              ADC1EN
#define         ADC2              ADC2EN
#define         TIM1              TIM1EN
#define         SPI1              SPI1EN
#define         TIM8              TIM8EN
#define         USART1            USART1EN
#define         ADC3              ADC3EN
/*********************************/
/*********************************/
/*********************************/
#define         TIM9              TIM9EN
#define         TIM10             TIM10EN
#define         TIM11             TIM11EN
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/




/*********************************************************************************/
/*                         IDs for peripherals in APB1                           */
/*********************************************************************************/

#define         TIM2              TIM2EN
#define         TIM3              TIM3EN
#define         TIM4              TIM4EN
#define         TIM5              TIM5EN
#define         TIM6              TIM6EN
#define         TIM7              TIM7EN
#define         TIM12             TIM12EN
#define         TIM13             TIM13EN
#define         TIM14             TIM14EN
/*********************************/
/*********************************/
#define         WWDG              WWDGEN
/*********************************/
/*********************************/
#define         SPI2              SPI2EN
#define         SPI3              SPI3EN
/*********************************/
#define         USART2            USART2EN
#define         USART3            USART3EN
#define         UART4             UART4EN
#define         UART5             UART5EN
#define         I2C1              I2C1EN
#define         I2C2              I2C2EN
#define         USB               USBEN
/*********************************/
#define         CAN               CANEN
/*********************************/
#define         BKP               BKPEN
#define         PWR               PWREN
#define         DAC               DACEN
/*********************************/
/*********************************/




/*********************************************************************************/
/*        Enable and disable symbols to be used by the user of this driver       */
/*********************************************************************************/

#define      ENABLE               1
#define      DISABLE              0




/*********************************************************************************/
/*                   IDs for buses available in the family                       */
/*********************************************************************************/

#define      AHB                  0
#define      APB2                 1
#define      APB1                 2




/*********************************************************************************/

void MRCC_vInit            (void)                      ;
Bool MRCC_BoolEnableClock  (u8 A_u8BusID, u8 A_u8PerID);
Bool MRCC_BoolDisableClock (u8 A_u8BusID, u8 A_u8PerID);
Bool MRCC_BoolResetPer     (u8 A_u8BusID, u8 A_u8PerID);

/*********************************************************************************/


#endif /* MCAL_RCC_RCC_INT_H_ */
