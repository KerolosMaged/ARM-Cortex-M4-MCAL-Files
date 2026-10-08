/*========================================================
File        : SPI_PRIVATE
Description : This file contain Rgisters address of SPI functions 
Author      : Kerolos Maged Amin Fekry
Date        : 30/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/ 

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/*============ SPI Registers ============*/
typedef struct {
    uint32_t    SPI_CR1    ;
    uint32_t    SPI_CR2    ;
    uint32_t    SPI_SR     ;
    uint32_t    SPI_DR     ;
    uint32_t    SPI_CRCPR  ;
    uint32_t    SPI_RXCRCR ;
    uint32_t    SPI_TXCRCR ;
}SPI_n;

/*============ SPI Registers Memory Map for addresses ============*/

#define     SPI_1       (( volatile SPI_n* )( 0x40013000 ))
#define     SPI_2       (( volatile SPI_n* )( 0x40003800 ))
#define     SPI_3       (( volatile SPI_n* )( 0x40003C00 ))
#define     SPI_4       (( volatile SPI_n* )( 0x40013400 ))


/*============ I2S Registers ============*/

typedef struct {
    uint32_t    SPI_I2SCFGR ;
    uint32_t    SPI_I2SPR   ;

}I2S_n;

/*============ I2S Registers Memory Map for addresses ============*/

#define     I2S_2           (( volatile I2S_n* )( 0x40003800 ))
#define     I2S2ext_2       (( volatile I2S_n* )( 0x40003400 ))

#define     I2S_3           (( volatile I2S_n* )( 0x40003C00 ))        
#define     I2S3ext_3       (( volatile I2S_n* )( 0x40004000 )) 





#endif