/*
 * HLEDMTX_int.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Ahmed
 */

#ifndef HAL_HLEDMATRIX_HLEDMTX_INT_H_
#define HAL_HLEDMATRIX_HLEDMTX_INT_H_



typedef ShiftReg_cfg LEDMTXCfg_t;





u8  HLEDMTX_u8Config(LEDMTXCfg_t *Cpy_LEDMTXCfgPtConfigPtr);
void HLEDMTX_vDisplayFrame(LEDMTXCfg_t *Cpy_LEDMTXCfgPtCfgPtr ,u16 *Cpy_u16ArrPinsVal);

#endif /* HAL_HLEDMATRIX_HLEDMTX_INT_H_ */
