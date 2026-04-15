/*========================================================
File        : SYSTICK_INTERFACE
Description : This file contain the declerations of SYSTICK functions 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef     SYSTICK_INTERFACE_H
#define     SYSTICK_INTERFACE_H

#include "../LIB/STD_TYPES_MATH.h"
#include "SYSTICK_CONFGR.h"



void SysTick_Init(void);
void SysTick_VoidDelay_ms(uint32_t time);
void SysTick_VoidDelay_us(uint32_t time);



void SysTick_Start_IT(uint32_t ticks);
void SysTick_SetCallback(void (*ptr)(void));
void SysTick_Stop(void);


#endif