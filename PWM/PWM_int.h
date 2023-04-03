/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 31 Mar 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_PWM_PWM_INT_H_
#define MCAL_PWM_PWM_INT_H_

#include "PWM_prv.h"




typedef struct
{

	TIMChID_t TIMChIDChannel;
	u8        u8DutyCycle;
	u32       u32TIMClk;
	u32       u32Frequency;

}PWM_cfg;





#define        TIM_CH1          0
#define        TIM_CH2          1
#define        TIM_CH3          2
#define        TIM_CH4          3



Bool MPWM_BoolInit(PWM_cfg *A_PWMCfgPtConfigPtr);
Bool MPWM_vGeneratePWM(PWM_cfg *A_PWMCfgPtConfigPtr);



#endif /* MCAL_PWM_PWM_INT_H_ */
