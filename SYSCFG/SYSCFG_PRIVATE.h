/*========================================================
File        : SYSCFG_PRIVATE
Description : This file contain Rgisters address of SYSCFG  
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H

/*==================== SYSCFG Registers =====================*/

#define     SYSCFG_MEMRMP       *((volatile uint32_t*)(0x40013800))
#define     SYSCFG_PMC          *((volatile uint32_t*)(0x40013804))
#define     SYSCFG_EXTICR1      *((volatile uint32_t*)(0x40013808))
#define     SYSCFG_EXTICR2      *((volatile uint32_t*)(0x4001380C))
#define     SYSCFG_EXTICR3      *((volatile uint32_t*)(0x40013810))
#define     SYSCFG_EXTICR4      *((volatile uint32_t*)(0x40013814))
#define     SYSCFG_CMPCR        *((volatile uint32_t*)(0x40013820))




#endif