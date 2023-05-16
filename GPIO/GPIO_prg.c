/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 7 May 2023                                             */
/*             VERSION  : V03                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GPIO_int.h"
#include "GPIO_cfg.h"


void MGPIO_vInit(void)
{
		#if PIN <= MAX_PIN
			#if PIN_MODE == INPUT
				CLR_BIT(PORT->CRL, 4*PIN+0);
				CLR_BIT(PORT->CRL, 4*PIN+1);

				#if PIN_CONFIG == INP_ANALOG
					CLR_BIT(PORT->CRL, 4*PIN+2);
					CLR_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == INP_FLOATING
					SET_BIT(PORT->CRL, 4*PIN+2);
					CLR_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == INP_PULL_DOWN
					CLR_BIT(PORT->CRL, 4*PIN+2);
					SET_BIT(PORT->CRL, 4*PIN+3);
					CLR_BIT(PORT->ODR, PIN)    ;

				#elif PIN_CONFIG == INP_PULL_UP
					CLR_BIT(PORT->CRL, 4*PIN+2);
					SET_BIT(PORT->CRL, 4*PIN+3);
					SET_BIT(PORT->ODR, PIN)    ;

				#else
					#error "Invalid Input Pin Configuration!"

				#endif

			/************************************************************/

			#elif PIN_MODE == OUTPUT_10M
				SET_BIT(PORT->CRL, 4*PIN+0);
				CLR_BIT(PORT->CRL, 4*PIN+1);

				#if PIN_CONFIG == OUT_PUSH_PULL
					CLR_BIT(PORT->CRL, 4*PIN+2);
					CLR_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_OPEN_DRAIN
					SET_BIT(PORT->CRL, 4*PIN+2);
					CLR_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_AF_PUSH_PULL
					CLR_BIT(PORT->CRL, 4*PIN+2);
					SET_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_AF_OPEN_DRAIN
					SET_BIT(PORT->CRL, 4*PIN+2);
					SET_BIT(PORT->CRL, 4*PIN+3);

				#else
					#error "Invalid Output Pin Configuration!"

				#endif

			/************************************************************/

			#elif PIN_MODE == OUTPUT_2M
				CLR_BIT(PORT->CRL, 4*PIN+0);
				SET_BIT(PORT->CRL, 4*PIN+1);

				#if PIN_CONFIG == OUT_PUSH_PULL
					CLR_BIT(PORT->CRL, 4*PIN+2);
					CLR_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_OPEN_DRAIN
					SET_BIT(PORT->CRL, 4*PIN+2);
					CLR_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_AF_PUSH_PULL
					CLR_BIT(PORT->CRL, 4*PIN+2);
					SET_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_AF_OPEN_DRAIN
					SET_BIT(PORT->CRL, 4*PIN+2);
					SET_BIT(PORT->CRL, 4*PIN+3);

				#else
					#error "Invalid Output Pin Configuration!"

				#endif

			/************************************************************/

			#elif PIN_MODE == OUTPUT_50M
				SET_BIT(PORT->CRL, 4*PIN+0);
				SET_BIT(PORT->CRL, 4*PIN+1);

				#if PIN_CONFIG == OUT_PUSH_PULL
					CLR_BIT(PORT->CRL, 4*PIN+2);
					CLR_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_OPEN_DRAIN
					SET_BIT(PORT->CRL, 4*PIN+2);
					CLR_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_AF_PUSH_PULL
					CLR_BIT(PORT->CRL, 4*PIN+2);
					SET_BIT(PORT->CRL, 4*PIN+3);

				#elif PIN_CONFIG == OUT_AF_OPEN_DRAIN
					SET_BIT(PORT->CRL, 4*PIN+2);
					SET_BIT(PORT->CRL, 4*PIN+3);

				#else
					#error "Invalid Output Pin Configuration!"

				#endif

			/************************************************************/

			#else
				#error "Invalid Pin Mode!"

				#endif




		/************************************************************/


		#elif((PIN > MAX_PIN) && (PIN <= MAX_PORT))
			#if PIN_MODE == INPUT
				CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+0);
				CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+1);

				#if PIN_CONFIG == INP_ANALOG
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == INP_FLOATING
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == INP_PULL_DOWN
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);
					CLR_BIT(PORT->ODR, PIN)    ;

				#elif PIN_CONFIG == INP_PULL_UP
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);
					SET_BIT(PORT->ODR, PIN)    ;

				#else
					#error "Invalid Input Pin Configuration!"

				#endif

			/************************************************************/

			#elif PIN_MODE == OUTPUT_10M
				SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+0);
				CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+1);

				#if PIN_CONFIG == OUT_PUSH_PULL
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_OPEN_DRAIN
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_AF_PUSH_PULL
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_AF_OPEN_DRAIN
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#else
					#error "Invalid Output Pin Configuration!"

				#endif

			/************************************************************/

			#elif PIN_MODE == OUTPUT_2M
				CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+0);
				SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+1);

				#if PIN_CONFIG == OUT_PUSH_PULL
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_OPEN_DRAIN
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_AF_PUSH_PULL
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_AF_OPEN_DRAIN
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#else
					#error "Invalid Output Pin Configuration!"

				#endif

			/************************************************************/

			#elif PIN_MODE == OUTPUT_50M
				SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+0);
				SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+1);

				#if PIN_CONFIG == OUT_PUSH_PULL
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_OPEN_DRAIN
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_AF_PUSH_PULL
					CLR_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#elif PIN_CONFIG == OUT_AF_OPEN_DRAIN
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+2);
					SET_BIT(PORT->CRH, 4*(PIN-MAX_PIN-1)+3);

				#else
					#error "Invalid Output Pin Configuration!"

				#endif

			/************************************************************/

			#else
				#error "Invalid Pin Mode!"

			#endif




		/************************************************************/


		#else
			#error "Invalid Pin Number!"

		#endif

}

/*******************************************************************/

Bool MGPIO_BoolSetPinDir(portID_t A_portIDPort, pinID_t A_pinIDPin, modeCfgID_t A_modeCfgIDPinMode)
{
	Bool L_BoolErrorState = 1;

	if(A_portIDPort <= PG)
	{
		if(A_pinIDPin <= MAX_PORT)
		{
			if(A_modeCfgIDPinMode <= MAX_CFG_NUM_DIR)
			{
				switch(A_modeCfgIDPinMode)
				{
					case INPUT :
						if(A_pinIDPin <= MAX_PIN)
						{
							switch (A_portIDPort)
							{
								case PA :
									CLR_BIT(PORTA->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTA->CRL, 4*A_pinIDPin+1);
									break;

								case PB :
									CLR_BIT(PORTB->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTB->CRL, 4*A_pinIDPin+1);
									break;

								case PC :
									CLR_BIT(PORTC->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTC->CRL, 4*A_pinIDPin+1);
									break;

								case PD :
									CLR_BIT(PORTD->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTD->CRL, 4*A_pinIDPin+1);
									break;

								case PE :
									CLR_BIT(PORTE->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTE->CRL, 4*A_pinIDPin+1);
									break;

								case PF :
									CLR_BIT(PORTF->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTF->CRL, 4*A_pinIDPin+1);
									break;

								case PG :
									CLR_BIT(PORTG->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTG->CRL, 4*A_pinIDPin+1);
									break;
							}
						}




						else
						{
							switch (A_portIDPort)
							{
								case PA :
									CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
									CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
									break;

								case PB :
									CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
									CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
									break;

								case PC :
									CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
									CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
									break;

								case PD :
									CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
									CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
									break;

								case PE :
									CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
									CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
									break;

								case PF :
									CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
									CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
									break;

								case PG :
									CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
									CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
									break;
							}

						}

						break;

					/************************************************************/

					case OUTPUT_10M :
						if(A_pinIDPin <= MAX_PIN)
						{
							switch (A_portIDPort)
							{
								case PA :
									SET_BIT(PORTA->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTA->CRL, 4*A_pinIDPin+1);
									break;

								case PB :
									SET_BIT(PORTB->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTB->CRL, 4*A_pinIDPin+1);
									break;

								case PC :
									SET_BIT(PORTC->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTC->CRL, 4*A_pinIDPin+1);
									break;

								case PD :
									SET_BIT(PORTD->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTD->CRL, 4*A_pinIDPin+1);
									break;

								case PE :
									SET_BIT(PORTE->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTE->CRL, 4*A_pinIDPin+1);
									break;

								case PF :
									SET_BIT(PORTF->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTF->CRL, 4*A_pinIDPin+1);
									break;
								case PG :
									SET_BIT(PORTG->CRL, 4*A_pinIDPin+0);
									CLR_BIT(PORTG->CRL, 4*A_pinIDPin+1);
									break;
							}
						}

						else
						{
							switch (A_portIDPort)
								{
									case PA :
										SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PB :
										SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PC :
										SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PD :
										SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PE :
										SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PF :
										SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;
									case PG :
										SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;
								}
						}

						break;

					/************************************************************/

					case OUTPUT_2M :
						if(A_pinIDPin <= MAX_PIN)
						{
							switch (A_portIDPort)
							{
								case PA :
									CLR_BIT(PORTA->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTA->CRL, 4*A_pinIDPin+1);
									break;

								case PB :
									CLR_BIT(PORTB->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTB->CRL, 4*A_pinIDPin+1);
									break;

								case PC :
									CLR_BIT(PORTC->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTC->CRL, 4*A_pinIDPin+1);
									break;

								case PD :
									CLR_BIT(PORTD->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTD->CRL, 4*A_pinIDPin+1);
									break;

								case PE :
									CLR_BIT(PORTE->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTE->CRL, 4*A_pinIDPin+1);
									break;

								case PF :
									CLR_BIT(PORTF->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTF->CRL, 4*A_pinIDPin+1);
									break;

								case PG :
									CLR_BIT(PORTG->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTG->CRL, 4*A_pinIDPin+1);
									break;
							}
						}

						else
						{
							switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PB :
										CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PC :
										CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PD :
										CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PE :
										CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PF :
										CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;
									case PG :
										CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;
								}
						}


						break;

					/************************************************************/

					case OUTPUT_50M :
						if(A_pinIDPin <= MAX_PIN)
						{
							switch (A_portIDPort)
							{
								case PA :
									SET_BIT(PORTA->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTA->CRL, 4*A_pinIDPin+1);
									break;

								case PB :
									SET_BIT(PORTB->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTB->CRL, 4*A_pinIDPin+1);
									break;

								case PC :
									SET_BIT(PORTC->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTC->CRL, 4*A_pinIDPin+1);
									break;

								case PD :
									SET_BIT(PORTD->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTD->CRL, 4*A_pinIDPin+1);
									break;

								case PE :
									SET_BIT(PORTE->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTE->CRL, 4*A_pinIDPin+1);
									break;

								case PF :
									SET_BIT(PORTF->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTF->CRL, 4*A_pinIDPin+1);
									break;
								case PG :
									SET_BIT(PORTG->CRL, 4*A_pinIDPin+0);
									SET_BIT(PORTG->CRL, 4*A_pinIDPin+1);
									break;
							}
						}

						else
						{
							switch (A_portIDPort)
								{
									case PA :
										SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PB :
										SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PC :
										SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PD :
										SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PE :
										SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;

									case PF :
										SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;
									case PG :
										SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+0);
										SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+1);
										break;
								}
						}


						break;
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

/*******************************************************************/

Bool MGPIO_BoolSetInpCfg(portID_t A_portIDPort, pinID_t A_pinIDPin, modeCfgID_t A_modeCfgIDPinConfig)
{
	Bool L_BoolErrorState = 1;

	if(A_portIDPort <= PG)
		{
			if(A_pinIDPin <= MAX_PORT)
			{
				if((A_modeCfgIDPinConfig >= MIN_CFG_NUM_INP) && (A_modeCfgIDPinConfig <= MAX_CFG_NUM_INP))
				{
					switch(A_modeCfgIDPinConfig)
					{
						case INP_ANALOG :
							if(A_pinIDPin <= MAX_PIN)
							{
								switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTA->CRL, 4*A_pinIDPin+3);
										break;

									case PB :
										CLR_BIT(PORTB->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTB->CRL, 4*A_pinIDPin+3);
										break;

									case PC :
										CLR_BIT(PORTC->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTC->CRL, 4*A_pinIDPin+3);
										break;

									case PD :
										CLR_BIT(PORTD->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTD->CRL, 4*A_pinIDPin+3);
										break;

									case PE :
										CLR_BIT(PORTE->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTE->CRL, 4*A_pinIDPin+3);
										break;

									case PF :
										CLR_BIT(PORTF->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTF->CRL, 4*A_pinIDPin+3);
										break;

									case PG :
										CLR_BIT(PORTG->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTG->CRL, 4*A_pinIDPin+3);
										break;
								}
							}




							else
							{
								switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PB :
										CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PC :
										CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PD :
										CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PE :
										CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PF :
										CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PG :
										CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;
								}

							}

							break;

						/************************************************************/

						case INP_FLOATING :
							if(A_pinIDPin <= MAX_PIN)
							{
								switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTA->CRL, 4*A_pinIDPin+3);
										break;

									case PB :
										CLR_BIT(PORTB->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTB->CRL, 4*A_pinIDPin+3);
										break;

									case PC :
										CLR_BIT(PORTC->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTC->CRL, 4*A_pinIDPin+3);
										break;

									case PD :
										CLR_BIT(PORTD->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTD->CRL, 4*A_pinIDPin+3);
										break;

									case PE :
										CLR_BIT(PORTE->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTE->CRL, 4*A_pinIDPin+3);
										break;

									case PF :
										CLR_BIT(PORTF->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTF->CRL, 4*A_pinIDPin+3);
										break;

									case PG :
										CLR_BIT(PORTG->CRL, 4*A_pinIDPin+2);
										CLR_BIT(PORTG->CRL, 4*A_pinIDPin+3);
										break;
								}
							}




							else
							{
								switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PB :
										CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PC :
										CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PD :
										CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PE :
										CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PF :
										CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;

									case PG :
										CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										break;
								}

							}

							break;

						/************************************************************/

						case INP_PULL_DOWN :
							if(A_pinIDPin <= MAX_PIN)
							{
								switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTA->CRL, 4*A_pinIDPin+3);
										CLR_BIT(PORTA->ODR, A_pinIDPin);
										break;

									case PB :
										CLR_BIT(PORTB->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTB->CRL, 4*A_pinIDPin+3);
										CLR_BIT(PORTB->ODR, A_pinIDPin);
										break;

									case PC :
										CLR_BIT(PORTC->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTC->CRL, 4*A_pinIDPin+3);
										CLR_BIT(PORTC->ODR, A_pinIDPin);
										break;

									case PD :
										CLR_BIT(PORTD->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTD->CRL, 4*A_pinIDPin+3);
										CLR_BIT(PORTD->ODR, A_pinIDPin);
										break;

									case PE :
										CLR_BIT(PORTE->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTE->CRL, 4*A_pinIDPin+3);
										CLR_BIT(PORTE->ODR, A_pinIDPin);
										break;

									case PF :
										CLR_BIT(PORTF->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTF->CRL, 4*A_pinIDPin+3);
										CLR_BIT(PORTF->ODR, A_pinIDPin);
										break;

									case PG :
										CLR_BIT(PORTG->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTG->CRL, 4*A_pinIDPin+3);
										CLR_BIT(PORTG->ODR, A_pinIDPin);
										break;
								}
							}




							else
							{
								switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										CLR_BIT(PORTA->ODR, A_pinIDPin);
										break;

									case PB :
										CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										CLR_BIT(PORTB->ODR, A_pinIDPin);
										break;

									case PC :
										CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										CLR_BIT(PORTC->ODR, A_pinIDPin);
										break;

									case PD :
										CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										CLR_BIT(PORTD->ODR, A_pinIDPin);
										break;

									case PE :
										CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										CLR_BIT(PORTE->ODR, A_pinIDPin);
										break;

									case PF :
										CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										CLR_BIT(PORTF->ODR, A_pinIDPin);
										break;

									case PG :
										CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										CLR_BIT(PORTG->ODR, A_pinIDPin);
										break;
								}

							}

							break;

						/************************************************************/

						case INP_PULL_UP :
							if(A_pinIDPin <= MAX_PIN)
							{
								switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTA->CRL, 4*A_pinIDPin+3);
										SET_BIT(PORTA->ODR, A_pinIDPin);
										break;

									case PB :
										CLR_BIT(PORTB->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTB->CRL, 4*A_pinIDPin+3);
										SET_BIT(PORTB->ODR, A_pinIDPin);
										break;

									case PC :
										CLR_BIT(PORTC->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTC->CRL, 4*A_pinIDPin+3);
										SET_BIT(PORTC->ODR, A_pinIDPin);
										break;

									case PD :
										CLR_BIT(PORTD->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTD->CRL, 4*A_pinIDPin+3);
										SET_BIT(PORTD->ODR, A_pinIDPin);
										break;

									case PE :
										CLR_BIT(PORTE->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTE->CRL, 4*A_pinIDPin+3);
										SET_BIT(PORTE->ODR, A_pinIDPin);
										break;

									case PF :
										CLR_BIT(PORTF->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTF->CRL, 4*A_pinIDPin+3);
										SET_BIT(PORTF->ODR, A_pinIDPin);
										break;

									case PG :
										CLR_BIT(PORTG->CRL, 4*A_pinIDPin+2);
										SET_BIT(PORTG->CRL, 4*A_pinIDPin+3);
										SET_BIT(PORTG->ODR, A_pinIDPin);
										break;
								}
							}




							else
							{
								switch (A_portIDPort)
								{
									case PA :
										CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										SET_BIT(PORTA->ODR, A_pinIDPin);
										break;

									case PB :
										CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										SET_BIT(PORTB->ODR, A_pinIDPin);
										break;

									case PC :
										CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										SET_BIT(PORTC->ODR, A_pinIDPin);
										break;

									case PD :
										CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										SET_BIT(PORTD->ODR, A_pinIDPin);
										break;

									case PE :
										CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										SET_BIT(PORTE->ODR, A_pinIDPin);
										break;

									case PF :
										CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										SET_BIT(PORTF->ODR, A_pinIDPin);
										break;

									case PG :
										CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
										SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
										SET_BIT(PORTG->ODR, A_pinIDPin);
										break;
								}

							}

							break;
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

/*******************************************************************/

Bool MGPIO_BoolSetOutCfg(portID_t A_portIDPort, pinID_t A_pinIDPin, modeCfgID_t A_modeCfgIDPinConfig)
{
	Bool L_BoolErrorState = 1;

	if(A_portIDPort <= PG)
			{
				if(A_pinIDPin <= MAX_PORT)
				{
					if((A_modeCfgIDPinConfig >= MIN_CFG_NUM_OUT) && (A_modeCfgIDPinConfig <= MAX_CFG_NUM_OUT))
					{
						switch(A_modeCfgIDPinConfig)
						{
							case OUT_PUSH_PULL :
								if(A_pinIDPin <= MAX_PIN)
								{
									switch (A_portIDPort)
									{
										case PA :
											CLR_BIT(PORTA->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTA->CRL, 4*A_pinIDPin+3);
											break;

										case PB :
											CLR_BIT(PORTB->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTB->CRL, 4*A_pinIDPin+3);
											break;

										case PC :
											CLR_BIT(PORTC->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTC->CRL, 4*A_pinIDPin+3);
											break;

										case PD :
											CLR_BIT(PORTD->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTD->CRL, 4*A_pinIDPin+3);
											break;

										case PE :
											CLR_BIT(PORTE->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTE->CRL, 4*A_pinIDPin+3);
											break;

										case PF :
											CLR_BIT(PORTF->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTF->CRL, 4*A_pinIDPin+3);
											break;

										case PG :
											CLR_BIT(PORTG->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTG->CRL, 4*A_pinIDPin+3);
											break;
									}
								}




								else
								{
									switch (A_portIDPort)
									{
										case PA :
											CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PB :
											CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PC :
											CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PD :
											CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PE :
											CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PF :
											CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PG :
											CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;
									}

								}

								break;

							/************************************************************/

							case OUT_OPEN_DRAIN :
								if(A_pinIDPin <= MAX_PIN)
								{
									switch (A_portIDPort)
									{
										case PA :
											SET_BIT(PORTA->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTA->CRL, 4*A_pinIDPin+3);
											break;

										case PB :
											SET_BIT(PORTB->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTB->CRL, 4*A_pinIDPin+3);
											break;

										case PC :
											SET_BIT(PORTC->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTC->CRL, 4*A_pinIDPin+3);
											break;

										case PD :
											SET_BIT(PORTD->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTD->CRL, 4*A_pinIDPin+3);
											break;

										case PE :
											SET_BIT(PORTE->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTE->CRL, 4*A_pinIDPin+3);
											break;

										case PF :
											SET_BIT(PORTF->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTF->CRL, 4*A_pinIDPin+3);
											break;

										case PG :
											SET_BIT(PORTG->CRL, 4*A_pinIDPin+2);
											CLR_BIT(PORTG->CRL, 4*A_pinIDPin+3);
											break;
									}
								}




								else
								{
									switch (A_portIDPort)
									{
										case PA :
											SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PB :
											SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PC :
											SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PD :
											SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PE :
											SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PF :
											SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PG :
											SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;
									}

								}

								break;

							/************************************************************/

							case OUT_AF_PUSH_PULL :
								if(A_pinIDPin <= MAX_PIN)
								{
									switch (A_portIDPort)
									{
										case PA :
											CLR_BIT(PORTA->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTA->CRL, 4*A_pinIDPin+3);
											break;

										case PB :
											CLR_BIT(PORTB->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTB->CRL, 4*A_pinIDPin+3);
											break;

										case PC :
											CLR_BIT(PORTC->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTC->CRL, 4*A_pinIDPin+3);
											break;

										case PD :
											CLR_BIT(PORTD->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTD->CRL, 4*A_pinIDPin+3);
											break;

										case PE :
											CLR_BIT(PORTE->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTE->CRL, 4*A_pinIDPin+3);
											break;

										case PF :
											CLR_BIT(PORTF->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTF->CRL, 4*A_pinIDPin+3);
											break;

										case PG :
											CLR_BIT(PORTG->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTG->CRL, 4*A_pinIDPin+3);
											break;
									}
								}




								else
								{
									switch (A_portIDPort)
									{
										case PA :
											CLR_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PB :
											CLR_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PC :
											CLR_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PD :
											CLR_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PE :
											CLR_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PF :
											CLR_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PG :
											CLR_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;
									}

								}

								break;

							/************************************************************/

							case OUT_AF_OPEN_DRAIN :
								if(A_pinIDPin <= MAX_PIN)
								{
									switch (A_portIDPort)
									{
										case PA :
											SET_BIT(PORTA->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTA->CRL, 4*A_pinIDPin+3);
											break;

										case PB :
											SET_BIT(PORTB->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTB->CRL, 4*A_pinIDPin+3);
											break;

										case PC :
											SET_BIT(PORTC->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTC->CRL, 4*A_pinIDPin+3);
											break;

										case PD :
											SET_BIT(PORTD->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTD->CRL, 4*A_pinIDPin+3);
											break;

										case PE :
											SET_BIT(PORTE->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTE->CRL, 4*A_pinIDPin+3);
											break;

										case PF :
											SET_BIT(PORTF->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTF->CRL, 4*A_pinIDPin+3);
											break;

										case PG :
											SET_BIT(PORTG->CRL, 4*A_pinIDPin+2);
											SET_BIT(PORTG->CRL, 4*A_pinIDPin+3);
											break;
									}
								}




								else
								{
									switch (A_portIDPort)
									{
										case PA :
											SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTA->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PB :
											SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTB->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PC :
											SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTC->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PD :
											SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTD->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PE :
											SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTE->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PF :
											SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTF->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;

										case PG :
											SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+2);
											SET_BIT(PORTG->CRH, 4*(A_pinIDPin-MAX_PIN-1)+3);
											break;
									}

								}

								break;
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

/*******************************************************************/

Bool MGPIO_BoolReadPin(portID_t A_portIDPort, pinID_t A_pinIDPin, Bool* A_BoolPtrData)
{
	Bool L_BoolErrorState = 1;

	if(A_portIDPort <= PG)
	{
		if(A_pinIDPin <= MAX_PORT)
		{
			switch (A_portIDPort)
			{
				case PA :
					GET_BIT(PORTA->IDR, A_pinIDPin, *A_BoolPtrData);
					break;

				case PB :
					GET_BIT(PORTB->IDR, A_pinIDPin, *A_BoolPtrData);
					break;

				case PC :
					GET_BIT(PORTC->IDR, A_pinIDPin, *A_BoolPtrData);
					break;

				case PD :
					GET_BIT(PORTD->IDR, A_pinIDPin, *A_BoolPtrData);
					break;

				case PE :
					GET_BIT(PORTE->IDR, A_pinIDPin, *A_BoolPtrData);
					break;

				case PF :
					GET_BIT(PORTF->IDR, A_pinIDPin, *A_BoolPtrData);
					break;

				case PG :
					GET_BIT(PORTG->IDR, A_pinIDPin, *A_BoolPtrData);
					break;

			}
			//*A_BoolPtrData = ((A_Port->IDR) & ((u32)(1 << A_pinIDPin))) >> A_pinIDPin;

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

/*******************************************************************/

Bool MGPIO_BoolWritePin(portID_t A_portIDPort, pinID_t A_pinIDPin, Bool A_BoolVal)
{
	Bool L_BoolErrorState = 1;

	if(A_portIDPort <= PG)
	{
		if(A_pinIDPin <= MAX_PORT)
		{
			switch (A_portIDPort)
			{
				case PA :
					if(A_BoolVal)
					{
						PORTA->BSRR = 1 << A_pinIDPin;
					}
					else
					{
						PORTA->BRR = 1 << A_pinIDPin;
					}

					break;

				case PB :
					if(A_BoolVal)
					{
						PORTB->BSRR = 1 << A_pinIDPin; //SET_BIT(PORTB->BSRR, A_pinIDPin);
					}
					else
					{
						PORTB->BRR = 1 << A_pinIDPin;  //SET_BIT(PORTB->BRR, A_pinIDPin);
					}

					break;

				case PC :
					if(A_BoolVal)
					{
						PORTC->BSRR = 1 << A_pinIDPin;
					}
					else
					{
						PORTC->BRR = 1 << A_pinIDPin;
					}

					break;

				case PD :
					if(A_BoolVal)
					{
						PORTD->BSRR = 1 << A_pinIDPin;
					}
					else
					{
						PORTD->BRR = 1 << A_pinIDPin;
					}

					break;

				case PE :
					if(A_BoolVal)
					{
						PORTE->BSRR = 1 << A_pinIDPin;
					}
					else
					{
						PORTE->BRR = 1 << A_pinIDPin;
					}

					break;

				case PF :
					if(A_BoolVal)
					{
						PORTF->BSRR = 1 << A_pinIDPin;
					}
					else
					{
						PORTF->BRR = 1 << A_pinIDPin;
					}

					break;

				case PG :
					if(A_BoolVal)
					{
						PORTG->BSRR = 1 << A_pinIDPin;
					}
					else
					{
						PORTG->BRR = 1 << A_pinIDPin;
					}

					break;

			}
			//A_BoolVal ? (A_Port->BSRR = (u16)(1 << A_pinIDPin)) : (A_Port->BRR = (u16)(1 << A_pinIDPin));

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

/*******************************************************************/

Bool MGPIO_BoolLockPin(portID_t A_portIDPort, pinID_t A_pinIDPin)
{
	Bool L_BoolErrorState = 1;

	if(A_portIDPort <= PG)
	{
		if(A_pinIDPin <= MAX_PORT)
		{
			Bool L_BoolLockState;

			switch (A_portIDPort)
			{
				case PA :
					SET_BIT(PORTA->LCKR, A_pinIDPin);
					SET_BIT(PORTA->LCKR, LCKK);
					CLR_BIT(PORTA->LCKR, LCKK);
					SET_BIT(PORTA->LCKR, LCKK);
					GET_BIT(PORTA->LCKR, LCKK, L_BoolLockState);
					if(!L_BoolLockState)
					{
						GET_BIT(PORTA->LCKR, LCKK, L_BoolLockState);
						if(!L_BoolLockState)
						{
							L_BoolErrorState = 0;
						}
					}
					else
					{
						L_BoolErrorState = 0;
					}

					break;

				case PB :
					SET_BIT(PORTB->LCKR, A_pinIDPin);
					SET_BIT(PORTB->LCKR, LCKK);
					CLR_BIT(PORTB->LCKR, LCKK);
					SET_BIT(PORTB->LCKR, LCKK);
					GET_BIT(PORTB->LCKR, LCKK, L_BoolLockState);
					if(!L_BoolLockState)
					{
						GET_BIT(PORTB->LCKR, LCKK, L_BoolLockState);
						if(!L_BoolLockState)
						{
							L_BoolErrorState = 0;
						}
					}
					else
					{
						L_BoolErrorState = 0;
					}

					break;

				case PC :
					SET_BIT(PORTC->LCKR, A_pinIDPin);
					SET_BIT(PORTC->LCKR, LCKK);
					CLR_BIT(PORTC->LCKR, LCKK);
					SET_BIT(PORTC->LCKR, LCKK);
					GET_BIT(PORTC->LCKR, LCKK, L_BoolLockState);
					if(!L_BoolLockState)
					{
						GET_BIT(PORTC->LCKR, LCKK, L_BoolLockState);
						if(!L_BoolLockState)
						{
							L_BoolErrorState = 0;
						}
					}
					else
					{
						L_BoolErrorState = 0;
					}

					break;

				case PD :
					SET_BIT(PORTD->LCKR, A_pinIDPin);
					SET_BIT(PORTD->LCKR, LCKK);
					CLR_BIT(PORTD->LCKR, LCKK);
					SET_BIT(PORTD->LCKR, LCKK);
					GET_BIT(PORTD->LCKR, LCKK, L_BoolLockState);
					if(!L_BoolLockState)
					{
						GET_BIT(PORTD->LCKR, LCKK, L_BoolLockState);
						if(!L_BoolLockState)
						{
							L_BoolErrorState = 0;
						}
					}
					else
					{
						L_BoolErrorState = 0;
					}

					break;

				case PE :
					SET_BIT(PORTE->LCKR, A_pinIDPin);
					SET_BIT(PORTE->LCKR, LCKK);
					CLR_BIT(PORTE->LCKR, LCKK);
					SET_BIT(PORTE->LCKR, LCKK);
					GET_BIT(PORTE->LCKR, LCKK, L_BoolLockState);
					if(!L_BoolLockState)
					{
						GET_BIT(PORTE->LCKR, LCKK, L_BoolLockState);
						if(!L_BoolLockState)
						{
							L_BoolErrorState = 0;
						}
					}
					else
					{
						L_BoolErrorState = 0;
					}

					break;

				case PF :
					SET_BIT(PORTF->LCKR, A_pinIDPin);
					SET_BIT(PORTF->LCKR, LCKK);
					CLR_BIT(PORTF->LCKR, LCKK);
					SET_BIT(PORTF->LCKR, LCKK);
					GET_BIT(PORTF->LCKR, LCKK, L_BoolLockState);
					if(!L_BoolLockState)
					{
						GET_BIT(PORTF->LCKR, LCKK, L_BoolLockState);
						if(!L_BoolLockState)
						{
							L_BoolErrorState = 0;
						}
					}
					else
					{
						L_BoolErrorState = 0;
					}

					break;

				case PG :
					SET_BIT(PORTG->LCKR, A_pinIDPin);
					SET_BIT(PORTG->LCKR, LCKK);
					CLR_BIT(PORTG->LCKR, LCKK);
					SET_BIT(PORTG->LCKR, LCKK);
					GET_BIT(PORTG->LCKR, LCKK, L_BoolLockState);
					if(!L_BoolLockState)
					{
						GET_BIT(PORTG->LCKR, LCKK, L_BoolLockState);
						if(!L_BoolLockState)
						{
							L_BoolErrorState = 0;
						}
					}
					else
					{
						L_BoolErrorState = 0;
					}

					break;
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
