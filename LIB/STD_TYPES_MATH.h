#ifndef STD_TYPES_MATH_H
#define STD_TYPES_MATH_H

/*==================== Math Bits ====================*/
#define SET_BIT(register,bit)      register|= (1<<bit)
#define CLEAR_BIT(register,bit)    register&= ~(1<<bit)
#define TOGGLE_BIT(register,bit)   register^= (1<<bit)
#define GET_BIT(register,bit)  ((register >> bit) & 1) 
/*===================================================*/

/*********  SIGNED DATA TYPES  *********/
typedef signed char             sint8_t;
typedef signed short int        sint16_t;
typedef signed long int         sint32_t;
typedef signed long long int    sint64_t;
/**************************************/

/********* UNSIGNED DATA TYPES  *********/
typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
typedef unsigned long int       uint32_t;
typedef unsigned long long int  uint64_t;
/**************************************/

/********* FLOATING DATA TYPES  *********/
typedef float   f32;
typedef double  f64;
/**************************************/

#define NULL 	 0

#endif
