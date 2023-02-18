/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 10 Feb 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "RCC_int.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"


void MRCC_vInit(void)
{
	#if CSS == ENABLE
		SET_BIT(RCC->CR, CSSON);
	#endif
/************************************************************/
	#if CLK_SRC == HSE_BYP
		SET_BIT(RCC->CFGR, SW0);
		CLR_BIT(RCC->CFGR, SW1);
		SET_BIT(RCC->CR, HSEBYP);
		SET_BIT(RCC->CR, HSEON);

	#elif CLK_SRC == HSE_NBYP
		SET_BIT(RCC->CFGR, SW0);
		CLR_BIT(RCC->CFGR, SW1);
		CLR_BIT(RCC->CR, HSEBYP);
		SET_BIT(RCC->CR, HSEON);

	#elif CLK_SRC == HSI
		CLR_BIT(RCC->CFGR, SW0);
		CLR_BIT(RCC->CFGR, SW1);
		SET_BIT(RCC->CR, HSION);

	#elif CLK_SRC == PLL_HSE
		CLR_BIT(RCC->CFGR, SW0);
		SET_BIT(RCC->CFGR, SW1);
		SET_BIT(RCC->CFGR, PLLSRC);
		CLR_BIT(RCC->CFGR, PLLXTPRE);
		WRITE_REG_MASKED(RCC->CFGR, PLL_MODE, 0x003C0000);
		SET_BIT(RCC->CR, PLLON);

	#elif CLK_SRC == PLL_HSE_OVER2
		CLR_BIT(RCC->CFGR, SW0);
		SET_BIT(RCC->CFGR, SW1);
		SET_BIT(RCC->CFGR, PLLSRC);
		SET_BIT(RCC->CFGR, PLLXTPRE);
		WRITE_REG_MASKED(RCC->CFGR, PLL_MODE, 0x003C0000);
		SET_BIT(RCC->CR, PLLON);

	#elif CLK_SRC == PLL_HSI_OVER2
		CLR_BIT(RCC->CFGR, SW0);
		SET_BIT(RCC->CFGR, SW1);
		CLR_BIT(RCC->CFGR, PLLSRC);
		WRITE_REG_MASKED(RCC->CFGR, PLL_MODE, 0x003C0000);
		SET_BIT(RCC->CR, PLLON);

	#endif
/************************************************************/


	/*	WRITE_REG_MASKED(RCC->CFGR, APB1_CLK, 0x00000700);
	WRITE_REG_MASKED(RCC->CFGR, APB2_CLK, 0x00003800);
	WRITE_REG_MASKED(RCC->CFGR, AHB_CLK,  0x000000F0);*/

		ASSIGN_BIT(RCC->CFGR, PPRE10, (APB1_CLK & 1)>>0);
		ASSIGN_BIT(RCC->CFGR, PPRE11, (APB1_CLK & 2)>>1);
		ASSIGN_BIT(RCC->CFGR, PPRE12, (APB1_CLK & 4)>>2);

		ASSIGN_BIT(RCC->CFGR, PPRE20, (APB2_CLK & 1)>>0);
		ASSIGN_BIT(RCC->CFGR, PPRE21, (APB2_CLK & 2)>>1);
		ASSIGN_BIT(RCC->CFGR, PPRE22, (APB2_CLK & 4)>>2);

		ASSIGN_BIT(RCC->CFGR, HPRE0, (AHB_CLK & 1)>>0);
		ASSIGN_BIT(RCC->CFGR, HPRE1, (AHB_CLK & 2)>>1);
		ASSIGN_BIT(RCC->CFGR, HPRE2, (AHB_CLK & 4)>>2);
		ASSIGN_BIT(RCC->CFGR, HPRE2, (AHB_CLK & 8)>>3);
}

/*******************************************************************/

Bool MRCC_BoolEnableClock(u8 A_u8BusID, u8 A_u8PerID)
{
	Bool L_BoolErrorState = 1;

	switch(A_u8BusID)
	{
		case AHB  :
			if(A_u8PerID <= RCC_AHBENR_END)
			{
				SET_BIT(RCC->AHBENR, A_u8PerID - RCC_AHBENR_START);
			}

			else
			{
				L_BoolErrorState = 0;
			}

			break;


		case APB2 :
			if((A_u8PerID >= RCC_APB2ENR_START) && (A_u8PerID <= RCC_APB2ENR_END))
			{
				SET_BIT(RCC->APB2ENR, A_u8PerID - RCC_APB2ENR_START);
			}

			else
			{
				L_BoolErrorState = 0;
			}

			break;


		case APB1 :
			if((A_u8PerID >= RCC_APB1ENR_START) && (A_u8PerID <= RCC_APB1ENR_END))
				{
					SET_BIT(RCC->APB1ENR, A_u8PerID - RCC_APB1ENR_START);
				}

			else
				{
					L_BoolErrorState = 0;
				}

			break;

		default   :
			L_BoolErrorState = 0;

	}

	return L_BoolErrorState;

}

/*******************************************************************/

Bool MRCC_BoolDisableClock(u8 A_u8BusID, u8 A_u8PerID)
{
	Bool L_BoolErrorState = 1;

	switch(A_u8BusID)
	{
		case AHB  :
			if(A_u8PerID <= RCC_AHBENR_END)
			{
				CLR_BIT(RCC->AHBENR, A_u8PerID - RCC_AHBENR_START);
			}

			else
			{
				L_BoolErrorState = 0;
			}

			break;


		case APB2 :
			if((A_u8PerID >= RCC_APB2ENR_START) && (A_u8PerID <= RCC_APB2ENR_END))
			{
				CLR_BIT(RCC->APB2ENR, A_u8PerID - RCC_APB2ENR_START);
			}

			else
			{
				L_BoolErrorState = 0;
			}

			break;


		case APB1 :
			if((A_u8PerID >= RCC_APB1ENR_START) && (A_u8PerID <= RCC_APB1ENR_END))
				{
					CLR_BIT(RCC->APB1ENR, A_u8PerID - RCC_APB1ENR_START);
				}

			else
				{
					L_BoolErrorState = 0;
				}

			break;

		default   :
			L_BoolErrorState = 0;

		}

	return L_BoolErrorState;

}

/*******************************************************************/

Bool MRCC_BoolResetPer(u8 A_u8BusID, u8 A_u8PerID)
{
	Bool L_BoolErrorState = 1;

	switch(A_u8BusID)
	{
		case APB2 :
			if((A_u8PerID >= RCC_APB2ENR_START) && (A_u8PerID <= RCC_APB2ENR_END))
			{
				SET_BIT(RCC->APB2RSTR, A_u8PerID - RCC_APB2ENR_START);
			}

			else
			{
				L_BoolErrorState = 0;
			}

			break;


		case APB1 :
			if((A_u8PerID >= RCC_APB1ENR_START) && (A_u8PerID <= RCC_APB1ENR_END))
				{
					SET_BIT(RCC->APB1RSTR, A_u8PerID - RCC_APB1ENR_START);
				}

			else
				{
					L_BoolErrorState = 0;
				}

			break;

		default   :
			L_BoolErrorState = 0;

	}

	return L_BoolErrorState;

}
