/*========================================================
File        : NVIC_CONFGR
Description : This file contain NVIC configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/



#ifndef NVIC_CONFGR_H
#define NVIC_CONFGR_H


/*======================= ENUM for vector table of Interrups ========================== */

typedef enum {

        NVIC_Reset                        = -16,
        NVIC_NMI                          = -15,
        NVIC_HardFault                    = -14,
        NVIC_MemManage                    = -12,
        NVIC_BusFault                     = -11,
        NVIC_UsageFault                   = -10,
        NVIC_SVCall                       =  -5,
        NVIC_Debug_Monitor                 =  -4,
        NVIC_PendSV                       =  -2,
        NVIC_Systick                      =  -1,

        NVIC_WWDG                         =   0,
        NVIC_EXTI16_PVD                   =   1,
        NVIC_EXTI21__TAMP_STAMP           =   2,
        NVIC_EXTI22__RTC_WKUP             =   3,
        NVIC_FLASH                        =   4,
        NVIC_RCC                          =   5,
        NVIC_EXTI0                        =   6,
        NVIC_EXTI1                        =   7,
        NVIC_EXTI2                        =   8,
        NVIC_EXTI3                        =   9,
        NVIC_EXTI4                        =  10,
        NVIC_DMA1_Stream0                 =  11,
        NVIC_DMA1_Stream1                 =  12,
        NVIC_DMA1_Stream2                 =  13,
        NVIC_DMA1_Stream3                 =  14,
        NVIC_DMA1_Stream4                 =  15,
        NVIC_DMA1_Stream5                 =  16,
        NVIC_DMA1_Stream6                 =  17,
        NVIC_ADC                          =  18,
        NVIC_EXTI9_5                      =  23,
        NVIC_TIM1_BRK_TIM9                =  24,
        NVIC_TIM1_UP_TIM10                =  25,
        NVIC_TIM1_TRG_COM_TIM11           =  26,
        NVIC_TIM1_CC                      =  27,
        NVIC_TIM2                         =  28,
        NVIC_TIM3                         =  29,
        NVIC_TIM4                         =  30,
        NVIC_I2C1_EV                      =  31,
        NVIC_I2C1_ER                      =  32,
        NVIC_I2C2_EV                      =  33,
        NVIC_I2C2_ER                      =  34,
        NVIC_SPI1                         =  35,
        NVIC_SPI2                         =  36,
        NVIC_USART1                       =  37,
        NVIC_USART2                       =  38,
        NVIC_EXTI15_10                    =  40,
        NVIC_EXTI17__RTC_Alarm            =  41,
        NVIC_EXTI18__OTG_FS_WKUP          =  42,
        NVIC_DMA1_Stream7                 =  47,
        NVIC_SDIO                         =  49,
        NVIC_TIM5                         =  50,
        NVIC_SPI3                         =  51,
        NVIC_DMA2_Stream0                 =  56,
        NVIC_DMA2_Stream1                 =  57,
        NVIC_DMA2_Stream2                 =  58,
        NVIC_DMA2_Stream3                 =  59,
        NVIC_DMA2_Stream4                 =  60,
        NVIC_OTG_FS                       =  67,
        NVIC_DMA2_Stream5                 =  68,
        NVIC_DMA2_Stream6                 =  69,
        NVIC_DMA2_Stream7                 =  70,
        NVIC_USART6                       =  71,
        NVIC_I2C3_EV                      =  72,
        NVIC_I2C3_ER                      =  73,
        NVIC_FPU                          =  81,
        NVIC_SPI4                         =  84

} IRQn_Type;

/*======================================================================================*/

#endif