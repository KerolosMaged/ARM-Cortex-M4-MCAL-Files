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

/*********** Include of GPIO files  **********/
#include "../GPIO/GPIO_INTERFACE.h"

/*********** Include of SPI files  **********/
#include "SPI_PRIVATE.h"
#include "SPI_CONFGR.h"
#include "SPI_INTERFACE.h"

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      SPI      $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/


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



void PIN_ACCESS_SPI(uint8_t Copy_port, uint8_t Copy_pin){
    GPIO_Init_Def SPI_PIN;
    SPI_PIN.PIN   = Copy_pin;
    SPI_PIN.MODE  = AF;
    SPI_PIN.OTYPE = OUTPUT_PP;
    SPI_PIN.SPEED = HIGH_SPEED;
    SPI_PIN.PULL  = NO_PULL;
    SPI_PIN.AFR   = 5;            /* AF5 = SPI1/SPI2 */
    GPIO_Init(Copy_port, &SPI_PIN);
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



/*=============================================================================================================================================================*/
/*======================================================================= STATUS FLAGS ========================================================================*/
/*=============================================================================================================================================================*/

uint8_t SPI_GetFlag(SPI_n *SPI_x, SPI_FLAG Copy_Flag)
{
    return (uint8_t)GET_BIT(SPI_x->SPI_SR, Copy_Flag);
}

uint8_t SPI_IsBusy(SPI_n *SPI_x)
{
    return (uint8_t)GET_BIT(SPI_x->SPI_SR, SPI_FLAG_BSY);
}

/*=============================================================================================================================================================*/
/*====================================================================== ERROR FLAGS ==========================================================================*/
/*=============================================================================================================================================================*/

/*------------------ Overrun : read DR then SR ------------------- */
void SPI_ClearOVR(SPI_n *SPI_x)
{
    volatile uint32_t Local_Tmp;
    Local_Tmp = SPI_x->SPI_DR;
    Local_Tmp = SPI_x->SPI_SR;
    (void)Local_Tmp;
}

/*------------------ Mode fault : read SR then write CR1 ------------------- */
/* Hardware clears SPE and MSTR on MODF, so call SPI_MasterInit again after this */
void SPI_ClearMODF(SPI_n *SPI_x)
{
    volatile uint32_t Local_Tmp;
    Local_Tmp = SPI_x->SPI_SR;
    (void)Local_Tmp;
    SPI_x->SPI_CR1 = SPI_x->SPI_CR1;
}

/*------------------ CRC error : write 0 to the flag ------------------- */
void SPI_ClearCRCERR(SPI_n *SPI_x)
{
    CLEAR_BIT(SPI_x->SPI_SR, SPI_FLAG_CRCERR);
}

/*------------------ Frame format error (TI mode) : read SR ------------------- */
void SPI_ClearFRE(SPI_n *SPI_x)
{
    volatile uint32_t Local_Tmp;
    Local_Tmp = SPI_x->SPI_SR;
    (void)Local_Tmp;
}

/*------------------ Get all error flags (0 = no error) ------------------- */
uint32_t SPI_GetErrors(SPI_n *SPI_x)
{
    return ( SPI_x->SPI_SR & SPI_ERR_MASK );
}

/*=============================================================================================================================================================*/
/*============================================================= DATA TRANSMISSION AND RECEPTION PROCEDURES ====================================================*/
/*=============================================================================================================================================================*/

/*=================== Full duplex buffers ===================*/

/*------------------ Master : transmit and receive buffer ------------------- */
void SPI_MasterTransiveBuffer(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len)
{
    uint32_t i;
    for (i = 0; i < Copy_Len; i++)
    {
        Copy_RX[i] = (uint8_t)SPI_MasterTransive(SPI_x, Copy_TX[i]);
    }
    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_BSY) == 1);     /* wait last frame finished */
}

/*------------------ Master : transmit only buffer ------------------- */
void SPI_MasterTXBuffer(SPI_n *SPI_x, uint8_t *Copy_TX, uint32_t Copy_Len)
{
    uint32_t i;
    for (i = 0; i < Copy_Len; i++)
    {
        SPI_MasterTXChar(SPI_x, Copy_TX[i]);
    }
    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_TXE) == 0);     /* wait TXE = 1 */
    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_BSY) == 1);     /* wait BSY = 0 */
    SPI_ClearOVR(SPI_x);                                   /* received bytes are ignored */
}

/*------------------ Master : receive only buffer (sends dummy bytes) ------------------- */
void SPI_MasterRXBuffer(SPI_n *SPI_x, uint8_t *Copy_RX, uint32_t Copy_Len, uint8_t Copy_Dummy)
{
    uint32_t i;
    for (i = 0; i < Copy_Len; i++)
    {
        Copy_RX[i] = (uint8_t)SPI_MasterTransive(SPI_x, Copy_Dummy);
    }
    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_BSY) == 1);
}

/*------------------ Slave : transmit and receive buffer ------------------- */
void SPI_SlaveTransiveBuffer(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len)
{
    uint32_t i;
    for (i = 0; i < Copy_Len; i++)
    {
        Copy_RX[i] = (uint8_t)SPI_SlaveTransive(SPI_x, Copy_TX[i]);
    }
}

/*------------------ Slave : transmit only buffer ------------------- */
void SPI_SlaveTXBuffer(SPI_n *SPI_x, uint8_t *Copy_TX, uint32_t Copy_Len)
{
    uint32_t i;
    for (i = 0; i < Copy_Len; i++)
    {
        (void)SPI_SlaveTransive(SPI_x, Copy_TX[i]);        /* read back to avoid OVR */
    }
}

/*------------------ Slave : receive only buffer ------------------- */
void SPI_SlaveRXBuffer(SPI_n *SPI_x, uint8_t *Copy_RX, uint32_t Copy_Len)
{
    uint32_t i;
    for (i = 0; i < Copy_Len; i++)
    {
        Copy_RX[i] = (uint8_t)SPI_SlaveRX(SPI_x);
    }
}

/*=================== Half duplex buffers ===================*/

/*------------------ Master : receive buffer ------------------- */
/* Follows the RM procedure: clear SPE after the second-last RXNE so that exactly Len frames are clocked */
void SPI_MasterHalfRXBuffer(SPI_n *SPI_x, uint8_t *Copy_RX, uint32_t Copy_Len)
{
    uint32_t i;

    if (Copy_Len == 0) return;

    CLEAR_BIT(SPI_x->SPI_CR1, 6);                          /* SPE = 0 */
    CLEAR_BIT(SPI_x->SPI_CR1, 14);                         /* BIDIOE = 0 : receive mode */
    SET_BIT(SPI_x->SPI_CR1, 6);                            /* SPE = 1 : master starts the clock */

    for (i = 0; i < (Copy_Len - 1); i++)
    {
        while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_RXNE) == 0);
        Copy_RX[i] = (uint8_t)SPI_x->SPI_DR;
    }

    CLEAR_BIT(SPI_x->SPI_CR1, 6);                          /* SPE = 0 : last frame is the one in progress */

    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_RXNE) == 0);
    Copy_RX[i] = (uint8_t)SPI_x->SPI_DR;

    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_BSY) == 1);
}

/*------------------ Slave : receive buffer ------------------- */
void SPI_SlaveHalfRXBuffer(SPI_n *SPI_x, uint8_t *Copy_RX, uint32_t Copy_Len)
{
    uint32_t i;
    for (i = 0; i < Copy_Len; i++)
    {
        Copy_RX[i] = (uint8_t)SPI_SlaveHalfRX(SPI_x);
    }
}

/*=============================================================================================================================================================*/
/*====================================================================== CRC CALCULATION ======================================================================*/
/*=============================================================================================================================================================*/

/*------------------ Enable CRC (CRCEN can only change when SPE = 0) ------------------- */
/* CRC size follows the frame length: 8-bit frame -> CRC8 , 16-bit frame -> CRC16 */
void SPI_CRC_Enable(SPI_n *SPI_x, uint16_t Copy_Poly)
{
    uint32_t Local_SPE = GET_BIT(SPI_x->SPI_CR1, 6);

    CLEAR_BIT(SPI_x->SPI_CR1, 6);                          /* SPE = 0 */
    CLEAR_BIT(SPI_x->SPI_CR1, 13);                         /* CRCEN = 0 (also resets the CRC registers) */
    SPI_x->SPI_CRCPR = Copy_Poly;                          /* polynomial (reset value is 0x7) */
    SET_BIT(SPI_x->SPI_CR1, 13);                           /* CRCEN = 1 */

    if (Local_SPE == 1) SET_BIT(SPI_x->SPI_CR1, 6);        /* restore SPE */
}

void SPI_CRC_Disable(SPI_n *SPI_x)
{
    uint32_t Local_SPE = GET_BIT(SPI_x->SPI_CR1, 6);

    CLEAR_BIT(SPI_x->SPI_CR1, 6);
    CLEAR_BIT(SPI_x->SPI_CR1, 13);

    if (Local_SPE == 1) SET_BIT(SPI_x->SPI_CR1, 6);
}

/*------------------ Send the CRC after the next data (set after writing the last data to DR) ------------------- */
void SPI_CRC_Next(SPI_n *SPI_x)
{
    SET_BIT(SPI_x->SPI_CR1, 12);                           /* CRCNEXT = 1 */
}

uint16_t SPI_GetRxCRC(SPI_n *SPI_x)
{
    return (uint16_t)SPI_x->SPI_RXCRCR;
}

uint16_t SPI_GetTxCRC(SPI_n *SPI_x)
{
    return (uint16_t)SPI_x->SPI_TXCRCR;
}

/*------------------ Full duplex buffer with CRC (returns 0 = OK , 1 = CRC error) ------------------- */
static uint8_t SPI_TransiveBufferCRC(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len)
{
    uint32_t i;
    volatile uint8_t Local_CRCFrame;

    for (i = 0; i < Copy_Len; i++)
    {
        while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_TXE) == 0);
        SPI_x->SPI_DR = Copy_TX[i];

        if (i == (Copy_Len - 1)) SPI_CRC_Next(SPI_x);      /* CRC frame follows the last data */

        while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_RXNE) == 0);
        Copy_RX[i] = (uint8_t)SPI_x->SPI_DR;
    }

    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_RXNE) == 0);    /* received CRC frame */
    Local_CRCFrame = (uint8_t)SPI_x->SPI_DR;
    (void)Local_CRCFrame;

    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_BSY) == 1);

    return (uint8_t)GET_BIT(SPI_x->SPI_SR, SPI_FLAG_CRCERR);
}

uint8_t SPI_MasterTransiveBufferCRC(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len)
{
    return SPI_TransiveBufferCRC(SPI_x, Copy_TX, Copy_RX, Copy_Len);
}

uint8_t SPI_SlaveTransiveBufferCRC(SPI_n *SPI_x, uint8_t *Copy_TX, uint8_t *Copy_RX, uint32_t Copy_Len)
{
    return SPI_TransiveBufferCRC(SPI_x, Copy_TX, Copy_RX, Copy_Len);
}

/*=============================================================================================================================================================*/
/*====================================================================== DISABLING THE SPI ====================================================================*/
/*=============================================================================================================================================================*/

void SPI_Enable(SPI_n *SPI_x)
{
    SET_BIT(SPI_x->SPI_CR1, 6);                            /* SPE = 1 */
}

/*------------------ Disable after the last frame (does not wait for RXNE so it cannot hang) ------------------- */
void SPI_Disable(SPI_n *SPI_x)
{
    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_TXE) == 0);     /* wait TXE = 1 */
    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_BSY) == 1);     /* wait BSY = 0 */
    CLEAR_BIT(SPI_x->SPI_CR1, 6);                          /* SPE = 0 */
    SPI_ClearOVR(SPI_x);                                   /* drop any unread data */
}

/*------------------ Disable and turn off the peripheral clock ------------------- */
void SPI_DeInit(uint32_t SPI_x){

    SPI_Disable((SPI_n*)SPI_x);

    if (SPI_x == (uint32_t)SPI_1)       RCC_VoidStatusPeripheral_CLK( RCC_APB2 , SPI1EN , DISABLE);
    else if (SPI_x == (uint32_t)SPI_2)  RCC_VoidStatusPeripheral_CLK( RCC_APB1 , SPI2EN , DISABLE);
    else if (SPI_x == (uint32_t)SPI_3)  RCC_VoidStatusPeripheral_CLK( RCC_APB1 , SPI3EN , DISABLE);
    else if (SPI_x == (uint32_t)SPI_4)  RCC_VoidStatusPeripheral_CLK( RCC_APB2 , SPI4EN , DISABLE);
}

/*=============================================================================================================================================================*/
/*====================================================================== COMMUNICATION USING DMA ==============================================================*/
/*=============================================================================================================================================================*/

/*------------------ Data register address (for the DMA peripheral address) ------------------- */
uint32_t SPI_GetDRAddress(SPI_n *SPI_x)
{
    return (uint32_t)&(SPI_x->SPI_DR);
}

void SPI_DMA_Enable(SPI_n *SPI_x, SPI_DMA Copy_Request)
{
    SET_BIT(SPI_x->SPI_CR2, Copy_Request);                 /* RXDMAEN = bit 0 , TXDMAEN = bit 1 */
}

/*------------------ Disable after the DMA transfer is complete ------------------- */
void SPI_DMA_Disable(SPI_n *SPI_x, SPI_DMA Copy_Request)
{
    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_TXE) == 0);
    while (GET_BIT(SPI_x->SPI_SR, SPI_FLAG_BSY) == 1);
    CLEAR_BIT(SPI_x->SPI_CR2, Copy_Request);
}

/*=============================================================================================================================================================*/
/*====================================================================== SPI INTERRUPTS =======================================================================*/
/*=============================================================================================================================================================*/

static SPI_CB SPI_RXNE_CB[4] = {0,0,0,0};
static SPI_CB SPI_TXE_CB [4] = {0,0,0,0};
static SPI_CB SPI_ERR_CB [4] = {0,0,0,0};

static uint8_t SPI_GetIndex(SPI_n *SPI_x)
{
    if      (SPI_x == SPI_1) return 0;
    else if (SPI_x == SPI_2) return 1;
    else if (SPI_x == SPI_3) return 2;
    else                     return 3;
}

void SPI_EnableInterrupt(SPI_n *SPI_x, SPI_INT Copy_Int)
{
    SET_BIT(SPI_x->SPI_CR2, Copy_Int);
}

void SPI_DisableInterrupt(SPI_n *SPI_x, SPI_INT Copy_Int)
{
    CLEAR_BIT(SPI_x->SPI_CR2, Copy_Int);
}

void SPI_SetCallBack(SPI_n *SPI_x, SPI_INT Copy_Int, SPI_CB Copy_Func)
{
    uint8_t Local_Index = SPI_GetIndex(SPI_x);

    switch (Copy_Int)
    {
        case SPI_INT_RXNE:  SPI_RXNE_CB[Local_Index] = Copy_Func;   break;
        case SPI_INT_TXE:   SPI_TXE_CB [Local_Index] = Copy_Func;   break;
        case SPI_INT_ERR:   SPI_ERR_CB [Local_Index] = Copy_Func;   break;
        default: break;
    }
}

static void SPI_IRQ_Handler(SPI_n *SPI_x)
{
    uint8_t Local_Index = SPI_GetIndex(SPI_x);

    if ( GET_BIT(SPI_x->SPI_CR2, SPI_INT_RXNE) && GET_BIT(SPI_x->SPI_SR, SPI_FLAG_RXNE) )
    {
        if (SPI_RXNE_CB[Local_Index] != 0) SPI_RXNE_CB[Local_Index]();      /* callback must read DR */
    }

    if ( GET_BIT(SPI_x->SPI_CR2, SPI_INT_TXE) && GET_BIT(SPI_x->SPI_SR, SPI_FLAG_TXE) )
    {
        if (SPI_TXE_CB[Local_Index] != 0) SPI_TXE_CB[Local_Index]();        /* callback must write DR or disable TXEIE */
    }

    if ( GET_BIT(SPI_x->SPI_CR2, SPI_INT_ERR) && (SPI_x->SPI_SR & SPI_ERR_MASK) )
    {
        if (SPI_ERR_CB[Local_Index] != 0) SPI_ERR_CB[Local_Index]();        /* callback must clear the error */
    }
}

/*------------------ Vector table handlers (names must match your startup file) ------------------- */
void SPI1_IRQHandler(void){ SPI_IRQ_Handler(SPI_1); }
void SPI2_IRQHandler(void){ SPI_IRQ_Handler(SPI_2); }
void SPI3_IRQHandler(void){ SPI_IRQ_Handler(SPI_3); }
void SPI4_IRQHandler(void){ SPI_IRQ_Handler(SPI_4); }




/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      I2S      $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/



