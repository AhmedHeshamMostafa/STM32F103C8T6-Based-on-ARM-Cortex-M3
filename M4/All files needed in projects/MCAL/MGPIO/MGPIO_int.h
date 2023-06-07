/*
 * MGPIO_int.h
 *
 *  Created on: May 29, 2023
 *      Author: Ahmed
 */

#ifndef MGPIO_INT_H
#define MGPIO_INT_H

/****************** FORBIDDEN PINS ARE PINS PA13, PA14, PA15, PB3, AND PB4 *****************************/

/*This software is guarded against accessing the forbidden pins in STM32f401CC microcontroller*/
/*If you try to call any of the 5 provided functions with a port ID and a pin number that correspond*/
/*to a forbidden pin, the software will exit and return an error state to you.*/






#define       PA             0
#define       PB             1
#define       PC             2
#define       PD             3
#define       PE             4
#define       PH             5


#define       PIN0              0
#define       PIN1              1
#define       PIN2              2
#define       PIN3              3
#define       PIN4              4
#define       PIN5              5
#define       PIN6              6
#define       PIN7              7
#define       PIN8              8
#define       PIN9              9
#define       PIN10             10
#define       PIN11             11
#define       PIN12             12
#define       PIN13             13
#define       PIN14             14
#define       PIN15             15



#define       INPUT             0b00
#define       OUTPUT            0b01
#define       ALTERNATE_FN      0b10
#define       ANALOG            0b11



#define      IN_FLOATING        0b00
#define      IN_PULL_UP         0b01
#define      IN_PULL_DOWN       0b10




#define       OUT_PUSH_PULL     0
#define       OUT_OPEN_DRAIN    1



#define       OUT_LOW_SPEED     0b00
#define       OUT_MED_SPEED     0b01
#define       OUT_HIGH_SPEED    0b10
#define       OUT_VHIGH_SPEED   0b11




#define       TIM1_OR_2            0b0001
#define       TIM3_TO_5            0b0010
#define       TIM9_TO_11           0b0011
#define       I2C1_TO_3            0b0100
#define       SPI1_TO_4            0b0101
#define       SPI_3                0b0110
#define       USART1_OR_2          0b0111
#define       USART_6              0b1000
#define       I2C2_OR_3            0b1001
#define       OTG_FS               0b1010

#define       SD_IO                0b1100


#define       EVENTOUT             0b1111




/*Successful return        : L_u8ErrorState = 0x00*/
/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
/*Wrong pin number entered : L_u8ErrorState = 0x03*/
/*Wrong pin mode entered   : L_u8ErrorState = 0x04*/
/*Forbidden pin entered    : L_u8ErrorState = 0x05*/
u8 MGPIO_u8CfgPinMode(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, u8 Cpy_u8PinMode);


/*Successful return          : L_u8ErrorState = 0x00*/
/*Wrong port ID entered      : L_u8ErrorState = 0x02*/
/*Wrong pin number entered   : L_u8ErrorState = 0x03*/
/*Wrong output type entered  : L_u8ErrorState = 0x04*/
/*Wrong output speed entered : L_u8ErrorState = 0x05*/
/*Forbidden pin entered      : L_u8ErrorState = 0x06*/
u8 MGPIO_u8CfgOutPin (u8 Cpy_u8PortID, u8 Cpy_u8PinNum, Bool Cpy_BoolOutType, u8 Cpy_u8OutSpeed);


/*Successful return        : L_u8ErrorState = 0x00*/
/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
/*Wrong pin number entered : L_u8ErrorState = 0x03*/
/*Wrong input type entered : L_u8ErrorState = 0x04*/
/*Forbidden pin entered    : L_u8ErrorState = 0x05*/
u8 MGPIO_u8CfgInPin (u8 Cpy_u8PortID, u8 Cpy_u8PinNum, u8 Cpy_u8InType);


/*Successful return        : L_u8ErrorState = 0x00*/
/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
/*Wrong pin number entered : L_u8ErrorState = 0x03*/
/*Forbidden pin entered    : L_u8ErrorState = 0x04*/
u8 MGPIO_u8WritePinVal (u8 Cpy_u8PortID, u8 Cpy_u8PinNum, Bool Cpy_BoolVal);


/*Successful return        : L_u8ErrorState = 0x00*/
/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
/*Wrong pin number entered : L_u8ErrorState = 0x03*/
/*Forbidden pin entered    : L_u8ErrorState = 0x04*/
u8 MGPIO_u8ReadPinVal(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, Bool *Cpy_BoolPtReadPtr);


u8 MGPIO_u8SetAF(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, u8 Cpy_u8AFID);



#endif
