/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 1 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/


#ifndef HAL_FLAMESENSOR_FLAMESENSOR_INT_H_
#define HAL_FLAMESENSOR_FLAMESENSOR_INT_H_


#define     SENSOR_CH          ADC_CH3


Bool HFlameSensor_BoolInit(void);
u16 HFlameSensor_u16ConvertData(void);



#endif /* HAL_FLAMESENSOR_FLAMESENSOR_INT_H_ */
