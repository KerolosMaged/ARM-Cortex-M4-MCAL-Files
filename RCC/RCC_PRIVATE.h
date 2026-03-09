/*========================================================
File        : RCC_INTERFACE
Description : This file contain Rgisters address of RCC functions 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include "../LIB/STD_TYPES_MATH.h"


/*============================= CLOCK REGISTERS =================================*/

#define     RCC_CR              *(( volatile uint32_t* )(0x40023800))
#define     RCC_CFGR            *(( volatile uint32_t* )(0x40023808))
#define     RCC_CIR             *(( volatile uint32_t* )(0x4002380C))
#define     RCC_CSR             *(( volatile uint32_t* )(0x40023874))
#define     RCC_BDCR            *(( volatile uint32_t* )(0x40023870))
#define     RCC_SSCGR           *(( volatile uint32_t* )(0x40023880))
#define     RCC_DCKCFGR         *(( volatile uint32_t* )(0x4002388C))

/*============================== PLL REGISTERS ==================================*/
#define     RCC_PLLCFGR         *(( volatile uint32_t* )(0x40023804))
#define     RCC_PLLI2SCFGR      *(( volatile uint32_t* )(0x40023884))

/*========================= AHB1 & AHB2 REGISTERS ===============================*/

#define     RCC_AHB1RSTR        *(( volatile uint32_t* )(0x40023810))
#define     RCC_AHB2RSTR        *(( volatile uint32_t* )(0x40023814))
#define     RCC_AHB1ENR         *(( volatile uint32_t* )(0x40023830))
#define     RCC_AHB2ENR         *(( volatile uint32_t* )(0x40023834))
#define     RCC_AHB1LPENR       *(( volatile uint32_t* )(0x40023850))
#define     RCC_AHB2LPENR       *(( volatile uint32_t* )(0x40023854))

/*========================= APB1 & APB2 REGISTERS ===============================*/

#define     RCC_APB1RSTR        *(( volatile uint32_t* )(0x40023820))
#define     RCC_APB2RSTR        *(( volatile uint32_t* )(0x40023824))
#define     RCC_APB1ENR         *(( volatile uint32_t* )(0x40023840))
#define     RCC_APB2ENR         *(( volatile uint32_t* )(0x40023844))
#define     RCC_APB1LPENR       *(( volatile uint32_t* )(0x40023860))
#define     RCC_APB2LPENR       *(( volatile uint32_t* )(0x40023864))

/*============================================================================== */

/*================ BITs OF RCC_CR =================*/

#define     HSION               0
#define     HSIRDY              1
#define     HSITRIM_0           3  
#define     HSITRIM_1           4
#define     HSITRIM_2           5
#define     HSITRIM_3           6
#define     HSITRIM_4           7
#define     HSICAL_0            8
#define     HSICAL_1            9
#define     HSICAL_2            10
#define     HSICAL_3            11
#define     HSICAL_4            12
#define     HSICAL_5            13
#define     HSICAL_6            14
#define     HSICAL_7            15
#define     HSEON               16
#define     HSERDY              17
#define     HSEBYP              18
#define     CSSON               19
#define     PLL_ON              24
#define     PLL_RDY             25
#define     PLL_I2SON           26
#define     PLL_I2SRDY          27 

/*==================================================*/

/*================ BITs OF RCC_PLLCFGR =================*/

#define     PLLM_0              0
#define     PLLM_1              1
#define     PLLM_2              2
#define     PLLM_3              3
#define     PLLM_4              4
#define     PLLM_5              5
#define     PLLN_0              6
#define     PLLN_1              7
#define     PLLN_2              8
#define     PLLN_3              9
#define     PLLN_4              10
#define     PLLN_5              11
#define     PLLN_6              12
#define     PLLN_7              13
#define     PLLN_8              14
#define     PLLP_0              16
#define     PLLP_1              17
#define     PLLSRC              22
#define     PLLQ_0              24 
#define     PLLQ_1              25 
#define     PLLQ_2              26 
#define     PLLQ_3              27 

/*======================================================*/

/*================= BITs of RCC_CFGR ===================*/

#define     SW_0                0
#define     SW_1                1
#define     SWS_0               2
#define     SWS_1               3
#define     HPRE_0              4
#define     HPRE_1              5
#define     HPRE_2              6
#define     HPRE_3              7
#define     PPRE1_0             10
#define     PPRE1_1             11
#define     PPRE1_2             12
#define     PPRE2_0             13
#define     PPRE2_1             14
#define     PPRE2_2             15
#define     RTCPRE_0            16
#define     RTCPRE_1            17
#define     RTCPRE_2            18
#define     RTCPRE_3            19
#define     RTCPRE_4            20
#define     MCO1_0              21
#define     MCO1_1              22
#define     I2SSRC              23
#define     MCO1PRE0            24
#define     MCO1PRE1            25
#define     MCO1PRE2            26
#define     MCO2PRE0            27
#define     MCO2PRE1            28
#define     MCO2PRE2            29
#define     MCO2_0              30
#define     MCO2_1              31


/*======================================================*/

/*================= BITs of  RCC_CIR ===================*/

#define     LSIRDYF             0    
#define     LSERDYF             1
#define     HSIRDYF             2
#define     HSERDYF             3
#define     PLLRDYF             4
#define     PLLI2SRDYF          5
#define     CSSF                7
#define     LSIRDYIE            8
#define     LSERDYIE            9
#define     HSIRDYIE            10
#define     HSERDYIE            11
#define     PLLRDYIE            12
#define     PLLI2SRDYIE         13
#define     LSIRDYC             16
#define     LSERDYC             17
#define     HSIRDYC             18
#define     HSERDYC             19
#define     PLLRDYC             20
#define     PLLI2SRDYC          21
#define     CSSC                23

/*======================================================*/


/*================= BITs of  RCC_AHB1RSTR ===================*/

#define     GPIOARST            0
#define     GPIOBRST            1
#define     GPIOCRST            2
#define     GPIODRST            3
#define     GPIOERST            4
#define     GPIOHRST            7
#define     CRCRST              12
#define     DMA1RST             21
#define     DMA2RST             22

/*===========================================================*/

/*================= BITs of  RCC_AHB2RSTR ===================*/

#define     OTGFSRS             7 

/*===========================================================*/

/*================= BITs of  RCC_APB1RSTR ===================*/

#define     TIM2RST             0
#define     TIM3RST             1
#define     TIM4RST             2
#define     TIM5RST             3
#define     WWDGRST             11
#define     SPI2RST             14
#define     SPI3RST             15
#define     USART2RST           17
#define     I2C1RST             21
#define     I2C2RST             22
#define     I2C3RST             23
#define     PWRRST              28

/*===========================================================*/

/*================= BITs of  RCC_APB2RSTR ===================*/

#define    TIM1RST              0
#define    USART1RST            4
#define    USART6RST            5
#define    ADC1RST              8
#define    SDIORST              11
#define    SPI1RST              12
#define    SP45RST              13
#define    SYSCFGRST            14
#define    TIM9RST              16
#define    TIM10RST             17
#define    TIM11RST             18
#define    SPI5RST              20    

/*===========================================================*/

/*================= BITs of  RCC_AHB1ENR ===================*/

#define    GPIOAEN              0
#define    GPIOBEN              1
#define    GPIOCEN              2
#define    GPIODEN              3
#define    GPIOEEN              4    
#define    GPIOHEN              7
#define    CRCEN                12
#define    DMA1EN               21
#define    DMA2EN               22

/*==========================================================*/

/*================= BITs of  RCC_AHB2ENR ===================*/

#define    OTGFSEN              7

/*==========================================================*/


/*================= BITs of  RCC_APB1ENR ===================*/

#define    TIM2EN               0
#define    TIM3EN               1
#define    TIM4EN               2
#define    TIM5EN               3
#define    WWDGEN               11
#define    SPI2EN               14
#define    SPI3EN               15
#define    USART2EN             17
#define    I2C1EN               21
#define    I2C2EN               22
#define    I2C3EN               23
#define    PWREN                28          

/*==========================================================*/

/*================= BITs of  RCC_APB2ENR ===================*/

#define    TIM1EN               0
#define    USART1EN             4
#define    USART6EN             5
#define    ADC1EN               8
#define    SDIOEN               11
#define    SPI1EN               12
#define    SPI4EN               13
#define    SYSCFGEN             14
#define    TIM9EN               16
#define    TIM10EN              17
#define    TIM11EN              18
#define    SPI5EN               20     

/*==========================================================*/

/*================= BITs of  RCC_AHB1LPENR ===================*/

#define    GPIOALPEN            0
#define    GPIOBLPEN            1
#define    GPIOCLPEN            2
#define    GPIODLPEN            3
#define    GPIOELPEN            4
#define    GPIOHLPEN            7
#define    CRCLPEN              12
#define    FLITFLPEN            15
#define    SRAM1LPEN            16
#define    DMA1LPEN             21
#define    DMA2LPEN             22    

/*============================================================*/

/*================= BITs of  RCC_AHB2LPENR ===================*/

#define    OTGFSLPEN            7

/*============================================================*/

/*================= BITs of  RCC_APB1LPENR ===================*/

#define    TIM2LPEN             0
#define    TIM3LPEN             1
#define    TIM4LPEN             2
#define    TIM5LPEN             3
#define    WWDGLPEN             11
#define    SPI2LPEN             14
#define    SPI3LPEN             15    
#define    USART2LPEN           17
#define    I2C1LPEN             21
#define    I2C2LPEN             22
#define    I2C3LPEN             23
#define    PWRLPEN              28


/*============================================================*/

/*================= BITs of  RCC_APB2LPENR ===================*/

#define    TIM1LPEN             0
#define    USART1LPEN           4
#define    USART6LPEN           5
#define    ADC1LPEN             8
#define    SDIOLPEN             11
#define    SPI1LPEN             12
#define    SPI4LPEN             13
#define    SYSCFGLPEN           14
#define    TIM9LPEN             16
#define    TIM10LPEN            17
#define    TIM11LPEN            18
#define    SPI5LPEN             20

/*============================================================*/

/*================= BITs of  RCC_BDCR ===================*/

#define    LSEON                0
#define    LSERDY               1
#define    LSEBYP               2
#define    LSEMOD               3
#define    RTCSEL_0             8
#define    RTCSEL_1             9
#define    RTCEN                15
#define    BDRST                16

/*=======================================================*/

/*================= BITs of  RCC_CSR ===================*/

#define    LSION                0
#define    LSIRDY               1
#define    RMVF                 24
#define    BORRSTF              25
#define    PADRSTF              26
#define    PORRSTF              27
#define    SFTRSTF              28
#define    WDGRSTF              29
#define    WWDGRSTF             30
#define    LPWRRSTF             31

/*=======================================================*/

/*================= BITs of RCC_SSCGR ===================*/

#define    MODPER               0
#define    MODPER_12            (0x1FFFU << MODPER) 
#define    INCSTEP              13
#define    INCSTEP_28           (0xFFFFU << INCSTEP)  
#define    SPREADSEL            30
#define    SSCGEN               31

/*=======================================================*/

/*================= BITs of RCC_PLLI2SCFGR ===================*/

#define    PLLI2SMx             0
#define    PLLI2SMx_5           (0x3FU << PLLI2SMx)
#define    PLLI2SNx             6
#define    PLLI2SNx_24          (0x1FFU << PLLI2SNx)
#define    PLLI2SRx             28
#define    PLLI2SRx_30          (0x7U << PLLI2SRx)

/*============================================================*/

/*================= BITs of RCC_DCKCFGR ===================*/

#define    TIMPRE               24

/*=========================================================*/

#endif



DCKCFGR