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

/*========= Timers initialization ==========*/
void TIMERs_VoidInit(TIMX_t TIMx);
/*========= Timers' counter  setting =========*/
void TIMERs_Set_Counter(TIMx_n *TIMx , DIRx Copy_DIR , CNS_MODE Copy_Mode , uint32_t Copy_PSC , uint32_t Copy_ARR );

/*========================================  compare / Capture Mode ========================================*/

/*========= TIMERs Input Capture mode initialization ========*/
void TIMERs_InputCaptureInit(TIMx_n *TIMx,T_CH Copy_CH,C_PSC Copy_psc,T_Edge Copy_Edge);

/*========= Get TIMERs Input Capture mode value ========*/
uint32_t TIMERs_IC_GetValue(TIMx_n *TIMx,T_CH Copy_CH);

/*========= TIMERs Output Compare mode initialization ========*/
void TIMERs_OutputCompareMode(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status,T_Edge Copy_Edge,T_PR Copy_PRE ,uint32_t Copy_ARR,uint32_t Copy_CCR );

/*======================================== PWM Mode ========================================*/
/*================================== INPUT MODE Functions =================================*/

/*========= TIMERs Input PWM mode  ========*/

/*  ..... There are EQUs for timming in i/p_pwm.....

Period = CCR1
Ton    = CCR2

Frequency = Timer_CLK / Period
Duty      = (Ton * 100.0) / Period

....................................................
*/

void TIMERs_InputPWM(TIMx_n *TIMx,T_CH Copy_CH1,T_CH Copy_CH2,C_PSC Copy_psc);

/*========= Read Input PWM mode values ========*/

PWM_RESULTS TIMERs_ReadPWM(TIMx_n *TIMx,C_PSC Copy_psc);

/*================================== OUTPUT MODE Functions =================================*/

void TIMERs_OutputPWM(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status,T_Edge Copy_Edge, DIRx Copy_DIR , CNS_MODE Copy_Mode ,C_PSC Copy_psc,T_PR Copy_PRE ,uint32_t Copy_ARR,uint32_t Copy_CCR);


#endif
