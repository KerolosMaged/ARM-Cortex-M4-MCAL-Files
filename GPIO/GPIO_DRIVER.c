/*========================================================
File        : GPIO_INTERFACE
Description : This file contain the definetions of GPIO functions and source file of GPIO
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
/*********** Include of GPIO files  **********/
#include "GPIO_CONFGR.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_PRIVATE.h"

void GPIO_Init( uint32_t GPIOx , GPIO_Init_Def *CFG ) {
    uint32_t pin = CFG->PIN ;
    switch(GPIOx)
    {   
        case GPIOA   :  
            RCC_VoidStatusPeripheral_CLK(RCC_AHB1,GPIOAEN,ENABLE);
            /*----------- MODE --------------*/ 
            GPIOA_MODER &= ~(3 << (pin*2));
            GPIOA_MODER |=  ( CFG->MODE << (pin*2));
            /*----------- OTYPE -------------*/
            CLEAR_BIT(GPIOA_OTYPER ,pin);
            GPIOA_OTYPER |= (CFG->OTYPE << pin);
            /*----------- SPEED -------------*/
            GPIOA_OSPEEDER &= ~(3 << (pin*2));
            GPIOA_OSPEEDER |=  ( CFG->SPEED << (pin*2));
            /*----------- PULL ---------*/
            GPIOA_PUPDR &= ~(3 << (pin*2));
            GPIOA_PUPDR |=  ( CFG->PULL << (pin*2));           
            /*----------- AF ----------*/
            if( CFG->MODE == AF )
            {
                if( pin < 8 )
                {
                    GPIOA_AFRL  &= ~(0xF << (pin*4));
                    GPIOA_AFRL  |=  (CFG->AFR << (pin*4));
                }
                else
                {
                    GPIOA_AFRH  &= ~(0xF << ((pin-8)*4));
                    GPIOA_AFRH  |=  (CFG->AFR << ((pin-8)*4));
                }
            }
            

        break;


        case GPIOB   :
            RCC_VoidStatusPeripheral_CLK(RCC_AHB1,GPIOBEN,ENABLE);
            /*----------- MODE --------------*/ 
            GPIOB_MODER &= ~(3 << (pin*2));
            GPIOB_MODER |=  ( CFG->MODE << (pin*2));
            /*----------- OTYPE -------------*/
            CLEAR_BIT(GPIOB_OTYPER ,pin);
            GPIOB_OTYPER |= (CFG->OTYPE << pin);
            /*----------- SPEED -------------*/
            GPIOB_OSPEEDER &= ~(3 << (pin*2));
            GPIOB_OSPEEDER |=  ( CFG->SPEED << (pin*2));
            /*----------- PULL ---------*/
            GPIOB_PUPDR &= ~(3 << (pin*2));
            GPIOB_PUPDR |=  ( CFG->PULL << (pin*2));              
            /*----------- AF ----------*/
            if( CFG->MODE == AF )
            {
                if( pin < 8 )
                {
                    GPIOB_AFRL  &= ~(0xF << (pin*4));
                    GPIOB_AFRL  |=  (CFG->AFR << (pin*4));
                }
                else
                {
                    GPIOB_AFRH  &= ~(0xF << ((pin-8)*4));
                    GPIOB_AFRH  |=  (CFG->AFR << ((pin-8)*4));
                }
            }
            

        break;
        
        case GPIOC   :
            RCC_VoidStatusPeripheral_CLK(RCC_AHB1,GPIOCEN,ENABLE);
        
            /*----------- MODE --------------*/ 
            GPIOC_MODER &= ~(3 << (pin*2));
            GPIOC_MODER |=  ( CFG->MODE << (pin*2));
            /*----------- OTYPE -------------*/
            CLEAR_BIT(GPIOC_OTYPER ,pin);
            GPIOC_OTYPER |= (CFG->OTYPE << pin);
            /*----------- SPEED -------------*/
            GPIOC_OSPEEDER &= ~(3 << (pin*2));
            GPIOC_OSPEEDER |=  ( CFG->SPEED << (pin*2));
            /*----------- PULL ---------*/
            GPIOC_PUPDR &= ~(3 << (pin*2));
            GPIOC_PUPDR |=  ( CFG->PULL << (pin*2));  
            /*----------- AF ----------*/
            if( CFG->MODE == AF )
            {
                if( pin < 8 )
                {
                    GPIOC_AFRL  &= ~(0xF << (pin*4));
                    GPIOC_AFRL  |=  (CFG->AFR << (pin*4));
                }
                else
                {
                    GPIOC_AFRH  &= ~(0xF << ((pin-8)*4));
                    GPIOC_AFRH  |=  (CFG->AFR << ((pin-8)*4));
                }
            }
            

        break;
        
        default :

        break;

    }




}


void GPIO_VoidWritePin( uint32_t GPIOx, uint8_t PINx, uint8_t STATUS){

    
    switch(STATUS)
    {
        case HIGH :
            switch (GPIOx)
            {
                case GPIOA :    SET_BIT(GPIOA_BSRR,PINx);       break;
                case GPIOB :    SET_BIT(GPIOB_BSRR,PINx);       break;
                case GPIOC :    SET_BIT(GPIOC_BSRR,PINx);       break;
                default    :                                    break;
            }
        break;

        case LOW :
            switch (GPIOx)
            {
                case GPIOA :    SET_BIT(GPIOA_BSRR,(PINx+16));   break;
                case GPIOB :    SET_BIT(GPIOB_BSRR,(PINx+16));   break;
                case GPIOC :    SET_BIT(GPIOC_BSRR,(PINx+16));   break;
                default    :                                     break;
            }
        break;
        default   :                                              break;    
    }

}

uint8_t GPIO_uint8_tReadPin( uint32_t GPIOx, uint8_t PINx){
        uint8_t VALUE = 0 ;
                switch (GPIOx)
        {
            case GPIOA :    VALUE = GET_BIT(GPIOA_IDR,PINx);       break;
            case GPIOB :    VALUE = GET_BIT(GPIOB_IDR,PINx);       break;
            case GPIOC :    VALUE = GET_BIT(GPIOC_IDR,PINx);       break;
            default    :                                           break;
        }
        return VALUE;
}


void GPIO_VoidTogglePin( uint32_t GPIOx, uint8_t PINx){

        switch (GPIOx)
        {
            case GPIOA :    TOGGLE_BIT(GPIOA_ODR,PINx);       break;
            case GPIOB :    TOGGLE_BIT(GPIOB_ODR,PINx);       break;
            case GPIOC :    TOGGLE_BIT(GPIOC_ODR,PINx);       break;
            default    :                                      break;
        }

}
