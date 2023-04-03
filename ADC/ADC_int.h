/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 2 Apr 2023                                             */
/*             VERSION  : V02                                                    */
/*********************************************************************************/

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#include "ADC_prv.h"




typedef struct
{

	/*Single Conversion or MultiConversion*/
	Bool BoolConvMode;

	/*Scan Mode Enabled or Not*/
	Bool BoolScanMode;

	/*Data is left-aligned or right-aligned*/
	Bool BoolDataAlign;

	/*ADC1, ADC2, or ADC3*/
	ADCPerID_t ADCPerIDModuleID;

	/*Which Dual Mode to be Enabled*/
	ADCDualMode_t ADCDualMModeType;

	/*Discontinuous Mode for Regular Channels*/
	ADCDiscont_t ADCDiscontReg;

	/*Discontinuous Mode for Injected Channels*/
	ADCDiscont_t ADCDiscontInj;

	/*Regular group is converted upon setting ADON or upon a certain external trigger*/
	ADCTrigID_t ADCTrigIDRegGrTrig;

	/*Injected group is converted after regular group or upon a certain external trigger*/
	ADCTrigID_t ADCTrigIDInjGrTrig;

	/*Analog Watchdog disabled for all channels, enabled for regular channels only,
	  enabled for injected channels only, or enabled for a single specified channel*/
	ADCAWD_t ADCAWDAWatchDogType;

	/*The single channel on which AWD is enabled, in case of single-channel mode for AWD*/
	ADCChID_t ADCChIDAWDCh;

	/*The High Thershold of the Analog Watchdog*/
	u16 u16AWDHighThresh;

	/*The Low Thershold of the Analog Watchdog*/
	u16 u16AWDLowThresh;

	/*This array must contain the IDs for injected channels, ordered according to the desired sequence*/
	ADCChID_t ADCChIDArrInjectedGrp[4];

	/*This array must contain the sample time for each injected channel,
	  each injected channel must have the same index in ADCChIDArrInjectedGrp,
	  and ADCSamplTArrInjGrpSampleT*/
	ADCSamplTime_t ADCSamplTArrInjGrpSampleT[4];

	/*This array must contain the data offset for each injected channel,
	  each injected channel must have the same index in ADCChIDArrInjectedGrp,
	  and u16ArrInjectedGrpOffset*/
	u16 u16ArrInjectedGrpOffset[4];

	/*This array must contain the IDs for regular channels, ordered according to the desired sequence*/
	ADCChID_t ADCChIDArrRegularGrp[16];

	/*This array must contain the sample time for each regular channel,
	  each regular channel must have the same index in ADCChIDArrRegularGrp,
	  and ADCSamplTArrRegGrpSampleT*/
	ADCSamplTime_t ADCSamplTArrRegGrpSampleT[16];


}ADC_cfg;



/*********************************************************************************/
/*           ADC configuration parameters available in the family                */
/*********************************************************************************/

#define      SINGLE_CONV            0
#define      MULTI_CONV             1

#define      DISABLE                0
#define      ENABLE                 1

#define      RIGHT                  0
#define      LEFT                   1

#define      MIN_12BIT              0x000
#define      MAX_12BIT              0xFFF
#define      NO_VAL                 0x1000

#define      ADC_CH0                0b00000
#define      ADC_CH1                0b00001
#define      ADC_CH2                0b00010
#define      ADC_CH3                0b00011
#define      ADC_CH4                0b00100
#define      ADC_CH5                0b00101
#define      ADC_CH6                0b00110
#define      ADC_CH7                0b00111
#define      ADC_CH8                0b01000
#define      ADC_CH9                0b01001
#define      ADC_CH10               0b01010
#define      ADC_CH11               0b01011
#define      ADC_CH12               0b01100
#define      ADC_CH13               0b01101
#define      ADC_CH14               0b01110
#define      ADC_CH15               0b01111
#define      ADC_CH16               0b10000
#define      ADC_CH17               0b10001
#define      NO_CH                  0b10010

#define      ONE_5CYCLES            0b000
#define      SEVEN_5CYCLES          0b001
#define      THIRTEEN_5CYCLES       0b010
#define      TWENTYEIGHT_5CYCLES    0b011
#define      FORTYONE_5CYCLES       0b100
#define      FIFTYFIVE_5CYCLES      0b101
#define      SEVENTYONE_5CYCLES     0b110
#define      TWOTHIRTYNINE_5CYCLES  0b111
#define      NA                     0b1000

#define      INDEP                  0b0000
#define      COMBREGSIM_INJSIM      0b0001
#define      COMBREGSIM_ALTTRIG     0b0010
#define      COMBINJSIM_FINTER      0b0011
#define      COMBINJSIM_SINTER      0b0100
#define      INJSIM_ONLY            0b0101
#define      REGSIM_ONLY            0b0110
#define      FINTER_ONLY            0b0111
#define      SINTER_ONLY            0b1000
#define      ALTTRIG_ONLY           0b1001

#define      DISC_DISABLE           0b0111
#define      DISC_1CH               0b1000
#define      DISC_2CH               0b1001
#define      DISC_3CH               0b1010
#define      DISC_4CH               0b1011
#define      DISC_5CH               0b1100
#define      DISC_6CH               0b1101
#define      DISC_7CH               0b1110
#define      DISC_8CH               0b1111

#define      NORMAL_AUTO            0b0111
#define      EXTTRIG_1              0b1000
#define      EXTTRIG_2              0b1001
#define      EXTTRIG_3              0b1010
#define      EXTTRIG_4              0b1011
#define      EXTTRIG_5              0b1100
#define      EXTTRIG_6              0b1101
#define      EXTTRIG_7              0b1110
#define      EXTTRIG_8              0b1111

#define      NO_AWD                 0b000
#define      ALLINJ_AWD             0b001
#define      ALLREG_AWD             0b010
#define      ALLREGINJ_AWD          0b011
#define      SINGLEINJ_AWD          0b101
#define      SINGLEREG_AWD          0b110
#define      SINGLEREGINJ_AWD       0b111




Bool MADC_BoolInit(ADC_cfg *ADCcfgPtConfigPtr);
void MADC_vStartADC(ADC_cfg *ADCcfgPtConfigPtr);
void MADC_vStopADC(ADC_cfg *ADCcfgPtConfigPtr);
void MADC_vGetDigitalDataReg(ADC_cfg *ADCcfgPtConfigPtr, u16 u16ArrData[16]);
void MADC_vGetDigitalDataInj(ADC_cfg *ADCcfgPtConfigPtr, u16 u16ArrData[4]);
void MADC_vSWTrigReg(ADC_cfg *ADCcfgPtConfigPtr);
void MADC_vSWTrigInj(ADC_cfg *ADCcfgPtConfigPtr);





#endif /* MCAL_ADC_ADC_INT_H_ */
