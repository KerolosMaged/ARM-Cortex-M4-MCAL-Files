/*========================================================
File        : SYSTICK_INTERFACE
Description : This file contain the definetions of SYSTICK functions and source file of SYSTICK
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
/*********** Include of SYSTICK files  **********/
#include "SYSTICK_CONFGR.h"
#include "SYSTICK_INTERFACE.h"
#include "SYSTICK_PRIVATE.h"

void SysTick_Init(void){


    SET_BIT(STK_CTRL,2);  
}




void SysTick_VoidDelay_ms(uint32_t time){

   
    uint32_t LOAD = ((time*(F_CLK / 1000)) - 1);
    
    STK_VAL = 0x00000000 ;
    STK_LOAD = LOAD;
    SET_BIT(STK_CTRL,0);

    while(GET_BIT(STK_CTRL,16)!=1);

    CLEAR_BIT(STK_CTRL,0);


}


void SysTick_VoidDelay_us(uint32_t time){
   
        uint32_t LOAD = ((time*(F_CLK / 1000000)) - 1);
        STK_LOAD = LOAD;

        STK_VAL = 0x00000000 ;
        SET_BIT(STK_CTRL,0);
        
        while(GET_BIT(STK_CTRL,16)!=1);
        
        CLEAR_BIT(STK_CTRL,0);
   

}


// under workkkkkkk