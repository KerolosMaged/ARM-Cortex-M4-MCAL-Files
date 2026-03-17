/*========================================================
File        : EXTI_PRIVATE
Description : This file contain Rgisters address of EXTI functions 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#include "../LIB/STD_TYPES_MATH.h"


/*================ EXTI Registers =============*/

#define     EXTI_IMR        *(( volatile uint32_t * )(0x40013C00))      
#define     EXTI_EMR        *(( volatile uint32_t * )(0x40013C04))
#define     EXTI_RTSR       *(( volatile uint32_t * )(0x40013C08))
#define     EXTI_FTSR       *(( volatile uint32_t * )(0x40013C0C))
#define     EXTI_SWIER      *(( volatile uint32_t * )(0x40013C10))
#define     EXTI_PR         *(( volatile uint32_t * )(0x40013C14))






#endif