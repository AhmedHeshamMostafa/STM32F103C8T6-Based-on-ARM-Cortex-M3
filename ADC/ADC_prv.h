/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 25 Mar 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_


#define     ADC1_BASE_ADDR          0x40012400
#define     ADC2_BASE_ADDR          0x40012800
#define     ADC3_BASE_ADDR          0x40013C00


typedef struct
{

	u32   SR;
	u32   CR1;
	u32   CR2;
	u32   SMPR1;
	u32   SMPR2;
	u32   JOFR1;
	u32   JOFR2;
	u32   JOFR3;
	u32   JOFR4;
	u32   HTR;
	u32   LTR;
	u32   SQR1;
	u32   SQR2;
	u32   SQR3;
	u32   JSQR;
	u32   JDR1;
	u32   JDR2;
	u32   JDR3;
	u32   JDR4;
	u32   DR;

}ADC_MemMap_t;




#define       ADC1               ((volatile ADC_MemMap_t*)ADC1_BASE_ADDR)
#define       ADC2               ((volatile ADC_MemMap_t*)ADC2_BASE_ADDR)
#define       ADC3               ((volatile ADC_MemMap_t*)ADC3_BASE_ADDR)




typedef   volatile ADC_MemMap_t*  ADCPerID_t;
typedef   u8                      ADCDualMode_t;
typedef   u8                      ADCChID_t;
typedef   u8                      ADCSamplTime_t;
typedef   u8                      ADCTrigID_t;
typedef   u8                      ADCAWD_t;
typedef   u8                      ADCDiscont_t;




/*********************************************************************************/
/*                 ADC_SR register bits needed in ADC_prg.c                      */
/*********************************************************************************/

#define       EOC        1
#define       JEOC       2



/*********************************************************************************/
/*                 ADC_CR1 register bits needed in ADC_prg.c                     */
/*********************************************************************************/

#define       AWDCH0     0
#define       AWDCH1     1
#define       AWDCH2     2
#define       AWDCH3     3
#define       AWDCH4     4

#define       SCAN       8
#define       AWDSGL     9
#define       JAUTO      10
#define       DISCEN     11
#define       JDISCEN    12
#define       DISCNUM0   13
#define       DISCNUM1   14
#define       DISCNUM2   15
#define       DUALMOD0   16
#define       DUALMOD1   17
#define       DUALMOD2   18
#define       DUALMOD3   19

#define       JAWDEN     22
#define       AWDEN      23



/*********************************************************************************/
/*                 ADC_CR2 register bits needed in ADC_prg.c                     */
/*********************************************************************************/

#define       ADON       0
#define       CONT       1
#define       CAL        2
#define       RSTCAL     3

#define       ALIGN      11
#define       JEXTSEL0   12
#define       JEXTSEL1   13
#define       JEXTSEL2   14
#define       JEXTTRIG   15

#define       EXTSEL0    17
#define       EXTSEL1    18
#define       EXTSEL2    19
#define       EXTTRIG    20
#define       JSWSTART   21
#define       SWSTART    22



/*********************************************************************************/
/*                 ADC_SQR1 register bits needed in ADC_prg.c                    */
/*********************************************************************************/

#define       L0         20
#define       L1         21
#define       L2         22
#define       L3         23



/*********************************************************************************/
/*                 ADC_JSQR register bits needed in ADC_prg.c                    */
/*********************************************************************************/

#define       JL0        20
#define       JL1        21



#endif /* MCAL_ADC_ADC_PRV_H_ */
