/*========================================================
File        : USART_PRIVATE
Description : This file contain Rgisters address of USART functions 
Author      : Kerolos Maged Amin Fekry
Date        : 30/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct {

    volatile uint32_t   USART_SR    ;
    volatile uint32_t   USART_DR    ;
    volatile uint32_t   USART_BRR   ;
    volatile uint32_t   USART_CR1   ;
    volatile uint32_t   USART_CR2   ;
    volatile uint32_t   USART_CR3   ;
    volatile uint32_t   USART_GTPR  ;

}USART_n;

#define USART_1     (( volatile USART_n* )( 0x40011000 ))
#define USART_2     (( volatile USART_n* )( 0x40004400 ))
#define USART_6     (( volatile USART_n* )( 0x40011400 ))


#endif