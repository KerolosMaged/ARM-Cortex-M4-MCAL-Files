/*========================================================
File        : DMA_PRIVATE
Description : This file contain Rgisters address of DMA functions 
Author      : Kerolos Maged Amin Fekry
Date        : 16/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct {
    
    volatile uint32_t   DMA_LISR;
    volatile uint32_t   DMA_HISR;
    volatile uint32_t   DMA_LIFCR;
    volatile uint32_t   DMA_HIFCR;
    volatile uint32_t   DMA_S0CR;
    volatile uint32_t   DMA_S0NDTR;
    volatile uint32_t   DMA_S0PAR;
    volatile uint32_t   DMA_S0M0AR;
    volatile uint32_t   DMA_S0M1AR;
    volatile uint32_t   DMA_S0FCR;
    volatile uint32_t   DMA_S1CR;
    volatile uint32_t   DMA_S1NDTR;
    volatile uint32_t   DMA_S1PAR;
    volatile uint32_t   DMA_S1M0AR;
    volatile uint32_t   DMA_S1M1AR;
    volatile uint32_t   DMA_S1FCR;
    volatile uint32_t   DMA_S2CR;
    volatile uint32_t   DMA_S2NDTR;
    volatile uint32_t   DMA_S2PAR;
    volatile uint32_t   DMA_S2M0AR;
    volatile uint32_t   DMA_S2M1AR;
    volatile uint32_t   DMA_S2FCR;
    volatile uint32_t   DMA_S3CR;
    volatile uint32_t   DMA_S3NDTR;
    volatile uint32_t   DMA_S3PAR;
    volatile uint32_t   DMA_S3M0AR;
    volatile uint32_t   DMA_S3M1AR;
    volatile uint32_t   DMA_S3FCR;
    volatile uint32_t   DMA_S4CR;
    volatile uint32_t   DMA_S4NDTR;
    volatile uint32_t   DMA_S4PAR;
    volatile uint32_t   DMA_S4M0AR;
    volatile uint32_t   DMA_S4M1AR;
    volatile uint32_t   DMA_S4FCR;
    volatile uint32_t   DMA_S5CR;
    volatile uint32_t   DMA_S5NDTR;
    volatile uint32_t   DMA_S5PAR;
    volatile uint32_t   DMA_S5M0AR;
    volatile uint32_t   DMA_S5M1AR;
    volatile uint32_t   DMA_S5FCR;
    volatile uint32_t   DMA_S6CR;
    volatile uint32_t   DMA_S6NDTR;
    volatile uint32_t   DMA_S6PAR;
    volatile uint32_t   DMA_S6M0AR;
    volatile uint32_t   DMA_S6M1AR;
    volatile uint32_t   DMA_S6FCR;
    volatile uint32_t   DMA_S7CR;
    volatile uint32_t   DMA_S7NDTR;
    volatile uint32_t   DMA_S7PAR;
    volatile uint32_t   DMA_S7M0AR;
    volatile uint32_t   DMA_S7M1AR;
    volatile uint32_t   DMA_S7FCR;

}DMA_n;

#define     DMA1    (( volatile DMA_n * )(0x40026000))
#define     DMA2    (( volatile DMA_n * )(0x40026400))

#endif