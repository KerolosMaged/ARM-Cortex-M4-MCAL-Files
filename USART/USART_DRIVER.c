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
        RCC_VoidStatusPeripheral_CLK( RCC_APB2 , USART1EN , ENABLE);
    }
    else if(CopyUsart == USART_2)
    {
        RCC_VoidStatusPeripheral_CLK( RCC_APB1 , USART2EN , ENABLE);
    }
    else if(CopyUsart == USART_6)
    {
        RCC_VoidStatusPeripheral_CLK( RCC_APB2 , USART6EN , ENABLE);
    }
    /*--- Set clock for usart ---*/
    TIM_CLK = Copy_Clock;
}

/*====================== Set the Baud Rate Value =======================*/

void USART_SetBaudRate( USART_n *USART_x  , uint32_t Copy_BR){
    /*--- clear OVER8 bit to make it for 16 ---*/
    CLEAR_BIT( USART_x->USART_CR1 , 14 );
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
    /*--------- Set the Baud Rate Value ---------*/
    
    USART_SetBaudRate(USART_x,Copy_BR);

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


    /*---- Enable USART ----*/
    SET_BIT(USART_x->USART_CR1,13);
    /*---- Send the idle ----*/
    SET_BIT(USART_x->USART_CR1,3);
}

/*========================= Sending the data ===========================*/

/*==== For sending Character or namber and it should be in ('') ====*/

void USART_AsyncTX_SendChar( USART_n *USART_x, uint16_t Copy_data ){
    while(GET_BIT(USART_x->USART_SR,7)==0);   
    USART_x->USART_DR = Copy_data;
    while(GET_BIT(USART_x->USART_SR,6)==0);   
}

/*==== For sending String and it should be in (" ") ====*/

void USART_AsyncTX_SendString( USART_n *USART_x, uint8_t *Copy_data ){
    uint32_t i=0;
    while (Copy_data[i] != '\0')
    {
        USART_AsyncTX_SendChar(USART_x,Copy_data[i]);
        i++;
    }
    
}
/*====================== Reciver Async Intialization ==========================*/

/*
                 RX
                  │
IDLE              │
111111111111111111
                  │
                  ↓ Falling Edge
                  0
                  │
                  │
        ┌─────────┴─────────┐
        │ Take 3 samples    │
        │ 3, 5, 7           │
        └─────────┬─────────┘
                  │
            At least 2 = 0?
              /          \
            No            Yes
            ↓              ↓
          Noise       Start Bit
            ↓              ↓
          IDLE        Continue receiving
                           │
                           ↓
                    Sample Data Bits
                           │
                           ↓
                         Stop Bit


*/



void USART_AsyncRX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR  ){

    /*--------- Set the Baud Rate Value ---------*/
    USART_SetBaudRate(USART_x,Copy_BR);
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

    /*----- Select method of sampling -----*/
    CLEAR_BIT(USART_x->USART_CR3,11);  // this is 3 sample method
    /*---- Enable USART ----*/
    SET_BIT(USART_x->USART_CR1,13);    
    /*---- Send the idle ----*/
    SET_BIT(USART_x->USART_CR1,2);
}

/*========================= Reciving the data ===========================*/

uint16_t USART_AsyncRX_Read( USART_n *USART_x ){

    while(GET_BIT(USART_x->USART_SR,5)==0); // Wait for ready to recive
    return  (uint16_t)USART_x->USART_DR; // read the data into the register
}
 


/*===================================================================================================*/
/*============================================ Sync USART ===========================================*/
/*===================================================================================================*/

/*====================== Transmiter Async Intialization ==========================*/

void USART_SyncTX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR , POLARITY_b POLARITY_n , PHASE_b PHASE_n ,LBCP_b LBCP_n){

    /*-- Clearing other modes  --*/

    CLEAR_BIT(USART_x->USART_CR2,14); // LINEN
    CLEAR_BIT(USART_x->USART_CR3,5);  // SCEN 
    CLEAR_BIT(USART_x->USART_CR3,1);  // IREN  
    CLEAR_BIT(USART_x->USART_CR3,3);  // HDSEL 

    /*--- Enabling the clock ---*/
    
    SET_BIT(USART_x->USART_CR2,11);

    /*--- Set the Polarity of the the clock ---*/
    
    CLEAR_BIT(USART_x->USART_CR2,10);   // Clear bit

    USART_x->USART_CR2 |= ( POLARITY_n << 10 );

    /*--- Set the Phase of the the clock ---*/

    CLEAR_BIT(USART_x->USART_CR2,9);   // Clear bit

    USART_x->USART_CR2 |= ( PHASE_n << 9 );

    /*--- Selection of the last bit clock pulse ---*/

    CLEAR_BIT(USART_x->USART_CR2,8);   // Clear bit

    USART_x->USART_CR2 |= ( LBCP_n << 8 );


    USART_AsyncTX_Init(USART_x,LENGTH_x,STOP_x,PARITY_x,Copy_BR);
}

void USART_SyncTX_SendChar( USART_n *USART_x, uint16_t Copy_data ){
    while(GET_BIT(USART_x->USART_SR,7)==0);   
    USART_x->USART_DR = Copy_data;
    while(GET_BIT(USART_x->USART_SR,6)==0);   
}

void USART_SyncTX_SendString( USART_n *USART_x, uint8_t *Copy_data ){
    uint32_t i=0;
    while (Copy_data[i] != '\0')
    {
        USART_SyncTX_SendChar(USART_x,Copy_data[i]);
        i++;
    }
    
}


/*====================== Reciver Async Intialization ==========================*/


void USART_SyncRX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR , POLARITY_b POLARITY_n , PHASE_b PHASE_n , LBCP_b LBCP_n ){

    /*-- Clearing Bits rm recommended --*/
    
    CLEAR_BIT(USART_x->USART_CR2,14); // LINEN
    CLEAR_BIT(USART_x->USART_CR3,5);  // SCEN 
    CLEAR_BIT(USART_x->USART_CR3,1);  // IREN  
    CLEAR_BIT(USART_x->USART_CR3,3);  // HDSEL 

    /*--- Enabling the clock ---*/
    
    SET_BIT(USART_x->USART_CR2,11);

    /*--- Set the Polarity of the the clock ---*/

    CLEAR_BIT(USART_x->USART_CR2,10);   // Clear bit

    USART_x->USART_CR2 |= ( POLARITY_n << 10 );

    /*--- Set the Phase of the the clock ---*/

    CLEAR_BIT(USART_x->USART_CR2,9);   // Clear bit

    USART_x->USART_CR2 |= ( PHASE_n << 9 );

    /*--- Selection of the last bit clock pulse ---*/

    CLEAR_BIT(USART_x->USART_CR2,8);   // Clear bit

    USART_x->USART_CR2 |= ( LBCP_n << 8 );

    USART_AsyncRX_Init(USART_x,LENGTH_x,STOP_x,PARITY_x,Copy_BR);
}

uint16_t USART_SyncRX_Read( USART_n *USART_x ){

    while(GET_BIT(USART_x->USART_SR,5)==0); // Wait for ready to recive
    return  (uint16_t)USART_x->USART_DR; // read the data into the register
}





/*===================================================================================================*/
/*=========================================== LIN usage =========================================*/
/*===================================================================================================*/


/*====================== LIN Initialization (Called ONCE at startup) ==========================*/


void USART_LIN_Init(USART_n *USART_x , uint32_t Copy_BR ){
    /*--- Enable LIN mode ---*/
    SET_BIT(USART_x->USART_CR2,14);
    
    /*-- Clearing other modes  --*/
    CLEAR_BIT(USART_x->USART_CR2,12); // STOP0
    CLEAR_BIT(USART_x->USART_CR2,13); // STOP1
    CLEAR_BIT(USART_x->USART_CR2,11); // CLKEN
    CLEAR_BIT(USART_x->USART_CR3,5);  // SCEN 
    CLEAR_BIT(USART_x->USART_CR3,1);  // IREN  
    CLEAR_BIT(USART_x->USART_CR3,3);  // HDSEL

    /*---- Intialization as an ordinary Async ----*/
    USART_AsyncTX_Init(USART_x,bit_8,bit_1,PARITY_NONE , Copy_BR);
    

}

/*====================== Send Break (called before every Master frame) ==========================*/

void USART_LIN_SendBreak(USART_n *USART_x){

    SET_BIT(USART_x->USART_CR1, 0);   // SBK

}

/*====================== Checksum Calculation (Enhanced Checksum) ==========================*/

uint8_t USART_LIN_CalculateChecksum(uint8_t CopyPID, uint8_t *CopyData, uint8_t CopyLength){
    uint16_t Sum = CopyPID;
    for(uint8_t i = 0; i < CopyLength; i++){
        Sum += CopyData[i];
    }
    while(Sum > 0xFF){
        Sum = (Sum & 0xFF) + (Sum >> 8);
    }
    return (uint8_t)(0xFF - Sum);
}



/*===================================================================================================*/
/*============================================ Master LIN ===========================================*/
/*===================================================================================================*/

/*====================== Master sends a full frame (Master owns the data) ==========================*/

uint8_t USART_LIN_Master_Send(USART_n *USART_x , uint8_t CopyPID , uint8_t *CopyDATA , uint8_t CopyLength){
    
 

    USART_LIN_SendBreak(USART_x);                // Send break the start sending 

    USART_AsyncTX_SendChar(USART_x , 0x55 );     // Send the Sync signal

    USART_AsyncTX_SendChar(USART_x , CopyPID );  // Send the PID signal for each device

    /*-------- Sending Matrix of Data --------*/
    for(uint8_t Data_i = 0 ;Data_i <=CopyLength ;Data_i++)  
    {
        USART_AsyncTX_SendChar(USART_x,CopyDATA[Data_i]);   

    }
    
    /*------ Oeration of CheckSum ------*/
    uint8_t ExpectedChecksum = USART_LIN_CalculateChecksum(CopyPID, CopyDATA, CopyLength);
    return ( ExpectedChecksum);


}

/*====================== Master requests a frame (Slave owns the data) ==========================*/

uint8_t USART_LIN_MasterRequestFrame(USART_n *USART_x , uint8_t CopyPID, uint8_t *ReceivedData, uint8_t CopyLength){


    
    USART_LIN_SendBreak(USART_x);
    USART_AsyncTX_SendChar(USART_x, 0x55);
    USART_AsyncTX_SendChar(USART_x, CopyPID);

    
    for(uint8_t i = 0; i < CopyLength; i++){
        ReceivedData[i] = USART_AsyncRX_Read(USART_x);
    }    
    uint8_t ReceivedChecksum = USART_AsyncRX_Read(USART_x);

    /*------ Oeration of CheckSum ------*/
    uint8_t ExpectedChecksum = USART_LIN_CalculateChecksum(CopyPID, ReceivedData, CopyLength);

    if(ReceivedChecksum == ExpectedChecksum){
        return 1;  
    }
    return 0; 
}


/*===================================================================================================*/
/*============================================ Slave LIN ===========================================*/
/*===================================================================================================*/

/*====================== Wait for a Break to arrive (start of a new frame) ==========================*/

void USART_LIN_SlaveWaitForBreak(USART_n *USART_x){

    while(GET_BIT(USART_x->USART_SR, 8) == 0);   // Wait until LBD flag is set (Break detected)

    CLEAR_BIT(USART_x->USART_SR, 8);              // Clear LBD flag for the next frame
}

/*====================== Read Sync byte + PID after a Break ==========================*/

uint8_t USART_LIN_SlaveReadHeader(USART_n *USART_x){

    uint8_t Sync = USART_AsyncRX_Read(USART_x);

    if(Sync != 0x55){
        return 0xFF;   // Invalid sync byte, ignore this frame
    }

    uint8_t PID = USART_AsyncRX_Read(USART_x);
    return PID;
}

/*====================== Slave sends Data + Checksum (Slave owns the data) ==========================*/

void USART_LIN_SlaveRespond(USART_n *USART_x, uint8_t CopyPID, uint8_t *CopyData, uint8_t Length){

    uint8_t CheckSum = USART_LIN_CalculateChecksum(CopyPID, CopyData, Length);

    for(uint8_t i = 0; i < Length; i++){
        USART_AsyncTX_SendChar(USART_x, CopyData[i]);
    }

    USART_AsyncTX_SendChar(USART_x, CheckSum);
}

/*====================== Slave receives Data + Checksum (Master owns the data) ==========================*/

uint8_t USART_LIN_SlaveReceiveFrame(USART_n *USART_x, uint8_t CopyPID, uint8_t *ReceivedData, uint8_t Length){

    for(uint8_t i = 0; i < Length; i++){
        ReceivedData[i] = USART_AsyncRX_Read(USART_x);
    }

    uint8_t ReceivedChecksum = USART_AsyncRX_Read(USART_x);
    uint8_t ExpectedChecksum = USART_LIN_CalculateChecksum(CopyPID, ReceivedData, Length);

    return (ReceivedChecksum == ExpectedChecksum) ? 1 : 0;
}

/*====================== Full Slave Listen Cycle ==========================*/

void USART_LIN_SlaveListen(USART_n *USART_x, uint8_t MyPID, LIN_SlaveRole_t Role, uint8_t *DataBuffer, uint8_t Length){

    USART_LIN_SlaveWaitForBreak(USART_x);

    uint8_t ReceivedPID = USART_LIN_SlaveReadHeader(USART_x);

    if(ReceivedPID != MyPID){
        return;   // Not my frame, ignore
    }

    if(Role == LIN_ROLE_RESPOND){
        USART_LIN_SlaveRespond(USART_x, MyPID, DataBuffer, Length);
    }
    else if(Role == LIN_ROLE_RECEIVE){
        USART_LIN_SlaveReceiveFrame(USART_x, MyPID, DataBuffer, Length);
    }
    // LIN_ROLE_IGNORE → do nothing
}