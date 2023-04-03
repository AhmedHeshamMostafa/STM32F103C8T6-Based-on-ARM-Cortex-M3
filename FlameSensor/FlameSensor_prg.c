/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 1 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/RCC/RCC_int.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "FlameSensor_int.h"





static ADC_cfg ADC1_config = {.BoolConvMode = MULTI_CONV,
				              .BoolScanMode = DISABLE,
							  .BoolDataAlign = RIGHT,
							  .ADCPerIDModuleID = ADC_ONE,
							  .ADCDualMModeType = INDEP,
							  .ADCDiscontReg = DISC_DISABLE,
							  .ADCDiscontInj = DISC_DISABLE,
							  .ADCTrigIDRegGrTrig = NORMAL_AUTO,
							  .ADCTrigIDInjGrTrig = EXTTRIG_8,
							  .ADCAWDAWatchDogType = SINGLEREG_AWD,
							  .ADCChIDAWDCh = SENSOR_CH,
							  .u16AWDHighThresh = 0xFFF,
							  .u16AWDLowThresh = 0x000,
							  .ADCChIDArrInjectedGrp[0] = NO_CH,
							  .ADCChIDArrInjectedGrp[1] = NO_CH,
							  .ADCChIDArrInjectedGrp[2] = NO_CH,
							  .ADCChIDArrInjectedGrp[3] = NO_CH,
							  .ADCSamplTArrInjGrpSampleT[0] = NA,
							  .ADCSamplTArrInjGrpSampleT[1] = NA,
							  .ADCSamplTArrInjGrpSampleT[2] = NA,
							  .ADCSamplTArrInjGrpSampleT[3] = NA,
							  .u16ArrInjectedGrpOffset[0] = NO_VAL,
							  .u16ArrInjectedGrpOffset[1] = NO_VAL,
							  .u16ArrInjectedGrpOffset[2] = NO_VAL,
							  .u16ArrInjectedGrpOffset[3] = NO_VAL,
							  .ADCChIDArrRegularGrp[0] = SENSOR_CH,
							  .ADCSamplTArrRegGrpSampleT[0] = SEVEN_5CYCLES

							 };


Bool HFlameSensor_BoolInit(void)
{
	Bool L_BoolErrorState = 1;

	switch(SENSOR_CH)
	{
	case ADC_CH0 ... ADC_CH9:
	{

		for(u8 L_u8RegGrpCntr = 1; L_u8RegGrpCntr < 16; L_u8RegGrpCntr++)
		{
			(ADC1_config.ADCChIDArrRegularGrp)[L_u8RegGrpCntr] = NO_CH;
			(ADC1_config.ADCSamplTArrRegGrpSampleT)[L_u8RegGrpCntr] = NA;
		}


		MRCC_vInit();


		switch(SENSOR_CH)
		{
		case ADC_CH0:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P0, INPUT);
			MGPIO_BoolSetInpCfg(PA, P0, INP_ANALOG);
			break;
		}

		case ADC_CH1:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P1, INPUT);
			MGPIO_BoolSetInpCfg(PA, P1, INP_ANALOG);
			break;
		}

		case ADC_CH2:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P2, INPUT);
			MGPIO_BoolSetInpCfg(PA, P2, INP_ANALOG);
			break;
		}

		case ADC_CH3:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P3, INPUT);
			MGPIO_BoolSetInpCfg(PA, P3, INP_ANALOG);
			break;
		}

		case ADC_CH4:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P4, INPUT);
			MGPIO_BoolSetInpCfg(PA, P4, INP_ANALOG);
			break;
		}

		case ADC_CH5:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P5, INPUT);
			MGPIO_BoolSetInpCfg(PA, P5, INP_ANALOG);
			break;
		}

		case ADC_CH6:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P6, INPUT);
			MGPIO_BoolSetInpCfg(PA, P6, INP_ANALOG);
			break;
		}

		case ADC_CH7:
		{
			MRCC_BoolEnableClock(APB2, IOPA);
			MGPIO_BoolSetPinDir(PA, P7, INPUT);
			MGPIO_BoolSetInpCfg(PA, P7, INP_ANALOG);
			break;
		}

		case ADC_CH8:
		{
			MRCC_BoolEnableClock(APB2, IOPB);
			MGPIO_BoolSetPinDir(PB, P0, INPUT);
			MGPIO_BoolSetInpCfg(PB, P0, INP_ANALOG);
			break;
		}

		case ADC_CH9:
		{
			MRCC_BoolEnableClock(APB2, IOPB);
			MGPIO_BoolSetPinDir(PB, P1, INPUT);
			MGPIO_BoolSetInpCfg(PB, P1, INP_ANALOG);
			break;
		}
		}

		MRCC_BoolEnableClock(APB2, AFIO);
		MRCC_BoolEnableClock(APB2, ADC1);
		MADC_BoolInit(&ADC1_config);
		MADC_vStartADC(&ADC1_config);

		return L_BoolErrorState;
		break;
	}

	default:
	{
		L_BoolErrorState = 0;
		return L_BoolErrorState;
		break;
	}
	}

}


/***********************************************************************************/


u16 HFlameSensor_u16ConvertData(void)
{
	u16 u16ArrDataConverted[2];
	MADC_vGetDigitalDataReg(&ADC1_config, u16ArrDataConverted);

	return (u16ArrDataConverted[0]);
}

