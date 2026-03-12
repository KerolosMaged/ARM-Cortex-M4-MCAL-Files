/*========================================================
File        : RCC_CONFGR
Description : This file contain RCC configration options  
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef RCC_CONFGR_H
#define RCC_CONFGR_H


#define     ENABLE          1
#define     DISABLE         0

#define     RCC_AHB1        0
#define     RCC_AHB2        1
#define     RCC_APB1        2
#define     RCC_APB2        3

/*============= Types of CLOCK Sourses ============*/

/*------------ Primary Sources --------------*/

#define     RCC_HSE         0
#define     RCC_HSI         1
#define     RCC_PLL         2
/*------------ Secondary Sources -----------*/
#define     RCC_LSE         3
#define     RCC_LSI         4

/*------------ RCC CLOCK Selection --------------*/

#define    RCC_CLK          RCC_HSE

/*=================================================*/


/*====================== PLL Confgration ==========================*/
// we'll make pll give 100 MHZ and optmize it to gives this value only
/*----------------- Equations for PLL -------------*/
#define     F_VCO_CLK                   (F_PLLCLK_INPUT * (PLL/PLLM))   
#define     F_PLL_GEN_CLK_OUTPUT        (F_VCO_CLK/PLLP)
#define     F_USB_OTG_FS__SDIO          (F_VCO_CLK/PLLQ)
/*----------------- PLL Factories -------------*/
#define     PLLM    25
#define     PLLN    200
#define     PLLP    2
#define     PLLQ    4
/*---------------- PLL Clock source -----------*/
#define     PLLSRC_HSI      0
#define     PLLSRC_HSE      1

#define     PLL_SRC         PLLSRC_HSE
/*=================================================================*/



/*============= AHB prescaler ==============*/

#define     AHB_DIVIDED_2        8
#define     AHB_DIVIDED_4        9
#define     AHB_DIVIDED_8        10
#define     AHB_DIVIDED_16       11
#define     AHB_DIVIDED_64       12
#define     AHB_DIVIDED_128      13
#define     AHB_DIVIDED_256      14
#define     AHB_DIVIDED_512      15

/*------------------------------------------*/

#define     AHB_PRESC       AHB_DIVIDED_  

/*==========================================*/


/*============= APB1 prescaler ==============*/

#define     APB1_DIVIDED_2        4
#define     APB1_DIVIDED_4        5
#define     APB1_DIVIDED_8        6
#define     APB1_DIVIDED_16       7

/*------------------------------------------*/

#define     APB1_PRESC       APB1_DIVIDED_16

/*==========================================*/


/*============= APB2 prescaler ==============*/
 
#define     APB2_DIVIDED_2        4
#define     APB2_DIVIDED_4        5
#define     APB2_DIVIDED_8        6
#define     APB2_DIVIDED_16       7

/*------------------------------------------*/

#define     APB2_PRESC      APB2_DIVIDED_16

/*==========================================*/









#endif