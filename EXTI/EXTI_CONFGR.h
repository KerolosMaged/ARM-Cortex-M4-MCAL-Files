/*========================================================
File        : EXTI_CONFGR
Description : This file contain EXTI configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef EXTI_CONFGR_H
#define EXTI_CONFGR_H


#include "../LIB/STD_TYPES_MATH.h"


typedef enum{
    
    Rising_trigger,
    Falling_trigger,
    Both_trigger

}Trigger_type;


typedef enum{
    
    INTERRUPT,
    EVENT


}EXTI_type;




/*========== Define Pins =========*/
#define     PIN0                0
#define     PIN1                1
#define     PIN2                2
#define     PIN3                3
#define     PIN4                4
#define     PIN5                5
#define     PIN6                6
#define     PIN7                7
#define     PIN8                8
#define     PIN9                9
#define     PIN10               10
#define     PIN11               11
#define     PIN12               12
#define     PIN13               13
#define     PIN14               14
#define     PIN15               15
/*================================*/






 
#endif
