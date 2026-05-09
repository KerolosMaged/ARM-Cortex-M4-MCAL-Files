/*========================================================
File        : GPIO_CONFGR
Description : This file contain GPIO configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef GPIO_CONFGR_H
#define GPIO_CONFGR_H

#include "../LIB/STD_TYPES_MATH.h"


#define     LOW                 0
#define     HIGH                1

/*=============== MODE ===============*/

#define     INPUT               0
#define     OUTPUT              1
#define     AF                  2
#define     ANALOG              3

/*=============== OTYPE ==============*/

#define     OUTPUT_PP         0
#define     OUTPUT_OPEN_DRAIN   1

/*=============== SPEED ==============*/

#define     LOW_SPEED           0
#define     MID_SPEED           1
#define     HIGH_SPEED          2
#define     V_HIGH_SPEED        3

/*=============== PULL ==============*/
#define     NO_PULL 			0
#define		PULL_UP				1
#define		PULL_DOWN			2

/*========== Define Ports =========*/

#define     GPIOA               0
#define     GPIOB               1    
#define     GPIOC               2       

/*=================================*/

typedef struct {

    uint8_t    PIN;
    uint8_t    MODE;
    uint8_t    OTYPE;
    uint8_t    SPEED;
    uint8_t    PULL;
    uint8_t    AFR;


}GPIO_Init_Def;

/*

    GPIO_Init_DefPIN = PIN15;          // >>>>> 15     
    GPIO_Init_Def.MODE = OUTPUT;        // >>>>>  1      SET_BIT()
    GPIO_Init_Def.OTYPE = OUTPUT_PUPD ; // >>>>>  0
    GPIO_Init_Def.SPEED = HIGH;         // >>>>>  2
    GPIO_Init_Def.AFR ;                 // >>>>> 15


*/



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
