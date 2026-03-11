/*========================================================
File        : GPIO_INTERFACE
Description : This file contain the declerations of GPIO functions 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
#include  "GPIO_CONFGR.h"
#include "../LIB/STD_TYPES_MATH.h"


void GPIO_Init( uint8_t GPIOx , GPIO_Init_Def *CFG );

void GPIO_VoidWritePin( uint32_t GPIOx, uint8_t PINx, uint8_t STATYUS);
uint8_t GPIO_uint8_tReadPin( uint32_t GPIOx, uint8_t PINx);

void GPIO_VoidTogglePin( uint32_t GPIOx, uint8_t PINx);


#endif
