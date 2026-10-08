/*========================================================
File        : SPI_INTERFACE
Description : This file contain the definetions of SPI functions and source file of SPI
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
/*********** Include of SPI files  **********/
#include "SPI_PRIVATE.h"
#include "SPI_CONFGR.h"
#include "SPI_INTERFACE.h"



/*===========================================================================*/
/*========================== Intialtization of SPI ==========================*/
/*===========================================================================*/

void SPI_Init(uint32_t SPI_x){

    if (SPI_x == SPI_1){
    
        RCC_VoidStatusPeripheral_CLK( RCC_APB2 , SPI1EN , ENABLE);

    }

    else if(SPI_x == SPI_2){

        RCC_VoidStatusPeripheral_CLK( RCC_APB1 , SPI2EN , ENABLE);

    } 

    else if(SPI_x == SPI_3){

        RCC_VoidStatusPeripheral_CLK( RCC_APB1 , SPI3EN , ENABLE);

    } 

    else if(SPI_x == SPI_4){

        RCC_VoidStatusPeripheral_CLK( RCC_APB2 , SPI4EN , ENABLE);

    } 
    
    
}


/*=========================================================================*/
/*============================= SLAVE MODE ================================*/
/*=========================================================================*/


/*=================== Inialization of Slave mode ===================*/

void SPI_SlaveInit(SPI_n*SPI_x ,FRAME_LEN Copy_LEN,CLK_PHA Copy_PHA, CLK_POL Copy_POL,FRAME_FORMAT Copy_Format,SLAVE_SEL Copy_SS,uint8_t Copy_TI_M){

    /*-------- Selection of the frame length --------*/
    SPI_x->SPI_CR1 |= ( Copy_LEN << 11 );
    /*----- Selection of the phase and polarity -----*/
    SPI_x->SPI_CR1 |= ( Copy_PHA << 0 );    // Phase
    SPI_x->SPI_CR1 |= ( Copy_POL << 1 );    // Polarity

    /*------- Selection of the Frame format --------*/
    SPI_x->SPI_CR1 |= ( Copy_Format << 7 ); 
    
    /*------ Selection of Slave ------*/
    SPI_x->SPI_CR1 |= ( Copy_SS << 9 ); 

    /*------- Selection of TI MODE ------*/
    SPI_x->SPI_CR2 |= ( Copy_TI_M << 4 ); // here to select put ENABLE

   CLEAR_BIT( SPI_x->SPI_CR1 , 2 );  //Disable master
   SET_BIT( SPI_x->SPI_CR2 , 6 );    // Enable SPI


}

/*=================== Transive of Slave mode ===================*/

uint16_t SPI_SlaveTransive(SPI_n *SPI_x, uint16_t Copy_Data){

    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);   /* wait until TX buffer empty */
    SPI_x->SPI_DR = Copy_Data;                          /* preload; sent when master clocks */

    while (GET_BIT(SPI_x->SPI_SR, 0) == 0);   /* wait for received data */
    return (uint16_t)SPI_x->SPI_DR;                     /* read clears RXNE */
}

/*=================== Trasmitter of Slave mode ===================*/

void SPI_SlaveTX(SPI_n *SPI_x, uint16_t Copy_Data)
{
    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);   /* wait until TX buffer empty */
    SPI_x->SPI_DR = Copy_Data;                          /* preload; sent when master clocks */
}

/*=================== Reciver of Slave mode ===================*/

uint16_t SPI_SlaveRX(SPI_n *SPI_x)
{
    while (GET_BIT(SPI_x->SPI_SR, 0) == 0);   /* wait for received data */
    return (uint16_t)SPI_x->SPI_DR;                     /* read clears RXNE */
}


/*===========================================================================*/
/*============================= Maseter MODE ================================*/
/*===========================================================================*/


void SPI_MaseterInit(SPI_n*SPI_x ,BR_N Copy_N,FRAME_LEN Copy_LEN,CLK_PHA Copy_PHA, CLK_POL Copy_POL,FRAME_FORMAT Copy_Format,SLAVE_SEL Copy_SS,uint8_t Copy_TI_M){
    /*----- Set the baud rate prescaler -----*/
    SPI_x->SPI_CR1 |= (Copy_N << 3);

    /*----- Selection of the phase and polarity -----*/
    SPI_x->SPI_CR1 |= ( Copy_PHA << 0 );    // Phase
    SPI_x->SPI_CR1 |= ( Copy_POL << 1 );    // Polarity
    /*-------- Selection of the frame length --------*/
    SPI_x->SPI_CR1 |= ( Copy_LEN << 11 );
    /*------- Selection of the Frame format --------*/
    SPI_x->SPI_CR1 |= ( Copy_Format << 7 ); 

    /*------ Selection of Slave ------*/
    SPI_x->SPI_CR1 |= ( Copy_SS << 9 ); 

    /*------- Selection of TI MODE ------*/
    SPI_x->SPI_CR2 |= ( Copy_TI_M << 4 ); // here to select put ENABLE

   SET_BIT( SPI_x->SPI_CR1 , 2 );  //Enable master
   SET_BIT( SPI_x->SPI_CR2 , 6 );    // Enable SPI
}