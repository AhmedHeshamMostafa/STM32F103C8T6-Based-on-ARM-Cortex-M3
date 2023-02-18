/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 16 Feb 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/

#ifndef MCAL_SCB_SCB_PRV_H_
#define MCAL_SCB_SCB_PRV_H_


#define           SCB_BASE_ADDR          0xE000ED00



typedef struct
{
	u32        CPUID;
	u32        ICSR;
	u32        VTOR;
	u32        AIRCR;
	u32        SCR;
	u32        CCR;
	u32        SHPR1;
	u32        SHPR2;
	u32        SHPR3;
	u32        SHCRS;
	u32        CFSR;
	u32        HFSR;
	u32        Reserved;
	u32        MMAR;
	u32        BFAR;


}SCBMemMap_t;


#define         SCB            ((volatile SCBMemMap_t*)(SCB_BASE_ADDR))


#endif /* MCAL_SCB_SCB_PRV_H_ */
