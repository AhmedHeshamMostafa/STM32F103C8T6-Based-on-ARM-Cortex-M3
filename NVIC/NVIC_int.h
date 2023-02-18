/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 16 Feb 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_NVIC_INT_H_
#define MCAL_NVIC_INT_H_


#define       FOURBIT_GRP           0b011
#define       THREEBIT_GRP          0b100
#define       TWOBIT_GRP            0b101
#define       ONEBIT_GRP            0b110
#define       ZEROBIT_GRP           0b111


#define    MEM_FAULT       -6
#define    BUS_FAULT       -5
#define    USAGE_FAULT     -4
#define    SVCALL          -3
#define    PENDSV          -2
#define    SYSTICK         -1
#define    WWDG            0
#define    PVD             1
#define    TAMPER          2
#define    RTC             3
#define    FLASH           4
#define    RCC             5
#define    EXTI0           6
#define    EXTI1           7
#define    EXTI2           8
#define    EXTI3           9
#define    EXTI4           10
#define    DMA1_CH1        11
#define    DMA1_CH2        12
#define    DMA1_CH3        13
#define    DMA1_CH4        14
#define    DMA1_CH5        15
#define    DMA1_CH6        16
#define    DMA1_CH7        17
#define    ADC1_2          18
#define    USB_HP_CAN_TX   19
#define    USB_LP_CAN_RX0  20
#define    CAN_RX1         21
#define    CAN_SCE         22
#define    EXTI9_5         23
#define    TIM1_BRK        24
#define    TIM1_UP         25
#define    TIM1_TRG_COM    26
#define    TIM1_CC         27
#define    TIM2            28
#define    TIM3            29
#define    TIM4            30
#define    I2C1_EV         31
#define    I2C1_ER         32
#define    I2C2_EV         33
#define    I2C2_ER         34
#define    SPI1            35
#define    SPI2            36
#define    USART1          37
#define    USART2          38
#define    USART3          39
#define    EXTI15_10       40
#define    RTCALARM        41
#define    USBWAKEUP       42
#define    TIM8_BRK        43
#define    TIM8_UP         44
#define    TIM8_TRG_COM    45
#define    TIM8_CC         46
#define    ADC3            47
#define    FSMC            48
#define    SDIO            49
#define    TIM5            50
#define    SPI3            51
#define    UART4           52
#define    UART5           53
#define    TIM6            54
#define    TIM7            55
#define    DMA2_Channel1   56
#define    DMA2_Channel2   57
#define    DMA2_Channel3   58
#define    DMA2_Channel4_5 59










void MNVIC_vInit(void);
Bool MNVIC_BoolSetPriority(s8 A_s8InterruptID, u8 A_u8Priority);
Bool MNVIC_BoolEnableInterrupt(u8 A_u8InterruptID);
Bool MNVIC_BoolDisableInterrupt(u8 A_u8InterruptID);
Bool MNVIC_BoolSetPending(u8 A_u8InterruptID);
Bool MNVIC_BoolClearPending(u8 A_u8InterruptID);
Bool MNVIC_BoolReadActiveState(u8 A_u8InterruptID, Bool* A_BoolPtrState);





#endif /* MCAL_NVIC_INT_H_ */
