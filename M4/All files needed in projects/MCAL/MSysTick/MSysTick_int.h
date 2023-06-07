/*
 * MSysTick_int.h
 *
 *  Created on: Jun 1, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_MSYSTICK_MSYSTICK_INT_H_
#define MCAL_MSYSTICK_MSYSTICK_INT_H_


#define        MIN_LOAD         0x00000001
#define        MAX_LOAD         0x00FFFFFF




Bool MSysTick_BoolWait(u32 Cpy_u32WaitedTicks);
u32 MSysTick_u32GetElapsedTime(void);
u32 MSysTick_u32GetRemainingTime(void);
void MSysTick_vStop(void);
Bool MSysTick_BoolSetIntervalSingle(u32 Cpy_u32WaitedTicks);
Bool MSysTick_BoolSetIntervalPeriodic(u32 Cpy_u32Periodicity);
void MSysTick_vSetCallBack(void(*Cpy_vFunvPtCalledPtr)(void));





#endif /* MCAL_MSYSTICK_MSYSTICK_INT_H_ */
