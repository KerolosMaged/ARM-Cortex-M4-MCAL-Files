/*========================================================
File        : RCC_INTERFACE
Description : This file contain the definetions of RCC functions and source file of GPIO
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/

/********** Include STD_TYPES_MATH file ***********/
#include "../LIB/STD_TYPES_MATH.h"
/*********** Include of RCC files  **********/
#include "RCC_CONFGR.h"
#include "RCC_INTERFACE.h"
#include "RCC_PRIVATE.h"



void RCC_VoidSysInit( void ){
    
    #if   (RCC_CLK==RCC_HSE)            // HSE selection

            CLEAR_BIT(RCC_CR, HSEBYP);
            SET_BIT(RCC_CR, HSEON);
            
            while(GET_BIT(RCC_CR,HSERDY)==0);

            SET_BIT(RCC_CFGR,SW_0);        
            CLEAR_BIT(RCC_CFGR, SW_1);

    #elif (RCC_CLK==RCC_HSI)            // HSI Selection 

            SET_BIT(RCC_CR, HSION);

            while(GET_BIT(RCC_CR,HSIRDY)==0);
            
            CLEAR_BIT(RCC_CFGR,SW_0);      
            CLEAR_BIT(RCC_CFGR, SW_1); 

    #elif (RCC_CLK==RCC_PLL)             // PLL Selection
            /*------ HSE ENABLE*/
            SET_BIT(RCC_CR , HSEON);
            while(GET_BIT(RCC_CR , HSERDY)==0);
            /*----- confgr OF PLL------*/            
            RCC_PLLCFGR = 0;
            RCC_PLLCFGR |= (PLLM << 0);
            RCC_PLLCFGR |= (PLLN << 6);
            RCC_PLLCFGR |= (0 << 16);
            SET_BIT(RCC_PLLCFGR , PLLSRC);
            RCC_PLLCFGR |= (PLLQ << 24);

            SET_BIT(RCC_CR, PLL_ON);

            while(GET_BIT(RCC_CR , PLL_RDY)==0);               
            
            CLEAR_BIT(RCC_CFGR,SW_0);     
            SET_BIT(RCC_CFGR, SW_1);      

    #endif




}


void RCC_VoidStatusPeripheral_CLK(uint8_t BUS ,uint8_t Peripheral ,uint8_t Status){

    switch (Status)
    {
        case ENABLE :     
                        switch(BUS)
                        {
                            case RCC_AHB1 :     SET_BIT(RCC_AHB1ENR,Peripheral);    break;
                            case RCC_AHB2 :     SET_BIT(RCC_AHB2ENR,Peripheral);    break;
                            case RCC_APB1 :     SET_BIT(RCC_APB1ENR,Peripheral);    break;
                            case RCC_APB2 :     SET_BIT(RCC_APB2ENR,Peripheral);    break;
                            default       :                                         break;
                        }
                                                                                    break;                
        case DISABLE :     
                        switch(BUS)
                        {
                            case RCC_AHB1 :     CLEAR_BIT(RCC_AHB1ENR,Peripheral);    break;
                            case RCC_AHB2 :     CLEAR_BIT(RCC_AHB2ENR,Peripheral);    break;
                            case RCC_APB1 :     CLEAR_BIT(RCC_APB1ENR,Peripheral);    break;
                            case RCC_APB2 :     CLEAR_BIT(RCC_APB2ENR,Peripheral);    break;
                            default       :                                           break;                            
                        }
                                                                                      break;
        default     :                                                                 break;    
    }


}


void RCC_VoidStatusPeripheral_LPCLK(uint8_t BUS ,uint8_t Peripheral ,uint8_t Status){

    switch (Status)
    {
        case ENABLE :     
                        switch(BUS)
                        {
                            case RCC_AHB1 :     SET_BIT(RCC_AHB1LPENR,Peripheral);    break;
                            case RCC_AHB2 :     SET_BIT(RCC_AHB2LPENR,Peripheral);    break;
                            case RCC_APB1 :     SET_BIT(RCC_APB1LPENR,Peripheral);    break;
                            case RCC_APB2 :     SET_BIT(RCC_APB2LPENR,Peripheral);    break;
                            default       :                                           break;
                        }
                                                                                      break;
        case DISABLE :     
                        switch(BUS)
                        {
                            case RCC_AHB1 :     CLEAR_BIT(RCC_AHB1LPENR,Peripheral);    break;
                            case RCC_AHB2 :     CLEAR_BIT(RCC_AHB2LPENR,Peripheral);    break;
                            case RCC_APB1 :     CLEAR_BIT(RCC_APB1LPENR,Peripheral);    break;
                            case RCC_APB2 :     CLEAR_BIT(RCC_APB2LPENR,Peripheral);    break;
                            default       :                                             break;                            
                        }
                                                                                        break;

        default     :                                                                   break;    
    }



}


void RCC_Void_Peripheral_RESET(uint8_t BUS ,uint8_t Peripheral ){

    switch(BUS)
    {
        case RCC_AHB1 :     SET_BIT(RCC_AHB1RSTR,Peripheral);   CLEAR_BIT(RCC_AHB1RSTR, Peripheral);    break;
        case RCC_AHB2 :     SET_BIT(RCC_AHB2RSTR,Peripheral);   CLEAR_BIT(RCC_AHB2RSTR, Peripheral);    break;
        case RCC_APB1 :     SET_BIT(RCC_APB1RSTR,Peripheral);   CLEAR_BIT(RCC_APB1RSTR, Peripheral);    break;
        case RCC_APB2 :     SET_BIT(RCC_APB2RSTR,Peripheral);   CLEAR_BIT(RCC_APB2RSTR, Peripheral);    break;
        default       :                                                                                 break;
    }

}
