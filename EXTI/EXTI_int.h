/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 Apr 2023                                             */
/*             VERSION  : V02                                                    */
/*********************************************************************************/

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#include "../AFIO/AFIO_prv.h"
#include "EXTI_prv.h"



/*********************************************************************************/
/*      Configuration parameters for EXTI that are supported in the family       */
/*********************************************************************************/

/*These are for BoolPinType*/
#define      INTERRUPT            0
#define      EVENT                1
/*These are for u8PinTrigger*/
#define      RISING_EDGE          0b01
#define      FALLING_EDGE         0b10
#define      CHANGE               0b11
/*These are for PortID_t*/
#define      PORTA                0b0000
#define      PORTB                0b0001
#define      PORTC                0b0010
#define      PORTD                0b0011
#define      PORTE                0b0100
#define      PORTF                0b0101
#define      PORTG                0b0110

/*These are for A_LineIDLine that is passed to MEXTI_BoolDisableLine,
  MEXTI_BoolSetSWInterrupt, and MEXTI_BoolClearSWInterrupt as an argument*/
#define      LINE0                0
#define      LINE1                1
#define      LINE2                2
#define      LINE3                3
#define      LINE4                4
#define      LINE5                5
#define      LINE6                6
#define      LINE7                7
#define      LINE8                8
#define      LINE9                9
#define      LINE10               10
#define      LINE11               11
#define      LINE12               12
#define      LINE13               13
#define      LINE14               14
#define      LINE15               15





typedef struct
{

	Bool      BoolPinType;
	u8        u8PinTrigger;
	PortID_t  PortIDPort;
	PinID_t   PinIDPin;


}EXTI_cfg;





void MEXTI_vInit(void);
Bool MEXTI_BoolEnableLine(EXTI_cfg *EXTICfgPtConfigPtr);
Bool MEXTI_BoolDisableLine(LineID_t A_LineIDLine);
Bool MEXTI_BoolSetSWInterrupt(LineID_t A_LineIDLine);
Bool MEXTI_BoolClearSWInterrupt(LineID_t A_LineIDLine);


#endif /* MCAL_EXTI_EXTI_INT_H_ */
