/*
 * MEXTI_prg.c
 *
 *  Created on: May 31, 2023
 *      Author: Ahmed
 */


#include<LIB/STD_TYPES.h>
#include<MCAL/MEXTI/MEXTI_prv.h>
#include<MCAL/MEXTI/MEXTI_int.h>



u8 MEXTI_u8SetHWInterrupt(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, triggerType_t Cpy_trigTypeTrigger)
{
	/*Successful return            : L_u8ErrorState = 0*/
	/*Wrong port ID entered        : L_u8ErrorState = 2*/
	/*Wrong pin number entered     : L_u8ErrorState = 3*/
	/*Wrong trigger type entered   : L_u8ErrorState = 4*/
	/*Forbidden pin entered        : L_u8ErrorState = 5*/

	u8 L_u8ErrorState = 0;



	if(Cpy_u8PinNum <= PIN15)
	{
		if(Cpy_trigTypeTrigger <= CHANGE)
		{
			//volatile u32 *L_u32PtRegAddr = SYSCFG_EXTICR1; + Cpy_u8PinNum/4;

			switch(Cpy_u8PortID)
			{
			case PA:
				   	   if((Cpy_u8PinNum!=PIN13) && (Cpy_u8PinNum!=PIN14) && (Cpy_u8PinNum!=PIN15))
				   	   {
				   		   if(Cpy_u8PinNum <= 3)
				   		   {
				   			   SYSCFG_EXTICR1 &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
				   			   SYSCFG_EXTICR1 |= PORTA_EXTI<<((Cpy_u8PinNum%4)*4);
				   		   }

				   		   else if((Cpy_u8PinNum>=4) && (Cpy_u8PinNum<=7))
				   		   {
				   			   SYSCFG_EXTICR2 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-4)%4)*4));
				   			   SYSCFG_EXTICR2 |= PORTA_EXTI<<(((Cpy_u8PinNum-4)%4)*4);
				   		   }

				   		   else if((Cpy_u8PinNum>=8) && (Cpy_u8PinNum<=11))
				   		   {
				   			   SYSCFG_EXTICR3 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-8)%4)*4));
				   			   SYSCFG_EXTICR3 |= PORTA_EXTI<<(((Cpy_u8PinNum-8)%4)*4);
				   		   }

				   		   else
				   		   {
				   			   SYSCFG_EXTICR4 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-12)%4)*4));
				   			   SYSCFG_EXTICR4 |= PORTA_EXTI<<(((Cpy_u8PinNum-12)%4)*4);
				   		   }

				   		   //*L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
				       	   //*L_u32PtRegAddr |= PORTA_EXTI<<((Cpy_u8PinNum%4)*4);

				   	   }
				   	   else
				   	   {
				   		   L_u8ErrorState = 0x05;
				   	   }
				   	   break;


			case PB:
					   if((Cpy_u8PinNum!=PIN3) && (Cpy_u8PinNum!=PIN4))
					   {
						   if(Cpy_u8PinNum <= 3)
						   {
							   SYSCFG_EXTICR1 &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
							   SYSCFG_EXTICR1 |= PORTB_EXTI<<((Cpy_u8PinNum%4)*4);
						   }

						   else if((Cpy_u8PinNum>=4) && (Cpy_u8PinNum<=7))
						   {
							   SYSCFG_EXTICR2 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-4)%4)*4));
							   SYSCFG_EXTICR2 |= PORTB_EXTI<<(((Cpy_u8PinNum-4)%4)*4);
						   }

						   else if((Cpy_u8PinNum>=8) && (Cpy_u8PinNum<=11))
						   {
							   SYSCFG_EXTICR3 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-8)%4)*4));
							   SYSCFG_EXTICR3 |= PORTB_EXTI<<(((Cpy_u8PinNum-8)%4)*4);
						   }

						   else
						   {
							   SYSCFG_EXTICR4 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-12)%4)*4));
							   SYSCFG_EXTICR4 |= PORTB_EXTI<<(((Cpy_u8PinNum-12)%4)*4);
						   }

						   //*L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
						   //*L_u32PtRegAddr |= PORTB_EXTI<<((Cpy_u8PinNum%4)*4);
						   //(EXTI->IMR) |= (1<<Cpy_u8PinNum);
					   }
					   else
					   {
						   L_u8ErrorState = 0x05;
					   }
					   break;


			case PC:
				if(Cpy_u8PinNum <= 3)
				{
					SYSCFG_EXTICR1 &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
					SYSCFG_EXTICR1 |= PORTC_EXTI<<((Cpy_u8PinNum%4)*4);
				}

				else if((Cpy_u8PinNum>=4) && (Cpy_u8PinNum<=7))
				{
					SYSCFG_EXTICR2 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-4)%4)*4));
					SYSCFG_EXTICR2 |= PORTC_EXTI<<(((Cpy_u8PinNum-4)%4)*4);
				}

				else if((Cpy_u8PinNum>=8) && (Cpy_u8PinNum<=11))
				{
					SYSCFG_EXTICR3 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-8)%4)*4));
					SYSCFG_EXTICR3 |= PORTC_EXTI<<(((Cpy_u8PinNum-8)%4)*4);
				}

				else
				{
					SYSCFG_EXTICR4 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-12)%4)*4));
					SYSCFG_EXTICR4 |= PORTC_EXTI<<(((Cpy_u8PinNum-12)%4)*4);
				}
					   //*L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
					   //*L_u32PtRegAddr |= PORTC_EXTI<<((Cpy_u8PinNum%4)*4);
					   //(EXTI->IMR) |= (1<<Cpy_u8PinNum);
					   break;


			case PD:
				if(Cpy_u8PinNum <= 3)
				{
					SYSCFG_EXTICR1 &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
					SYSCFG_EXTICR1 |= PORTD_EXTI<<((Cpy_u8PinNum%4)*4);
				}

				else if((Cpy_u8PinNum>=4) && (Cpy_u8PinNum<=7))
				{
					SYSCFG_EXTICR2 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-4)%4)*4));
					SYSCFG_EXTICR2 |= PORTD_EXTI<<(((Cpy_u8PinNum-4)%4)*4);
				}

				else if((Cpy_u8PinNum>=8) && (Cpy_u8PinNum<=11))
				{
					SYSCFG_EXTICR3 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-8)%4)*4));
					SYSCFG_EXTICR3 |= PORTD_EXTI<<(((Cpy_u8PinNum-8)%4)*4);
				}

				else
				{
					SYSCFG_EXTICR4 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-12)%4)*4));
					SYSCFG_EXTICR4 |= PORTD_EXTI<<(((Cpy_u8PinNum-12)%4)*4);
				}
						//*L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
			   	   	   //*L_u32PtRegAddr |= PORTD_EXTI<<((Cpy_u8PinNum%4)*4);
			   	   	   //(EXTI->IMR) |= (1<<Cpy_u8PinNum);
			   	   	   break;


			case PE:
				if(Cpy_u8PinNum <= 3)
				{
					SYSCFG_EXTICR1 &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
					SYSCFG_EXTICR1 |= PORTE_EXTI<<((Cpy_u8PinNum%4)*4);
				}

				else if((Cpy_u8PinNum>=4) && (Cpy_u8PinNum<=7))
				{
					SYSCFG_EXTICR2 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-4)%4)*4));
					SYSCFG_EXTICR2 |= PORTE_EXTI<<(((Cpy_u8PinNum-4)%4)*4);
				}

				else if((Cpy_u8PinNum>=8) && (Cpy_u8PinNum<=11))
				{
					SYSCFG_EXTICR3 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-8)%4)*4));
					SYSCFG_EXTICR3 |= PORTE_EXTI<<(((Cpy_u8PinNum-8)%4)*4);
				}

				else
				{
					SYSCFG_EXTICR4 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-12)%4)*4));
					SYSCFG_EXTICR4 |= PORTE_EXTI<<(((Cpy_u8PinNum-12)%4)*4);
				}
				//*L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
				//*L_u32PtRegAddr |= PORTE_EXTI<<((Cpy_u8PinNum%4)*4);
				//(EXTI->IMR) |= (1<<Cpy_u8PinNum);
				   	   break;


			case PH:
				if(Cpy_u8PinNum <= 3)
				{
					SYSCFG_EXTICR1 &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
					SYSCFG_EXTICR1 |= PORTH_EXTI<<((Cpy_u8PinNum%4)*4);
				}

				else if((Cpy_u8PinNum>=4) && (Cpy_u8PinNum<=7))
				{
					SYSCFG_EXTICR2 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-4)%4)*4));
					SYSCFG_EXTICR2 |= PORTH_EXTI<<(((Cpy_u8PinNum-4)%4)*4);
				}

				else if((Cpy_u8PinNum>=8) && (Cpy_u8PinNum<=11))
				{
					SYSCFG_EXTICR3 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-8)%4)*4));
					SYSCFG_EXTICR3 |= PORTH_EXTI<<(((Cpy_u8PinNum-8)%4)*4);
				}

				else
				{
					SYSCFG_EXTICR4 &= ~(EXTI_MASK<<(((Cpy_u8PinNum-12)%4)*4));
					SYSCFG_EXTICR4 |= PORTH_EXTI<<(((Cpy_u8PinNum-12)%4)*4);
				}
				   	   //*L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
				   	   //*L_u32PtRegAddr |= PORTH_EXTI<<((Cpy_u8PinNum%4)*4);
				   	   //(EXTI->IMR) |= (1<<Cpy_u8PinNum);
				   	   break;


			default:
					   L_u8ErrorState = 0x02;
					   break;
			}

			(EXTI->IMR) |= (1<<Cpy_u8PinNum);

			switch(Cpy_trigTypeTrigger)
			{
			case RISINGEDGE:
				           	   (EXTI->RTSR) |= (1<<Cpy_u8PinNum);
				           	   (EXTI->FTSR) &= ~(1<<Cpy_u8PinNum);
				           	   break;
			case FALLINGEDGE:
								(EXTI->RTSR) &= ~(1<<Cpy_u8PinNum);
								(EXTI->FTSR) |= (1<<Cpy_u8PinNum);
								break;
			default:
				   	            (EXTI->RTSR) |= (1<<Cpy_u8PinNum);
				   	            (EXTI->FTSR) |= (1<<Cpy_u8PinNum);
				   	            break;
			}
		}

		else
		{
			L_u8ErrorState = 0x04;
		}
	}

	else
	{
		L_u8ErrorState = 0x03;
	}


	return L_u8ErrorState;
}


/*****************************************************************************************************/
/*****************************************************************************************************/


//u8 MEXTI_u8SetHWEvent(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, triggerType_t Cpy_trigTypeTrigger)
//{
//	/*Successful return            : L_u8ErrorState = 0*/
//	/*Wrong port ID entered        : L_u8ErrorState = 2*/
//	/*Wrong pin number entered     : L_u8ErrorState = 3*/
//	/*Wrong trigger type entered   : L_u8ErrorState = 4*/
//	/*Forbidden pin entered        : L_u8ErrorState = 5*/
//
//	u8 L_u8ErrorState = 0;
//
//
//	if(Cpy_u8PinNum <= PIN15)
//	{
//		if(Cpy_trigTypeTrigger <= CHANGE)
//		{
//			volatile u32 *L_u32PtRegAddr = SYSCFG_EXTICR1 + Cpy_u8PinNum/4;
//
//			switch(Cpy_u8PortID)
//			{
//			case PA:
//				   	   if((Cpy_u8PinNum!=PIN13) && (Cpy_u8PinNum!=PIN14) && (Cpy_u8PinNum!=PIN15))
//				   	   {
//				   		   *L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
//				       	   *L_u32PtRegAddr |= PORTA_EXTI<<((Cpy_u8PinNum%4)*4);
//				       	   (EXTI->EMR) |= (1<<Cpy_u8PinNum);
//				   	   }
//				   	   else
//				   	   {
//				   		   L_u8ErrorState = 0x05;
//				   	   }
//				   	   break;
//
//
//			case PB:
//					   if((Cpy_u8PinNum!=PIN3) && (Cpy_u8PinNum!=PIN4))
//					   {
//						   *L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
//						   *L_u32PtRegAddr |= PORTB_EXTI<<((Cpy_u8PinNum%4)*4);
//						   (EXTI->EMR) |= (1<<Cpy_u8PinNum);
//					   }
//					   else
//					   {
//						   L_u8ErrorState = 0x05;
//					   }
//					   break;
//
//
//			case PC:
//					   *L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
//					   *L_u32PtRegAddr |= PORTC_EXTI<<((Cpy_u8PinNum%4)*4);
//					   (EXTI->EMR) |= (1<<Cpy_u8PinNum);
//					   break;
//
//
//			case PD:   *L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
//			   	   	   *L_u32PtRegAddr |= PORTD_EXTI<<((Cpy_u8PinNum%4)*4);
//			   	   	   (EXTI->EMR) |= (1<<Cpy_u8PinNum);
//			   	   	   break;
//
//
//			case PE:
//				   	   *L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
//				   	   *L_u32PtRegAddr |= PORTE_EXTI<<((Cpy_u8PinNum%4)*4);
//				   	   (EXTI->EMR) |= (1<<Cpy_u8PinNum);
//				   	   break;
//
//
//			case PH:
//				   	   *L_u32PtRegAddr &= ~(EXTI_MASK<<((Cpy_u8PinNum%4)*4));
//				   	   *L_u32PtRegAddr |= PORTH_EXTI<<((Cpy_u8PinNum%4)*4);
//				   	   (EXTI->EMR) |= (1<<Cpy_u8PinNum);
//				   	   break;
//
//
//			default:
//					   L_u8ErrorState = 0x02;
//					   break;
//			}
//
//			switch(Cpy_trigTypeTrigger)
//			{
//			case RISINGEDGE:
//				           	   (EXTI->RTSR) |= (1<<Cpy_u8PinNum);
//				           	   (EXTI->FTSR) &= ~(1<<Cpy_u8PinNum);
//				           	   break;
//			case FALLINGEDGE:
//								(EXTI->RTSR) &= ~(1<<Cpy_u8PinNum);
//								(EXTI->FTSR) |= (1<<Cpy_u8PinNum);
//								break;
//			default:
//				   	            (EXTI->RTSR) |= (1<<Cpy_u8PinNum);
//				   	            (EXTI->FTSR) |= (1<<Cpy_u8PinNum);
//				   	            break;
//			}
//		}
//
//		else
//		{
//			L_u8ErrorState = 0x04;
//		}
//	}
//
//	else
//	{
//		L_u8ErrorState = 0x03;
//	}
//
//
//	return L_u8ErrorState;
//}
//

/*****************************************************************************************************/
/*****************************************************************************************************/

Bool MEXTI_BoolSetSWInterrupt(EXTILine_t Cpy_EXTILineNum)
{
	/*Successful return       : L_BoolErrorState = 0*/
	/*Wrong EXTI line entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	if(Cpy_EXTILineNum <= EXTIL15)
	{
		(EXTI->IMR) |= (1<<Cpy_EXTILineNum);
		(EXTI->SWIER) |= (1<<Cpy_EXTILineNum);

		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MEXTI_BoolSetSWEvent(EXTILine_t Cpy_EXTILineNum)
{
	/*Successful return       : L_BoolErrorState = 0*/
	/*Wrong EXTI line entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	if(Cpy_EXTILineNum <= EXTIL15)
	{
		(EXTI->EMR) |= (1<<Cpy_EXTILineNum);
		(EXTI->SWIER) |= (1<<Cpy_EXTILineNum);

		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MEXTI_BoolIsPending(EXTILine_t Cpy_EXTILineNum)
{
	/*Successful return, EXTI line is NOT pending: L_BoolErrorState = 0*/
	/*Successful return, EXTI line is pending    : L_BoolErrorState = 1*/
	/*Wrong EXTI line entered : L_BoolErrorState = 2*/

	Bool L_BoolErrorState = 2;

	if(Cpy_EXTILineNum <= EXTIL15)
	{
		L_BoolErrorState = ((EXTI->PR)&(1<<Cpy_EXTILineNum)) >> Cpy_EXTILineNum;
	}


	return L_BoolErrorState;

}


/*****************************************************************************************************/
/*****************************************************************************************************/


Bool MEXTI_BoolClrPending(EXTILine_t Cpy_EXTILineNum)
{
	/*Successful return       : L_BoolErrorState = 0*/
	/*Wrong EXTI line entered : L_BoolErrorState = 1*/

	Bool L_BoolErrorState = 1;

	if(Cpy_EXTILineNum <= EXTIL15)
	{
		/*PR bits are cleared by writing 1 to them*/
		(EXTI->PR) |= (1<<Cpy_EXTILineNum);

		L_BoolErrorState = 0;
	}


	return L_BoolErrorState;

}
