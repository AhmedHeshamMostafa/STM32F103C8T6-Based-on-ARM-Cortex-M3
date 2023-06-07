/*
 * MEXTI_prv.h
 *
 *  Created on: May 31, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_MEXTI_MEXTI_PRV_H_
#define MCAL_MEXTI_MEXTI_PRV_H_


#define       EXTI_BASE_ADDRESS              (0x40013C00)

#define       SYSCFG_EXTICR1                 *((volatile u32*)0x40013808)
#define       SYSCFG_EXTICR2                 *((volatile u32*)0x4001380C)
#define       SYSCFG_EXTICR3                 *((volatile u32*)0x40013810)
#define       SYSCFG_EXTICR4                 *((volatile u32*)0x40013814)

//#define       SYSCFG_EXTICR_BASE_ADDRESS     (0x40013808)



typedef struct
{

	u32    IMR;
	u32    EMR;
	u32    RTSR;
	u32    FTSR;
	u32    SWIER;
	u32    PR;

}EXTI_memMap_t;








#define         EXTI               ((volatile EXTI_memMap_t*)EXTI_BASE_ADDRESS)





#define        PORTA_EXTI          0b0000
#define        PORTB_EXTI          0b0001
#define        PORTC_EXTI          0b0010
#define        PORTD_EXTI          0b0011
#define        PORTE_EXTI          0b0100
#define        PORTH_EXTI          0b0111


#define        EXTI_MASK           0b1111


#ifndef       PA
#define       PA             0
#endif

#ifndef       PB
#define       PB             1
#endif

#ifndef       PC
#define       PC             2
#endif

#ifndef       PD
#define       PD             3
#endif

#ifndef       PE
#define       PE             4
#endif

#ifndef       PH
#define       PH             5
#endif





#ifndef       PIN0
#define       PIN0              0
#endif

#ifndef       PIN1
#define       PIN1              1
#endif

#ifndef       PIN2
#define       PIN2              2
#endif

#ifndef       PIN3
#define       PIN3              3
#endif

#ifndef       PIN4
#define       PIN4              4
#endif

#ifndef       PIN5
#define       PIN5              5
#endif

#ifndef       PIN6
#define       PIN6              6
#endif

#ifndef       PIN7
#define       PIN7              7
#endif

#ifndef       PIN8
#define       PIN8              8
#endif

#ifndef       PIN9
#define       PIN9              9
#endif

#ifndef       PIN10
#define       PIN10             10
#endif

#ifndef       PIN11
#define       PIN11             11
#endif

#ifndef       PIN12
#define       PIN12             12
#endif

#ifndef       PIN13
#define       PIN13             13
#endif

#ifndef       PIN14
#define       PIN14             14
#endif

#ifndef       PIN15
#define       PIN15             15
#endif



#endif /* MCAL_MEXTI_MEXTI_PRV_H_ */
