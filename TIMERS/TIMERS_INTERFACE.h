/*========================================================
File        : TIMERS_INTERFACE
Description : This file contain the declerations of TIMERS functions 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

/*========= Timers initialization ==========*/
void Void_TIM_Init(uint8_t TIMx);

void Void_Set_Counter(TIMX_t TIMx, DIRx Copy_DIR, CNS_MODE Copy_Mode, uint32_t Copy_PSC, uint32_t Copy_ARR);
#endif