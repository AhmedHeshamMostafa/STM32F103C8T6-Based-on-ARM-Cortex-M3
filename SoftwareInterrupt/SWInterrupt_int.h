/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 Apr 2023                                             */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef HAL_SWINTERRUPT_SWINTERRUPT_INT_H_
#define HAL_SWINTERRUPT_SWINTERRUPT_INT_H_





void HSWInt_BoolInit(void);
void HSWInt_BoolSetInterrupt(void);
void HSWInt_BoolClearInterrupt(void);
void HSWInt_vSetCallBack(void(*vAppFunv)(void));



#endif /* HAL_SWINTERRUPT_SWINTERRUPT_INT_H_ */
