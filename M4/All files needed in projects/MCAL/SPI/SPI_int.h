/*
 * SPI_int.h
 *
 *  Created on: Jun 8, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_

typedef struct
{

	Bool  nodeMode;
	Bool  frameSize;
	Bool  dataOrder;
	Bool  clkPol;
	Bool  clkPhase;
	u8    baudRate;
	u8    channelID;
}SPICfg_t;




/*Configure the baud rate for the data exchange*/
#define      FPCLK_OVER2              0b000
#define      FPCLK_OVER4              0b001
#define      FPCLK_OVER8              0b010
#define      FPCLK_OVER16             0b011
#define      FPCLK_OVER32             0b100
#define      FPCLK_OVER64             0b101
#define      FPCLK_OVER128            0b110
#define      FPCLK_OVER256            0b111



/*Configure the SPI channel*/
#define      SPI_CH1                  1
#define      SPI_CH2                  2
#define      SPI_CH3                  3
#define      SPI_CH4                  4




/*Configure the clock to be 0 or 1 when idle*/
#define      IDLE_LOW                 0
#define      IDLE_HIGH                1



/*Configure the sampling edge to be the first edge or the second edge*/
#define     SAMPLE_1ST_EDGE           0
#define     SAMPLE_2ND_EDGE           1



/*Configure the transmission as LSB first or MSB first*/
#define      LSB_FIRST                1
#define      MSB_FIRST                0



/*Configure the frame size to be 8-bit or 16-bit*/
#define      EIGHTBIT_FRAME           0
#define      SIXTEENBIT_FRAME         1



/*Configure the SPI node as master or slave*/
#define      MASTER                   1
#define      SLAVE                    0








Bool MSPI_BoolInit(SPICfg_t*SPICfgPtConfigPtr);
void MSPI_vEnableSPI(SPICfg_t*SPICfgPtConfigPtr);
void MSPI_vTransceiveFrame(SPICfg_t*SPICfgPtConfigPtr,u16 u16SentData, u16 *u16PtRecDataPtr);




#endif /* MCAL_SPI_SPI_INT_H_ */
