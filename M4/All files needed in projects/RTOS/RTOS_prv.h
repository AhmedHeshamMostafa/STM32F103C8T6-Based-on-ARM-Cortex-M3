/*
 * RTOS_prv.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Ahmed
 */

#ifndef RTOS_RTOS_PRV_H_
#define RTOS_RTOS_PRV_H_


typedef enum
{
	DORMANT,
	READY,
	RUNNING,
	SUSPENDED
}State_t;



/*The struct "Task" is a struct that contains the parameters for a task*/
typedef struct
{

	/*Task state, initially as long as a task is not created yet it's in the dormant state*/
	State_t TaskState;
	/*Task periodicity in RTOS ticks*/
	u32   TaskPeriodicity;
	/*Task first delay in RTOS ticks*/
	u32   TaskFirstDelay;
	/*The operation that the task executes when it is in the running state*/
	void (*TaskOperation)(void);

}Task;



#endif /* RTOS_RTOS_PRV_H_ */
