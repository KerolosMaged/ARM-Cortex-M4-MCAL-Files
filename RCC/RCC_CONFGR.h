/*========================================================
File        : RCC_CONFGR
Description : This file contain RCC configration options and main registers and bit names 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef RCC_CONFGR_H
#define RCC_CONFGR_H

#define     F_VCO_CLK                   (F_PLLCLK_INPUT * (PLL/PLLM))   
#define     F_PLL_GEN_CLK_OUTPUT        (F_VCO_CLK/PLLP)
#define     F_USB_OTG_FS__SDIO          (F_VCO_CLK/PLLQ)

/*============= Types of CLOCK Sourses ============*/

/*------------ Primary Sources --------------*/

#define     RCC_HSE         0
#define     RCC_HSI         1
#define     RCC_PLL         2
/*------------ Secondary Sources -----------*/
#define     RCC_LSE         3
#define     RCC_LSI         4
 
/*=================================================*/

/*============= System clock switch ===============*/

#define     HSI             0
#define     HSE             1
#define     PLL             2
#define     REVERSED        3

/*-------------------------------------------------*/

#define     SW              HSE

/*=================================================*/

/*============= AHB prescaler ==============*/

#define     DIVIDED_2        8
#define     DIVIDED_4        9
#define     DIVIDED_8        10
#define     DIVIDED_16       11
#define     DIVIDED_64       12
#define     DIVIDED_128      13
#define     DIVIDED_256      14
#define     DIVIDED_512      15

/*------------------------------------------*/

#define     AHB_PRESC       DIVIDED_512

/*==========================================*/





#endif