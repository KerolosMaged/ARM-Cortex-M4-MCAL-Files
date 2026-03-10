/*========================================================
File        : GPIO_INTERFACE
Description : This file contain the declerations of GPIO functions 
Author      : Kerolos Maged Amin Fekry
Date        : 9/2/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

void GPIO_VoidInit( uint32_t GPIOx, uint8_t PINx, uint8_t MODE ,uint8_t PULL, uint8_t SPEED );
void GPIO_VoidWrite( uint32_t GPIOx, uint8_t PINx, uint8_t STATYUS);
uint8_t GPIO_uint8_tRead( uint32_t GPIOx, uint8_t PINx,);
void GPIO_VoidToggle( uint32_t GPIOx, uint8_t PINx);
#endif