/*========================================================
File        : SYSTICK_PRIVATE
Description : This file contain Rgisters address of SYSTICK functions 
Author      : Kerolos Maged Amin Fekry
Date        : 22/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H



#define     STK_CTRL     *(( volatile uint32_t* )(0xE000E010))
#define     STK_LOAD     *(( volatile uint32_t* )(0xE000E014))
#define     STK_VAL      *(( volatile uint32_t* )(0xE000E018))
#define     STK_CALIB    *(( volatile uint32_t* )(0xE000E01C))

#define     FCLK             84000000UL


#endif





