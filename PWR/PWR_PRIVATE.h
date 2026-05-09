/*========================================================
File        : PWR_PRIVATE
Description : This file contain Rgisters address of PWR  
Author      : Kerolos Maged Amin Fekry
Date        : 7/5/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef PWR_PRIVATE_H
#define PWR_PRIVATE_H

typedef struct {

    volatile uint32_t   PWR_CR;
    volatile uint32_t   PWR_CSR;

}PWR_n;

#define     PWR     ((volatile PWR_n* )(0x40007000))

#endif