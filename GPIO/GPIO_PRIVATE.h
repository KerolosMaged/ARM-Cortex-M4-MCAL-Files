/*========================================================
File        : GPIO_CONFGR
Description : This file contain GPIO main registers and bit names 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef     GPIO_PRIVATE_H
#define     GPIO_PRIVATE_H



#include "../LIB/STD_TYPES_MATH.h"



/*======================= GPIOA Registers =========================*/

#define     GPIOA_MODER         *(( volatile uint32_t* )(0x40020000))
#define     GPIOA_OTYPER        *(( volatile uint32_t* )(0x40020004))
#define     GPIOA_OSPEEDER      *(( volatile uint32_t* )(0x40020008))
#define     GPIOA_PUPDR         *(( volatile uint32_t* )(0x4002000C))
#define     GPIOA_IDR           *(( volatile uint32_t* )(0x40020010))
#define     GPIOA_ODR           *(( volatile uint32_t* )(0x40020014))
#define     GPIOA_BSRR          *(( volatile uint32_t* )(0x40020018))
#define     GPIOA_LCKR          *(( volatile uint32_t* )(0x4002001C))
#define     GPIOA_AFRL          *(( volatile uint32_t* )(0x40020020))
#define     GPIOA_AFRH          *(( volatile uint32_t* )(0x40020024))


/*=================================================================*/


/*======================= GPIOB Registers =========================*/

#define     GPIOB_MODER         *(( volatile uint32_t* )(0x40020400))
#define     GPIOB_OTYPER        *(( volatile uint32_t* )(0x40020404))
#define     GPIOB_OSPEEDER      *(( volatile uint32_t* )(0x40020408))
#define     GPIOB_PUPDR         *(( volatile uint32_t* )(0x4002040C))
#define     GPIOB_IDR           *(( volatile uint32_t* )(0x40020410))
#define     GPIOB_ODR           *(( volatile uint32_t* )(0x40020414))
#define     GPIOB_BSRR          *(( volatile uint32_t* )(0x40020418))
#define     GPIOB_LCKR          *(( volatile uint32_t* )(0x4002041C))
#define     GPIOB_AFRL          *(( volatile uint32_t* )(0x40020420))
#define     GPIOB_AFRH          *(( volatile uint32_t* )(0x40020424)) 

/*=================================================================*/


/*======================= GPIOC Registers =========================*/

#define     GPIOC_MODER         *(( volatile uint32_t* )(0x40020800))
#define     GPIOC_OTYPER        *(( volatile uint32_t* )(0x40020804))
#define     GPIOC_OSPEEDER      *(( volatile uint32_t* )(0x40020808))
#define     GPIOC_PUPDR         *(( volatile uint32_t* )(0x4002080C))
#define     GPIOC_IDR           *(( volatile uint32_t* )(0x40020810))
#define     GPIOC_ODR           *(( volatile uint32_t* )(0x40020814))
#define     GPIOC_BSRR          *(( volatile uint32_t* )(0x40020818))
#define     GPIOC_LCKR          *(( volatile uint32_t* )(0x4002081C))
#define     GPIOC_AFRL          *(( volatile uint32_t* )(0x40020820))
#define     GPIOC_AFRH          *(( volatile uint32_t* )(0x40020824))
/*=================================================================*/







#endif 