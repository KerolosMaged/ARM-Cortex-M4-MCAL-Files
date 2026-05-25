/*========================================================
File        : TIMERS_INTERFACE
Description : This file contain the declerations of TIMERS functions 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

#include "TIMERS_CONFGR.h"
#include "TIMERS_PRIVATE.h"


/*===============================================================================================*/
/*===================== TIMER initalization for timer name and clock from rcc ===================*/
/*===============================================================================================*/

void TIMERs_VoidInit(TIMX_t TIMx,T_CLK Copy_CLk);

/*================== TIMER Break Function from pin ================*/

void TIMERs_Break_Pin(TIMx_n *TIMx,T_Polarity Copy_Polarity);

/*================= TIMER Break Function Software ================*/

void TIMERs_Break_SW(TIMx_n *TIMx);

/*================== TIMER Break INTERRUPT Software ================*/

void TIMERs_Break_IT_Enable(TIMx_n *TIMx); 

/*================== TIMER Break Reload Software ================*/

void TIMERs_Break_AOE_Enable(TIMx_n *TIMx);

/*================== TIMER Clearing signal ================*/

void TIMERs_Clear(TIMx_n *TIMx, TRI_Polarity Copy_Polarity);

/*============================================================================*/
/*========================= Timer counter setting ============================*/
/*============================================================================*/
/*===================== Set counter setting ==================*/
void TIMERs_Set_Counter(TIMx_n *TIMx , DIRx Copy_DIR , CNS_MODE Copy_Mode , uint32_t Copy_PSC , uint32_t Copy_ARR );

/*================== Delay mille seconed ===========*/

void TIMERs_VoidDelay_ms(TIMx_n *TIMx, uint32_t Copy_ms);

/*================== Delay micro seconed ===========*/

void TIMERs_VoidDelay_us(TIMx_n *TIMx, uint32_t Copy_us);

/*============================================================================================================*/
/*======================================== [ compare / Capture Mode ] ========================================*/
/*============================================================================================================*/

/*---------------------------- INPUT MODE Functions ---------------------------------*/

/*========= TIMERs Input Capture mode initialization ========*/
void TIMERs_InputCaptureInit(TIMx_n *TIMx,T_CH Copy_CH,C_PSC Copy_psc,T_Edge Copy_Edge);

/*========= Get TIMERs Input Capture mode value ========*/
uint32_t TIMERs_IC_GetValue(TIMx_n *TIMx,T_CH Copy_CH);

/*--------------------------- OUTPUT MODE Functions ----------------------------*/

/*========= TIMERs Output Compare mode initialization ========*/
void TIMERs_OutputCompareMode(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status,T_Polarity Copy_Polarity,T_PR Copy_PRE ,uint32_t Copy_ARR,uint32_t Copy_CCR );



/*==============================================================================================*/
/*======================================== [ PWM Mode ] ========================================*/
/*==============================================================================================*/



/*-----------------------------------------------------------------------------------*/
/*---------------------------- INPUT MODE Functions ---------------------------------*/
/*-----------------------------------------------------------------------------------*/

/*========= TIMERs Input PWM mode  ========*/

/* 
....... There are EQUs for timming in i/p_pwm .....

Period = CCR1
Ton    = CCR2

Frequency = Timer_CLK / Period
Duty      = (Ton * 100.0) / Period

....................................................
*/

void TIMERs_InputPWM(TIMx_n *TIMx,T_CH Copy_CH1,T_CH Copy_CH2,C_PSC Copy_psc);

/*-------------------- Read Input PWM mode values --------------------*/

PWM_RESULTS TIMERs_ReadPWM(TIMx_n *TIMx,C_PSC Copy_psc);

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

void TIMERs_SetPWM_AD(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status,T_Polarity Copy_Polarity, DIRx Copy_DIR ,C_PSC Copy_psc,T_PR Copy_PRE ,uint32_t Copy_ARR,uint32_t Copy_CCR);
/*------------------ Set Freq ------------------*/

void TIMERs_PWM_SetFreq(TIMx_n *TIMx,uint32_t Copy_Freq);

/*------------------ Set Duty ------------------*/

void TIMERs_PWM_SetDuty(TIMx_n *TIMx,T_CH Copy_CH,uint32_t Copy_Duty);

/*------------------ defualt Timer Output PWM Setting ------------------*/

/*!!!!!!!!!!!!!!!! u should to know that when u use this u should set duty and freq !!!!!!!!!!!!!!! */

void TIMERs_SetPWM(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status);

/*==========================================================================================*/



/*=============================================================*/
/*==================== One pulse mode =========================*/
/*=============================================================*/


void TIMERs_OnePulse(TIMx_n *TIMx, T_CH Copy_CH, T_Polarity Copy_Polarity,DIRx Copy_DIR, uint32_t Copy_Freq, uint32_t Copy_Duty);




/*=====================================================================================================================*/
/*=============================================== Advanced Timers TIM1 ================================================*/
/*=====================================================================================================================*/


/*==================== Complementry & Dead time =========================*/

void TIMER_1_Com_DT_Set(TIMx_n *TIMx,T_CH Copy_CH,T_Polarity Copy_Polarity,f32 Copy_DT);

/*=========================== Timer 6 step PWM ==========================*/

void TIMER1_6_Step_PWM(f32 Copy_DT1, f32 Copy_DT2, f32 Copy_DT3, uint32_t Copy_Freq); 







#endif
