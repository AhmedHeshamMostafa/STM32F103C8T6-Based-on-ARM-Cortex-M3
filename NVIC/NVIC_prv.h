/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 16 Feb 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_NVIC_PRV_H_
#define MCAL_NVIC_PRV_H_


#define           NVIC_BASE_ADDR          0xE000E100
#define           NVIC_STIR_ADDR          0xE000EF00



typedef struct
{

	u32        ISER[3];
	u32        Reserved0[29];
	u32        ICER[3];
	u32        Reserved1[29];
	u32        ISPR[3];
	u32        Reserved2[29];
	u32        ICPR[3];
	u32        Reserved3[29];
	u32        IABR[3];
	u32        Reserved4[61];
	u8         IPR[81];

}NVICMemMap_t;


#define         NVIC            ((volatile NVICMemMap_t*)(NVIC_BASE_ADDR))
#define         NVIC_STIR       ((volatile u32*)( NVIC_STIR_ADDR))





#endif /* MCAL_NVIC_PRV_H_ */
