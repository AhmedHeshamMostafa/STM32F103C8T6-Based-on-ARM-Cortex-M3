/*
 * DMA_int.h
 *
 *  Created on: Jun 5, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_DMA_DMA_INT_H_
#define MCAL_DMA_DMA_INT_H_


void DMA2_vInit(void);
void DMA2_CfgStream(u8 Cpy_u8StreamID, u8 Cpy_chID, u32 *Cpy_u32PtSourceAddr, u32 *Cpy_u32DestAddr, u8 Cpy_u8ElementSize, u16 Cpy_u16BlockSize);
void DMA2_S0_setCallBack(void (*fnPtr)(void));

#endif /* MCAL_DMA_DMA_INT_H_ */
