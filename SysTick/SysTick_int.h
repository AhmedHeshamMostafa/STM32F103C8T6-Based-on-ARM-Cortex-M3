/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 10 Apr 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/


#ifndef MCAL_SYSTICK_SYSTICK_INT_H_
#define MCAL_SYSTICK_SYSTICK_INT_H_

#include "SysTick_prv.h"



typedef struct
{

	Bool      BoolSTKClkSrc;

}SysTick_cfg;




Bool MSysTick_BoolInit(SysTick_cfg *STKCfgPtConfigPtr);
void MSysTick_vStop(void);
Bool MSysTick_BoolWait(u32 A_u32WaitedTicks);
Bool MSysTick_BoolSetIntervalSingle(u32 A_u32WaitedTicks);
Bool MSysTick_BoolSetIntervalPeriodic(u32 A_u32Periodicity);
u32 MSysTick_u32GetElapsedTime(void);
u32 MSysTick_u32GetRemainingTime(void);
void MSysTick_vSetCallBack(void(*A_vFunvPtCalledPtr)(void));



#endif /* MCAL_SYSTICK_SYSTICK_INT_H_ */
