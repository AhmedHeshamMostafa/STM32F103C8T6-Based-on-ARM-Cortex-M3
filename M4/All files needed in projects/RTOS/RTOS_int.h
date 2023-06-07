/*
 * RTOS_int.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Ahmed
 */

#ifndef RTOS_RTOS_INT_H_
#define RTOS_RTOS_INT_H_


/*The smaller the number, the higher the priority for the task*/
/*The highest priority is the value 0, the lowest priority is the value MAX_TASKS_NUM-1*/
/*Each task has a unique priority in the range 0 to MAX_TASKS_NUM-1 inclusive,*/
/*It's NOT allowed to assign the same priority to more than one task*/


void RTOS_vStartOS(void);
u8 RTOS_u8CreateTask(void (*Cpy_fnPtTaskOpFnPtr)(void), u32 Cpy_u32TaskPeriodicity, u8 Cpy_u8TaskPriority, u32 Cpy_u32TaskFirstDelay);
void RTOS_vScheduler(void);
Bool RTOS_BoolDeleteTask(u8 Cpy_u8TaskPriority);
Bool RTOS_BoolSuspendTask(u8 Cpy_u8TaskPriority);
Bool RTOS_BoolResumeTask(u8 Cpy_u8TaskPriority);



#endif /* RTOS_RTOS_INT_H_ */
