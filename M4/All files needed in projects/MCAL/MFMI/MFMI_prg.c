/*
 * MFMI_prg.c
 *
 *  Created on: Jun 14, 2023
 *      Author: Ahmed
 */



Bool MFMI_BoolEraseSector(u8 Cpy_u8SectorID)
{
	/*Successful return : L_BoolErrorState = 0*/
	/*Invalid sector ID entered for Cpy_u8SectorID : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	switch(Cpy_u8SectorID)
	{
	case SECTOR_0 ... SECTOR_7:
		/*Poll the busy flag, to wait for the flash to finish its ongoing operation*/
		while(((FMI->SR)&(1<<BSY)) != 0);
		/*Check whether the CR is locked, and if so unlock it*/
		if(((FMI->CR)&(1<<LOCK)) != 0)
		{
			FMI->KEYR = FMI_KEY1;
			FMI->KEYR = FMI_KEY2;
		}
		/*Choose the sector you want to erase*/
		FMI->CR &= ~(MASK_SECTORNUM<<SNB0);
		FMI->CR |= (Cpy_u8SectorID<<SNB0);
		/*Activate the sector erase operation*/
		FMI->CR |= (1<<SER);
		/*Start the operation*/
		FMI->CR |= (1<<STRT);
		/*Wait for the operation to finish*/
		while(((FMI->SR)&(1<<BSY)) != 0);
		/*Deactivate the sector erase operation, allowing the user to select
		/*any operation but the sector erase operation*/
		FMI->CR &= ~(1<<SER);

		L_BoolErrorState = 0;

		break;
	default:
		L_BoolErrorState = 1;
	}



	return L_BoolErrorState;
}






Bool MFMI_BoolWriteonAddress(u32 Cpy_u32BaseAddr, u8 Cpy_u8ElementSize,  u16 *Cpy_u16PtDataArr, u16 Cpy_u16DataLength)
{
	/*Successful return : L_BoolErrorState = 0*/
	/*Invalid element size entered for Cpy_u8ElementSize : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	switch(Cpy_u8ElementSize)
	{
	case ONE_BYTE ... EIGHT_BYTES:
		/*Poll the busy flag, to wait for the flash to finish its ongoing operation*/
		while(((FMI->SR)&(1<<BSY)) != 0);
		/*Check whether the CR is locked, and if so unlock it*/
		if(((FMI->CR)&(1<<LOCK)) != 0)
		{
			FMI->KEYR = FMI_KEY1;
			FMI->KEYR = FMI_KEY2;
		}

		/*Set the writing to be Cpy_u8ElementSize at a time*/
		FMI->CR &= ~(MASK_ELEMENTSIZE<<PSIZE0);
		FMI->CR |= (Cpy_u8ElementSize<<PSIZE0);

		switch(Cpy_u8ElementSize)
		{
		case ONE_BYTE:
			u8 *L_StartAddr = (u8 *)Cpy_u32BaseAddr;
			break;

		case TWO_BYTES:
			u16 *L_StartAddr = (u16 *)Cpy_u32BaseAddr;
			break;

		case FOUR_BYTES:
			u32 *L_StartAddr = (u32 *)Cpy_u32BaseAddr;
			break;

		default:
			u64 *L_StartAddr = (u64 *)Cpy_u32BaseAddr;
			break;
		}

		/*Activate the writing operation*/
		FMI->CR |= (1<<PG);
		/*Start the operation*/
		FMI->CR |= (1<<STRT);

		/*Actually write the given block into the given base address*/
		for(u16 L_u16DataIndex=0; L_u16DataIndex<Cpy_u16DataLength; L_u16DataIndex++)
		{
			*L_StartAddr = Cpy_u16PtDataArr[L_u16DataIndex];
			L_StartAddr++;
		}

		/*Wait for the operation to finish*/
		while(((FMI->SR)&(1<<BSY)) != 0);
		/*Deactivate the writing operation, allowing the user to select
		/*any operation but the writing operation*/
		FMI->CR &= ~(1<<PG);


		L_BoolErrorState = 0;
		break;

	default:
		L_BoolErrorState = 1;
	}


	return L_BoolErrorState;

}





void MFMI_vEraseAllSectors(void)
{
	/*Poll the busy flag, to wait for the flash to finish its ongoing operation*/
	while(((FMI->SR)&(1<<BSY)) != 0);
	/*Check whether the CR is locked, and if so unlock it*/
	if(((FMI->CR)&(1<<LOCK)) != 0)
	{
		FMI->KEYR = FMI_KEY1;
		FMI->KEYR = FMI_KEY2;
	}

	/*Activate the mass erase operation*/
	FMI->CR |= (1<<MER);
	/*Start the operation*/
	FMI->CR |= (1<<STRT);
	/*Wait for the operation to finish*/
	while(((FMI->SR)&(1<<BSY)) != 0);
	/*Deactivate the mass erase operation, allowing the user to select
	/*any operation but the mass erase operation*/
	FMI->CR &= ~(1<<MER);
}



