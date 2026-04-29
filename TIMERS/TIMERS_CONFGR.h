/*========================================================
File        : TIMERS_CONFGR
Description : This file contain TIMERS configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/


#ifndef TIMERS_CONFGR_H
#define TIMERS_CONFGR_H

/*----------- Timers alias ----------*/

typedef enum {
    TIM1_ID = 0,
    TIM2_ID = 1,
    TIM3_ID = 2,
    TIM4_ID = 3,
    TIM5_ID = 4,
    TIM9_ID = 5,
    TIM10_ID = 6,
    TIM11_ID = 7,

}TIMX_t;

/*--------- Direction of counter  ----------*/

typedef enum{
    UP = 0,
    DOWN = 1,
}DIRx;


/*------------ Counter Mode selection -----------*/
typedef enum {
    Edge_aligned = 0,
    Center_aligned_1 = 1,
    Center_aligned_2 = 2,
    Center_aligned_3 = 3,

}CNS_MODE;

/*------------ CLOCK selection -----------*/
typedef enum {
    CK_INT,
    CK_TIx,
    CK_ETR,
    CK_ITRx,

}Clk_SR;




#endif