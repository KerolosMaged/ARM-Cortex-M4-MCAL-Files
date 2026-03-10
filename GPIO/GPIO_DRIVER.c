/*========================================================
File        : GPIO_INTERFACE
Description : This file contain the definetions of GPIO functions and source file of GPIO
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/

/********** Include STD_TYPES_MATH file ***********/
#include "../LIB/STD_TYPES_MATH.h"
/*********** Include of GPIO files  **********/
#include "GPIO_CONFGR.h"
#include "GPIO_INTERFACE.h"


void GPIO_Init( uint32_t *GPIOx, uint8_t PINx, uint8_t MODE ,uint8_t PULL, uint8_t SPEED ) {

    switch(GPIOx)
    {
        case    GPIOA   :  
        
                switch(MODE)
                {
                    case    INPUT    :
                    case    OUTPUT   :
                    case    AF       :
                    case    ANALOG   :

                }

                switch(PULL)
                {
                    case   OUTPUT_PUPD          : 
                    case   OUTPUT_OPEN_DRAIN    : 
                }

                switch(SPEED)
                {

                }
        
        
        
        
        
        
        
        break;
        case    GPIOB   :        break;
        case    GPIOC   :        break;


    }




}