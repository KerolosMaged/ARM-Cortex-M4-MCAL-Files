/*========================================================
File        : TIMERS_PRIVATE
Description : This file contain Rgisters address of TIMERS functions 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H



/*********** Registers of ( TIM1 ) *************/

typedef struct {
    volatile uint32_t    REG_CR1;
    volatile uint32_t    REG_CR2;
    volatile uint32_t    REG_SMCR;
    volatile uint32_t    REG_DIER;
    volatile uint32_t    REG_SR;
    volatile uint32_t    REG_EGR;
    volatile uint32_t    REG_CCMR1;
    volatile uint32_t    REG_CCMR2;
    volatile uint32_t    REG_CCER;
    volatile uint32_t    REG_CNT;
    volatile uint32_t    REG_PSC;
    volatile uint32_t    REG_ARR;
    volatile uint32_t    REG_RCR;
    volatile uint32_t    REG_CCR1;
    volatile uint32_t    REG_CCR2;
    volatile uint32_t    REG_CCR3;
    volatile uint32_t    REG_CCR4;
    volatile uint32_t    REG_BDTR;
    volatile uint32_t    REG_DCR;
    volatile uint32_t    REG_DMAR;
    
}TIMx_n;

#define    TIM1 ((volatile TIMx_n*)(0x40010000 )) 

/********** Registers of ( TIM2 to TIM5 ) *************/

#define    TIM2 ((volatile TIMx_n*)(0x40000000)) 
#define    TIM3 ((volatile TIMx_n*)(0x40000400)) 
#define    TIM4 ((volatile TIMx_n*)(0x40000800)) 
#define    TIM5 ((volatile TIMx_n*)(0x40000C00)) 

#define    TIM2_OR      *((volatile uint32_t*)(0x40000050)) 
#define    TIM5_OR      *((volatile uint32_t*)(0x40000C50)) 

/********** Registers of ( TIM9 to TIM11) *************/


#define    TIM9  ((volatile TIMx_n*)( 0x40014000 )) 
#define    TIM10 ((volatile TIMx_n*)( 0x40014400 )) 
#define    TIM11 ((volatile TIMx_n*)( 0x40014800 )) 


/**********************************************/




#endif