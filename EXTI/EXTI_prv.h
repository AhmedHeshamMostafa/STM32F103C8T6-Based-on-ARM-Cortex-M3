/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 Apr 2023                                             */
/*             VERSION  : V02                                                    */
/*********************************************************************************/

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#include "../GPIO/GPIO_int.h"




#define        EXTI_BASE_ADDR      0x40010400



typedef struct
{
	u32    IMR;
	u32    EMR;
	u32    RTSR;
	u32    FTSR;
	u32    SWIER;
	u32    PR;

}EXTI_MemMap_t;


#define         EXTI             ((volatile EXTI_MemMap_t*)(EXTI_BASE_ADDR))


#define         MIN_TYPE           0
#define         MAX_TYPE           1
#define         MIN_TRIGGER        0
#define         MAX_TRIGGER        2


typedef    u8     PortID_t;
typedef    u8     PinID_t;
typedef    u8     LineID_t;





#endif /* MCAL_EXTI_EXTI_PRV_H_ */
