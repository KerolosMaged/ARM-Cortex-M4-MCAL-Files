/*========================================================
File        : I2C_PRIVATE
Description : This file contain Rgisters address of I2C functions 
Author      : Kerolos Maged Amin Fekry
Date        : 16/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

typedef struct {
    
    uint32_t    I2C_CR1;
    uint32_t    I2C_CR2;
    uint32_t    I2C_OAR1;
    uint32_t    I2C_OAR2;
    uint32_t    I2C_DR;
    uint32_t    I2C_SR1;
    uint32_t    I2C_SR2;
    uint32_t    I2C_CCR;
    uint32_t    I2C_TRISE;
    uint32_t    I2C_FLTR;

}I2C_n;

#define I2C_1   (( volatile I2C_n * )( 0x40005400 ))
#define I2C_2   (( volatile I2C_n * )( 0x40005800 ))
#define I2C_3   (( volatile I2C_n * )( 0x40005C00 ))


#endif