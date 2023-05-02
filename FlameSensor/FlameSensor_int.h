/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 1 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/


#ifndef HAL_FLAMESENSOR_FLAMESENSOR_INT_H_
#define HAL_FLAMESENSOR_FLAMESENSOR_INT_H_



#define     SENSOR_CH          ADC_CH0
/*The flame sensor outputs 0b111111111111  when there is no fire detected,
  given that it's supplied from a 3.3V supply*/
#define        NO_FIRE      0b111111111111



Bool HFlameSensor_BoolInit(void);
u16 HFlameSensor_u16ConvertData(void);



#endif /* HAL_FLAMESENSOR_FLAMESENSOR_INT_H_ */
