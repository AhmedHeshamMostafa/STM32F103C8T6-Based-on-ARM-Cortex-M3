/*
 * MFMI_int.h
 *
 *  Created on: Jun 14, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_MFMI_MFMI_INT_H_
#define MCAL_MFMI_MFMI_INT_H_



#define        SECTOR_0          (0b0000)
#define        SECTOR_1          (0b0001)
#define        SECTOR_2          (0b0010)
#define        SECTOR_3          (0b0011)
#define        SECTOR_4          (0b0100)
#define        SECTOR_5          (0b0101)
#define        SECTOR_6          (0b0110)
#define        SECTOR_7          (0b0111)




#define       ONE_BYTE           (0b00)
#define       TWO_BYTES          (0b01)
#define       FOUR_BYTES         (0b10)
#define       EIGHT_BYTES        (0b11)




Bool MFMI_BoolEraseSector(u8 Cpy_u8SectorID);
Bool MFMI_BoolWriteonAddress(u32 Cpy_u32BaseAddr, u8 Cpy_u8ElementSize,  u16 *Cpy_u16PtDataArr, u16 Cpy_u16DataLength);
void MFMI_vEraseAllSectors(void);





#endif /* MCAL_MFMI_MFMI_INT_H_ */
