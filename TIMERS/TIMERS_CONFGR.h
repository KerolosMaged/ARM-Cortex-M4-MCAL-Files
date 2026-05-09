/*========================================================
File        : TIMERS_CONFGR
Description : This file contain TIMERS configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/


#ifndef TIMERS_CONFGR_H
#define TIMERS_CONFGR_H


#define    TIM_CLK  25000000


/*----------- Timers alias ----------*/

typedef enum {
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5,
    TIMER9,
    TIMER10,
    TIMER11,

}TIMX_t;

/*--------- Direction of counter  ----------*/

typedef enum{
    UP = 0,
    DOWN = 1,
}DIRx;


/*------------ Counter Mode selection -----------*/
typedef enum {
    Edge_aligned     = 0,
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

/*------------ Channel selection -----------*/
typedef enum {

    CH1=0,
    CH2=1,
    CH3=2,
    CH4=3,
}T_CH;

/*------------ Edge selection -----------*/
typedef enum {
    RISING_EDGE =0,
    FALLING_EDGE=1,
    BOTH_EDGE   =3,
}T_Edge;

/*------------ Divition capture selection -----------*/
typedef enum {
    NONE=0b00,
    DIV_2=0b01,
    DIV_4=0b10,
    DIV_8=0b11,
}C_PSC;

/*------------ Compare status selection -----------*/
typedef enum {

    FROZEN        =0b000,
    ACTIVE        =0b001,
    INACTIVE      =0b010,
    TOGGLE        =0b011,
    FORCE_INACTIVE=0b100,
    FORCE_ACTIVE  =0b101,
    PWM_MODE_1    =0b110,
    PWM_MODE_2    =0b111,


}OUTPUT_STATUS;


typedef enum {
    PR_DIS=0 , PR_EN=1,
}T_PR;


typedef struct {

    f32 FREQ;
    f32 DUTY;

}PWM_RESULTS;

#endif
