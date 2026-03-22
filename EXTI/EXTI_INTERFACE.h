/*========================================================
File        : EXTI_INTERFACE
Description : This file contain the declerations of EXTI functions 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef     EXTI_INTERFACE_H
#define     EXTI_INTERFACE_H

#include "../LIB/STD_TYPES_MATH.h"
#include "EXTI_CONFGR.h"


void EXTI_Init(uint8_t EXTI_PORT,uint8_t EXTI_PIN,Trigger_type Trigger_type);

void EXTI_VoidEnable(uint8_t EXTI_PIN, EXTI_type EXTI);
void EXTI_VoidDisable(uint8_t EXTI_PIN , EXTI_type EXTI);

uint8_t EXTI_GetPending(uint8_t EXTI_PIN);
void EXTI_ClearPending(uint8_t EXTI_PIN);



void EXTI_SetCallBack(uint8_t EXTI_PIN,void(*EXTI_Ptr)(void));

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);


void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);

#endif