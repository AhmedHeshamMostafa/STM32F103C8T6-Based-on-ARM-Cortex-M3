/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 25 Mar 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

/* Notice that case MINRANGE ... MAXRANGE: is a feature available only in gcc.
   If you are willing to use a different compiler, you should refer to its documentation.*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_int.h"
#include "ADC_prv.h"





Bool MADC_BoolInit(ADC_cfg *ADCcfgPtConfigPtr)
{
	Bool L_BoolErrorState = 1;

	if(((ADCcfgPtConfigPtr->ADCPerIDModuleID) != ADC1) && ((ADCcfgPtConfigPtr->ADCPerIDModuleID) != ADC2) && ((ADCcfgPtConfigPtr->ADCPerIDModuleID) != ADC3))
	{
		L_BoolErrorState = 0;
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->BoolConvMode))
	{
	case SINGLE_CONV ... MULTI_CONV:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->BoolScanMode))
	{
	case DISABLE ... ENABLE:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCDiscontReg))
	{
	case DISC_DISABLE ... DISC_8CH:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCDiscontInj))
	{
	case DISC_DISABLE ... DISC_8CH:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCDualMModeType))
	{
	case INDEP ... ALTTRIG_ONLY:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->BoolDataAlign))
	{
	case RIGHT ... LEFT:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCTrigIDRegGrTrig))
	{
	case NORMAL_AUTO ... EXTTRIG_8:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCTrigIDInjGrTrig))
	{
	case NORMAL_AUTO ... EXTTRIG_8:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCAWDAWatchDogType))
	{
	case NO_AWD ... SINGLEREGINJ_AWD:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCChIDAWDCh))
	{
	case ADC_CH0 ... NO_CH:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->u16AWDHighThresh))
	{
	case MIN_12BIT ... MAX_12BIT:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->u16AWDLowThresh))
	{
	case MIN_12BIT ... MAX_12BIT:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/
	/*                           Injected Channels Arrays                               */
	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCChIDArrInjectedGrp[0]))
	{
	case ADC_CH0 ... NO_CH:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCChIDArrInjectedGrp[1]))
	{
	case ADC_CH0 ... NO_CH:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCChIDArrInjectedGrp[2]))
	{
	case ADC_CH0 ... NO_CH:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCChIDArrInjectedGrp[3]))
	{
	case ADC_CH0 ... NO_CH:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/
	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT[0]))
	{
	case ONE_5CYCLES ... NA:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT[1]))
	{
	case ONE_5CYCLES ... NA:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT[2]))
	{
	case ONE_5CYCLES ... NA:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT[3]))
	{
	case ONE_5CYCLES ... NA:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/
	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->u16ArrInjectedGrpOffset[0]))
	{
	case MIN_12BIT ... NO_VAL:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->u16ArrInjectedGrpOffset[1]))
	{
	case MIN_12BIT ... NO_VAL:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->u16ArrInjectedGrpOffset[2]))
	{
	case MIN_12BIT ... NO_VAL:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/

	switch((ADCcfgPtConfigPtr->u16ArrInjectedGrpOffset[3]))
	{
	case MIN_12BIT ... NO_VAL:
	{
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		break;
	}
	}

	/************************************************************************************/
	/*                           Regular Channels Arrays                                */
	/************************************************************************************/

	for(u8 L_u8ArrCount = 0; L_u8ArrCount - 16 != 0; L_u8ArrCount++)
	{
		switch((ADCcfgPtConfigPtr->ADCChIDArrRegularGrp[L_u8ArrCount]))
		{
		case ADC_CH0 ... NO_CH:
		{
			break;
		}

		default:
		{
			L_BoolErrorState = 0;
			break;
		}
		}

		/************************************************************************************/

		switch((ADCcfgPtConfigPtr->ADCSamplTArrRegGrpSampleT[L_u8ArrCount]))
		{
		case ONE_5CYCLES ... NA:
		{
			break;
		}

		default:
		{
			L_BoolErrorState = 0;
			break;
		}
		}
	}


	switch (L_BoolErrorState)
	{
	case 1:
	{
		u8   L_u8IndexCount  = 0;
		volatile u32 *L_u32PtJOFRAddr = &(ADCcfgPtConfigPtr->ADCPerIDModuleID->JOFR1);
		u8  *L_u8PtArrayPtr  = ADCcfgPtConfigPtr->ADCChIDArrInjectedGrp;

		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, CONT, ADCcfgPtConfigPtr->BoolConvMode);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, SCAN, ADCcfgPtConfigPtr->BoolScanMode);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, DISCEN, ((ADCcfgPtConfigPtr->ADCDiscontReg)&(1<<3))>>3);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, JDISCEN, ((ADCcfgPtConfigPtr->ADCDiscontInj)&(1<<3))>>3);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, DISCNUM0, ((ADCcfgPtConfigPtr->ADCDiscontReg)&(1<<0))>>0);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, DISCNUM1, ((ADCcfgPtConfigPtr->ADCDiscontReg)&(1<<1))>>1);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, DISCNUM2, ((ADCcfgPtConfigPtr->ADCDiscontReg)&(1<<2))>>2);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, ALIGN, ADCcfgPtConfigPtr->BoolDataAlign);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, DUALMOD0, ((ADCcfgPtConfigPtr->ADCDualMModeType)&(1<<0))>>0);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, DUALMOD1, ((ADCcfgPtConfigPtr->ADCDualMModeType)&(1<<1))>>1);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, DUALMOD2, ((ADCcfgPtConfigPtr->ADCDualMModeType)&(1<<2))>>2);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, DUALMOD3, ((ADCcfgPtConfigPtr->ADCDualMModeType)&(1<<3))>>3);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, EXTTRIG, ((ADCcfgPtConfigPtr->ADCTrigIDRegGrTrig)&(1<<3))>>3);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, EXTSEL0, ((ADCcfgPtConfigPtr->ADCTrigIDRegGrTrig)&(1<<0))>>0);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, EXTSEL1, ((ADCcfgPtConfigPtr->ADCTrigIDRegGrTrig)&(1<<1))>>1);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, EXTSEL2, ((ADCcfgPtConfigPtr->ADCTrigIDRegGrTrig)&(1<<2))>>2);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, JEXTTRIG, ((ADCcfgPtConfigPtr->ADCTrigIDInjGrTrig)&(1<<3))>>3);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, JEXTSEL0, ((ADCcfgPtConfigPtr->ADCTrigIDInjGrTrig)&(1<<0))>>0);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, JEXTSEL1, ((ADCcfgPtConfigPtr->ADCTrigIDInjGrTrig)&(1<<1))>>1);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, JEXTSEL2, ((ADCcfgPtConfigPtr->ADCTrigIDInjGrTrig)&(1<<2))>>2);

		if((((ADCcfgPtConfigPtr->ADCTrigIDInjGrTrig)&(1<<3))>>3) == 0)
		{
			SET_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, JAUTO);
		}

		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, JAWDEN, ((ADCcfgPtConfigPtr->ADCAWDAWatchDogType)&(1<<0))>>0);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, AWDEN, ((ADCcfgPtConfigPtr->ADCAWDAWatchDogType)&(1<<1))>>1);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, AWDSGL, ((ADCcfgPtConfigPtr->ADCAWDAWatchDogType)&(1<<2))>>2);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, AWDCH0, ((ADCcfgPtConfigPtr->ADCChIDAWDCh)&(1<<0))>>0);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, AWDCH1, ((ADCcfgPtConfigPtr->ADCChIDAWDCh)&(1<<1))>>1);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, AWDCH2, ((ADCcfgPtConfigPtr->ADCChIDAWDCh)&(1<<2))>>2);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, AWDCH3, ((ADCcfgPtConfigPtr->ADCChIDAWDCh)&(1<<3))>>3);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR1, AWDCH4, ((ADCcfgPtConfigPtr->ADCChIDAWDCh)&(1<<4))>>4);

		ADCcfgPtConfigPtr->ADCPerIDModuleID->HTR = (u32)(ADCcfgPtConfigPtr->u16AWDHighThresh);
		ADCcfgPtConfigPtr->ADCPerIDModuleID->LTR = (u32)(ADCcfgPtConfigPtr->u16AWDLowThresh);



		/**************************************************************************************************************************/
		/*                                             Injected Channels Configurations                                           */
		/**************************************************************************************************************************/

		while(L_u8PtArrayPtr[L_u8IndexCount] - NO_CH != 0)
		{
			ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->JSQR, L_u8IndexCount*5+0, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<0))>>0);
			ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->JSQR, L_u8IndexCount*5+1, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<1))>>1);
			ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->JSQR, L_u8IndexCount*5+2, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<2))>>2);
			ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->JSQR, L_u8IndexCount*5+3, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<3))>>3);
			ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->JSQR, L_u8IndexCount*5+4, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<4))>>4);


			switch(L_u8PtArrayPtr[L_u8IndexCount])
			{
			case ADC_CH0 ... ADC_CH9:
			{
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR2, 3*L_u8PtArrayPtr[L_u8IndexCount]+0, (((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT)[L_u8IndexCount])&(1<<0))>>0);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR2, 3*L_u8PtArrayPtr[L_u8IndexCount]+1, (((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT)[L_u8IndexCount])&(1<<1))>>1);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR2, 3*L_u8PtArrayPtr[L_u8IndexCount]+2, (((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT)[L_u8IndexCount])&(1<<2))>>2);
				break;
			}

			case ADC_CH10 ... ADC_CH17:
			{
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR1, 3*(L_u8PtArrayPtr[L_u8IndexCount]-10)+0, (((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT)[L_u8IndexCount])&(1<<0))>>0);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR1, 3*(L_u8PtArrayPtr[L_u8IndexCount]-10)+1, (((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT)[L_u8IndexCount])&(1<<1))>>1);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR1, 3*(L_u8PtArrayPtr[L_u8IndexCount]-10)+2, (((ADCcfgPtConfigPtr->ADCSamplTArrInjGrpSampleT)[L_u8IndexCount])&(1<<2))>>2);
				break;
			}
			}


			*(L_u32PtJOFRAddr) = (ADCcfgPtConfigPtr->u16ArrInjectedGrpOffset)[L_u8IndexCount];

			L_u8IndexCount++;
			L_u32PtJOFRAddr++;
		}


		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->JSQR, JL0, ((L_u8IndexCount-1)&(1<<0))>>0);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->JSQR, JL1, ((L_u8IndexCount-1)&(1<<1))>>1);


		/**************************************************************************************************************************/
		/*                                              Regular Channels Configurations                                           */
		/**************************************************************************************************************************/

		L_u8IndexCount  = 0;
		L_u8PtArrayPtr  = ADCcfgPtConfigPtr->ADCChIDArrRegularGrp;

		while(L_u8PtArrayPtr[L_u8IndexCount] - NO_CH != 0)
		{
			switch(L_u8IndexCount)
			{
			case 0 ... 5:
			{
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR3, L_u8IndexCount*5+0, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<0))>>0);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR3, L_u8IndexCount*5+1, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<1))>>1);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR3, L_u8IndexCount*5+2, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<2))>>2);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR3, L_u8IndexCount*5+3, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<3))>>3);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR3, L_u8IndexCount*5+4, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<4))>>4);
				break;
			}

			case 6 ... 11:
			{
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR2, (L_u8IndexCount-6)*5+0, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<0))>>0);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR2, (L_u8IndexCount-6)*5+1, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<1))>>1);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR2, (L_u8IndexCount-6)*5+2, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<2))>>2);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR2, (L_u8IndexCount-6)*5+3, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<3))>>3);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR2, (L_u8IndexCount-6)*5+4, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<4))>>4);
				break;
			}

			case 12 ... 15:
			{
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, (L_u8IndexCount-12)*5+0, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<0))>>0);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, (L_u8IndexCount-12)*5+1, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<1))>>1);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, (L_u8IndexCount-12)*5+2, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<2))>>2);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, (L_u8IndexCount-12)*5+3, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<3))>>3);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, (L_u8IndexCount-12)*5+4, ((L_u8PtArrayPtr[L_u8IndexCount])&(1<<4))>>4);
				break;
			}
			}


			switch(L_u8PtArrayPtr[L_u8IndexCount])
			{
			case ADC_CH0 ... ADC_CH9:
			{
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR2, 3*L_u8PtArrayPtr[L_u8IndexCount]+0, (((ADCcfgPtConfigPtr->ADCSamplTArrRegGrpSampleT)[L_u8IndexCount])&(1<<0))>>0);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR2, 3*L_u8PtArrayPtr[L_u8IndexCount]+1, (((ADCcfgPtConfigPtr->ADCSamplTArrRegGrpSampleT)[L_u8IndexCount])&(1<<1))>>1);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR2, 3*L_u8PtArrayPtr[L_u8IndexCount]+2, (((ADCcfgPtConfigPtr->ADCSamplTArrRegGrpSampleT)[L_u8IndexCount])&(1<<2))>>2);
				break;
			}

			case ADC_CH10 ... ADC_CH17:
			{
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR1, 3*(L_u8PtArrayPtr[L_u8IndexCount]-10)+0, (((ADCcfgPtConfigPtr->ADCSamplTArrRegGrpSampleT)[L_u8IndexCount])&(1<<0))>>0);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR1, 3*(L_u8PtArrayPtr[L_u8IndexCount]-10)+1, (((ADCcfgPtConfigPtr->ADCSamplTArrRegGrpSampleT)[L_u8IndexCount])&(1<<1))>>1);
				ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SMPR1, 3*(L_u8PtArrayPtr[L_u8IndexCount]-10)+2, (((ADCcfgPtConfigPtr->ADCSamplTArrRegGrpSampleT)[L_u8IndexCount])&(1<<2))>>2);
				break;
			}
			}


			L_u8IndexCount++;
		}


		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, L0, ((L_u8IndexCount-1)&(1<<0))>>0);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, L1, ((L_u8IndexCount-1)&(1<<1))>>1);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, L2, ((L_u8IndexCount-1)&(1<<1))>>2);
		ASSIGN_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->SQR1, L3, ((L_u8IndexCount-1)&(1<<1))>>3);


		return L_BoolErrorState;
		break;
	}

	default:
	{
		return L_BoolErrorState;
		break;
	}
	}

}


/***********************************************************************************/


void MADC_vStartADC(ADC_cfg *ADCcfgPtConfigPtr)
{
	SET_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, ADON);
	/*Before starting calibration, the ADC must have been in Power On state for
      at least two ADC clock cycles*/
	for(u8 L_u8DelayCntr = 0; L_u8DelayCntr < 10; L_u8DelayCntr++);

	SET_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, RSTCAL);
	SET_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, CAL);

	while(((ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2)&(1<<CAL)) == 1);
}


/***********************************************************************************/


void MADC_vStopADC(ADC_cfg *ADCcfgPtConfigPtr)
{
	CLR_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, ADON);
}


/***********************************************************************************/


void MADC_vGetDigitalDataReg(ADC_cfg *ADCcfgPtConfigPtr, u16 u16ArrData[16])
{
	/*To be added later : The code for scan mode and DMA*/

	/*Wait for the End-of-Conversion flag to be raised*/
	while(((ADCcfgPtConfigPtr->ADCPerIDModuleID->SR)&(1<<EOC)) == 0);

	u16ArrData[0] = (u16)(ADCcfgPtConfigPtr->ADCPerIDModuleID->DR);
	u16ArrData[1] = (u16)((ADCcfgPtConfigPtr->ADCPerIDModuleID->DR)>>16);
}


/***********************************************************************************/


void MADC_vGetDigitalDataInj(ADC_cfg *ADCcfgPtConfigPtr, u16 u16ArrData[4])
{
	/*Wait for the End-of-Conversion flag to be raised*/
	while(((ADCcfgPtConfigPtr->ADCPerIDModuleID->SR)&(1<<JEOC)) == 0);

	u16ArrData[0] = (u16)(ADCcfgPtConfigPtr->ADCPerIDModuleID->JDR1);
	u16ArrData[1] = (u16)(ADCcfgPtConfigPtr->ADCPerIDModuleID->JDR2);
	u16ArrData[2] = (u16)(ADCcfgPtConfigPtr->ADCPerIDModuleID->JDR3);
	u16ArrData[3] = (u16)(ADCcfgPtConfigPtr->ADCPerIDModuleID->JDR4);
}


/***********************************************************************************/


void MADC_vSWTrigReg(ADC_cfg *ADCcfgPtConfigPtr)
{
	SET_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, SWSTART);
}


/***********************************************************************************/


void MADC_vSWTrigInj(ADC_cfg *ADCcfgPtConfigPtr)
{
	SET_BIT(ADCcfgPtConfigPtr->ADCPerIDModuleID->CR2, JSWSTART);
}


