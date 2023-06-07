/*
 * HLEDMTX_prg.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Ahmed
 */

#include<LIB/STD_TYPES.h>
#include<LIB/Delay_int.h>
#include<HAL/HShiftRegister/HShiftReg_int.h>
#include<HAL/HLEDMatrix/HLEDMTX_int.h>



u8  HLEDMTX_u8Config(LEDMTXCfg_t *Cpy_LEDMTXCfgPtConfigPtr)
{
	u8 L_u8ErrorState = HShiftReg_u8Config(Cpy_LEDMTXCfgPtConfigPtr);

	return L_u8ErrorState;
}


void HLEDMTX_vDisplayFrame(LEDMTXCfg_t *Cpy_LEDMTXCfgPtCfgPtr ,u16 *Cpy_u16ArrPinsVal)
{
	HShiftReg_vParallelOut(Cpy_LEDMTXCfgPtCfgPtr, Cpy_u16ArrPinsVal[0]);
	BoolDelay_us(2500);
	HShiftReg_vParallelOut(Cpy_LEDMTXCfgPtCfgPtr, Cpy_u16ArrPinsVal[1]);
	BoolDelay_us(2500);
	HShiftReg_vParallelOut(Cpy_LEDMTXCfgPtCfgPtr, Cpy_u16ArrPinsVal[2]);
	BoolDelay_us(2500);
	HShiftReg_vParallelOut(Cpy_LEDMTXCfgPtCfgPtr, Cpy_u16ArrPinsVal[3]);
	BoolDelay_us(2500);
	HShiftReg_vParallelOut(Cpy_LEDMTXCfgPtCfgPtr, Cpy_u16ArrPinsVal[4]);
	BoolDelay_us(2500);
	HShiftReg_vParallelOut(Cpy_LEDMTXCfgPtCfgPtr, Cpy_u16ArrPinsVal[5]);
	BoolDelay_us(2500);
	HShiftReg_vParallelOut(Cpy_LEDMTXCfgPtCfgPtr, Cpy_u16ArrPinsVal[6]);
	BoolDelay_us(2500);
	HShiftReg_vParallelOut(Cpy_LEDMTXCfgPtCfgPtr, Cpy_u16ArrPinsVal[7]);
	BoolDelay_us(2500);
}


