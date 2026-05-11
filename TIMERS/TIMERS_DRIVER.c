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

/*========= Timers initialization ==========*/

void TIMERs_VoidInit(TIMX_t TIMx){
    switch (TIMx)
    {
        case TIMER1  :    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM1EN,ENABLE);    break;
        case TIMER2  :    RCC_VoidStatusPeripheral_CLK(RCC_APB1,TIM2EN,ENABLE);    break;
        case TIMER3  :    RCC_VoidStatusPeripheral_CLK(RCC_APB1,TIM3EN,ENABLE);    break;
        case TIMER4  :    RCC_VoidStatusPeripheral_CLK(RCC_APB1,TIM4EN,ENABLE);    break;
        case TIMER5  :    RCC_VoidStatusPeripheral_CLK(RCC_APB1,TIM5EN,ENABLE);    break;
        case TIMER9  :    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM9EN,ENABLE);    break;
        case TIMER10 :    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM10EN,ENABLE);   break;
        case TIMER11 :    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM11EN,ENABLE);   break;

        default     :                                                               break;
    }
}


/*============================================= Timers' counter  setting =====================================================*/
/*--------- u should know that Ttick = [(psc+1)/Fclk]     ///     over all period=[(ARR+1)*Ttick ----------------*/
/*============================================================================================================================*/

void TIMERs_Set_Counter(TIMx_n *TIMx , DIRx Copy_DIR , CNS_MODE Copy_Mode , uint32_t Copy_PSC , uint32_t Copy_ARR ){

    /*---------- DISABLE the counter  ----------*/ 
    CLEAR_BIT(TIMx->REG_CR1,0);
    /*-------------------- Set the mode---------------------*/
    switch (Copy_Mode)
    {
        case   Edge_aligned :                                   

            CLEAR_BIT(TIMx->REG_CR1,5); CLEAR_BIT(TIMx->REG_CR1,6);
          /*-------------- set the direction only in edged ------------------*/  
           switch(Copy_DIR)
            {
                case UP   :  CLEAR_BIT(TIMx->REG_CR1,4);    break;
                case DOWN :  SET_BIT(TIMx->REG_CR1,4);      break;
                default   :                                 break;
            } 
                                                            break;

        case   Center_aligned_1 : SET_BIT(TIMx->REG_CR1,5);   CLEAR_BIT(TIMx->REG_CR1,6);  break;
        case   Center_aligned_2 : CLEAR_BIT(TIMx->REG_CR1,5); SET_BIT(TIMx->REG_CR1,6);    break;
        case   Center_aligned_3 : SET_BIT(TIMx->REG_CR1,5);   SET_BIT(TIMx->REG_CR1,6);    break;
        default :                                                                          break;
        
    }

    /*---------- set the prescaler value ----------*/
        TIMx->REG_PSC = Copy_PSC;
    /*---------- set the ARR value ----------*/        
        TIMx->REG_ARR = Copy_ARR;
    /*--------- Enable preload --------*/
        SET_BIT(TIMx->REG_CR1,7);
    /*--------- Reset counter ---------*/
        TIMx->REG_CNT = 0;
        /*--------- Reset FLAG ---------*/
        CLEAR_BIT(TIMx->REG_SR, 0);
    /*----------- Update --------------*/
        SET_BIT(TIMx->REG_EGR,0);   
    /*--- Clear the initial UG flag before entering the user wait loop ---*/
        CLEAR_BIT(TIMx->REG_SR,0);
    /*---------- ENABLE the counter  ----------*/    
        SET_BIT(TIMx->REG_CR1,0);




}

/*================== Delay mille seconed ===========*/


void TIMERs_VoidDelay_ms(TIMx_n *TIMx, uint32_t Copy_ms)
{
    uint16_t PSC = (TIM_CLK / 1000) - 1;  // 1 tick = 1ms
    uint16_t ARR = Copy_ms - 1;

    TIMERs_Set_Counter(TIMx,UP,Edge_aligned, PSC, ARR);

    while(!(TIMx->REG_SR & (1 << 0)));
    CLEAR_BIT(TIMx->REG_CR1, 0);

}

/*================== Delay micro seconed ===========*/

void TIMERs_VoidDelay_us(TIMx_n *TIMx, uint32_t Copy_us)
{
    uint16_t PSC = (TIM_CLK) - 1;  // 1 tick = 1ms
    uint16_t ARR = Copy_us - 1;

    TIMERs_Set_Counter(TIMx,UP,Edge_aligned, PSC, ARR);

    while(!(TIMx->REG_SR & (1 << 0)));
    CLEAR_BIT(TIMx->REG_CR1, 0);

}
/*============================================================================================================*/
/*======================================== [ compare / Capture Mode ] ========================================*/
/*============================================================================================================*/


/*========= TIMERs Input Capture mode initialization ========*/

void TIMERs_InputCaptureInit(TIMx_n *TIMx,T_CH Copy_CH,C_PSC Copy_psc,T_Edge Copy_Edge){

    uint8_t CCER_E[4] = {0,4,8,12};
    uint8_t CCER_P[4] = {1,5,9,13};
    uint8_t CCER_NP[4] = {3,7,11,15};
 
    /*---------- Disable Input Capture --------*/    
    CLEAR_BIT(TIMx->REG_CCER,CCER_E[Copy_CH]);
    /*----------- Choose the channel ---------*/
    switch(Copy_CH){
        case CH1 :
            /*----- Clear CC1S -----*/
            TIMx->REG_CCMR1&=~(0b11<<0);
            /*----- Set CC1S to be i/p -----*/
            TIMx->REG_CCMR1|= (0b01<<0);
            /*----- Confgr the filer -----*/
            TIMx->REG_CCMR1 &=~(0b1111<<4);
            TIMx->REG_CCMR1|=(0b0011<<4);
            /*----- Confgr the prescaler -----*/
            TIMx->REG_CCMR1 &= ~(3 << 2);
            TIMx->REG_CCMR1|= (Copy_psc<<2);            
        break;
        case CH2 :
            TIMx->REG_CCMR1&=~(0b11<<8);
            /*----- Set CC2S to be i/p -----*/
            TIMx->REG_CCMR1|= (0b01<<8);
            /*----- Confgr the filer -----*/
            TIMx->REG_CCMR1 &=~(0b1111<<12);            
            TIMx->REG_CCMR1|=(0b0011<<12);
            /*----- Confgr the prescaler -----*/
            TIMx->REG_CCMR1 &= ~(3 << 10);
            TIMx->REG_CCMR1|= (Copy_psc<<10);               
        break;             
        case CH3 :
            /*----- Clear CC3S -----*/
            TIMx->REG_CCMR2&=~(0b11<<0);
            /*----- Set CC3S to be i/p -----*/
            TIMx->REG_CCMR2|= (0b01<<0);
            /*----- Confgr the filer -----*/
            TIMx->REG_CCMR2 &=~(0b1111<<4);
            TIMx->REG_CCMR2|=(0b0011<<4);
            /*----- Confgr the prescaler -----*/
            TIMx->REG_CCMR2 &= ~(3 << 2);
            TIMx->REG_CCMR2|= (Copy_psc<<2);             
        break;
        case CH4 :
            TIMx->REG_CCMR2&=~(0b11<<8);
            /*----- Set CC4S to be i/p -----*/
            TIMx->REG_CCMR2|= (0b01<<8);
            /*----- Confgr the filer -----*/
            TIMx->REG_CCMR2 &=~(0b1111<<12);
            TIMx->REG_CCMR2|=(0b0011<<12);
            /*----- Confgr the prescaler -----*/
            TIMx->REG_CCMR2 &= ~(3 << 10);
            TIMx->REG_CCMR2|= (Copy_psc<<10);             
        break;
        default: 
        break;            
    }  
    /*----- Activation of the Capture & Edging of the signal ------- */
   
    switch(Copy_Edge)
    {
        case RISING_EDGE  : CLEAR_BIT(TIMx->REG_CCER, CCER_P[Copy_CH]);   CLEAR_BIT(TIMx->REG_CCER,CCER_NP[Copy_CH]);  break;
        case FALLING_EDGE : SET_BIT(TIMx->REG_CCER, CCER_P[Copy_CH]);     CLEAR_BIT(TIMx->REG_CCER,CCER_NP[Copy_CH]);  break;
        case BOTH_EDGE    : SET_BIT(TIMx->REG_CCER, CCER_P[Copy_CH]);     SET_BIT(TIMx->REG_CCER,CCER_NP[Copy_CH]);    break;
        default           :                                                                                            break;
    }

    /*---------- Enable Input Capture --------*/
    SET_BIT(TIMx->REG_CCER,CCER_E[Copy_CH]);
}

/*========= Get TIMERs Input Capture mode value ========*/

uint32_t TIMERs_IC_GetValue(TIMx_n *TIMx,T_CH Copy_CH){

    switch(Copy_CH)
    {
        case CH1: return TIMx->REG_CCR1;
        case CH2: return TIMx->REG_CCR2;
        case CH3: return TIMx->REG_CCR3;
        case CH4: return TIMx->REG_CCR4;
    }
    return 0;       


}

/*========= TIMERs Output Compare mode initialization ========*/

void TIMERs_OutputCompareMode(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status,T_Edge Copy_Edge,T_PR Copy_PRE ,uint32_t Copy_ARR,uint32_t Copy_CCR ){
    
    uint8_t CCER_E[4] = {0,4,8,12};
    uint8_t CCER_P[4] = {1,5,9,13};
    uint8_t CCER_NP[4] = {3,7,11,15};
    /*----- ARR value -----*/
    TIMx->REG_ARR= Copy_ARR;
    /*----- Choose of the preload -----*/
    TIMx->REG_CR1|=(Copy_PRE<<7);
    /*---------- Disable Output Compare --------*/    
    CLEAR_BIT(TIMx->REG_CCER,CCER_E[Copy_CH]);
    /*----------- Choose the channel ---------*/
    switch(Copy_CH){
        case CH1 :
            /*----- Clear CC1S -----*/
            TIMx->REG_CCMR1&=~(0b11<<0);
            /*----- Set CC1S to be o/p -----*/
            TIMx->REG_CCMR1|= (0b00<<0);
            /*----- Confgr status of compare -----*/
            TIMx->REG_CCMR1&= ~(7 << 4);
            TIMx->REG_CCMR1|= (Copy_Status<<4);
            CLEAR_BIT(TIMx->REG_CCMR1,3);
            TIMx->REG_CCMR1|= (Copy_PRE<<3);
            /*---- Value of CCR ----*/
            TIMx->REG_CCR1= Copy_CCR;
 
        break;
        case CH2 :
            /*----- Clear CC2S -----*/        
            TIMx->REG_CCMR1&=~(0b11<<8);
            /*----- Set CC2S to be o/p -----*/
            TIMx->REG_CCMR1|= (0b00<<8);
            /*----- Confgr status of compare -----*/
            TIMx->REG_CCMR1 &= ~(7 << 12);
            TIMx->REG_CCMR1|= (Copy_Status<<12);
            /*---- Confgr preload----*/
            CLEAR_BIT(TIMx->REG_CCMR1,11);
            TIMx->REG_CCMR1|= (Copy_PRE<<11);
            /*---- Value of CCR ----*/
            TIMx->REG_CCR2= Copy_CCR;                                         
        break;             
        case CH3 :
            /*----- Clear CC3S -----*/
            TIMx->REG_CCMR2&=~(0b11<<0);
            /*----- Set CC3S to be o/p -----*/
            TIMx->REG_CCMR2|= (0b00<<0);
            /*----- Confgr status of compare -----*/
            TIMx->REG_CCMR2&= ~(7 << 4);
            TIMx->REG_CCMR2|= (Copy_Status<<4);            
            /*---- Confgr preload----*/
            CLEAR_BIT(TIMx->REG_CCMR2,3);
            TIMx->REG_CCMR2|= (Copy_PRE<<3);
            /*---- Value of CCR ----*/
            TIMx->REG_CCR3= Copy_CCR; 
        break;               
        case CH4 :
            /*----- Clear CC4S -----*/        
            TIMx->REG_CCMR2&=~(0b11<<8);
            /*----- Set CC4S to be o/p -----*/
            TIMx->REG_CCMR2|= (0b00<<8);
            /*----- Confgr status of compare -----*/
            TIMx->REG_CCMR2&= ~(7 << 12);
            TIMx->REG_CCMR2|= (Copy_Status<<12);   
            /*---- Confgr preload----*/
            CLEAR_BIT(TIMx->REG_CCMR2,11);
            TIMx->REG_CCMR2|= (Copy_PRE<<11);
            /*---- Value of CCR ----*/
            TIMx->REG_CCR4= Copy_CCR;                                
        break;
        default: 
        break;      
        
    
    }  

    /*----- Activation of the Compare & Edging of the signal ------- */   
    switch(Copy_Edge)
    {
        case RISING_EDGE  : CLEAR_BIT(TIMx->REG_CCER, CCER_P[Copy_CH]);   CLEAR_BIT(TIMx->REG_CCER,CCER_NP[Copy_CH]);  break;
        case FALLING_EDGE : SET_BIT(TIMx->REG_CCER, CCER_P[Copy_CH]);     CLEAR_BIT(TIMx->REG_CCER,CCER_NP[Copy_CH]);  break;
        case BOTH_EDGE    : SET_BIT(TIMx->REG_CCER, CCER_P[Copy_CH]);     SET_BIT(TIMx->REG_CCER,CCER_NP[Copy_CH]);    break;
        default           :                                                                                            break;
    }
    /*---------- Enable OUTPUT Compare --------*/
    SET_BIT(TIMx->REG_CCER,CCER_E[Copy_CH]);
    /*---- Set Main output enable ----*/
    if (TIMx == TIM1)
    {
        SET_BIT(TIMx->REG_BDTR, 15);
    }  
}


/*==============================================================================================*/
/*======================================== [ PWM Mode ] ========================================*/
/*==============================================================================================*/


/*-----------------------------------------------------------------------------------*/
/*---------------------------- INPUT MODE Functions ---------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*========= TIMERs Input PWM mode  ========*/

/*  ..... There are EQUs for timming in i/p_pwm.....

Period = CCR1
Ton    = CCR2

Frequency = Timer_CLK / Period
Duty      = (Ton * 100.0) / Period

....................................................
*/

void TIMERs_InputPWM(TIMx_n *TIMx,T_CH Copy_CH1,T_CH Copy_CH2,C_PSC Copy_psc){
    /*----------- First Input Capture -----------*/
    TIMERs_InputCaptureInit(TIMx,Copy_CH1,Copy_psc,RISING_EDGE);
    /*----------- First Input Capture -----------*/
    TIMERs_InputCaptureInit(TIMx,Copy_CH2,Copy_psc,FALLING_EDGE);

    /*---- Set TI1FP1 FOR one ----*/
    TIMx->REG_SMCR &=~(0b111<<4);
    TIMx->REG_SMCR |= (0b101<<4);
    /*---- Set SLAVE MODE for second  ----*/
    TIMx->REG_SMCR &=~(0b111<<0);
    TIMx->REG_SMCR |= (0b100<<0);
    
}

/*========= Read Input PWM mode values ========*/

PWM_RESULTS TIMERs_ReadPWM(TIMx_n *TIMx,C_PSC Copy_psc){
    PWM_RESULTS Results;

    uint32_t PERIOD = TIMx->REG_CCR1;
    uint32_t TON    = TIMx->REG_CCR2;

    if(PERIOD == 0 ){
        Results.FREQ = 0;
        Results.DUTY = 0;
        return Results;        
    }
    
    Results.FREQ = (((f32)TIM_CLK)/((Copy_psc + 1) * PERIOD));
    Results.DUTY = (((f32)TON * 100.0) / (PERIOD));

    return Results;


}

/*------------------------------------------------------------------------------*/
/*--------------------------- OUTPUT MODE Functions ----------------------------*/
/*------------------------------------------------------------------------------*/

/* 
....... There are EQUs for timming in O /p_pwm .....

Frequency = ARR
Duty      = CCR

Duty % = CCR/ARR *100
Tperiod = (ARR+1)*Tclk
Ton = CCR * Tclk
Toff = Tperiod - Ton

....................................................
*/

/*------------------ Advanced Timer Output PWM Setting ------------------*/

void TIMERs_SetPWM_AD(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status,T_Edge Copy_Edge, DIRx Copy_DIR , CNS_MODE Copy_Mode ,C_PSC Copy_psc,T_PR Copy_PRE ,uint32_t Copy_ARR,uint32_t Copy_CCR){

    CLEAR_BIT(TIMx->REG_CR1,0);
    TIMx->REG_PSC = Copy_psc;

    if(Copy_DIR == UP)   CLEAR_BIT(TIMx->REG_CR1, 4);
    else                 SET_BIT(TIMx->REG_CR1, 4);

    CLEAR_BIT(TIMx->REG_CR1, 5); 
    CLEAR_BIT(TIMx->REG_CR1, 6);

    SET_BIT(TIMx->REG_CR1, 7);

    TIMERs_OutputCompareMode(TIMx, Copy_CH, Copy_Status, Copy_Edge, Copy_PRE, Copy_ARR, Copy_CCR);

    SET_BIT(TIMx->REG_EGR, 0);
    CLEAR_BIT(TIMx->REG_SR, 0);

}

/*------------------ Set Freq ------------------*/

void TIMERs_PWM_SetFreq(TIMx_n *TIMx,uint32_t Copy_Freq){

    if(Copy_Freq == 0)
    {
         return;
    }
    uint32_t ARR_Val = ((TIM_CLK / (( TIMx->REG_PSC + 1) * Copy_Freq ))-1);
    
    if(ARR_Val > 0xFFFF) 
    {
        ARR_Val = 0xFFFF;
    }
    
    TIMx->REG_ARR = ARR_Val;
    SET_BIT(TIMx->REG_EGR,0);
}

/*------------------ Set Duty ------------------*/

void TIMERs_PWM_SetDuty(TIMx_n *TIMx,T_CH Copy_CH,uint32_t Copy_Duty){
    
    uint32_t CCR_n = (((TIMx->REG_ARR + 1) * Copy_Duty) / 100 );

    if(CCR_n > TIMx->REG_ARR)
    { 
        CCR_n = TIMx->REG_ARR;
    }
    switch(Copy_CH)
    {
        case CH1:  TIMx->REG_CCR1 = CCR_n ;   break;
        case CH2:  TIMx->REG_CCR2 = CCR_n ;   break;
        case CH3:  TIMx->REG_CCR3 = CCR_n ;   break;
        case CH4:  TIMx->REG_CCR4 = CCR_n ;   break;
    }

}

/*------------------ defualt Timer Output PWM Setting ------------------*/


void TIMERs_SetPWM(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status){


	TIMERs_SetPWM_AD(
    		TIMx,
			Copy_CH,
			Copy_Status,
			RISING_EDGE,
			UP,
			Edge_aligned,
			24,
			PR_EN,
			0,
			0
        );
    SET_BIT(TIMx->REG_CR1, 0);
    
    /*
     * for servo motor
     * freq = 44
     * 0 = 3%
     * 90 = 7%
     * 180 = 11%
     *
     */
}




