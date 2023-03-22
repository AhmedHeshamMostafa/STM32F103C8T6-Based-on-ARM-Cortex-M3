/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 20 Mar 2023                                            */
/*             VERSION  : V02                                                    */
/*********************************************************************************/

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_


#define        PORTA_BASE_ADDR      0x40010800
#define        PORTB_BASE_ADDR      0x40010C00
#define        PORTC_BASE_ADDR      0x40011000
#define        PORTD_BASE_ADDR      0x40011400
#define        PORTE_BASE_ADDR      0x40011800
#define        PORTF_BASE_ADDR      0x40011C00
#define        PORTG_BASE_ADDR      0x40012000


typedef struct
{
	u32    CRL;
	u32    CRH;
	u32    IDR;
	u32    ODR;
	u32    BSRR;
	u32    BRR;
	u32    LCKR;


}GPIO_MemMap_t;











#define         PORTA             ((volatile GPIO_MemMap_t*)(PORTA_BASE_ADDR))
#define         PORTB             (( volatile GPIO_MemMap_t*)(PORTB_BASE_ADDR))
#define         PORTC             ((volatile  GPIO_MemMap_t*)(PORTC_BASE_ADDR))
#define         PORTD             (( volatile GPIO_MemMap_t*)(PORTD_BASE_ADDR))
#define         PORTE             ((volatile  GPIO_MemMap_t*)(PORTE_BASE_ADDR))
#define         PORTF             (( volatile GPIO_MemMap_t*)(PORTF_BASE_ADDR))
#define         PORTG             ((volatile  GPIO_MemMap_t*)(PORTG_BASE_ADDR))


#define         MIN_PIN           0
#define         MAX_PIN           7
#define         MAX_PORT          15
#define         MIN_PORT_NUM      0
#define         MAX_PORT_NUM      6
#define         MIN_MODE_NUM      0
#define         MAX_MODE_NUM      3
#define         MIN_CFG_NUM_DIR   0
#define         MAX_CFG_NUM_DIR   3
#define         MIN_CFG_NUM_INP   4
#define         MAX_CFG_NUM_INP   7
#define         MIN_CFG_NUM_OUT   8
#define         MAX_CFG_NUM_OUT   11


/*********************************************************************************/
/*                         GPIOx_CRL register pins                               */
/*********************************************************************************/

#define         MODE00            0
#define         MODE01            1
#define         CNF00             2
#define         CNF01             3
#define         MODE10            4
#define         MODE11            5
#define         CNF10             6
#define         CNF11             7
#define         MODE20            8
#define         MODE21            9
#define         CNF20             10
#define         CNF21             11
#define         MODE30            12
#define         MODE31            13
#define         CNF30             14
#define         CNF31             15
#define         MODE40            16
#define         MODE41            17
#define         CNF40             18
#define         CNF41             19
#define         MODE50            20
#define         MODE51            21
#define         CNF50             22
#define         CNF51             23
#define         MODE60            24
#define         MODE61            25
#define         CNF60             26
#define         CNF61             27
#define         MODE70            28
#define         MODE71            29
#define         CNF70             30
#define         CNF71             31




/*********************************************************************************/
/*                         GPIOx_CRH register pins                               */
/*********************************************************************************/

#define         MODE80            0
#define         MODE81            1
#define         CNF80             2
#define         CNF81             3
#define         MODE90            4
#define         MODE91            5
#define         CNF90             6
#define         CNF91             7
#define         MODE100           8
#define         MODE101           9
#define         CNF100            10
#define         CNF101            11
#define         MODE110           12
#define         MODE111           13
#define         CNF110            14
#define         CNF111            15
#define         MODE120           16
#define         MODE121           17
#define         CNF120            18
#define         CNF121            19
#define         MODE130           20
#define         MODE131           21
#define         CNF130            22
#define         CNF131            23
#define         MODE140           24
#define         MODE141           25
#define         CNF140            26
#define         CNF141            27
#define         MODE150           28
#define         MODE151           29
#define         CNF150            30
#define         CNF151            31




/*********************************************************************************/
/*                          GPIOx_IDR register pins                              */
/*********************************************************************************/

#define         IDR0              0
#define         IDR1              1
#define         IDR2              2
#define         IDR3              3
#define         IDR4              4
#define         IDR5              5
#define         IDR6              6
#define         IDR7              7
#define         IDR8              8
#define         IDR9              9
#define         IDR10             10
#define         IDR11             11
#define         IDR12             12
#define         IDR13             13
#define         IDR14             14
#define         IDR15             15
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/




/*********************************************************************************/
/*                          GPIOx_ODR register pins                              */
/*********************************************************************************/

#define         ODR0              0
#define         ODR1              1
#define         ODR2              2
#define         ODR3              3
#define         ODR4              4
#define         ODR5              5
#define         ODR6              6
#define         ODR7              7
#define         ODR8              8
#define         ODR9              9
#define         ODR10             10
#define         ODR11             11
#define         ODR12             12
#define         ODR13             13
#define         ODR14             14
#define         ODR15             15
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/




/*********************************************************************************/
/*                          GPIOx_BSRR register pins                             */
/*********************************************************************************/

#define         BSR0              0
#define         BSR1              1
#define         BSR2              2
#define         BSR3              3
#define         BSR4              4
#define         BSR5              5
#define         BSR6              6
#define         BSR7              7
#define         BSR8              8
#define         BSR9              9
#define         BSR10             10
#define         BSR11             11
#define         BSR12             12
#define         BSR13             13
#define         BSR14             14
#define         BSR15             15




/*********************************************************************************/
/*                          GPIOx_BRR register pins                              */
/*********************************************************************************/

#define         BR0               0
#define         BR1               1
#define         BR2               2
#define         BR3               3
#define         BR4               4
#define         BR5               5
#define         BR6               6
#define         BR7               7
#define         BR8               8
#define         BR9               9
#define         BR10              10
#define         BR11              11
#define         BR12              12
#define         BR13              13
#define         BR14              14
#define         BR15              15
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/




/*********************************************************************************/
/*                          GPIOx_LCKR register pins                             */
/*********************************************************************************/

#define         LCK0              0
#define         LCK1              1
#define         LCK2              2
#define         LCK3              3
#define         LCK4              4
#define         LCK5              5
#define         LCK6              6
#define         LCK7              7
#define         LCK8              8
#define         LCK9              9
#define         LCK10             10
#define         LCK11             11
#define         LCK12             12
#define         LCK13             13
#define         LCK14             14
#define         LCK15             15
#define         LCKK              16
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/
/*********************************/




#endif /* MCAL_RCC_RCC_PRV_H_ */
