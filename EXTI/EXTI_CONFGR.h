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


}ُْEXTI_type;







 
#endif