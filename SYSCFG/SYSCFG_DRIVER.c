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





void SYSCFG_Init(uint8_t PORT,){

    #if   (PORT==PORTA)

    #elif (PORT==PORTB)
    
    #elif (PORT==PORTC)
    
    #endif

}
