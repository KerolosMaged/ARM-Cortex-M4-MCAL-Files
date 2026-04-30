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


/**********************************************/



/********** Registers of ( TIM2 to TIM5 ) *************/
/*
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
    volatile uint32_t    REG_RESERVED0;
    volatile uint32_t    REG_CCR1;
    volatile uint32_t    REG_CCR2;
    volatile uint32_t    REG_CCR3;
    volatile uint32_t    REG_CCR4;
    volatile uint32_t    REG_RESERVED1;
    volatile uint32_t    REG_DCR;
    volatile uint32_t    REG_DMAR;
    
}TIM2_5_n;*/

#define    TIM2 ((volatile TIMx_n*)(0x40000000)) 
#define    TIM3 ((volatile TIMx_n*)(0x40000400)) 
#define    TIM4 ((volatile TIMx_n*)(0x40000800)) 
#define    TIM5 ((volatile TIMx_n*)(0x40000C00)) 

#define    TIM2_OR      *((volatile uint32_t*)(0x40000050)) 
#define    TIM5_OR      *((volatile uint32_t*)(0x40000C50)) 

/******************************************************/



/********** Registers of ( TIM9 to TIM11) *************/
/*
typedef struct {
    volatile uint32_t    REG_CR1;       //00 
    volatile uint32_t    REG_RESERVED0;        //04
    volatile uint32_t    REG_SMCR;      //08 
    volatile uint32_t    REG_DIER;      //0C
    volatile uint32_t    REG_SR;        //10
    volatile uint32_t    REG_EGR;       //14
    volatile uint32_t    REG_CCMR1;     //18
    volatile uint32_t    REG_RESERVED1;        //1C
    volatile uint32_t    REG_CCER;      //20
    volatile uint32_t    REG_CNT;       //24
    volatile uint32_t    REG_PSC;       //28 
    volatile uint32_t    REG_ARR;       //2C
    volatile uint32_t    REG_RESERVED2;        //30
    volatile uint32_t    REG_CCR1;      //34
    volatile uint32_t    REG_CCR2;      //38
    volatile uint32_t    REG_RESERVED3[5];        //3C >>>>>> 4C
    volatile uint32_t    REG_OR;        //50     

    
}TIMx_n;*/

#define    TIM9  ((volatile TIMx_n*)( 0x40014000 )) 
#define    TIM10 ((volatile TIMx_n*)( 0x40014400 )) 
#define    TIM11 ((volatile TIMx_n*)( 0x40014800 )) 


/**********************************************/




#endif