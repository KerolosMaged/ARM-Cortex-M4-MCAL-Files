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
void Void_TIMx_Init(TIMX_t TIMx);

void Void_Set_Counter(TIMx_n *TIMx , DIRx Copy_DIR , CNS_MODE Copy_Mode , uint32_t Copy_PSC , uint32_t Copy_ARR );

#endif