
#include "../../LIB/STD_TYPES.h"
#include "MGPIO_prv.h"
#include "MGPIO_int.h"




u8 MGPIO_u8CfgPinMode(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, u8 Cpy_u8PinMode)
{
	/*Successful return        : L_u8ErrorState = 0x00*/
	/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
	/*Wrong pin number entered : L_u8ErrorState = 0x03*/
	/*Wrong pin mode entered   : L_u8ErrorState = 0x04*/
	/*Forbidden pin entered    : L_u8ErrorState = 0x05*/

	u8 L_u8ErrorState = 0x00;

	if(Cpy_u8PinNum <= PIN15)
	{
		if(Cpy_u8PinMode <= ANALOG)
		{
			switch(Cpy_u8PortID)
			{
				case PA:  if((Cpy_u8PinNum!=PIN13) && (Cpy_u8PinNum!=PIN14) && (Cpy_u8PinNum!=PIN15))
							 {
			         	 	 	 PORTA->MODER &= ~(MODE_MASK<<(Cpy_u8PinNum*2));
			         	 	 	 PORTA->MODER |= Cpy_u8PinMode<<(Cpy_u8PinNum*2);
							 }
							 else
							 {
								 L_u8ErrorState = 0x05;
							 }
					 	 	 break;


				case PB:  if((Cpy_u8PinNum!=PIN3) && (Cpy_u8PinNum!=PIN4))
							 {
			         	 	 	 PORTB->MODER &= ~(MODE_MASK<<(Cpy_u8PinNum*2));
			         	 	 	 PORTB->MODER |= Cpy_u8PinMode<<(Cpy_u8PinNum*2);
							 }
				             else
				             {
				            	 L_u8ErrorState = 0x05;
				             }
		             	 	 break;


				case PC:  PORTC->MODER &= ~(MODE_MASK<<(Cpy_u8PinNum*2));
		             	 	 PORTC->MODER |= Cpy_u8PinMode<<(Cpy_u8PinNum*2);
		             	 	 break;


				case PD:  PORTD->MODER &= ~(MODE_MASK<<(Cpy_u8PinNum*2));
		             	 	 PORTD->MODER |= Cpy_u8PinMode<<(Cpy_u8PinNum*2);
		             	 	 break;


				case PE:  PORTE->MODER &= ~(MODE_MASK<<(Cpy_u8PinNum*2));
		             	 	 PORTE->MODER |= Cpy_u8PinMode<<(Cpy_u8PinNum*2);
		             	 	 break;


				case PH:  PORTH->MODER &= ~(MODE_MASK<<(Cpy_u8PinNum*2));
		             	 	 PORTH->MODER |= Cpy_u8PinMode<<(Cpy_u8PinNum*2);
		             	 	 break;


				default   :  L_u8ErrorState = 0x02;
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


u8 MGPIO_u8CfgOutPin (u8 Cpy_u8PortID, u8 Cpy_u8PinNum, Bool Cpy_BoolOutType, u8 Cpy_u8OutSpeed)
{
	/*Successful return          : L_u8ErrorState = 0x00*/
	/*Wrong port ID entered      : L_u8ErrorState = 0x02*/
	/*Wrong pin number entered   : L_u8ErrorState = 0x03*/
	/*Wrong output type entered  : L_u8ErrorState = 0x04*/
	/*Wrong output speed entered : L_u8ErrorState = 0x05*/
	/*Forbidden pin entered      : L_u8ErrorState = 0x06*/

	u8 L_u8ErrorState = 0x00;

	if(Cpy_u8PinNum <= PIN15)
	{
		if((Cpy_BoolOutType==OUT_PUSH_PULL) || (Cpy_BoolOutType==OUT_OPEN_DRAIN))
		{
			if(Cpy_u8OutSpeed <= OUT_VHIGH_SPEED)
			{
				switch(Cpy_u8PortID)
				{
					case PA:  if((Cpy_u8PinNum!=PIN13) && (Cpy_u8PinNum!=PIN14) && (Cpy_u8PinNum!=PIN15))
					             {
								 	 PORTA->OTYPER &= ~(BIT_MASK<<Cpy_u8PinNum);
								 	 PORTA->OTYPER |= Cpy_BoolOutType<<Cpy_u8PinNum;
								 	 PORTA->OSPEEDR &= ~(SPEED_MASK<<(Cpy_u8PinNum*2));
								 	 PORTA->OSPEEDR |= Cpy_u8OutSpeed<<(Cpy_u8PinNum*2);
					             }
					             else
					             {
					            	 L_u8ErrorState = 0x06;
					             }
								 break;


					case PB:  if((Cpy_u8PinNum!=PIN3) && (Cpy_u8PinNum!=PIN4))
					             {
						         	 PORTB->OTYPER &= ~(BIT_MASK<<Cpy_u8PinNum);
						         	 PORTB->OTYPER |= Cpy_BoolOutType<<Cpy_u8PinNum;
						         	 PORTB->OSPEEDR &= ~(SPEED_MASK<<(Cpy_u8PinNum*2));
						         	 PORTB->OSPEEDR |= Cpy_u8OutSpeed<<(Cpy_u8PinNum*2);
					             }
							     else
							     {
							    	 L_u8ErrorState = 0x06;
							     }
								 break;


					case PC:  PORTC->OTYPER &= ~(BIT_MASK<<Cpy_u8PinNum);
					             PORTC->OTYPER |= Cpy_BoolOutType<<Cpy_u8PinNum;
								 PORTC->OSPEEDR &= ~(SPEED_MASK<<(Cpy_u8PinNum*2));
								 PORTC->OSPEEDR |= Cpy_u8OutSpeed<<(Cpy_u8PinNum*2);
								 break;


					case PD:  PORTD->OTYPER &= ~(BIT_MASK<<Cpy_u8PinNum);
					             PORTD->OTYPER |= Cpy_BoolOutType<<Cpy_u8PinNum;
								 PORTD->OSPEEDR &= ~(SPEED_MASK<<(Cpy_u8PinNum*2));
								 PORTD->OSPEEDR |= Cpy_u8OutSpeed<<(Cpy_u8PinNum*2);
								 break;


					case PE:  PORTE->OTYPER &= ~(BIT_MASK<<Cpy_u8PinNum);
								 PORTE->OTYPER |= Cpy_BoolOutType<<Cpy_u8PinNum;
								 PORTE->OSPEEDR &= ~(SPEED_MASK<<(Cpy_u8PinNum*2));
								 PORTE->OSPEEDR |= Cpy_u8OutSpeed<<(Cpy_u8PinNum*2);
								 break;


					case PH:  PORTH->OTYPER &= ~(BIT_MASK<<Cpy_u8PinNum);
								 PORTH->OTYPER |= Cpy_BoolOutType<<Cpy_u8PinNum;
								 PORTH->OSPEEDR &= ~(SPEED_MASK<<(Cpy_u8PinNum*2));
								 PORTH->OSPEEDR |= Cpy_u8OutSpeed<<(Cpy_u8PinNum*2);
								 break;


					default   :  L_u8ErrorState = 0x02;
					             break;

				}
			}

			else
			{
				L_u8ErrorState = 0x05;
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


u8 MGPIO_u8CfgInPin (u8 Cpy_u8PortID, u8 Cpy_u8PinNum, u8 Cpy_u8InType)
{
	/*Successful return        : L_u8ErrorState = 0x00*/
	/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
	/*Wrong pin number entered : L_u8ErrorState = 0x03*/
	/*Wrong input type entered : L_u8ErrorState = 0x04*/
	/*Forbidden pin entered    : L_u8ErrorState = 0x05*/

	u8 L_u8ErrorState = 0x00;

	if(Cpy_u8PinNum <= PIN15)
	{
		if(Cpy_u8InType <= IN_PULL_DOWN)
		{
			switch(Cpy_u8PortID)
			{
				case PA:  if((Cpy_u8PinNum!=PIN13) && (Cpy_u8PinNum!=PIN14) && (Cpy_u8PinNum!=PIN15))
				             {
					         	 PORTA->PUPDR &= ~(IN_TYPE_MASK<<(Cpy_u8PinNum*2));
								 PORTA->PUPDR |= Cpy_u8InType<<(Cpy_u8PinNum*2);
				             }
				             else
				             {
				            	 L_u8ErrorState = 0x05;
				             }
			             	 break;


				case PB:  if((Cpy_u8PinNum!=PIN3) && (Cpy_u8PinNum!=PIN4))
				             {
					         	 PORTB->PUPDR &= ~(IN_TYPE_MASK<<(Cpy_u8PinNum*2));
								 PORTB->PUPDR |= Cpy_u8InType<<(Cpy_u8PinNum*2);
				             }
				             else
				             {
				            	 L_u8ErrorState = 0x05;
				             }
			             	 break;


				case PC:  PORTC->PUPDR &= ~(IN_TYPE_MASK<<(Cpy_u8PinNum*2));
							 PORTC->PUPDR |= Cpy_u8InType<<(Cpy_u8PinNum*2);
							 break;


				case PD:  PORTD->PUPDR &= ~(IN_TYPE_MASK<<(Cpy_u8PinNum*2));
			             	 PORTD->PUPDR |= Cpy_u8InType<<(Cpy_u8PinNum*2);
			             	 break;


				case PE:  PORTE->PUPDR &= ~(IN_TYPE_MASK<<(Cpy_u8PinNum*2));
			             	 PORTE->PUPDR |= Cpy_u8InType<<(Cpy_u8PinNum*2);
			             	 break;


				case PH:  PORTH->PUPDR &= ~(IN_TYPE_MASK<<(Cpy_u8PinNum*2));
			             	 PORTH->PUPDR |= Cpy_u8InType<<(Cpy_u8PinNum*2);
			             	 break;


				default   :  L_u8ErrorState = 0x02;
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


u8 MGPIO_u8WritePinVal (u8 Cpy_u8PortID, u8 Cpy_u8PinNum, Bool Cpy_BoolVal)
{
	/*This equation "PORTA->BSRR = 1 << (Cpy_u8PinNum+(16*(!Cpy_BoolVal)))" writes 1*/
	/*on a bit in the range 0-15 inclusive in BSRR if a nonzero value is given for Cpy_BoolVal,*/
	/*and writes 1 on a bit in the range 16-31 inclusive in BSRR if the value 0 is given for Cpy_BoolVal.*/
	/*And similarly for ports B to H*/

	/*Successful return        : L_u8ErrorState = 0x00*/
	/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
	/*Wrong pin number entered : L_u8ErrorState = 0x03*/
	/*Forbidden pin entered    : L_u8ErrorState = 0x04*/

	u8 L_u8ErrorState = 0x00;

	if(Cpy_u8PinNum <= PIN15)
	{
		switch(Cpy_u8PortID)
		{
			case PA:   if((Cpy_u8PinNum!=PIN13) && (Cpy_u8PinNum!=PIN14) && (Cpy_u8PinNum!=PIN15))
			              {
				          	  PORTA->BSRR = 1 << (Cpy_u8PinNum+(16*(!Cpy_BoolVal)));
			              }
			              else
			              {
			            	  L_u8ErrorState = 0x04;
			              }
			             break;


			case PB:  if((Cpy_u8PinNum!=PIN3) && (Cpy_u8PinNum!=PIN4))
			             {
				         	 PORTB->BSRR = 1 << (Cpy_u8PinNum+(16*(!Cpy_BoolVal)));
			             }
			             else
			             {
			            	 L_u8ErrorState = 0x04;
			             }
			             break;


			case PC:  PORTC->BSRR = 1 << (Cpy_u8PinNum+(16*(!Cpy_BoolVal)));
			             break;


			case PD:  PORTD->BSRR = 1 << (Cpy_u8PinNum+(16*(!Cpy_BoolVal)));
			             break;

			case PE:  PORTE->BSRR = 1 << (Cpy_u8PinNum+(16*(!Cpy_BoolVal)));
			             break;


			case PH:  PORTH->BSRR = 1 << (Cpy_u8PinNum+(16*(!Cpy_BoolVal)));
			             break;


			default   :  L_u8ErrorState = 0x02;
			break;
		}


	}

	else
	{
		L_u8ErrorState = 0x03;
	}


	return L_u8ErrorState;
}


u8 MGPIO_u8ReadPinVal(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, Bool *Cpy_BoolPtReadPtr)
{
	/*Successful return        : L_u8ErrorState = 0x00*/
	/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
	/*Wrong pin number entered : L_u8ErrorState = 0x03*/
	/*Forbidden pin entered    : L_u8ErrorState = 0x04*/

	u8 L_u8ErrorState = 0x00;

	if(Cpy_u8PinNum <= PIN15)
	{
		switch(Cpy_u8PortID)
		{
			case PA:  if((Cpy_u8PinNum!=PIN13) && (Cpy_u8PinNum!=PIN14) && (Cpy_u8PinNum!=PIN15))
			             {
				         	 *Cpy_BoolPtReadPtr = ((PORTA->IDR)&(1<<Cpy_u8PinNum)) >> Cpy_u8PinNum;
			             }
			             else
			             {
			            	 L_u8ErrorState = 0x04;
			             }
			             break;


			case PB:  if((Cpy_u8PinNum!=PIN3) && (Cpy_u8PinNum!=PIN4))
			             {
				         	 *Cpy_BoolPtReadPtr = ((PORTB->IDR)&(1<<Cpy_u8PinNum)) >> Cpy_u8PinNum;
			             }
			             else
			             {
			            	 L_u8ErrorState = 0x04;
			             }
			             break;


			case PC:  *Cpy_BoolPtReadPtr = ((PORTC->IDR)&(1<<Cpy_u8PinNum)) >> Cpy_u8PinNum;
			             break;


			case PD:  *Cpy_BoolPtReadPtr = ((PORTD->IDR)&(1<<Cpy_u8PinNum)) >> Cpy_u8PinNum;
			             break;


			case PE:  *Cpy_BoolPtReadPtr = ((PORTE->IDR)&(1<<Cpy_u8PinNum)) >> Cpy_u8PinNum;
			             break;


			case PH:  *Cpy_BoolPtReadPtr = ((PORTH->IDR)&(1<<Cpy_u8PinNum)) >> Cpy_u8PinNum;
			             break;


			default   :  L_u8ErrorState = 0x02;
			             break;
		}


	}

	else
	{
		L_u8ErrorState = 0x03;
	}


	return L_u8ErrorState;
}





u8 MGPIO_u8SetAF(u8 Cpy_u8PortID, u8 Cpy_u8PinNum, u8 Cpy_u8AFID)
{
	/*Successful return        : L_u8ErrorState = 0x00*/
	/*Wrong port ID entered    : L_u8ErrorState = 0x02*/
	/*Wrong pin number entered : L_u8ErrorState = 0x03*/
	/*Wrong alternate function ID entered : L_u8ErrorState = 0x04*/
	/*Forbidden pin entered    : L_u8ErrorState = 0x05*/

	u8 L_u8ErrorState = 0x00;

	if(Cpy_u8PinNum <= PIN15)
	{
		if(Cpy_u8AFID <= EVENTOUT)
		{
			switch(Cpy_u8PortID)
			{
			case PA:  if((Cpy_u8PinNum!=PIN13) && (Cpy_u8PinNum!=PIN14) && (Cpy_u8PinNum!=PIN15))
			{
				if (Cpy_u8PinNum <=7)
				{
					PORTA->AFRL &= ~(AF_MASK<<(Cpy_u8PinNum*4));
					PORTA->AFRL |= Cpy_u8AFID<<(Cpy_u8PinNum*4);
				}

				else
				{
					PORTA->AFRH &= ~(AF_MASK<<((Cpy_u8PinNum-8)*4));
					PORTA->AFRH |= Cpy_u8AFID<<((Cpy_u8PinNum-8)*4);
				}


			}
			else
			{
				L_u8ErrorState = 0x05;
			}
			break;


			case PB:  if((Cpy_u8PinNum!=PIN3) && (Cpy_u8PinNum!=PIN4))
			{
				if (Cpy_u8PinNum <=7)
				{
					PORTB->AFRL &= ~(AF_MASK<<(Cpy_u8PinNum*4));
					PORTB->AFRL |= Cpy_u8AFID<<(Cpy_u8PinNum*4);
				}

				else
				{
					PORTB->AFRH &= ~(AF_MASK<<((Cpy_u8PinNum-8)*4));
					PORTB->AFRH |= Cpy_u8AFID<<((Cpy_u8PinNum-8)*4);
				}
			}
			else
			{
				L_u8ErrorState = 0x05;
			}
			break;


			case PC:
				if (Cpy_u8PinNum <=7)
				{
					PORTC->AFRL &= ~(AF_MASK<<(Cpy_u8PinNum*4));
					PORTC->AFRL |= Cpy_u8AFID<<(Cpy_u8PinNum*4);
				}

				else
				{
					PORTC->AFRH &= ~(AF_MASK<<((Cpy_u8PinNum-8)*4));
					PORTC->AFRH |= Cpy_u8AFID<<((Cpy_u8PinNum-8)*4);
				}
			break;


			case PD:
				if (Cpy_u8PinNum <=7)
				{
					PORTD->AFRL &= ~(AF_MASK<<(Cpy_u8PinNum*4));
					PORTD->AFRL |= Cpy_u8AFID<<(Cpy_u8PinNum*4);
				}

				else
				{
					PORTD->AFRH &= ~(AF_MASK<<((Cpy_u8PinNum-8)*4));
					PORTD->AFRH |= Cpy_u8AFID<<((Cpy_u8PinNum-8)*4);
				}
			break;


			case PE:
				if (Cpy_u8PinNum <=7)
				{
					PORTE->AFRL &= ~(AF_MASK<<(Cpy_u8PinNum*4));
					PORTE->AFRL |= Cpy_u8AFID<<(Cpy_u8PinNum*4);
				}

				else
				{
					PORTE->AFRH &= ~(AF_MASK<<((Cpy_u8PinNum-8)*4));
					PORTE->AFRH |= Cpy_u8AFID<<((Cpy_u8PinNum-8)*4);
				}
			break;


			case PH:
				if (Cpy_u8PinNum <=7)
				{
					PORTH->AFRL &= ~(AF_MASK<<(Cpy_u8PinNum*4));
					PORTH->AFRL |= Cpy_u8AFID<<(Cpy_u8PinNum*4);
				}

				else
				{
					PORTH->AFRH &= ~(AF_MASK<<((Cpy_u8PinNum-8)*4));
					PORTH->AFRH |= Cpy_u8AFID<<((Cpy_u8PinNum-8)*4);
				}
			break;


			default   :  L_u8ErrorState = 0x02;
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


