/*========================================================
File        : USART_INTERFACE
Description : This file contain the definetions of USART functions and source file of USART
Author      : Kerolos Maged Amin Fekry
Date        : 30/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/

/********** Include STD_TYPES_MATH file ***********/
#include "../LIB/STD_TYPES_MATH.h"
/*********** Include of RCC files  **********/
#include "../RCC/RCC_CONFGR.h"
#include "../RCC/RCC_INTERFACE.h"
#include "../RCC/RCC_PRIVATE.h"
/*********** Include of NVIC files  **********/
#include "../NVIC/NVIC_CONFGR.h"
#include "../NVIC/NVIC_INTERFACE.h"
#include "../NVIC/NVIC_PRIVATE.h"
/*********** Include of SYSCFG files  **********/
#include "../SYSCFG/SYSCFG_CONFGR.h"
#include "../SYSCFG/SYSCFG_INTERFACE.h"
#include "../SYSCFG/SYSCFG_PRIVATE.h"
/*********** Include of USART files  **********/
#include "USART_CONFGR.h"
#include "USART_INTERFACE.h"
#include "USART_PRIVATE.h"

static uint32_t TIM_CLK = 0 ;


/*==================== Initialization of USART ==================*/

void USART_INIT(uint32_t CopyUsart , uint32_t Copy_Clock ){
    /*------- Enable specific RCC clock for each usart --------*/
    if (CopyUsart == USART_1)
    {
        RCC_VoidStatusPeripheral_CLK( RCC_APB2ENR , USART1EN , ENABLE);
    }
    else if(CopyUsart == USART_2)
    {
        RCC_VoidStatusPeripheral_CLK( RCC_APB1ENR , USART2EN , ENABLE);
    }
    else if(CopyUsart == USART_6)
    {
        RCC_VoidStatusPeripheral_CLK( RCC_APB2ENR , USART6EN , ENABLE);
    }
    /*--- Set clock for usart ---*/
    TIM_CLK = Copy_Clock;
}

/*====================== Set the Baud Rate Value =======================*/

void USART_SetBaudRate( USART_n *USART_x  , uint32_t Copy_BR){
    /*--- clear OVER8 bit to make it for 16 ---*/
    CLEAR_BIT( USART_x->USART_CR1 , 15 );
    uint32_t USARTDIV_x100 = (25*TIM_CLK)/(4*Copy_BR);  // transfer the baud rate to value in mantissa and fraction
    uint32_t DIV_Mantissa  = (USARTDIV_x100/100); // is the real part 
    uint32_t DIV_Fraction  = ((USARTDIV_x100 - (DIV_Mantissa * 100)) * 16 + 50) / 100;  // is the fraction part
    USART_x->USART_BRR     = (DIV_Mantissa << 4) | (DIV_Fraction & 0xF);    // the value for confgr the baud rate in BRR register
}

/*===================================================================================================*/
/*============================================ Async USART ==========================================*/
/*===================================================================================================*/

/*====================== Transmiter Async Intialization ==========================*/

void USART_AsyncTX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR  ){

    /*---- Enable USART ----*/
    SET_BIT(USART_x->USART_CR1,13);
    /*---- Select the number of bits ----*/
    USART_x->USART_CR1 |= (LENGTH_x<<12);
    /*---- Select the number of stop bits ----*/
    USART_x->USART_CR2 |= (STOP_x<<12);
    /*---- Set the parity ----*/
    if (PARITY_x != PARITY_NONE){
        SET_BIT(USART_x->USART_CR1,10);
        if(PARITY_x == PARITY_ODD){
            SET_BIT(USART_x->USART_CR1,9);
        }
        else {
            CLEAR_BIT(USART_x->USART_CR1,9);
        }
    }
    /*--------- Set the Baud Rate Value ---------*/
    
    USART_SetBaudRate(USART_x,Copy_BR);
    
    /*---- Send the idle ----*/
    SET_BIT(USART_x->USART_CR1,3);
}

/*========================= Sending the data ===========================*/
void USART_AsyncTX_Send( USART_n *USART_x ,uint16_t Copy_data ){
    /*---- send the data for register ----*/
    USART_x->USART_DR = Copy_data ;
    while(GET_BIT(USART_x->USART_SR,6)!=0); // Wait for ths Transmiting complete
}

/*====================== Reciver Async Intialization ==========================*/

void USART_AsyncRX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR  ){

    /*---- Enable USART ----*/
    SET_BIT(USART_x->USART_CR1,13);
    /*---- Select the number of bits ----*/
    USART_x->USART_CR1 |= (LENGTH_x<<12);
    /*---- Select the number of stop bits ----*/
    USART_x->USART_CR2 |= (STOP_x<<12);
    /*---- Set the parity ----*/
    if (PARITY_x != PARITY_NONE){
        SET_BIT(USART_x->USART_CR1,10);
        if(PARITY_x == PARITY_ODD){
            SET_BIT(USART_x->USART_CR1,9);
        }
        else {
            CLEAR_BIT(USART_x->USART_CR1,9);
        }
    }
    /*--------- Set the Baud Rate Value ---------*/

    USART_SetBaudRate(USART_x,Copy_BR);
    
    /*---- Send the idle ----*/
    SET_BIT(USART_x->USART_CR1,2);
}

/*========================= Reciving the data ===========================*/

uint16_t USART_AsyncRX_Read( USART_n *USART_x ){

    while(GET_BIT(USART_x->USART_SR,5)==0); // Wait for ready to recive
    return  (uint16_t)USART_x->USART_DR; // read the data into the register
}
