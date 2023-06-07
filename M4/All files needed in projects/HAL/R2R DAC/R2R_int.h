/*
 * R2R_int.h
 *
 *  Created on: Jun 4, 2023
 *      Author: Ahmed
 */

#ifndef HAL_R2RDAC_R2R_INT_H_
#define HAL_R2RDAC_R2R_INT_H_


typedef struct
{

	u8 digitalBitsPort;
	u8 bit0Pin;
	u8 bit1Pin;
	u8 bit2Pin;
	u8 bit3Pin;
	u8 bit4Pin;
	u8 bit5Pin;
	u8 bit6Pin;
	u8 bit7Pin;


}R2RDACCfg_t;




u8 R2RDAC_u8Init(R2RDACCfg_t* Cpy_R2RDacCfgPtConfigPtr);
void R2RDAC_vPlayAudio(R2RDACCfg_t *Cpy_R2RDacCfgPtConfigPtr, volatile const u8 *Cpy_u8PtrFirstSamplePtr, u32 Cpy_u32AudioDataSize);











#endif /* HAL_R2RDAC_R2R_INT_H_ */
