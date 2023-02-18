/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 10 Feb 2023                                            */
/*             VERSION  : V01                                                    */
/*********************************************************************************/ 

/******* This file contains the function-like macros used for register manipulations in the driver *******/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bitNo)                (reg) |= (1 << (bitNo))                                      //Precondition : bitNo is between 0-31 inclusive.


#define CLR_BIT(reg, bitNo)                (reg) &= (~(1 << (bitNo)))                                   //Precondition : bitNo is between 0-31 inclusive.


#define TOGGLE_BIT(reg, bitNo)             (reg) ^= (1 << (bitNo))                                      //Precondition : bitNo is between 0-31 inclusive.


#define GET_BIT(reg, bitNo, var)           (var) =  ((reg) & (1 << (bitNo))) >> (bitNo)                 //Reads a certain bit in a register and makes it the LSB in val.
                                                                                                        //Precondition : bitNo is between 0-31 inclusive.
			  
#define ASSIGN_BIT(reg, bitNo, val)        (reg) =  ((~(1 << (bitNo))) &  (reg)) | ((val) << (bitNo))   //Writes one or zero in a certain bit position in a register.
                                                                                                        /*Preconditions : bitNo is between 0-31 inclusive,
                                                                                                          and val is either 1 or 0 only.*/  
#define SET_CLR_REG(reg, val)              (reg) = ( (val) == 1 ) ? 0xFFFFFFFF : 0x00000000             //Precondition : val is either one or zero.


#define WRITE_REG(reg, val)                (reg) = (val)


#define READ_REG(reg, var)                 (var) = (reg)


#define WRITE_REG_MASKED(reg, val, mask)   (reg) = ((mask) & (val))  |  ((reg) & (~(mask)))             /*Takes an 32-bit value(val) a mask and a register(reg), writes the bits of
                                                                                                         the val at positions corresponding to the 1s positions in the mask.
																								         Hint : A mask is a 31-bit value of all zeros except some ones at
																								         certain positions.*/

#endif 
