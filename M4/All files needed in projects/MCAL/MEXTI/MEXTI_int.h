/*
 * MEXTI_int.h
 *
 *  Created on: May 31, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_MEXTI_MEXTI_INT_H_
#define MCAL_MEXTI_MEXTI_INT_H_


typedef enum
{

	EXTIL0,
	EXTIL1,
	EXTIL2,
	EXTIL3,
	EXTIL4,
	EXTIL5,
	EXTIL6,
	EXTIL7,
	EXTIL8,
	EXTIL9,
	EXTIL10,
	EXTIL11,
	EXTIL12,
	EXTIL13,
	EXTIL14,
	EXTIL15

}EXTILine_t;




typedef enum
{
	RISINGEDGE,
	FALLINGEDGE,
	CHANGE

}triggerType_t;






u8 MEXTI_u8SetHWInterrupt(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, triggerType_t Cpy_trigTypeTrigger);
u8 MEXTI_u8SetHWEvent(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, triggerType_t Cpy_trigTypeTrigger);
Bool MEXTI_BoolSetSWInterrupt(EXTILine_t Cpy_EXTILineNum);
Bool MEXTI_BoolSetSWEvent(EXTILine_t Cpy_EXTILineNum);
Bool MEXTI_BoolIsPending(EXTILine_t Cpy_EXTILineNum);
Bool MEXTI_BoolClrPending(EXTILine_t Cpy_EXTILineNum);





#endif /* MCAL_MEXTI_MEXTI_INT_H_ */
