/*========================================================
File        : SYSCFG_INTERFACE
Description : This file contain the definetions of SYSCFG functions and source file of SYSCFG
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
/*********** Include of SYSCFG files  **********/
#include "SYSCFG_CONFGR.h"
#include "SYSCFG_INTERFACE.h"
#include "SYSCFG_PRIVATE.h"




void SYSCFG_SetEXTI(uint8_t PORT, uint8_t PIN){
    RCC_VoidStatusPeripheral_CLK(RCC_APB2ENR,SYSCFGEN,ENABLE);

    if(PIN < 4)
    {
        SYSCFG_EXTICR1 |= (PORT << ((PIN % 4) * 4));
    }
    else if(PIN < 8)
    {
        SYSCFG_EXTICR2 |= (PORT << ((PIN % 4) * 4));
    }
    else if(PIN < 12)
    {
        SYSCFG_EXTICR3 |= (PORT << ((PIN % 4) * 4));
    }
    else if(PIN < 16)
    {
        SYSCFG_EXTICR4 |= (PORT << ((PIN % 4) * 4));
    }

}