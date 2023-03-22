/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 Mar 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_prv.h"
#include "EXTI_int.h"
#include "EXTI_cfg.h"


void MEXTI_vInit(void)
{
	/*Clear All Flags*/
	EXTI->PR = 0xFFFFFFFF;

	/*Mask All Interrupts*/
	EXTI->IMR = 0;

	/*Mask All Events*/
	EXTI->EMR = 0;


	#if PIN <= MAX_PORT
		#if TYPE <= MAX_TYPE
			#if TRIGGER <= MAX_TRIGGER
				#if PIN <= P3
					ASSIGN_BIT(AFIO->EXTICR1, PIN*4+0, (PORT & 1)>>0);
					ASSIGN_BIT(AFIO->EXTICR1, PIN*4+1, (PORT & 2)>>1);
					ASSIGN_BIT(AFIO->EXTICR1, PIN*4+2, (PORT & 4)>>2);
					ASSIGN_BIT(AFIO->EXTICR1, PIN*4+3, (PORT & 8)>>3);

					#if TYPE == INTERRUPT
						SET_BIT(EXTI->IMR, PIN);
						CLR_BIT(EXTI->EMR, PIN);
					#else
						SET_BIT(EXTI->EMR, PIN);
						CLR_BIT(EXTI->IMR, PIN);

					#if TRIGGER == RISING_EDGE
						SET_BIT(EXTI->RTSR, PIN);
						CLR_BIT(EXTI->FTSR, PIN);
					#elif TRIGGER == FALLING_EDGE
						SET_BIT(EXTI->FTSR, PIN);
						CLR_BIT(EXTI->RTSR, PIN);
					#else
						SET_BIT(EXTI->RTSR, PIN);
						SET_BIT(EXTI->FTSR, PIN);


				#elif PIN <= P7
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-4)*4+0, (PORT & 1)>>0);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-4)*4+1, (PORT & 2)>>1);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-4)*4+2, (PORT & 4)>>2);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-4)*4+3, (PORT & 8)>>3);
					#if TYPE == INTERRUPT
						SET_BIT(EXTI->IMR, PIN);
					#else
						SET_BIT(EXTI->EMR, PIN);
					#endif

					#if TRIGGER == RISING_EDGE
						SET_BIT(EXTI->RTSR, PIN);
						CLR_BIT(EXTI->FTSR, PIN);
					#elif TRIGGER == FALLING_EDGE
						SET_BIT(EXTI->FTSR, PIN);
						CLR_BIT(EXTI->RTSR, PIN);
					#else
						SET_BIT(EXTI->RTSR, PIN);
						SET_BIT(EXTI->FTSR, PIN);
					#endif



				#elif PIN <= P11
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-8)*4+0, (PORT & 1)>>0);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-8)*4+1, (PORT & 2)>>1);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-8)*4+2, (PORT & 4)>>2);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-8)*4+3, (PORT & 8)>>3);
					#if TYPE == INTERRUPT
						SET_BIT(EXTI->IMR, PIN);
					#else
						SET_BIT(EXTI->EMR, PIN);
					#endif

					#if TRIGGER == RISING_EDGE
						SET_BIT(EXTI->RTSR, PIN);
						CLR_BIT(EXTI->FTSR, PIN);
					#elif TRIGGER == FALLING_EDGE
						SET_BIT(EXTI->FTSR, PIN);
						CLR_BIT(EXTI->RTSR, PIN);
					#else
						SET_BIT(EXTI->RTSR, PIN);
						SET_BIT(EXTI->FTSR, PIN);
					#endif



				#elif PIN <= P15
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-12)*4+0, (PORT & 1)>>0);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-12)*4+1, (PORT & 2)>>1);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-12)*4+2, (PORT & 4)>>2);
					ASSIGN_BIT(AFIO->EXTICR2, (PIN-12)*4+3, (PORT & 8)>>3);
					#if TYPE == INTERRUPT
						SET_BIT(EXTI->IMR, PIN);
					#else
						SET_BIT(EXTI->EMR, PIN);
					#endif

					#if TRIGGER == RISING_EDGE
						SET_BIT(EXTI->RTSR, PIN);
						CLR_BIT(EXTI->FTSR, PIN);
					#elif TRIGGER == FALLING_EDGE
						SET_BIT(EXTI->FTSR, PIN);
						CLR_BIT(EXTI->RTSR, PIN);
					#else
						SET_BIT(EXTI->RTSR, PIN);
						SET_BIT(EXTI->FTSR, PIN);
					#endif

			#else
				#error "Invalid Trigger Mode!"
			#endif

		#else
			#error "Invalid Pin Type!"
		#endif

	#else
		#error "Invalid Pin Number!"
	#endif
}

Bool MEXTI_BoolEnableLine(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinType, u8 A_u8PinTrigger)
{
	Bool L_BoolErrorState = 1;

	if (A_u8Port <= PG)
	{
		if(A_u8Pin <= MAX_PORT)
		{
			if(A_u8PinType <= MAX_TYPE)
			{
				if(A_u8PinTrigger <= MAX_TRIGGER)
				{
					if (A_u8Pin <= P3)
					{
						ASSIGN_BIT(AFIO->EXTICR1, PIN*4+0, (PORT & 1)>>0);
						ASSIGN_BIT(AFIO->EXTICR1, PIN*4+1, (PORT & 2)>>1);
						ASSIGN_BIT(AFIO->EXTICR1, PIN*4+2, (PORT & 4)>>2);
						ASSIGN_BIT(AFIO->EXTICR1, PIN*4+3, (PORT & 8)>>3);
					}

					else if (A_u8Pin <= P7)
					{
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-4)*4+0, (PORT & 1)>>0);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-4)*4+1, (PORT & 2)>>1);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-4)*4+2, (PORT & 4)>>2);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-4)*4+3, (PORT & 8)>>3);
					}

					else if(A_u8Pin <= P11)
					{
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-8)*4+0, (PORT & 1)>>0);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-8)*4+1, (PORT & 2)>>1);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-8)*4+2, (PORT & 4)>>2);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-8)*4+3, (PORT & 8)>>3);
					}

					else if(A_u8Pin <= P15)
					{
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-12)*4+0, (PORT & 1)>>0);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-12)*4+1, (PORT & 2)>>1);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-12)*4+2, (PORT & 4)>>2);
						ASSIGN_BIT(AFIO->EXTICR2, (PIN-12)*4+3, (PORT & 8)>>3);
					}


					switch(A_u8PinType)
					{
						case INTERRUPT:
							SET_BIT(EXTI->IMR, PIN);
							CLR_BIT(EXTI->EMR, PIN);
							break;

						case EVENT:
							SET_BIT(EXTI->EMR, PIN);
							CLR_BIT(EXTI->IMR, PIN);
							break;
					}


					switch(A_u8PinTrigger)
					{
						case RISING_EDGE:
							SET_BIT(EXTI->RTSR, PIN);
							CLR_BIT(EXTI->FTSR, PIN);
							break;

						case FALLING_EDGE:
							SET_BIT(EXTI->FTSR, PIN);
							CLR_BIT(EXTI->RTSR, PIN);
							break;

						case CHANGE:
							SET_BIT(EXTI->RTSR, PIN);
							SET_BIT(EXTI->FTSR, PIN);
							break;
					}
				}
			}

			else
			{
				L_BoolErrorState = 0;
			}
		}

		else
		{
			L_BoolErrorState = 0;
		}
	}

	else
	{
		L_BoolErrorState = 0;
	}

	return L_BoolErrorState;
}

Bool MEXTI_BoolDisableLine(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinType, u8 A_u8PinTrigger)
{
	Bool L_BoolErrorState = 1;

	if (A_u8Port <= PG)
	{
		if(A_u8Pin <= MAX_PORT)
		{
			if(A_u8PinType <= MAX_TYPE)
			{
				if(A_u8PinTrigger <= MAX_TRIGGER)
				{
					CLR_BIT(EXTI->IMR, PIN);
					CLR_BIT(EXTI->EMR, PIN);
				}

				else
				{
					L_BoolErrorState = 0;
				}

			else
			{
				L_BoolErrorState = 0;
			}

		else
		{
				L_BoolErrorState = 0;
		}

	else
	{
		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;
}
