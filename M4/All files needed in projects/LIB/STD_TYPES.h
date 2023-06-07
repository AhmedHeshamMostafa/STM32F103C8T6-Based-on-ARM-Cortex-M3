/*********************************************************************************/
/*             AUTHOR   : Ahmed Hesham Mostafa                                   */
/*             DATE     : 18 Feb 2023                                            */
/*             VERSION  : V02                                                    */
/*********************************************************************************/

/******* This file contains the type definitions used to standardize data types in the driver *******/



#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#ifndef    LOW
#define    LOW      0x00000000
#endif

#ifndef    HIGH
#define    HIGH     0x00000001
#endif

#ifndef    TRUE
#define    TRUE     HIGH
#endif

#ifndef    FALSE
#define    FALSE     LOW
#endif

#ifndef    NULL
#define    NULL     (void*)0x00000000
#endif



typedef    unsigned char         u8;
typedef    signed   char         s8;
typedef    unsigned short int    u16;
typedef    signed   short int    s16;
typedef    unsigned int          u32;
typedef    signed   int          s32;
typedef    float                 f32;
typedef    u8                    Bool;                         /*For the data that is either 1 or 0, this unique descriptive
                                                            data type is preferred.*/


#endif 
