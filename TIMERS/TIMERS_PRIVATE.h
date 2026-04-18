/*========================================================
File        : TIMERS_PRIVATE
Description : This file contain Rgisters address of TIMERS functions 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H



/********** Registers of ( TIM1 ) *************/

typedef struct {
    volatile uint32_t    CR1;
    volatile uint32_t    CR2;
    volatile uint32_t    SMCR;
    volatile uint32_t    DIER;
    volatile uint32_t    SR;
    volatile uint32_t    EGR;
    volatile uint32_t    CCMR1;
    volatile uint32_t    CCMR2;
    volatile uint32_t    CCER;
    volatile uint32_t    CNT;
    volatile uint32_t    PSC;
    volatile uint32_t    ARR;
    volatile uint32_t    RCR;
    volatile uint32_t    CCR1;
    volatile uint32_t    CCR2;
    volatile uint32_t    CCR3;
    volatile uint32_t    CCR4;
    volatile uint32_t    BDTR;
    volatile uint32_t    DCR;
    volatile uint32_t    DMAR;
    
}TIM1_n;

#define    TIM1 ((volatile TIM1_n*)(0x40010000 )) 


/**********************************************/



/********** Registers of ( TIM2 to TIM5 ) *************/

typedef struct {
    volatile uint32_t    CR1;
    volatile uint32_t    CR2;
    volatile uint32_t    SMCR;
    volatile uint32_t    DIER;
    volatile uint32_t    SR;
    volatile uint32_t    EGR;
    volatile uint32_t    CCMR1;
    volatile uint32_t    CCMR2;
    volatile uint32_t    CCER;
    volatile uint32_t    CNT;
    volatile uint32_t    PSC;
    volatile uint32_t    ARR;
    volatile uint32_t    RESERVED0;
    volatile uint32_t    CCR1;
    volatile uint32_t    CCR2;
    volatile uint32_t    CCR3;
    volatile uint32_t    CCR4;
    volatile uint32_t    RESERVED1;
    volatile uint32_t    DCR;
    volatile uint32_t    DMAR;
    
}TIM2_5_n;

#define    TIM2 ((volatile TIM2_5_n*)(0x40000000)) 
#define    TIM3 ((volatile TIM2_5_n*)(0x40000400)) 
#define    TIM4 ((volatile TIM2_5_n*)(0x40000800)) 
#define    TIM5 ((volatile TIM2_5_n*)(0x40000C00)) 

#define    TIM2_OR      *((volatile uint32_t*)(0x40000050)) 
#define    TIM5_OR      *((volatile uint32_t*)(0x40000C50)) 

/******************************************************/



/********** Registers of ( TIM9 to TIM11) *************/

typedef struct {
    volatile uint32_t    CR1;       //00 
    volatile uint32_t    RESERVED0;        //04
    volatile uint32_t    SMCR;      //08 
    volatile uint32_t    DIER;      //0C
    volatile uint32_t    SR;        //10
    volatile uint32_t    EGR;       //14
    volatile uint32_t    CCMR1;     //18
    volatile uint32_t    RESERVED1;        //1C
    volatile uint32_t    CCER;      //20
    volatile uint32_t    CNT;       //24
    volatile uint32_t    PSC;       //28 
    volatile uint32_t    ARR;       //2C
    volatile uint32_t    RESERVED2;        //30
    volatile uint32_t    CCR1;      //34
    volatile uint32_t    CCR2;      //38
    volatile uint32_t    RESERVED3[5];        //3C >>>>>> 4C
    volatile uint32_t    OR;        //50     

    
}TIM9_11_n;

#define    TIM9  ((volatile TIM9_11_n*)( 0x40014000 )) 
#define    TIM10 ((volatile TIM9_11_n*)( 0x40014400 )) 
#define    TIM11 ((volatile TIM9_11_n*)( 0x40014800 )) 


/**********************************************/




#endif