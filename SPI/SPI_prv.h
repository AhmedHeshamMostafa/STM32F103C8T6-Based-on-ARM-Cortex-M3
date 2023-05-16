/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 4 May 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_SPI_SPI_PRV_H_
#define MCAL_SPI_SPI_PRV_H_



#define      SPI1_BASE_ADDR              0x40013000
#define      SPI2_I2S_BASE_ADDR          0x40003800
#define      SPI3_I2S_BASE_ADDR          0x40003C00



typedef struct
{

	u32   CR1;
	u32   CR2;
	u32   SR;
	u32   DR;
	u32   CRCPR;
	u32   RXCRCR;
	u32   TXCRCR;
	u32   I2SCFGR;
	u32   I2SPR;

}SPI_I2S_MamMap_t;



typedef volatile SPI_I2S_MamMap_t* SPIChID_t;



#define     SPI_ONE                (volatile SPI_I2S_MamMap_t*)SPI1_BASE_ADDR
#define     SPI_TWO_I2S            (volatile SPI_I2S_MamMap_t*)SPI2_I2S_BASE_ADDR
#define     SPI_THREE_I2S          (volatile SPI_I2S_MamMap_t*)SPI3_I2S_BASE_ADDR




/*********************************************************************************/
/*                 SPI_CR1 register bits needed in SPI_prg.c                     */
/*********************************************************************************/
#define         BIDIMODE          15

#define         CRCE              13

#define         DFF               11
#define         RXONLY            10
#define         SSM               9

#define         LSBFIRST          7
#define         SPE               6
#define         BAUD2             5
#define         BAUD1             4
#define         BAUD0             3
#define         MSTR              2
#define         CPOL              1
#define         CPHA              0



/*********************************************************************************/
/*                 SPI_CR2 register bits needed in SPI_prg.c                     */
/*********************************************************************************/
#define         SSOE              2



/*********************************************************************************/
/*                 SPI_SR register bits needed in SPI_prg.c                      */
/*********************************************************************************/
#define         OVR               6
#define         MODF              5



#define         TXE               1
#define         RXNE              0






#endif /* MCAL_SPI_SPI_PRV_H_ */
