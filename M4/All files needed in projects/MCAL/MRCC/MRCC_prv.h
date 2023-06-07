#ifndef  MRCC_PRV_H
#define  MRCC_PRV_H


#define              RCC_BASE_ADDR             (0x40023800)       



typedef struct
{
	
	u32   CR;
	u32   PLLCFGR;
	u32   CFGR;
	u32   CIR;
	u32   AHB1RSTR;
	u32   AHB2RSTR;
	u32   reserved1;
	u32   reserved2;
	u32   APB1RSTR;
	u32   APB2RSTR;
	u32   reserved3;
	u32   reserved4;
	u32   AHB1ENR;
	u32   AHB2ENR;
	u32   reserved5;
	u32   reserved6;
	u32   APB1ENR;
	u32   APB2ENR;
	u32   reserved7;
	u32   reserved8;
	u32   AHB1LPENR;
	u32   AHB2LPENR;
	u32   reserved9;
	u32   reserved10;
	u32   APB1LPENR;
	u32   APB2LPENR;
	u32   reserved11;
	u32   reserved12;
	u32   BDCR;
	u32   CSR;
	u32   reserved13;
	u32   reserved14;
	u32   SSCGR;
	u32   PLLI2SCFGR;
	u32   reserved15;
	u32   DCKCFGR;
	
}RCC_memMap_t;



#define          RCC               ((volatile RCC_memMap_t*)(RCC_BASE_ADDR))


/*System clock options available*/
#define         HSI         0
#define         HSE         16
#define         PLL         24
/*HSE clock options available*/
#define         HSE_RC      1
#define         HSE_CRY     2
/*PLL input options available*/
#define         PLL_HSE     1
#define         PLL_HSI     0

/*******************************************************************************************/
/*******************************************************************************************/
/************************* END OF SYSTEM CLOCK SOURCE CONFIGURATIONS ***********************/
/*******************************************************************************************/
/*******************************************************************************************/


/*CR register bit definitions needed in MRCC_prg.c*/
#define      HSEBYP       18
#define      HSERDY       17
#define      HSIRDY       1
/*PLLCFGR register bit definitions needed in MRCC_prg.c*/
#define      PLLSRC       22
/*CFGR register bit definitions needed in MRCC_prg.c*/
#define      SWS1         3
#define      SWS0         2
#define      SW1          1
#define      SW0          0



/*******************************************************************************************/
/*******************************************************************************************/
/****************************** END OF REGISTERS BIT DEFINITIONS ***************************/
/*******************************************************************************************/
/*******************************************************************************************/


#endif 
