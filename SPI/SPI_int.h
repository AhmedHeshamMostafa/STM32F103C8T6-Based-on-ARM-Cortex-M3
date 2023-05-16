/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 4 May 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_


#include "SPI_prv.h"




typedef struct
{

	Bool         mode;     /**/
	Bool         frameSize;/**/
	Bool         dataOrder;/**/
	Bool         SPIClkPol;/**/
	Bool         SPIClkPhase;/**/
	u8           SPIBaudRate;/**/
	SPIChID_t    SPIChannel;/**/
	u32          APB1Freq;
	u32          APB2Freq;

}SPI_cfg;








/*********************************************************************************/
/*     Configuration parameters for that basic SPI supported in the family       */
/*     (Full duplex only, no CRC,                                                */
/*      no software slave management,                                            */
/*      no DMA in TX nor RX)                                                     */
/*********************************************************************************/



/*Configure the SPI node as master or slave*/
#define      SPI_MASTER               1
#define      SPI_SLAVE                0

/*Configure the frame size to be 8-bit or 16-bit*/
#define      EIGHTBIT_FRAME           0
#define      SIXTEENBIT_FRAME         1

/*Configure the transmission as LSB first or MSB first*/
#define      LSB_FIRST                1
#define      MSB_FIRST                0

/*Configure the baud rate for the data exchange*/
#define      FPCLK_OVER2              0b000
#define      FPCLK_OVER4              0b001
#define      FPCLK_OVER8              0b010
#define      FPCLK_OVER16             0b011
#define      FPCLK_OVER32             0b100
#define      FPCLK_OVER64             0b101
#define      FPCLK_OVER128            0b110
#define      FPCLK_OVER256            0b111

/*Configure the clock to be 0 or 1 when idle*/
#define      IDLE_LOW                 0
#define      IDLE_HIGH                1

/*Configure the sampling edge to be the first edge or the second edge*/
#define     SAMPLE_1ST_EDGE           0
#define     SAMPLE_2ND_EDGE           1





Bool MSPI_BoolInit(SPI_cfg *A_SPICfgPtConfigPtr);
Bool MSPI_BoolTransceiveFrame(SPI_cfg *A_UARTCfgPtConfigPtr, u16 A_u16FrameSent, u16* A_u16PtFrameRecPtr);


#endif /* MCAL_SPI_SPI_INT_H_ */
