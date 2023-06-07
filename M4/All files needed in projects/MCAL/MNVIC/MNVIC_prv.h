/*
 * MNVIC_prv.h
 *
 *  Created on: May 30, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_MNVIC_MNVIC_PRV_H_
#define MCAL_MNVIC_MNVIC_PRV_H_


#define        NVIC_BASE_ADDRESS         (0xE000E100)


typedef struct
{
	//u32   reserved1[64];
	u32   ISER[8];
	u32   reserved2[24];
	u32   ICER[8];
	u32   reserved3[24];
	u32   ISPR[8];
	u32   reserved4[24];
	u32   ICPR[8];
	u32   reserved5[24];
	u32   IABR[8];
	u32   reserved6[56];
	u8    IPR[240];
	u32   reserved7[580];

}NVIC_memMap_t;


#define     NVIC                 ((volatile NVIC_memMap_t*)NVIC_BASE_ADDRESS)


#define     AIRCR                *((volatile u32*)0xE000ED0C)


#define     VECTKEY               0x05FA0000


#define     PRIORITYMASK          0b11110000


static priorityMode_t GS_prModeSavedPrMode;



#endif /* MCAL_MNVIC_MNVIC_PRV_H_ */
