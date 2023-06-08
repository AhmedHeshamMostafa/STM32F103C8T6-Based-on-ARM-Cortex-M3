/*
 * SPI_prv.h
 *
 *  Created on: Jun 8, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_



#define           SPI1_BASE_ADDRESS             (0x40013000)
#define           SPI2_I2S2_BASE_ADDRESS        (0x40003800)
#define           SPI3_I2S3_BASE_ADDRESS        (0x40003C00)
#define           SPI4_BASE_ADDRESS             (0x40013400)





typedef struct
{
	u32     CR1;
	u32     CR2;
	u32     SR;
	u32     DR;
	u32     CRCPR;
	u32     RXCRCR;
	u32     TXCRCR;
	u32     I2SCFGR;
	u32     I2SPR;

}SPII2Sx_memMap_t;





#define          SPICHANNEL1            ((volatile SPII2Sx_memMap_t *)SPI1_BASE_ADDRESS)
#define          SPICHANNEL2            ((volatile SPII2Sx_memMap_t *)SPI2_I2S2_BASE_ADDRESS)
#define          SPICHANNEL3            ((volatile SPII2Sx_memMap_t *)SPI3_I2S3_BASE_ADDRESS)
#define          SPICHANNEL4            ((volatile SPII2Sx_memMap_t *)SPI4_BASE_ADDRESS)






#define         BR0               3
#define         CPOL              1
#define         CPHA              0
#define         LSBFIRST          7
#define         DFF               11
#define         MSTR              2
#define         SPE               6




#define        BSY                7
#define        TXE                1
#define        RXNE               0








#define        BRMASK           0b111
#define        CLKPOLMASK       1
#define        CLKPHASEMASK     1
#define        DATAORDERMASK    1
#define        FRAMESIZEMASK    1
#define        NODEMODEMASK     1

#endif /* MCAL_SPI_SPI_PRV_H_ */
