/*========================================================
File        : TIMERS_INTERFACE
Description : This file contain the definetions of TIMERS functions and source file of TIMERS
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/

/********** Include STD_TYPES_MATH file ***********/
#include "../LIB/STD_TYPES_MATH.h"
/*********** Include of RCC files  **********/
#include "../RCC/RCC_CONFGR.h"
#include "../RCC/RCC_INTERFACE.h"
#include "../RCC/RCC_PRIVATE.h"
/*********** Include of NVIC files  **********/
#include "../NVIC/NVIC_CONFGR.h"
#include "../NVIC/NVIC_INTERFACE.h"
#include "../NVIC/NVIC_PRIVATE.h"
/*********** Include of SYSCFG files  **********/
#include "../SYSCFG/SYSCFG_CONFGR.h"
#include "../SYSCFG/SYSCFG_INTERFACE.h"
#include "../SYSCFG/SYSCFG_PRIVATE.h"
/*********** Include of TIMERS files  **********/
#include "TIMERS_CONFGR.h"
#include "TIMERS_INTERFACE.h"
#include "TIMERS_PRIVATE.h"


void Void_TIMx_Init(TIMX_t TIMx){
    switch (TIMx)
    {
        case TIM1_ID   :    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM1EN,ENABLE);    break;
        case TIM2_ID   :    RCC_VoidStatusPeripheral_CLK(RCC_APB1,TIM2EN,ENABLE);    break;
        case TIM3_ID   :    RCC_VoidStatusPeripheral_CLK(RCC_APB1,TIM3EN,ENABLE);    break;
        case TIM4_ID   :    RCC_VoidStatusPeripheral_CLK(RCC_APB1,TIM4EN,ENABLE);    break;
        case TIM5_ID   :    RCC_VoidStatusPeripheral_CLK(RCC_APB1,TIM5EN,ENABLE);    break;
        case TIM9_ID   :    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM9EN,ENABLE);    break;
        case TIM10_ID  :    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM10EN,ENABLE);   break;
        case TIM11_ID  :    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM11EN,ENABLE);   break;

        default     :                                                             break;
    }
}


void Void_Set_Counter(TIMX_t TIMx, DIRx Copy_DIR, CNS_MODE Copy_Mode, uint32_t Copy_PSC, uint32_t Copy_ARR){
    volatile uint32_t *regCR1 = NULL;
    volatile uint32_t *regPSC = NULL;
    volatile uint32_t *regARR = NULL;

    switch (TIMx)
    {
        case TIM1_ID:
            regCR1 = &TIM1->CR1;
            regPSC = &TIM1->PSC;
            regARR = &TIM1->ARR;
            break;
        case TIM2_ID:
            regCR1 = &TIM2->CR1;
            regPSC = &TIM2->PSC;
            regARR = &TIM2->ARR;
            break;
        case TIM3_ID:
            regCR1 = &TIM3->CR1;
            regPSC = &TIM3->PSC;
            regARR = &TIM3->ARR;
            break;
        case TIM4_ID:
            regCR1 = &TIM4->CR1;
            regPSC = &TIM4->PSC;
            regARR = &TIM4->ARR;
            break;
        case TIM5_ID:
            regCR1 = &TIM5->CR1;
            regPSC = &TIM5->PSC;
            regARR = &TIM5->ARR;
            break;
        case TIM9_ID:
            regCR1 = &TIM9->CR1;
            regPSC = &TIM9->PSC;
            regARR = &TIM9->ARR;
            break;
        case TIM10_ID:
            regCR1 = &TIM10->CR1;
            regPSC = &TIM10->PSC;
            regARR = &TIM10->ARR;
            break;
        case TIM11_ID:
            regCR1 = &TIM11->CR1;
            regPSC = &TIM11->PSC;
            regARR = &TIM11->ARR;
            break;
        default:
            break;
    }

    switch (Copy_Mode)
    {
        case Edge_aligned:
            CLEAR_BIT(*regCR1, 5);
            CLEAR_BIT(*regCR1, 6);
            break;
        case Center_aligned_1:
            SET_BIT(*regCR1, 5);
            CLEAR_BIT(*regCR1, 6);
            break;
        case Center_aligned_2:
            CLEAR_BIT(*regCR1, 5);
            SET_BIT(*regCR1, 6);
            break;
        case Center_aligned_3:
            SET_BIT(*regCR1, 5);
            SET_BIT(*regCR1, 6);
            break;
        default:
            return;
    }

    switch (Copy_DIR)
    {
        case UP:
            SET_BIT(*regCR1, 4);
            break;
        case DOWN:
            CLEAR_BIT(*regCR1, 4);
            break;
        default:
            break;
    }

    *regPSC = Copy_PSC;
    *regARR = Copy_ARR;
    SET_BIT(*regCR1, 0);
}
