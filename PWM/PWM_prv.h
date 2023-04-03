/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 31 Mar 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_PWM_PWM_PRV_H_
#define MCAL_PWM_PWM_PRV_H_


#define      TIM4_BASE_ADDR      0x40000800


typedef struct
{

	u32  CR1;
	u32  CR2;
	u32  SMCR;
	u32  DIER;
	u32  SR;
	u32  EGR;
	u32  CCMR1;
	u32  CCMR2;
	u32  CCER;
	u32  CNT;
	u32  PSC;
	u32  ARR;
	u32  Reserved1;
	u32  CCR1;
	u32  CCR2;
	u32  CCR3;
	u32  CCR4;
	u32  Reserved2;
	u32  DCR;
	u32  DMAR;


}TIM4_MemMap_t;



#define     TIM4      ((volatile TIM4_MemMap_t*)TIM4_BASE_ADDR)




typedef     u8      TIMChID_t;



/*********************************************************************************/
/*                    TIM4_CR1 register bits needed in PWM_prg.c                 */
/*********************************************************************************/

#define      CEN        0

#define      DIR        4
#define      CMS0       5
#define      CMS1       6
#define      ARPE       7



/*********************************************************************************/
/*                    TIM4_EGR register bits needed in PWM_prg.c                 */
/*********************************************************************************/

#define      UG         0






/*********************************************************************************/
/*           TIM4_CCMR1 & TIM4_CCMR2 register bits needed in PWM_prg.c           */
/*********************************************************************************/

#define      CCS0       0
#define      CCS1       1
#define      OCM0       4
#define      OCM1       5
#define      OCM2       6
#define      OCPE       3




/*********************************************************************************/
/*                 TIM4_CCER register bits needed in PWM_prg.c                   */
/*********************************************************************************/

#define      CCE        0
#define      CCP        1




#endif /* MCAL_PWM_PWM_PRV_H_ */
