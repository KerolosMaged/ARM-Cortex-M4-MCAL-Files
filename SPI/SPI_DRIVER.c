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
/*=============================================================================================================================================================*/
/*======================================================================== FULL DUPLEX ========================================================================*/
/*=============================================================================================================================================================*/


/*=========================================================================*/
/*============================= SLAVE MODE ================================*/
/*=========================================================================*/


/*=================== Inialization of Slave mode ===================*/

void SPI_SlaveInit(SPI_n*SPI_x ,FRAME_LEN Copy_LEN,CLK_PHA Copy_PHA, CLK_POL Copy_POL,FRAME_FORMAT Copy_Format,SLAVE_SEL Copy_SS,uint8_t Copy_TI_M){
    
    /*----- Clear old setting ------*/
    SPI_x->SPI_CR1 = 0;
    SPI_x->SPI_CR2 = 0;

    /*-------- Selection of the frame length --------*/
    SPI_x->SPI_CR1 |= ( Copy_LEN << 11 );
    /*----- Selection of the phase and polarity -----*/
    SPI_x->SPI_CR1 |= ( Copy_PHA << 0 );    // Phase
    SPI_x->SPI_CR1 |= ( Copy_POL << 1 );    // Polarity

    /*------- Selection of the Frame format --------*/
    SPI_x->SPI_CR1 |= ( Copy_Format << 7 ); 
    
    /*------ Selection of Slave ------*/

    switch (Copy_SS)
    {
        case SW:
            SET_BIT(SPI_x->SPI_CR1, 9);              
            CLEAR_BIT(SPI_x->SPI_CR1, 8);        
        break;
    
        case HW:
            CLEAR_BIT(SPI_x->SPI_CR1, 9);            

        break;
    
        default: break;
    }
   

    /*------- Selection of TI MODE ------*/
    SPI_x->SPI_CR2 |= ( Copy_TI_M << 4 ); // here to select put ENABLE

   CLEAR_BIT( SPI_x->SPI_CR1 , 2 );  //Disable master
   SET_BIT( SPI_x->SPI_CR1 , 6 );    // Enable SPI


}

/*=================== Transive of Slave mode ===================*/

uint16_t SPI_SlaveTransive(SPI_n *SPI_x, uint16_t Copy_Data){

    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);   /* wait until TX buffer empty */
    SPI_x->SPI_DR = Copy_Data;                          /* preload; sent when master clocks */

    while (GET_BIT(SPI_x->SPI_SR, 0) == 0);   /* wait for received data */
    return (uint16_t)SPI_x->SPI_DR;                     /* read clears RXNE */
}

/*=================== Trasmitter of Slave mode ===================*/

/*------------------ Transmitting for char ------------------- */
void SPI_SlaveTXChar(SPI_n *SPI_x, uint16_t Copy_Data)
{
    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);   /* wait until TX buffer empty */
    SPI_x->SPI_DR = Copy_Data;                          /* preload; sent when master clocks */
}


/*------------------ Transmitting for string ------------------- */
void SPI_SlaveTXString( SPI_n *SPI_x, uint8_t *Copy_data ){
    uint32_t i=0;
    while (Copy_data[i] != '\0')
    {
        SPI_SlaveTXChar(SPI_x,Copy_data[i]);
        i++;
    }
    
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


void SPI_MasterInit(SPI_n*SPI_x ,BR_N Copy_N,FRAME_LEN Copy_LEN,CLK_PHA Copy_PHA, CLK_POL Copy_POL,FRAME_FORMAT Copy_Format,SLAVE_SEL Copy_SS,uint8_t Copy_TI_M){

    /*----- Clear old setting ------*/
    SPI_x->SPI_CR1 = 0;
    SPI_x->SPI_CR2 = 0;

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

    switch (Copy_SS)
    {
        case SW:
            SET_BIT(SPI_x->SPI_CR1, 9);              
            SET_BIT(SPI_x->SPI_CR1, 8);         
        break;

        case HW:
            CLEAR_BIT(SPI_x->SPI_CR1, 9);        
            SET_BIT(SPI_x->SPI_CR2, 2);          
        break;

        default: break;
    }
    
    /*------- Selection of TI MODE ------*/
    SPI_x->SPI_CR2 |= ( Copy_TI_M << 4 ); // here to select put ENABLE

   SET_BIT( SPI_x->SPI_CR1 , 2 );  //Enable master
   SET_BIT( SPI_x->SPI_CR1 , 6 );    // Enable SPI
}

/*=================== Transive of Master mode ===================*/

uint16_t SPI_MasterTransive(SPI_n *SPI_x, uint16_t Copy_Data){

    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);   /* wait until TX buffer empty */
    SPI_x->SPI_DR = Copy_Data;                          /* preload; sent when master clocks */

    while (GET_BIT(SPI_x->SPI_SR, 0) == 0);   /* wait for received data */
    return (uint16_t)SPI_x->SPI_DR;                     /* read clears RXNE */
}

/*=================== Trasmitter of Master mode ===================*/

/*------------------ Transmitting for char ------------------- */
void SPI_MasterTXChar(SPI_n *SPI_x, uint16_t Copy_Data)
{
    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);   /* wait until TX buffer empty */
    SPI_x->SPI_DR = Copy_Data;                          /* preload; sent when master clocks */
}


/*------------------ Transmitting for string ------------------- */
void SPI_MasterTXString( SPI_n *SPI_x, uint8_t *Copy_data ){
    uint32_t i=0;
    while (Copy_data[i] != '\0')
    {
        SPI_MasterTXChar(SPI_x,Copy_data[i]);
        i++;
    }
    
}


/*=================== Reciver of Master mode ===================*/

uint16_t SPI_MasterRX(SPI_n *SPI_x)
{
    while (GET_BIT(SPI_x->SPI_SR, 0) == 0);   /* wait for received data */
    return (uint16_t)SPI_x->SPI_DR;                     /* read clears RXNE */
}

/*=============================================================================================================================================================*/
/*======================================================================== HALF DUPLEX ========================================================================*/
/*=============================================================================================================================================================*/

/*=========================================================================*/
/*============================= SLAVE MODE ================================*/
/*=========================================================================*/

/*=================== Inialization of Slave mode ===================*/

void SPI_SlaveHalfInit(SPI_n*SPI_x ,FRAME_LEN Copy_LEN,CLK_PHA Copy_PHA, CLK_POL Copy_POL,FRAME_FORMAT Copy_Format,SLAVE_SEL Copy_SS,uint8_t Copy_TI_M,SPI_DIR Copy_DIR){

    /*----- Clear old setting ------*/
    SPI_x->SPI_CR1 = 0;
    SPI_x->SPI_CR2 = 0;

    /*-------- Selection of the frame length --------*/
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_LEN << 11 );
    /*----- Selection of the phase and polarity -----*/
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_PHA << 0 );    // Phase
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_POL << 1 );    // Polarity
    /*------- Selection of the Frame format --------*/
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_Format << 7 );

    /*------ Selection of Slave ------*/
    switch (Copy_SS)
    {
        case SW:
            SET_BIT(SPI_x->SPI_CR1, 9);
            CLEAR_BIT(SPI_x->SPI_CR1, 8);
        break;

        case HW:
            CLEAR_BIT(SPI_x->SPI_CR1, 9);
        break;

        default: break;
    }

    /*------- Selection of TI MODE ------*/
    SPI_x->SPI_CR2 |= ( (uint32_t)(Copy_TI_M & 1U) << 4 );

    /*------- Half duplex : 1-line bidirectional -------*/
    SET_BIT( SPI_x->SPI_CR1 , 15 );                  // BIDIMODE = 1
    if (Copy_DIR == SPI_DIR_TX)  SET_BIT( SPI_x->SPI_CR1 , 14 );     // BIDIOE = 1 (TX)
    else                         CLEAR_BIT( SPI_x->SPI_CR1 , 14 );   // BIDIOE = 0 (RX)

    CLEAR_BIT( SPI_x->SPI_CR1 , 2 );  //Disable master
    SET_BIT( SPI_x->SPI_CR1 , 6 );    // Enable SPI
}

/*=================== Trasmitter of Slave mode ===================*/

/*------------------ Transmitting for char ------------------- */
void SPI_SlaveHalfTXChar(SPI_n *SPI_x, uint16_t Copy_Data)
{
    SET_BIT(SPI_x->SPI_CR1, 14);                 /* BIDIOE = 1 : transmit mode */
    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);      /* wait until TX buffer empty */
    SPI_x->SPI_DR = Copy_Data;                   /* preload; sent when master clocks */
}

/*------------------ Transmitting for string ------------------- */
void SPI_SlaveHalfTXString(SPI_n *SPI_x, uint8_t *Copy_data)
{
    uint32_t i = 0;
    while (Copy_data[i] != '\0')
    {
        SPI_SlaveHalfTXChar(SPI_x, Copy_data[i]);
        i++;
    }
}

/*=================== Reciver of Slave mode ===================*/

uint16_t SPI_SlaveHalfRX(SPI_n *SPI_x)
{
    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);      /* wait last TX finished (TXE = 1) */
    while (GET_BIT(SPI_x->SPI_SR, 7) == 1);      /* wait BSY = 0 before changing direction */
    CLEAR_BIT(SPI_x->SPI_CR1, 14);               /* BIDIOE = 0 : receive mode */

    while (GET_BIT(SPI_x->SPI_SR, 0) == 0);      /* wait for received data */
    return (uint16_t)SPI_x->SPI_DR;              /* read clears RXNE */
}


/*===========================================================================*/
/*============================= Maseter MODE ================================*/
/*===========================================================================*/

/*=================== Inialization of Master mode ===================*/

void SPI_MasterHalfInit(SPI_n*SPI_x ,BR_N Copy_N,FRAME_LEN Copy_LEN,CLK_PHA Copy_PHA, CLK_POL Copy_POL,FRAME_FORMAT Copy_Format,SLAVE_SEL Copy_SS,uint8_t Copy_TI_M){

    /*----- Clear old setting ------*/
    SPI_x->SPI_CR1 = 0;
    SPI_x->SPI_CR2 = 0;

    /*----- Set the baud rate prescaler -----*/
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_N << 3 );
    /*----- Selection of the phase and polarity -----*/
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_PHA << 0 );    // Phase
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_POL << 1 );    // Polarity
    /*-------- Selection of the frame length --------*/
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_LEN << 11 );
    /*------- Selection of the Frame format --------*/
    SPI_x->SPI_CR1 |= ( (uint32_t)Copy_Format << 7 );

    /*------ Selection of Slave ------*/
    switch (Copy_SS)
    {
        case SW:
            SET_BIT(SPI_x->SPI_CR1, 9);
            SET_BIT(SPI_x->SPI_CR1, 8);
        break;

        case HW:
            CLEAR_BIT(SPI_x->SPI_CR1, 9);
            SET_BIT(SPI_x->SPI_CR2, 2);
        break;

        default: break;
    }

    /*------- Selection of TI MODE ------*/
    SPI_x->SPI_CR2 |= ( (uint32_t)(Copy_TI_M & 1U) << 4 );

    /*------- Half duplex : 1-line bidirectional -------*/
    SET_BIT( SPI_x->SPI_CR1 , 15 );   // BIDIMODE = 1
    SET_BIT( SPI_x->SPI_CR1 , 2 );    // Enable master

    /* SPE is NOT set here: in RX direction the master starts the clock as soon as SPE = 1,
       so SPE is enabled inside the TX / RX functions. */
}

/*=================== Trasmitter of Master mode ===================*/

/*------------------ Transmitting for char ------------------- */
void SPI_MasterHalfTXChar(SPI_n *SPI_x, uint16_t Copy_Data)
{
    SET_BIT(SPI_x->SPI_CR1, 14);                 /* BIDIOE = 1 : transmit mode */
    SET_BIT(SPI_x->SPI_CR1, 6);                  /* SPE = 1 */

    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);      /* wait until TX buffer empty */
    SPI_x->SPI_DR = Copy_Data;

    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);      /* wait TXE = 1 */
    while (GET_BIT(SPI_x->SPI_SR, 7) == 1);      /* wait BSY = 0 (last bit shifted out) */
}

/*------------------ Transmitting for string ------------------- */
void SPI_MasterHalfTXString(SPI_n *SPI_x, uint8_t *Copy_data)
{
    uint32_t i = 0;

    SET_BIT(SPI_x->SPI_CR1, 14);                 /* BIDIOE = 1 : transmit mode */
    SET_BIT(SPI_x->SPI_CR1, 6);                  /* SPE = 1 */

    while (Copy_data[i] != '\0')
    {
        while (GET_BIT(SPI_x->SPI_SR, 1) == 0);  /* wait until TX buffer empty */
        SPI_x->SPI_DR = Copy_data[i];
        i++;
    }

    while (GET_BIT(SPI_x->SPI_SR, 1) == 0);      /* wait TXE = 1 */
    while (GET_BIT(SPI_x->SPI_SR, 7) == 1);      /* wait BSY = 0 */
}

/*=================== Reciver of Master mode ===================*/

uint16_t SPI_MasterHalfRX(SPI_n *SPI_x)
{
    uint16_t Local_Data;

    CLEAR_BIT(SPI_x->SPI_CR1, 6);                /* SPE = 0 : safe to change direction */
    CLEAR_BIT(SPI_x->SPI_CR1, 14);               /* BIDIOE = 0 : receive mode */

    SET_BIT(SPI_x->SPI_CR1, 6);                  /* SPE = 1 : master starts the clock */
    CLEAR_BIT(SPI_x->SPI_CR1, 6);                /* SPE = 0 : stop after the current frame */

    while (GET_BIT(SPI_x->SPI_SR, 0) == 0);      /* wait for received data */
    Local_Data = (uint16_t)SPI_x->SPI_DR;        /* read clears RXNE */

    while (GET_BIT(SPI_x->SPI_SR, 7) == 1);      /* wait BSY = 0 */
    return Local_Data;
}




