/*
 * HShiftReg_int.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Ahmed
 */

#ifndef HAL_HSHIFTREGISTER_HSHIFTREG_INT_H_
#define HAL_HSHIFTREGISTER_HSHIFTREG_INT_H_


typedef struct
{

	u8   serialDataINPort;
	u8   serialDataINPin;

	u8   clearPort;
	u8   clearPin;

	u8   shiftClkPort;
	u8   shiftClkPin;

	u8   latchClkPort;
	u8   latchClkPin;

}ShiftReg_cfg;


ShiftReg_cfg  ShiftRegCfgStruct;




u8  HShiftReg_u8Config(ShiftReg_cfg *Cpy_ShiftRegCfgPtConfigPtr);
void  HShiftReg_vParallelOut(ShiftReg_cfg *Cpy_ShiftRegCfgPtConfigPtr, u16 Cpy_u32SerialIn);




#endif /* HAL_HSHIFTREGISTER_HSHIFTREG_INT_H_ */
