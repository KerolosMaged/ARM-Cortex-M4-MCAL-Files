/*========================================================
File        : USART_INTERFACE
Description : This file contain the declerations of USART functions 
Author      : Kerolos Maged Amin Fekry
Date        : 30/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


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

void USART_AsyncTX_Send( USART_n *USART_x ,uint16_t Copy_data );

/*====================== Reciver Async Intialization ==========================*/

void USART_AsyncRX_Init( USART_n *USART_x , LENGTH_b LENGTH_x , STOP_b STOP_x , PARITY_b PARITY_x,uint32_t Copy_BR  );


/*========================= Reciving the data ===========================*/

uint16_t USART_AsyncRX_Read( USART_n *USART_x );

#endif