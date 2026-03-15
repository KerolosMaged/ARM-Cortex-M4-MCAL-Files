/*========================================================
File        : NVIC_INTERFACE
Description : This file contain the definetions of NVIC functions and source file of NVIC
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
#include "NVIC_CONFGR.h"
#include "NVIC_INTERFACE.h"
#include "NVIC_PRIVATE.h"


// Peripheral Event → Interrupt Flag → NVIC checks ISER → NVIC finds ISR in Vector Table → ISR runs → Peripheral data handled 


void NVIC_EnableIRQ(IRQn_Type IRQn){
    
    SET_BIT(NVIC_ISER[(IRQn/32)],(IRQn%32));

}

void NVIC_DisableIRQ(IRQn_Type IRQn){
    
    SET_BIT(NVIC_ICER[(IRQn/32)],(IRQn%32));

}


void NVIC_SetPendingIRQ(IRQn_Type IRQn){

    SET_BIT(NVIC_ISPR[(IRQn/32)],(IRQn%32));
    
}


void NVIC_ClearPendingIRQ(IRQn_Type IRQn){

    SET_BIT(NVIC_ICPR[(IRQn/32)],(IRQn%32));

}

uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn){            

    uint32_t NVIC_Pending = GET_BIT(NVIC_ISPR[(IRQn/32)],(IRQn%32)) ;

    return NVIC_Pending;      
  
}


void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority){

    NVIC_IPR[IRQn/4] |= (priority << ((IRQn%4)*8 + 4));
}



uint32_t NVIC_GetPriority(IRQn_Type IRQn){

    uint8_t NVIC_Priority = (NVIC_IPR[IRQn/4] >> ((IRQn%4)*8 + 4)) & 0xF;

    return  NVIC_Priority;
}

