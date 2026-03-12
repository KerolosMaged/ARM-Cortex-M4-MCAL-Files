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


#define     NIVC_Reset                       *(( volatile uint32_t * )(0x00000004))
#define     NIVC_NMI                         *(( volatile uint32_t * )(0x00000008))
#define     NIVC_HardFault                   *(( volatile uint32_t * )(0x0000000C))
#define     NIVC_MemManage                   *(( volatile uint32_t * )(0x00000010))
#define     NIVC_BusFault                    *(( volatile uint32_t * )(0x00000014))
#define     NIVC_UsageFault                  *(( volatile uint32_t * )(0x00000018))
#define     NIVC_SVCall                      *(( volatile uint32_t * )(0x0000002C))
#define     NIVC_Debug_Monito                *(( volatile uint32_t * )(0x00000030))
#define     NIVC_PendSV                      *(( volatile uint32_t * )(0x00000038))
#define     NIVC_Systick                     *(( volatile uint32_t * )(0x0000003C))
#define     NIVC_WWDG                        *(( volatile uint32_t * )(0x00000040))
#define     NIVC_EXTI16_PVD                  *(( volatile uint32_t * )(0x00000044))
#define     NIVC_EXTI21__TAMP_STAMP          *(( volatile uint32_t * )(0x00000048))
#define     NIVC_EXTI22__RTC_WKUP            *(( volatile uint32_t * )(0x0000004C))
#define     NIVC_FLASH                       *(( volatile uint32_t * )(0x00000050))
#define     NIVC_RCC                         *(( volatile uint32_t * )(0x00000054))
#define     NIVC_EXTI0                       *(( volatile uint32_t * )(0x00000058))
#define     NIVC_EXTI1                       *(( volatile uint32_t * )(0x0000005C))
#define     NIVC_EXTI2                       *(( volatile uint32_t * )(0x00000060))
#define     NIVC_EXTI3                       *(( volatile uint32_t * )(0x00000064))
#define     NIVC_EXTI4                       *(( volatile uint32_t * )(0x00000068))
#define     NIVC_DMA1_Stream0                *(( volatile uint32_t * )(0x0000006C))
#define     NIVC_DMA1_Stream1                *(( volatile uint32_t * )(0x00000070))
#define     NIVC_DMA1_Stream2                *(( volatile uint32_t * )(0x00000074))
#define     NIVC_DMA1_Stream3                *(( volatile uint32_t * )(0x00000078))
#define     NIVC_DMA1_Stream4                *(( volatile uint32_t * )(0x0000007C))
#define     NIVC_DMA1_Stream5                *(( volatile uint32_t * )(0x00000080))
#define     NIVC_DMA1_Stream6                *(( volatile uint32_t * )(0x00000084))
#define     NIVC_ADC                         *(( volatile uint32_t * )(0x00000088))
#define     NIVC_EXTI9_5                     *(( volatile uint32_t * )(0x0000009C))
#define     NIVC_TIM1_BRK_TIM9               *(( volatile uint32_t * )(0x000000A0))
#define     NIVC_TIM1_UP_TIM10               *(( volatile uint32_t * )(0x000000A4))
#define     NIVC_TIM1_TRG_COM_TIM11          *(( volatile uint32_t * )(0x000000A8))
#define     NIVC_TIM1_CC                     *(( volatile uint32_t * )(0x000000AC))
#define     NIVC_TIM2                        *(( volatile uint32_t * )(0x000000B0))
#define     NIVC_TIM3                        *(( volatile uint32_t * )(0x000000B4))
#define     NIVC_TIM4                        *(( volatile uint32_t * )(0x000000B8))
#define     NIVC_I2C1_EV                     *(( volatile uint32_t * )(0x000000BC))
#define     NIVC_I2C1_ER                     *(( volatile uint32_t * )(0x000000C0))
#define     NIVC_I2C2_EV                     *(( volatile uint32_t * )(0x000000C4))
#define     NIVC_I2C2_ER                     *(( volatile uint32_t * )(0x000000C8))
#define     NIVC_SPI1                        *(( volatile uint32_t * )(0x000000CC))
#define     NIVC_SPI2                        *(( volatile uint32_t * )(0x000000D0))
#define     NIVC_USART1                      *(( volatile uint32_t * )(0x000000D4))
#define     NIVC_USART2                      *(( volatile uint32_t * )(0x000000D8))
#define     NIVC_EXTI15_10                   *(( volatile uint32_t * )(0x000000E0))
#define     NIVC_EXTI17__RTC_Alarm           *(( volatile uint32_t * )(0x000000E4))
#define     NIVC_EXTI18__OTG_FS_WKUP         *(( volatile uint32_t * )(0x000000E8))
#define     NIVC_DMA1_Stream7                *(( volatile uint32_t * )(0x000000FC))
#define     NIVC_SDIO                        *(( volatile uint32_t * )(0x00000104))
#define     NIVC_TIM5                        *(( volatile uint32_t * )(0x00000108))
#define     NIVC_SPI3                        *(( volatile uint32_t * )(0x0000010C))
#define     NIVC_DMA2_Stream0                *(( volatile uint32_t * )(0x00000120))
#define     NIVC_DMA2_Stream1                *(( volatile uint32_t * )(0x00000124))
#define     NIVC_DMA2_Stream2                *(( volatile uint32_t * )(0x00000128))
#define     NIVC_DMA2_Stream3                *(( volatile uint32_t * )(0x0000012C))
#define     NIVC_DMA2_Stream4                *(( volatile uint32_t * )(0x00000130))
#define     NIVC_OTG_FS                      *(( volatile uint32_t * )(0x0000014C))
#define     NIVC_DMA2_Stream5                *(( volatile uint32_t * )(0x00000150))
#define     NIVC_DMA2_Stream6                *(( volatile uint32_t * )(0x00000154))
#define     NIVC_DMA2_Stream7                *(( volatile uint32_t * )(0x00000158))
#define     NIVC_USART6                      *(( volatile uint32_t * )(0x0000015C))
#define     NIVC_I2C3_EV                     *(( volatile uint32_t * )(0x00000160))
#define     NIVC_I2C3_ER                     *(( volatile uint32_t * )(0x00000164))
#define     NIVC_FPU                         *(( volatile uint32_t * )(0x00000184))
#define     NIVC_SPI4                        *(( volatile uint32_t * )(0x00000190))




#endif