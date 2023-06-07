/*
 * RTOS_cfg.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Ahmed
 */

#ifndef RTOS_RTOS_CFG_H_
#define RTOS_RTOS_CFG_H_


/*Tick time for the RTOS in terms of SysTick ticks*/
/*E.g The tick time for the RTOS = 4 SysTick ticks, in other words*/
/*each RTOS tick lasts for 4 SysTick ticks*/
#define   OS_TICKTIME            4
/*Maximum number of tasks the RTOS can handle*/
#define   MAX_TASKS_NUM          20


#endif /* RTOS_RTOS_CFG_H_ */
