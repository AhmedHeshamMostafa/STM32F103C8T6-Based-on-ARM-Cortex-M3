/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 18 Feb 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_


/*********************************************************************************/
/*    Configuration parameters for GPIO pins that are supported in the family    */
/*********************************************************************************/

#define      INPUT                0
#define      OUTPUT_10M           1
#define      OUTPUT_2M            2
#define      OUTPUT_50M           3

#define      INP_ANALOG           4
#define      INP_FLOATING         5
#define      INP_PULL_DOWN        6
#define      INP_PULL_UP          7

#define      OUT_PUSH_PULL        8
#define      OUT_OPEN_DRAIN       9
#define      OUT_AF_PUSH_PULL     10
#define      OUT_AF_OPEN_DRAIN    11




/*********************************************************************************/
/*                    IDs for ports available in the family                      */
/*********************************************************************************/



#define         PA                0
#define         PB                1
#define         PC                2
#define         PD                3
#define         PE                4
#define         PF                5
#define         PG                6


/*********************************************************************************/
/*                    IDs for ports available in the family                      */
/*********************************************************************************/

#define      P0                   0
#define      P1                   1
#define      P2                   2
#define      P3                   3
#define      P4                   4
#define      P5                   5
#define      P6                   6
#define      P7                   7
#define      P8                   8
#define      P9                   9
#define      P10                  10
#define      P11                  11
#define      P12                  12
#define      P13                  13
#define      P14                  14
#define      P15                  15




/*********************************************************************************/

void MGPIO_vInit(void);
Bool MGPIO_BoolSetPinDir(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinMode);
Bool MGPIO_BoolSetInpCfg(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinConfig);
Bool MGPIO_BoolSetOutCfg(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinConfig);
Bool MGPIO_BoolReadPin(u8 A_u8Port, u8 A_u8Pin, Bool* A_BoolPtrData);
Bool MGPIO_BoolWritePin(u8 A_u8Port, u8 A_u8Pin, Bool A_BoolVal);
Bool MGPIO_BoolLockPin(u8 A_u8Port, u8 A_u8Pin);

/*********************************************************************************/


#endif /* MCAL_GPIO_GPIO_INT_H_ */
