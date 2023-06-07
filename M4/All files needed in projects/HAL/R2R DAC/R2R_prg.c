/*
 * R2R_prg.c
 *
 *  Created on: Jun 4, 2023
 *      Author: Ahmed
 */


#include<LIB/STD_TYPES.h>
#include<LIB/BIT_MATH.h>
#include<LIB/Delay_int.h>
#include<MCAL/MRCC/MRCC_int.h>
#include<MCAL/MGPIO/MGPIO_int.h>
#include<HAL/R2RDAC/R2R_int.h>





u8 R2RDAC_u8Init(R2RDACCfg_t *Cpy_R2RDacCfgPtConfigPtr)
{
	u8 L_u8ErrorState;

	MRCC_u8InitSysClk();

	switch(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort)
	{
	case PA:	L_u8ErrorState = MRCC_BoolEnablePerClk(GPIOA);
				break;

	case PB:	L_u8ErrorState = MRCC_BoolEnablePerClk(GPIOB);
				break;

	case PC:	L_u8ErrorState = MRCC_BoolEnablePerClk(GPIOC);
				break;

	case PD:	L_u8ErrorState = MRCC_BoolEnablePerClk(GPIOD);
				break;

	case PE:	L_u8ErrorState = MRCC_BoolEnablePerClk(GPIOE);
				break;

	case PH:	L_u8ErrorState = MRCC_BoolEnablePerClk(GPIOH);
				break;

	default:    L_u8ErrorState = MRCC_BoolEnablePerClk(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort);
				break;
	}


	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit0Pin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit1Pin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit2Pin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit3Pin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit4Pin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit5Pin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit6Pin, OUTPUT);
	L_u8ErrorState = MGPIO_u8CfgPinMode(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit7Pin, OUTPUT);



	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit0Pin, OUT_PUSH_PULL, OUT_MED_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit1Pin, OUT_PUSH_PULL, OUT_MED_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit2Pin, OUT_PUSH_PULL, OUT_MED_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit3Pin, OUT_PUSH_PULL, OUT_MED_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit4Pin, OUT_PUSH_PULL, OUT_MED_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit5Pin, OUT_PUSH_PULL, OUT_MED_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit6Pin, OUT_PUSH_PULL, OUT_MED_SPEED);
	L_u8ErrorState = MGPIO_u8CfgOutPin(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit7Pin, OUT_PUSH_PULL, OUT_MED_SPEED);



	return L_u8ErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/



void R2RDAC_vPlayAudio(R2RDACCfg_t *Cpy_R2RDacCfgPtConfigPtr, volatile const u8 *Cpy_u8PtrFirstSamplePtr, u32 Cpy_u32AudioDataSize)
{
	/*Bool L_var = 0;*/
//	MGPIO_u8WritePinVal (PA, PIN0, 1);
//	MGPIO_u8WritePinVal (PA, PIN1, 1);
//	MGPIO_u8WritePinVal (PA, PIN2, 0);
//	MGPIO_u8WritePinVal (PA, PIN3, 0);
//	MGPIO_u8WritePinVal (PA, PIN4, 0);
//	MGPIO_u8WritePinVal (PA, PIN5, 1);
//	MGPIO_u8WritePinVal (PA, PIN6, 1);
//	MGPIO_u8WritePinVal (PA, PIN7, 0);
//	BoolDelay_us(125);

	volatile u8 L_sample;

	for(u32 L_u32DataIndex = 0; L_u32DataIndex < Cpy_u32AudioDataSize; Cpy_u32AudioDataSize++)
	{
		L_sample = Cpy_u8PtrFirstSamplePtr[L_u32DataIndex];

		MGPIO_u8WritePinVal(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit0Pin, L_sample&1);
		//L_var = 0;
		MGPIO_u8WritePinVal(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit1Pin, (L_sample>>1)&1);
		//L_var = 0;
		MGPIO_u8WritePinVal(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit2Pin, (L_sample>>2)&1);
		//L_var = 0;
		MGPIO_u8WritePinVal(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit3Pin, (L_sample>>3)&1);
		//L_var = 0;
		MGPIO_u8WritePinVal(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit4Pin, (L_sample>>4)&1);
		//L_var = 0;
		MGPIO_u8WritePinVal(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit5Pin, (L_sample>>5)&1);
		//L_var = 0;
		MGPIO_u8WritePinVal(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit6Pin, (L_sample>>6)&1);
		//L_var = 0;
		MGPIO_u8WritePinVal(Cpy_R2RDacCfgPtConfigPtr->digitalBitsPort, Cpy_R2RDacCfgPtConfigPtr->bit7Pin, (L_sample>>7)&1);
		//L_var = 0;

		for(int i = 0; i < 1000000; i++); /*There is a bug in this fn.*/
	}
}
