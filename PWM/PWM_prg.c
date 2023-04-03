/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 31 Mar 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

/* Notice that case MINRANGE ... MAXRANGE: is a feature available only in gcc.
   If you are willing to use a different compiler, you should refer to its documentation.*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "PWM_int.h"
#include "PWM_prv.h"




Bool MPWM_BoolInit(PWM_cfg *A_PWMCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	switch(A_PWMCfgPtConfigPtr->TIMChIDChannel)
	{
	case TIM_CH1 ... TIM_CH4:
	{
		/*Enable the auto-reload-preload register*/
		SET_BIT(TIM4->CR1, ARPE);
		/*Set the timer to be in edge-aligned mode.
		  The counter counts up or down depending on
		  the direction bit (DIR).*/
		CLR_BIT(TIM4->CR1, CMS0);
		CLR_BIT(TIM4->CR1, CMS1);
		/*The timer is to upcount*/
		CLR_BIT(TIM4->CR1, DIR);
		/*Update the registers and initialize the counter*/
		SET_BIT(TIM4->EGR, UG);
		/*Enable the counter*/
		SET_BIT(TIM4->CR1, CEN);
		/*Set the timer in PWM mode1*/
		CLR_BIT(*((u32*)(&(TIM4->CCMR1)) + ((A_PWMCfgPtConfigPtr->TIMChIDChannel)>TIM_CH2)), (((A_PWMCfgPtConfigPtr->TIMChIDChannel)%2)*8) + OCM0);
		SET_BIT(*((u32*)(&(TIM4->CCMR1)) + ((A_PWMCfgPtConfigPtr->TIMChIDChannel)>TIM_CH2)), (((A_PWMCfgPtConfigPtr->TIMChIDChannel)%2)*8) + OCM1);
		SET_BIT(*((u32*)(&(TIM4->CCMR1)) + ((A_PWMCfgPtConfigPtr->TIMChIDChannel)>TIM_CH2)), (((A_PWMCfgPtConfigPtr->TIMChIDChannel)%2)*8) + OCM2);
		/*Enable the preload register*/
		SET_BIT(*((u32*)(&(TIM4->CCMR1)) + ((A_PWMCfgPtConfigPtr->TIMChIDChannel)>TIM_CH2)), (((A_PWMCfgPtConfigPtr->TIMChIDChannel)%2)*8) + OCPE);
		/*Set the channel as output*/
		CLR_BIT(*((u32*)(&(TIM4->CCMR1)) + ((A_PWMCfgPtConfigPtr->TIMChIDChannel)>TIM_CH2)), (((A_PWMCfgPtConfigPtr->TIMChIDChannel)%2)*8) + CCS0);
		CLR_BIT(*((u32*)(&(TIM4->CCMR1)) + ((A_PWMCfgPtConfigPtr->TIMChIDChannel)>TIM_CH2)), (((A_PWMCfgPtConfigPtr->TIMChIDChannel)%2)*8) + CCS1);
		/*Set the channel to be active high*/
		CLR_BIT(TIM4->CCER, (A_PWMCfgPtConfigPtr->TIMChIDChannel)*4 + CCP);

		break;
	}

	default:
	{
		L_BoolErrorState = 0;
	}
	}


	return L_BoolErrorState;

}


/***********************************************************************************/


Bool MPWM_vGeneratePWM(PWM_cfg *A_PWMCfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	u32 L_u32MinFreq = (A_PWMCfgPtConfigPtr->u32TIMClk) / ((u32)0xFFFF);

	if(((A_PWMCfgPtConfigPtr->u32Frequency) < L_u32MinFreq) || ((A_PWMCfgPtConfigPtr->u32Frequency) > (A_PWMCfgPtConfigPtr->u32TIMClk)))
	{
		L_BoolErrorState = 0;
		return L_BoolErrorState;
	}


	switch((A_PWMCfgPtConfigPtr->u8DutyCycle))
	{
	case 0 ... 100:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		return L_BoolErrorState;
		break;
	}
	}



	u32* u32PtCCRAddr = (u32*)((u32*)(&(TIM4->CCR1)) + (A_PWMCfgPtConfigPtr->TIMChIDChannel));

	/*No prescaler*/
	TIM4->PSC = (u32)0x0000;
	/*Set the frequency of the PWM signal*/
	TIM4->ARR = ((u32)(((f32)(A_PWMCfgPtConfigPtr->u32TIMClk)) / (A_PWMCfgPtConfigPtr->u32Frequency))) - (u32)1;
	/*Set the duty cycle of the PWM signal*/
	*u32PtCCRAddr =  (u32)((u32)((A_PWMCfgPtConfigPtr->u8DutyCycle)/((f32)100)) * (TIM4->ARR));
	/*Clear the counter*/
	TIM4->CNT = (u32)0x0000;
	/*Start outputting the PWM signal on the microcontroller pin*/
	SET_BIT(TIM4->CCER, (A_PWMCfgPtConfigPtr->TIMChIDChannel)*4 + CCE);

	return L_BoolErrorState;

}


