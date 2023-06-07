/*
 * MSysTick_prv.h
 *
 *  Created on: Jun 1, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_MSYSTICK_MSYSTICK_PRV_H_
#define MCAL_MSYSTICK_MSYSTICK_PRV_H_


#define              SysTick_BASE_ADDRESS            (0xE000E010)



typedef struct
{

	u32   CTRL;
	u32   LOAD;
	u32   VAL;
	u32   CALIB;

}SysTick_memMap_t;





#define            SYSTICK              ((volatile SysTick_memMap_t*)SysTick_BASE_ADDRESS)




#define            EN              0
#define            TICKINT         1
#define            CLKSOURCE       2
#define            COUNTFLAG       16



#endif /* MCAL_MSYSTICK_MSYSTICK_PRV_H_ */
