/*
 * RTOS_prg.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Ahmed
 */

#include<LIB/STD_TYPES.h>
#include<MCAL/MSysTick/MSysTick_int.h>
#include<RTOS/RTOS_prv.h>
#include"RTOS_cfg.h"
#include<RTOS/RTOS_int.h>



/*This is an array of pointers to the struct "Task"*/
/*The struct "Task" itself is a struct that contains*/
/*the void void function and the periodicity of the task*/
static Task GS_TaskArrTaskContainer[MAX_TASKS_NUM] = {0};
static u8   GS_u8ArrTaskTime[MAX_TASKS_NUM];



void RTOS_vStartOS(void)
{
	MSysTick_vSetCallBack(RTOS_vScheduler);
	MSysTick_BoolSetIntervalPeriodic(OS_TICKTIME);

	while(TRUE);
}


/*****************************************************************************************************/
/*****************************************************************************************************/


u8 RTOS_u8CreateTask(void (*Cpy_fnPtTaskOpFnPtr)(void), u32 Cpy_u32TaskPeriodicity, u8 Cpy_u8TaskPriority, u32 Cpy_u32TaskFirstDelay)
{
	/*Successful return : L_u8ErrorState = 0*/
	/*There is already a task in this priority position : L_u8ErrorState = 2*/
	/*Value entered for Cpy_u8TaskPriority is out of allowed range (0 to MAX_TASKS_NUM-1 inclusive)  : L_u8ErrorState = 3*/

	u8 L_u8ErrorState = 3;

	if(Cpy_u8TaskPriority < MAX_TASKS_NUM)
	{
		if(((GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskOperation) == NULL)
		{
			(GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskOperation = Cpy_fnPtTaskOpFnPtr;
			(GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskPeriodicity = Cpy_u32TaskPeriodicity;
			(GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskFirstDelay = Cpy_u32TaskFirstDelay;
			GS_u8ArrTaskTime[Cpy_u8TaskPriority] = Cpy_u32TaskFirstDelay;
			(GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskState = READY;

			L_u8ErrorState = 0;
		}

		else
		{
			L_u8ErrorState = 2;
		}
	}


	return L_u8ErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/


void RTOS_vScheduler(void)
{
	u8 L_u8TasksIndex = 0;

	for(L_u8TasksIndex = 0; L_u8TasksIndex<MAX_TASKS_NUM; L_u8TasksIndex++)
	{
		if(((GS_TaskArrTaskContainer[L_u8TasksIndex]).TaskOperation) != NULL)
		{
			if((((GS_TaskArrTaskContainer[L_u8TasksIndex]).TaskState) == READY) || (((GS_TaskArrTaskContainer[L_u8TasksIndex]).TaskState) == RUNNING))
			{
				if(GS_u8ArrTaskTime[L_u8TasksIndex] == 0)
				{
					(GS_TaskArrTaskContainer[L_u8TasksIndex]).TaskState = RUNNING;
					GS_u8ArrTaskTime[L_u8TasksIndex] = (GS_TaskArrTaskContainer[L_u8TasksIndex]).TaskPeriodicity;
					((GS_TaskArrTaskContainer[L_u8TasksIndex]).TaskOperation)();

				}

				else
				{
					(GS_u8ArrTaskTime[L_u8TasksIndex])--;
				}
			}

		}
	}
}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool RTOS_BoolDeleteTask(u8 Cpy_u8TaskPriority)
{
	/*Successful return : L_BoolErrorState = 0*/
	/*There is no created task at this priority position : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 0;

	if(((GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskOperation) != NULL)
	{
		(GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskOperation = NULL;
		(GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskState = DORMANT;
	}

	else
	{
		L_BoolErrorState = 1;
	}

	return L_BoolErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool RTOS_BoolSuspendTask(u8 Cpy_u8TaskPriority)
{
	/*Successful return : L_BoolErrorState = 0*/
	/*There is no created task at this priority position : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 0;

	if(((GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskOperation) != NULL)
	{
		(GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskState = SUSPENDED;
	}

	else
	{
		L_BoolErrorState = 1;
	}


	return L_BoolErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool RTOS_BoolResumeTask(u8 Cpy_u8TaskPriority)
{
	/*Successful return : L_BoolErrorState = 0*/
	/*There is no created task at this priority position : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 0;

	if(((GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskOperation) != NULL)
	{
		(GS_TaskArrTaskContainer[Cpy_u8TaskPriority]).TaskState = READY;
	}

	else
	{
		L_BoolErrorState = 1;
	}


	return L_BoolErrorState;

}
