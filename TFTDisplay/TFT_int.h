/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 7 May 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef HAL_TFT_INT_H_
#define HAL_TFT_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/SPI/SPI_int.h"
#include "TFT_prv.h"



typedef struct
{

	u16            horPixels;
	u16            verPixels;
	TFTColorID_t   colorMode;        /**/
	SPIChID_t      SPIChannel;       /**/
	portID_t       RESPort;          /**/
	pinID_t        RESPin;           /**/
	portID_t       DCPort;           /**/
	pinID_t        DCPin;            /**/

}TFT_cfg;



#define     RGB444        RGB444ID
#define     RGB565        RGB565ID
#define     RGB666        RGB666ID




Bool HTFT_BoolInit(TFT_cfg* A_TFTCfgPtrConfig);
void HTFT_BoolDisplayFrame(const u32* A_u32PtrFrameArr);


#endif /* HAL_TFT_INT_H_ */
