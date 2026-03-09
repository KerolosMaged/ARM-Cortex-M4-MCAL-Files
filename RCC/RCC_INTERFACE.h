/*========================================================
File        : RCC_INTERFACE
Description : This file contain the declerations of RCC functions 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


void RCC_VoidSysInit( void );

void RCC_VoidStatusPeripheral_CLK(uint8_t BUS ,uint8_t Peripheral ,uint8_t Status);

void RCC_VoidStatusPeripheral_LPCLK(uint8_t BUS ,uint8_t Peripheral ,uint8_t Status);

void RCC_Void_Peripheral_RESET(uint8_t BUS ,uint8_t Peripheral );


#endif