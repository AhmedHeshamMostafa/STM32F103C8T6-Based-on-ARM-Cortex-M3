/*
 * HShiftReg_prg.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Ahmed
 */

#include<LIB/STD_TYPES.h>
#include<MCAL/MRCC/MRCC_int.h>
#include<MCAL/MGPIO/MGPIO_int.h>
#include<HAL/HShiftRegister/HShiftReg_int.h>


u8  HShiftReg_u8Config(ShiftReg_cfg *Cpy_ShiftRegCfgPtConfigPtr)
{
	/*Successful return        : L_u8ErrorState = 0x00*/
	/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
	/*Wrong pin number entered : L_u8ErrorState = 0x03*/

	u8 L_u8ErrorState;

	MRCC_u8InitSysClk();


	if((Cpy_ShiftRegCfgPtConfigPtr->serialDataINPort) == PH)
	{
		MRCC_BoolEnablePerClk(GPIOH);
	}

	else
	{
		MRCC_BoolEnablePerClk((Cpy_ShiftRegCfgPtConfigPtr->serialDataINPort));
	}


	if((Cpy_ShiftRegCfgPtConfigPtr->clearPort) == PH)
	{
		MRCC_BoolEnablePerClk(GPIOH);
	}

	else
	{
		MRCC_BoolEnablePerClk((Cpy_ShiftRegCfgPtConfigPtr->clearPort));
	}


	if((Cpy_ShiftRegCfgPtConfigPtr->shiftClkPort) == PH)
	{
		MRCC_BoolEnablePerClk(GPIOH);
	}

	else
	{
		MRCC_BoolEnablePerClk((Cpy_ShiftRegCfgPtConfigPtr->shiftClkPort));
	}


	if((Cpy_ShiftRegCfgPtConfigPtr->latchClkPort) == PH)
	{
		MRCC_BoolEnablePerClk(GPIOH);
	}

	else
	{
		MRCC_BoolEnablePerClk((Cpy_ShiftRegCfgPtConfigPtr->latchClkPort));
	}






	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_ShiftRegCfgPtConfigPtr->serialDataINPort, Cpy_ShiftRegCfgPtConfigPtr->serialDataINPin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_ShiftRegCfgPtConfigPtr->clearPort, Cpy_ShiftRegCfgPtConfigPtr->clearPin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_ShiftRegCfgPtConfigPtr->shiftClkPort, Cpy_ShiftRegCfgPtConfigPtr->shiftClkPin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_ShiftRegCfgPtConfigPtr->latchClkPort, Cpy_ShiftRegCfgPtConfigPtr->latchClkPin, OUTPUT);

	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_ShiftRegCfgPtConfigPtr->serialDataINPort, Cpy_ShiftRegCfgPtConfigPtr->serialDataINPin, OUT_PUSH_PULL, OUT_HIGH_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_ShiftRegCfgPtConfigPtr->clearPort, Cpy_ShiftRegCfgPtConfigPtr->clearPin, OUT_PUSH_PULL, OUT_HIGH_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_ShiftRegCfgPtConfigPtr->shiftClkPort, Cpy_ShiftRegCfgPtConfigPtr->shiftClkPin, OUT_PUSH_PULL, OUT_HIGH_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_ShiftRegCfgPtConfigPtr->latchClkPort, Cpy_ShiftRegCfgPtConfigPtr->latchClkPin, OUT_PUSH_PULL, OUT_HIGH_SPEED);


	MGPIO_u8WritePinVal (Cpy_ShiftRegCfgPtConfigPtr->clearPort, Cpy_ShiftRegCfgPtConfigPtr->clearPin, LOW);
	MGPIO_u8WritePinVal (Cpy_ShiftRegCfgPtConfigPtr->clearPort, Cpy_ShiftRegCfgPtConfigPtr->clearPin, HIGH);



	return L_u8ErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/


void  HShiftReg_vParallelOut(ShiftReg_cfg *Cpy_ShiftRegCfgPtConfigPtr, u16 Cpy_u16SerialIn)
{


	for(u8 L_u8BitIndex=0; L_u8BitIndex<16; L_u8BitIndex++)
	{
		MGPIO_u8WritePinVal (Cpy_ShiftRegCfgPtConfigPtr->serialDataINPort, Cpy_ShiftRegCfgPtConfigPtr->serialDataINPin, (Cpy_u16SerialIn&(1<<(15-L_u8BitIndex)))>>(15-L_u8BitIndex));
		MGPIO_u8WritePinVal (Cpy_ShiftRegCfgPtConfigPtr->shiftClkPort, Cpy_ShiftRegCfgPtConfigPtr->shiftClkPin, LOW);
		MGPIO_u8WritePinVal (Cpy_ShiftRegCfgPtConfigPtr->shiftClkPort, Cpy_ShiftRegCfgPtConfigPtr->shiftClkPin, HIGH);
	}





	MGPIO_u8WritePinVal (Cpy_ShiftRegCfgPtConfigPtr->latchClkPort, Cpy_ShiftRegCfgPtConfigPtr->latchClkPin, LOW);
	MGPIO_u8WritePinVal (Cpy_ShiftRegCfgPtConfigPtr->latchClkPort, Cpy_ShiftRegCfgPtConfigPtr->latchClkPin, HIGH);


}
