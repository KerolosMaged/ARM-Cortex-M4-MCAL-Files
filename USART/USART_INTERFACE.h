/*========================================================
File        : USART_INTERFACE
Description : This file contain the declerations of USART functions 
Author      : Kerolos Maged Amin Fekry
Date        : 30/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "USART_PRIVATE.h"

/*==================== Initialization of USART ==================*/

void USART_INIT(uint32_t CopyUsart , uint32_t Copy_Clock );



/*====================== Set the Baud Rate Value =======================*/

void USART_SetBaudRate( USART_n *USART_x  , uint32_t Copy_BR);    // is an addtional func but it used in functions 



/*===================================================================================================*/
/*============================================ Async USART ==========================================*/
/*===================================================================================================*/

/*====================== Transmiter Async Intialization ==========================*/

void USART_AsyncTX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR );

/*========================= Sending the data ===========================*/

/*==== For sending Character or namber and it should be in ('') ====*/
void USART_AsyncTX_SendChar( USART_n *USART_x, uint16_t Copy_data );

/*==== For sending String and it should be in (" ") ====*/
void USART_AsyncTX_SendString( USART_n *USART_x, uint8_t *Copy_data );

/*====================== Reciver Async Intialization ==========================*/

void USART_AsyncRX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR  );


/*========================= Reciving the data ===========================*/

uint16_t USART_AsyncRX_Read( USART_n *USART_x );



/*===================================================================================================*/
/*======================================= Multiprocessor USART ======================================*/
/*===================================================================================================*/

/*====================== Multiprocessor Initialization (Called ONCE at startup) ==========================*/
/* Copy_WakeMethod: 0 = Idle Line Detection, 1 = Address Mark Detection */

void USART_Multiprocessor_Init(USART_n *USART_x, LENGTH_b LENGTH_x, STOP_b STOP_x, PARITY_b PARITY_x, uint32_t Copy_BR, uint8_t Copy_WakeMethod);

/*====================== Set this device's own address (used only in Address Mark mode) ==========================*/

void USART_Multiprocessor_SetAddress(uint8_t Copy_Address);

/*====================== Master: Send an Address byte (MSB = 1) ==========================*/

void USART_Multiprocessor_SendAddress(USART_n *USART_x, uint8_t CopyAddress);

/*====================== Master: Send a Data byte (MSB = 0) ==========================*/

void USART_Multiprocessor_SendData(USART_n *USART_x, uint8_t CopyData);

/*====================== Slave: Enter Mute mode ==========================*/

void USART_Multiprocessor_EnterMute(USART_n *USART_x);


/*====================== Slave: Exit Mute mode manually (optional, hardware also clears RWU automatically) ==========================*/

void USART_Multiprocessor_ExitMute(USART_n *USART_x);


/*====================== Slave: Check if this incoming byte is MY address (Address Mark mode) ==========================*/
/* Returns 1 if the byte is an address byte AND it matches my own address.
   Returns 0 otherwise (not an address byte, or address for someone else). */

uint8_t USART_Multiprocessor_CheckAddress(uint8_t ReceivedByte);

/*===================================================================================================*/
/*============================================ Sync USART ===========================================*/
/*===================================================================================================*/

/*====================== Transmiter Async Intialization ==========================*/

void USART_SyncTX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR , POLARITY_b POLARITY_n , PHASE_b PHASE_n ,LBCP_b LBCP_n);
void USART_SyncTX_SendChar( USART_n *USART_x, uint16_t Copy_data );
void USART_SyncTX_SendString( USART_n *USART_x, uint8_t *Copy_data );

/*====================== Reciver Async Intialization ==========================*/

void USART_SyncRX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR , POLARITY_b POLARITY_n , PHASE_b PHASE_n , LBCP_b LBCP_n );

uint16_t USART_SyncRX_Read( USART_n *USART_x );


/*===================================================================================================*/
/*================================= Single-Wire Half-Duplex USART ===================================*/
/*===================================================================================================*/

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! U should to know !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

=====> change setting of the GPIO <=====
   > USART_PIN.OTYPE = OUTPUT_OPEN_DRAIN;  
   > USART_PIN.PULL  = PULL_UP; 

*/



/*====================== Half-Duplex Initialization (Called ONCE at startup) ==========================*/

void USART_HalfDuplex_Init(USART_n *USART_x, LENGTH_b LENGTH_x, STOP_b STOP_x, PARITY_b PARITY_x, uint32_t Copy_BR);


/*===================================================================================================*/
/*=========================================== LIN usage =========================================*/
/*===================================================================================================*/


/*====================== LIN Initialization (Called ONCE at startup) ==========================*/


void USART_LIN_Init(USART_n *USART_x , uint32_t Copy_BR );

/*====================== Send Break (called before every Master frame) ==========================*/

void USART_LIN_SendBreak(USART_n *USART_x);

/*====================== Checksum Calculation (Enhanced Checksum) ==========================*/

uint8_t USART_LIN_CalculateChecksum(uint8_t CopyPID, uint8_t *CopyData, uint8_t CopyLength);

/*===================================================================================================*/
/*============================================ Master LIN ===========================================*/
/*===================================================================================================*/

/*====================== Master sends a full frame (Master owns the data) ==========================*/

uint8_t USART_LIN_Master_Send(USART_n *USART_x , uint8_t CopyPID , uint8_t *CopyDATA , uint8_t CopyLength);

/*====================== Master requests a frame (Slave owns the data) ==========================*/

uint8_t USART_LIN_MasterRequestFrame(USART_n *USART_x , uint8_t CopyPID, uint8_t *ReceivedData, uint8_t CopyLength);

/*===================================================================================================*/
/*============================================ Slave LIN ===========================================*/
/*===================================================================================================*/

/*====================== Wait for a Break to arrive (start of a new frame) ==========================*/

void USART_LIN_SlaveWaitForBreak(USART_n *USART_x);

/*====================== Read Sync byte + PID after a Break ==========================*/

uint8_t USART_LIN_SlaveReadHeader(USART_n *USART_x);

/*====================== Slave sends Data + Checksum (Slave owns the data) ==========================*/

void USART_LIN_SlaveRespond(USART_n *USART_x, uint8_t CopyPID, uint8_t *CopyData, uint8_t Length);

/*====================== Slave receives Data + Checksum (Master owns the data) ==========================*/

uint8_t USART_LIN_SlaveReceiveFrame(USART_n *USART_x, uint8_t CopyPID, uint8_t *ReceivedData, uint8_t Length);

/*====================== Full Slave Listen Cycle ==========================*/

void USART_LIN_SlaveListen(USART_n *USART_x, uint8_t MyPID, LIN_SlaveRole_t Role, uint8_t *DataBuffer, uint8_t Length);

/*===================================================================================================*/
/*========================================= USART Interrupts =======================================*/
/*===================================================================================================*/


/*====================== Enable a specific USART interrupt ==========================*/

void USART_INTERRUPT_Selection(USART_n *USART_x, USART_Interrupt_t Copy_Interrupt);

/*====================== Check if a specific USART interrupt flag is set ==========================*/

uint8_t USART_INTERRUPT_GetFlagStatus(USART_n *USART_x, USART_Interrupt_t Copy_Interrupt);




#endif