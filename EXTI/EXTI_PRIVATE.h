/*========================================================
File        : EXTI_INTERFACE
Description : This file contain Rgisters address of EXTI functions 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


#include "../LIB/STD_TYPES_MATH.h"


/*================ EXTI Registers =============*/

#define     EXTI_IMR        *(( volatile uint32_t * )(0x40013C00))
#define     EXTI_EMR        *(( volatile uint32_t * )(0x40013C04))
#define     EXTI_RTSR       *(( volatile uint32_t * )(0x40013C08))
#define     EXTI_FTSR       *(( volatile uint32_t * )(0x40013C0C))
#define     EXTI_SWIER      *(( volatile uint32_t * )(0x40013C10))
#define     EXTI_PR         *(( volatile uint32_t * )(0x40013C14))

/*=============== INTERRUPT VECTORS =============*/


#define     NVIC_Reset                       *(( volatile uint32_t * )(0x00000004))
#define     NVIC_NMI                         *(( volatile uint32_t * )(0x00000008))
#define     NVIC_HardFault                   *(( volatile uint32_t * )(0x0000000C))
#define     NVIC_MemManage                   *(( volatile uint32_t * )(0x00000010))
#define     NVIC_BusFault                    *(( volatile uint32_t * )(0x00000014))
#define     NVIC_UsageFault                  *(( volatile uint32_t * )(0x00000018))
#define     NVIC_SVCall                      *(( volatile uint32_t * )(0x0000002C))
#define     NVIC_Debug_Monito                *(( volatile uint32_t * )(0x00000030))
#define     NVIC_PendSV                      *(( volatile uint32_t * )(0x00000038))
#define     NVIC_Systick                     *(( volatile uint32_t * )(0x0000003C))
#define     NVIC_WWDG                        *(( volatile uint32_t * )(0x00000040))
#define     NVIC_EXTI16_PVD                  *(( volatile uint32_t * )(0x00000044))
#define     NVIC_EXTI21__TAMP_STAMP          *(( volatile uint32_t * )(0x00000048))
#define     NVIC_EXTI22__RTC_WKUP            *(( volatile uint32_t * )(0x0000004C))
#define     NVIC_FLASH                       *(( volatile uint32_t * )(0x00000050))
#define     NVIC_RCC                         *(( volatile uint32_t * )(0x00000054))
#define     NVIC_EXTI0                       *(( volatile uint32_t * )(0x00000058))
#define     NVIC_EXTI1                       *(( volatile uint32_t * )(0x0000005C))
#define     NVIC_EXTI2                       *(( volatile uint32_t * )(0x00000060))
#define     NVIC_EXTI3                       *(( volatile uint32_t * )(0x00000064))
#define     NVIC_EXTI4                       *(( volatile uint32_t * )(0x00000068))
#define     NVIC_DMA1_Stream0                *(( volatile uint32_t * )(0x0000006C))
#define     NVIC_DMA1_Stream1                *(( volatile uint32_t * )(0x00000070))
#define     NVIC_DMA1_Stream2                *(( volatile uint32_t * )(0x00000074))
#define     NVIC_DMA1_Stream3                *(( volatile uint32_t * )(0x00000078))
#define     NVIC_DMA1_Stream4                *(( volatile uint32_t * )(0x0000007C))
#define     NVIC_DMA1_Stream5                *(( volatile uint32_t * )(0x00000080))
#define     NVIC_DMA1_Stream6                *(( volatile uint32_t * )(0x00000084))
#define     NVIC_ADC                         *(( volatile uint32_t * )(0x00000088))
#define     NVIC_EXTI9_5                     *(( volatile uint32_t * )(0x0000009C))
#define     NVIC_TIM1_BRK_TIM9               *(( volatile uint32_t * )(0x000000A0))
#define     NVIC_TIM1_UP_TIM10               *(( volatile uint32_t * )(0x000000A4))
#define     NVIC_TIM1_TRG_COM_TIM11          *(( volatile uint32_t * )(0x000000A8))
#define     NVIC_TIM1_CC                     *(( volatile uint32_t * )(0x000000AC))
#define     NVIC_TIM2                        *(( volatile uint32_t * )(0x000000B0))
#define     NVIC_TIM3                        *(( volatile uint32_t * )(0x000000B4))
#define     NVIC_TIM4                        *(( volatile uint32_t * )(0x000000B8))
#define     NVIC_I2C1_EV                     *(( volatile uint32_t * )(0x000000BC))
#define     NVIC_I2C1_ER                     *(( volatile uint32_t * )(0x000000C0))
#define     NVIC_I2C2_EV                     *(( volatile uint32_t * )(0x000000C4))
#define     NVIC_I2C2_ER                     *(( volatile uint32_t * )(0x000000C8))
#define     NVIC_SPI1                        *(( volatile uint32_t * )(0x000000CC))
#define     NVIC_SPI2                        *(( volatile uint32_t * )(0x000000D0))
#define     NVIC_USART1                      *(( volatile uint32_t * )(0x000000D4))
#define     NVIC_USART2                      *(( volatile uint32_t * )(0x000000D8))
#define     NVIC_EXTI15_10                   *(( volatile uint32_t * )(0x000000E0))
#define     NVIC_EXTI17__RTC_Alarm           *(( volatile uint32_t * )(0x000000E4))
#define     NVIC_EXTI18__OTG_FS_WKUP         *(( volatile uint32_t * )(0x000000E8))
#define     NVIC_DMA1_Stream7                *(( volatile uint32_t * )(0x000000FC))
#define     NVIC_SDIO                        *(( volatile uint32_t * )(0x00000104))
#define     NVIC_TIM5                        *(( volatile uint32_t * )(0x00000108))
#define     NVIC_SPI3                        *(( volatile uint32_t * )(0x0000010C))
#define     NVIC_DMA2_Stream0                *(( volatile uint32_t * )(0x00000120))
#define     NVIC_DMA2_Stream1                *(( volatile uint32_t * )(0x00000124))
#define     NVIC_DMA2_Stream2                *(( volatile uint32_t * )(0x00000128))
#define     NVIC_DMA2_Stream3                *(( volatile uint32_t * )(0x0000012C))
#define     NVIC_DMA2_Stream4                *(( volatile uint32_t * )(0x00000130))
#define     NVIC_OTG_FS                      *(( volatile uint32_t * )(0x0000014C))
#define     NVIC_DMA2_Stream5                *(( volatile uint32_t * )(0x00000150))
#define     NVIC_DMA2_Stream6                *(( volatile uint32_t * )(0x00000154))
#define     NVIC_DMA2_Stream7                *(( volatile uint32_t * )(0x00000158))
#define     NVIC_USART6                      *(( volatile uint32_t * )(0x0000015C))
#define     NVIC_I2C3_EV                     *(( volatile uint32_t * )(0x00000160))
#define     NVIC_I2C3_ER                     *(( volatile uint32_t * )(0x00000164))
#define     NVIC_FPU                         *(( volatile uint32_t * )(0x00000184))
#define     NVIC_SPI4                        *(( volatile uint32_t * )(0x00000190))




#endif