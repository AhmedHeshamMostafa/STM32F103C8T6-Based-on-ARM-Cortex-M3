/*
 * DMA_prv.h
 *
 *  Created on: Jun 5, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_DMA_DMA_PRV_H_
#define MCAL_DMA_DMA_PRV_H_



#define        DMA1_BASE_ADDRESS          (0x40026000)
#define        DMA2_BASE_ADDRESS          (0x40026400)


typedef struct
{

	u32   CR;
	u32   NDTR;
	u32   PAR;
	u32   *M0AR;
	u32   *M1AR;
	u32   FCR;

}DMA_streamBlock_t;






typedef struct
{

	u32  LISR;
	u32  HISR;
	u32  LIFCR;
	u32  HIFCR;
	DMA_streamBlock_t  streamsRegs[8];

}DMA_memMap_t;




#define          DMA1                ((volatile DMA_memMap_t *)DMA1_BASE_ADDRESS)
#define          DMA2                ((volatile DMA_memMap_t *)DMA2_BASE_ADDRESS)


#endif /* MCAL_DMA_DMA_PRV_H_ */
