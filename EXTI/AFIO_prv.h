/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 3 Apr 2023                                             */
/*             VERSION  : V02                                                    */
/*********************************************************************************/


#ifndef MCAL_SCB_SCB_PRV_H_
#define MCAL_SCB_SCB_PRV_H_


#define           AFIO_BASE_ADDR          0x40010000



typedef struct
{

	u32   EVCR;
	u32   MAPR;
	u32   EXTICR1;
	u32   EXTICR2;
	u32   EXTICR3;
	u32   EXTICR4;
	u32   Reserved;
	u32   MAPR2;

}AFIOMemMap_t;


#define         AFIO_BLOCK         ((volatile AFIOMemMap_t*)(AFIO_BASE_ADDR))


#endif /* MCAL_SCB_SCB_PRV_H_ */
