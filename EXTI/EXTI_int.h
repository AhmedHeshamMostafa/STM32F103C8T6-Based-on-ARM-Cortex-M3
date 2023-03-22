/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 Mar 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_


/*********************************************************************************/
/*      Configuration parameters for EXTI that are supported in the family       */
/*********************************************************************************/

#define      INTERRUPT            0
#define      EVENT                1

#define      RISING_EDGE          0
#define      FALLING_EDGE         1
#define      CHANGE               2

#define      PORTA                0b0000
#define      PORTB                0b0001
#define      PORTC                0b0010
#define      PORTD                0b0011
#define      PORTE                0b0100
#define      PORTF                0b0101
#define      PORTG                0b0110




void MEXTI_vInit(void);
Bool MEXTI_BoolSetPinType(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinType);
Bool MEXTI_BoolSetPinTrigger(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinType);

#endif /* MCAL_EXTI_EXTI_INT_H_ */
