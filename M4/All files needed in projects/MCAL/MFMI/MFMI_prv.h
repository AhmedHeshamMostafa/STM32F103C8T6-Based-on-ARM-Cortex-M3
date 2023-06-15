/*
 * MFMI_prv.h
 *
 *  Created on: Jun 14, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_MFMI_MFMI_PRV_H_
#define MCAL_MFMI_MFMI_PRV_H_


#define        FMI_BASE_ADDRESS           (0x40023C00)


typedef struct
{
	u32   ACR;
	u32   KEYR;
	u32   OPTKEYR;
	u32   SR;
	u32   CR;
	u32   OPTCR;

}FMI_memMap_t;



#define            FMI          ((volatile FMI_memMap_t *)FMI_BASE_ADDRESS)


#define           FMI_KEY1          (0x45670123)
#define           FMI_KEY2          (0xCDEF89AB)



/**********************************************************/
/*********** Bits in SR needed in MFMI_prg.c **************/
/**********************************************************/

#define      EOP         0
#define      BSY         16




/**********************************************************/
/*********** Bits in CR needed in MFMI_prg.c **************/
/**********************************************************/

#define      PG           0
#define      SER          1
#define      MER          2
#define      SNB0         3
#define      SNB1         4
#define      SNB2         5
#define      SNB3         6
#define      PSIZE0       8
#define      PSIZE1       9
#define      STRT         16
#define      LOCK         31




#define      MASK_SECTORNUM       0b1111
#define      MASK_ELEMENTSIZE     0b11



#endif /* MCAL_MFMI_MFMI_PRV_H_ */
