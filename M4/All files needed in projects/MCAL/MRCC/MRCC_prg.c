
#include <LIB/BIT_MATH.h>
#include <LIB/STD_TYPES.h>
#include <MCAL/MRCC/MRCC_prv.h>
#include <MCAL/MRCC/MRCC_int.h>
#include "MRCC_cfg.h"



u8 MRCC_u8InitSysClk(void)
{
	/*Successful return : L_u8ErrorState = 0*/
	/*System clock is to be configured as HSI but configuration failed : L_u8ErrorState = 2*/
	/*System clock is to be configured as HSE but configuration failed : L_u8ErrorState = 3*/
	/*System clock is to be configured as PLL but configuration failed : L_u8ErrorState = 4*/

	u8 L_u8ErrorState = 0;


	(RCC->CR) &= ~(1<<SYSCLK);
	
	#if(SYSCLK == HSI)
		(RCC->CFGR) &= ~(1<<SW0);
		(RCC->CFGR) &= ~(1<<SW1);
		
		(RCC->CR) |= (1<<SYSCLK);
		
		while(((RCC->CR)&(1<<HSIRDY)) == LOW);
		
		if (((RCC->CFGR)&(1<<SWS0)) == LOW)
		{
			if (((RCC->CFGR)&(1<<SWS1)) == LOW)
			{
				/*Do nothing, you configured system clock as HSI correctly*/
			}

			else
			{
				L_u8ErrorState = 2;
			}
		}
		
		else
		{
			L_u8ErrorState = 2;
		}

	/*********************************************************/
	
	#elif(SYSCLK == HSE)
		#if(HSE_OSC == HSE_RC)
			(RCC->CR) |= (1<<HSEBYP);
		#elif(HSE_OSC == HSE_CRY)
			(RCC->CR) &= ~(1<<HSEBYP);
		#else
			#error "Invalid HSE Configuration!"
		#endif
		
		(RCC->CFGR) |= (1<<SW0);
		(RCC->CFGR) &= ~(1<<SW1);
	
		(RCC->CR) |= (1<<SYSCLK);
		
		while(((RCC->CR)&(1<<HSIRDY)) == HSERDY);
		
		if((((RCC->CFGR)&(1<<SWS0))>>SWS0) == HIGH)
		{
			if(((RCC->CFGR)&(1<<SWS1)) == LOW)
			{
				/*Do nothing, you configured system clock as HSE correctly*/
			}

			else
			{
				L_u8ErrorState = 3;
			}
		}
		
		else
		{
			L_u8ErrorState = 3;
		}

	/*********************************************************/
	
	#elif(SYSCLK == PLL)
		#if(PLL_INP == PLL_HSI)
			(RCC->PLLCFGR) &= ~(1<<PLLSRC);
		#elif(PLL_INP == PLL_HSE)
			(RCC->PLLCFGR) |= (1<<PLLSRC);
			
		#else
			#error "Invalid PLL Configuration!"
		#endif
		
		(RCC->CFGR) &= ~(1<<SW0);
		(RCC->CFGR) |= (1<<SW1)
		
		(RCC->CR) |= (1<<SYSCLK);
		
		while(((RCC->CR)&(1<<PLLRDY)) == LOW);
		
		if(((RCC->CFGR)&(1<<SWS0)) == LOW)
		{
			if((((RCC->CFGR)&(1<<SWS1))>>SWS1) == HIGH)
			{
				/*Do nothing, you configured system clock as PLL correctly*/
			}

			else
			{
				L_u8ErrorState = 4;
			}
		}

		else
		{
			L_u8ErrorState = 4;
		}
	#else
		#error "Invalid System Clock Configuration!"
	
	#endif


		return L_u8ErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MRCC_BoolEnablePerClk(u8 Cpy_u8PerID)
{
	Bool L_BoolErrorState = 1;
	
	if (Cpy_u8PerID<=DMA2)
	{
		(RCC->AHB1ENR) |= (1<<Cpy_u8PerID);
	}
	
	else if (Cpy_u8PerID == USBOTGFS)
	{
		(RCC->AHB2ENR) |= (1<<(Cpy_u8PerID-32));
	}
		
	else if ((Cpy_u8PerID>=TIM2) && (Cpy_u8PerID<=PWR))
	{
		(RCC->APB1ENR) |= (1<<(Cpy_u8PerID-64));
		
	}
	
	else if ((Cpy_u8PerID>=TIM1) && (Cpy_u8PerID<=TIM11))
	{
		(RCC->APB2ENR) |= (1<<(Cpy_u8PerID-96));
	}
	
	else
	{
		L_BoolErrorState = 0;
	}
	
	
	return L_BoolErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MRCC_BoolDisablePerClk(u8 Cpy_u8PerID)
{
	Bool L_BoolErrorState = 1;
	
	if (Cpy_u8PerID<=DMA2)
	{
		(RCC->AHB1ENR) &= ~(1<<Cpy_u8PerID);
	}
	
	else if (Cpy_u8PerID == USBOTGFS)
	{
		(RCC->AHB2ENR) &= ~(1<<Cpy_u8PerID);
	}
		
	else if ((Cpy_u8PerID>=TIM2) && (Cpy_u8PerID<=PWR))
	{
		(RCC->APB1ENR) &= ~(1<<Cpy_u8PerID);
		
	}
	
	else if ((Cpy_u8PerID>=TIM1) && (Cpy_u8PerID<=TIM11))
	{
		(RCC->APB2ENR) &= ~(1<<Cpy_u8PerID);
	}
	
	else
	{
		L_BoolErrorState = 0;
	}
	
	
	return L_BoolErrorState;
}

