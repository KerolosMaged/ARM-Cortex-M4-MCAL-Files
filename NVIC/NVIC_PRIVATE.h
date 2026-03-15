/*========================================================
File        : NVIC_INTERFACE
Description : This file contain Rgisters address of NVIC functions 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#include "../LIB/STD_TYPES_MATH.h"


/*======================== NVIC Registers ========================*/

/*----------- NVIC_ISER Register ----------*/

#define     NVIC_ISER        (( volatile uint32_t * )(0xE000E100))

/*----------- NVIC_ICER Register ----------*/

#define     NVIC_ICER        (( volatile uint32_t * )(0xE000E180))

/*----------- NVIC_ISPR Register ----------*/

#define     NVIC_ISPR        (( volatile uint32_t * )(0xE000E200))

/*----------- NVIC_ICPR Register ----------*/

#define     NVIC_ICPR        (( volatile uint32_t * )(0xE000E280))

/*----------- NVIC_IABR Register ----------*/

#define     NVIC_IABR        (( volatile uint32_t * )(0xE000E300))

/*----------- NVIC_IPR Register ----------*/

#define     NVIC_IPR         (( volatile uint32_t * )(0xE000E400))

/*----------- NVIC_STIR Register ----------*/

#define     NVIC_STIR        (( volatile uint8_t * )(0xE000EF00))

/*==============================================================*/



#endif 