/*
 * DMA_prg.c
 *
 *  Created on: Jun 5, 2023
 *      Author: Ahmed
 */


#include<LIB/STD_TYPES.h>
#include<LIB/BIT_MATH.h>
#include<LIB/Delay_int.h>
#include<MCAL/MGPIO/MGPIO_int.h>
#include<MCAL/DMA/DMA_prv.h>
#include<MCAL/DMA/DMA_int.h>


static void (*DMA_S0_fptr) (void);


void DMA2_vInit(void)
{
	(DMA2->streamsRegs[0]).CR &= ~(1<<0);
	(DMA2->LISR) |= (1<<0)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
	(DMA2->streamsRegs[0]).CR |= (1<<14)|(1<<12)|(1<<9)|(1<<10)|(1<<7)|(1<<4)|(1<<3)|(1<<2)|(1<<1);
	(DMA2->streamsRegs[0]).FCR |= (1<<0)|(1<<1)|(1<<2);

}



void DMA2_CfgStream(u8 Cpy_u8StreamID, u8 Cpy_chID, u32 *Cpy_u32PtSourceAddr, u32 *Cpy_u32DestAddr, u8 Cpy_u8ElementSize, u16 Cpy_u16BlockSize)
{
	(DMA2->streamsRegs[Cpy_u8StreamID]).CR &= ~(1<<0);
	(DMA2->streamsRegs[Cpy_u8StreamID]).CR |= (Cpy_chID<<25);
	(DMA2->streamsRegs[Cpy_u8StreamID]).CR |= (Cpy_u8ElementSize<<11);
	(DMA2->streamsRegs[Cpy_u8StreamID]).CR |= (Cpy_u8ElementSize<<13);
	(DMA2->streamsRegs[Cpy_u8StreamID]).NDTR = Cpy_u16BlockSize;
	(DMA2->streamsRegs[Cpy_u8StreamID]).M0AR = Cpy_u32PtSourceAddr;
	(DMA2->streamsRegs[Cpy_u8StreamID]).M1AR = Cpy_u32DestAddr;

	(DMA2->streamsRegs[Cpy_u8StreamID]).CR |= (1<<0);

}


void DMA2_S0_setCallBack(void (*fnPtr)(void))
{
	if(fnPtr != NULL)
	{
		DMA_S0_fptr = fnPtr;
	}
}



void DMA2_Stream0_IRQHandler(void)
{
	DMA_S0_fptr();
	//MGPIO_u8WritePinVal (PA, PIN0, HIGH);
	//BoolDelay_us(500000000);
}



