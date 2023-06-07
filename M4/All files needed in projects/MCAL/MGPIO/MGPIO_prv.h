/*
 * MGPIO_prv.h
 *
 *  Created on: May 29, 2023
 *      Author: Ahmed
 */

#ifndef MGPIO_PRV_H
#define MGPIO_PRV_H


#define          GPIOA_BASE_ADDRESS          (0x40020000)
#define          GPIOB_BASE_ADDRESS          (0x40020400)
#define          GPIOC_BASE_ADDRESS          (0x40020800)
#define          GPIOD_BASE_ADDRESS          (0x40020C00)
#define          GPIOE_BASE_ADDRESS          (0x40021000)
#define          GPIOH_BASE_ADDRESS          (0x40021C00)



typedef struct
{

	u32   MODER;
	u32   OTYPER;
	u32   OSPEEDR;
	u32   PUPDR;
	u32   IDR;
	u32   ODR;
	u32   BSRR;
	u32   LCKR;
	u32   AFRL;
	u32   AFRH;

}GPIOx_memMap_t;



#define        PORTA               ((volatile GPIOx_memMap_t*)GPIOA_BASE_ADDRESS)
#define        PORTB               ((volatile GPIOx_memMap_t*)GPIOB_BASE_ADDRESS)
#define        PORTC               ((volatile GPIOx_memMap_t*)GPIOC_BASE_ADDRESS)
#define        PORTD               ((volatile GPIOx_memMap_t*)GPIOD_BASE_ADDRESS)
#define        PORTE               ((volatile GPIOx_memMap_t*)GPIOE_BASE_ADDRESS)
#define        PORTH               ((volatile GPIOx_memMap_t*)GPIOH_BASE_ADDRESS)



#define        MODE_MASK            3
#define        BIT_MASK             1
#define        SPEED_MASK           3
#define        IN_TYPE_MASK         3
#define        AF_MASK              15


#endif
