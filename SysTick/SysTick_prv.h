/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 10 Apr 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/


#ifndef MCAL_SYSTICK_SYSTICK_PRV_H_
#define MCAL_SYSTICK_SYSTICK_PRV_H_


#define         SYSTICK_BASE_ADDR      0xE000E010

typedef struct
{

	u32  CTRL;
	u32  LOAD;
	u32  VAL;
	u32  CALIB;

}SysTick_MemMap_t;



#define     SYSTICK         ((volatile SysTick_MemMap_t*)(SYSTICK_BASE_ADDR))




#define    AHBCLK_OVER_8      0
#define    AHBCLK             1
#define    MAX_LOAD           0x00FFFFFF
#define    MIN_LOAD           0x00000001


/*********************************************************************************/
/*               STK_CTRL register bits needed in SysTick_prg.c                  */
/*********************************************************************************/

#define       COUNTFLAG        16
#define       CLKSOURCE        2
#define       TICKINT          1
#define       EN               0



#endif /* MCAL_SYSTICK_SYSTICK_PRV_H_ */
