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


void Void_TIM1_Init(void){

    RCC_VoidStatusPeripheral_CLK(RCC_APB2,TIM1EN,ENABLE);

    Clk_SR TIM1 = CK_INT;


}