/*========================================================
File        : WDG_PRIVATE
Description : This file contain Rgisters address of IWDG & WWDG  
Author      : Kerolos Maged Amin Fekry
Date        : 7/5/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef WDG_PRIVATE_H
#define WDG_PRIVATE_H


/*============ Resisters of IWDG ===========*/
typedef struct {


    volatile uint32_t IWDG_KR;
    volatile uint32_t IWDG_PR;
    volatile uint32_t IWDG_RLR;
    volatile uint32_t IWDG_SR;


}IWDG_n;


#define    IWDG     ((volatile IWDG_n *)( 0x40003000 )) 

/*============ Resisters of WWDG ===========*/
typedef struct {


    volatile uint32_t WWDG_CR;
    volatile uint32_t WWDG_CFR;
    volatile uint32_t WWDG_SR;


}WWDG_n;



#define    WWDG     ((volatile WWDG_n *)( 0x40002C00 )) 



 #endif


 