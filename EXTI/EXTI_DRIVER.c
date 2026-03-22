/*========================================================
File        : EXTI_INTERFACE
Description : This file contain the definetions of EXTI functions and source file of EXTI
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
/*********** Include of EXTI files  **********/
#include "EXTI_CONFGR.h"
#include "EXTI_INTERFACE.h"
#include "EXTI_PRIVATE.h"

static void (*EXTI_CALLBACK[16]) (void) = { 0 } ; 



void EXTI_Init(uint8_t EXTI_PORT,uint8_t EXTI_PIN,Trigger_type Trigger_type){
    
    SYSCFG_SetEXTI( EXTI_PORT,  EXTI_PIN);
    switch ( Trigger_type )
    {
        case Rising_trigger :   SET_BIT(EXTI_RTSR,EXTI_PIN);    break;

        case Falling_trigger :  SET_BIT(EXTI_FTSR,EXTI_PIN);    break;
        
        case Both_trigger :     SET_BIT(EXTI_RTSR,EXTI_PIN);    SET_BIT(EXTI_FTSR,EXTI_PIN);    break;
        
        default:                                                break;

    }


}


void EXTI_VoidEnable(uint8_t EXTI_PIN, EXTI_type EXTI){

    switch (EXTI)
    {
        case INTERRUPT :    SET_BIT(EXTI_IMR,EXTI_PIN);     break; 
        case EVENT     :    SET_BIT(EXTI_EMR,EXTI_PIN);     break;
        default :                                           break;
    } 

}

void EXTI_VoidDisable(uint8_t EXTI_PIN , EXTI_type EXTI){

    switch (EXTI)
    {
        case INTERRUPT :    CLEAR_BIT(EXTI_IMR,EXTI_PIN);     break; 
        case EVENT     :    CLEAR_BIT(EXTI_EMR,EXTI_PIN);     break;
        default :                                             break;
    } 

}


uint8_t EXTI_GetPending(uint8_t EXTI_PIN){

    uint8_t Pending = GET_BIT(EXTI_PR,EXTI_PIN);
    return Pending;
}


void EXTI_ClearPending(uint8_t EXTI_PIN){

    SET_BIT(EXTI_PR,EXTI_PIN);

}



void EXTI_SetCallBack(uint8_t EXTI_PIN,void(*EXTI_Ptr)(void)){

    EXTI_CALLBACK[EXTI_PIN] = EXTI_Ptr;

}


void EXTI0_IRQHandler(void){

    if(EXTI_CALLBACK[0]!= NULL){
        EXTI_CALLBACK[0](); 
    }
    SET_BIT(EXTI_PR,PIN0);
}

void EXTI1_IRQHandler(void){

    if(EXTI_CALLBACK[1]!= NULL){
        EXTI_CALLBACK[1](); 
    }
    SET_BIT(EXTI_PR,PIN1);
}

void EXTI2_IRQHandler(void){

    if(EXTI_CALLBACK[2]!= NULL){
        EXTI_CALLBACK[2](); 
    }
    SET_BIT(EXTI_PR,PIN2);

}
void EXTI3_IRQHandler(void){

    if(EXTI_CALLBACK[3]!= NULL){
        EXTI_CALLBACK[3](); 
    }
    SET_BIT(EXTI_PR,PIN3);

}
void EXTI4_IRQHandler(void){

    if(EXTI_CALLBACK[4]!= NULL){
        EXTI_CALLBACK[4](); 
    }
    SET_BIT(EXTI_PR,PIN4);    

}

void EXTI9_5_IRQHandler(void) {
    for(int i = 5; i <= 9; i++) {
        if(READ_BIT(EXTI->PR, (1 << i))) {
            if(EXTI_CALLBACK[i] != NULL) EXTI_CALLBACK[i]();
            SET_BIT(EXTI->PR, (1 << i));
        }
    }
}

void EXTI15_10_IRQHandler(void) {
    for(int i = 10; i <= 15; i++) {
        if(READ_BIT(EXTI->PR, (1 << i))) {
            if(EXTI_CALLBACK[i] != NULL) EXTI_CALLBACK[i]();
            SET_BIT(EXTI->PR, (1 << i));
        }
    }
}