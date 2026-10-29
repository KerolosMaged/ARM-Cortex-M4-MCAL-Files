/*========================================================
File        : SPI_CONFGR
Description : This file contain SPI configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 30/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef SPI_CONFGR_H
#define SPI_CONFGR_H




#define ENABLE   1
#define DISABLE  0


/*------ Selection of Polarity ------*/

typedef enum{
    RIS_EDGE  = 0,   /* CPOL = 0 : idle Low,  leading edge rising  */
    FALL_EDGE = 1,   /* CPOL = 1 : idle High, leading edge falling */
}CLK_POL;


/*------ Selection of phase ------*/

typedef enum{

    FIR_CLK = 0,
    SEC_CLK = 1,

}CLK_PHA;

/*-------- Selection of the Frame length -------*/

typedef enum{

    Bit_8 = 0, 
    Bit_16 = 1, 

}FRAME_LEN;


/*------ Selection of the frame format ------*/

typedef enum{

    MSB = 0, 
    LSB = 1, 

}FRAME_FORMAT;


/*---- Selection of Slave ----*/

typedef enum{

    HW = 0, 
    SW = 1, 

}SLAVE_SEL;

/*----- Prescaler Values*/

typedef enum{
    N_2   = 0,
    N_4   = 1,
    N_8   = 2,
    N_16  = 3,
    N_32  = 4,
    N_64  = 5,
    N_128 = 6,
    N_256 = 7,
}BR_N;
/*----- Bidirectional mode ----*/

typedef enum{
    SPI_DIR_RX = 0,
    SPI_DIR_TX = 1,
}SPI_DIR;


/*----- Status flags (SPI_SR bit positions) -----*/

typedef enum{
    SPI_FLAG_RXNE   = 0,
    SPI_FLAG_TXE    = 1,
    SPI_FLAG_UDR    = 3,
    SPI_FLAG_CRCERR = 4,
    SPI_FLAG_MODF   = 5,
    SPI_FLAG_OVR    = 6,
    SPI_FLAG_BSY    = 7,
    SPI_FLAG_FRE    = 8,
}SPI_FLAG;

/*----- Interrupt sources (SPI_CR2 bit positions) -----*/

typedef enum{
    SPI_INT_ERR  = 5,
    SPI_INT_RXNE = 6,
    SPI_INT_TXE  = 7,
}SPI_INT;

/*----- DMA requests (SPI_CR2 bit positions) -----*/

typedef enum{
    SPI_DMA_RX = 0,
    SPI_DMA_TX = 1,
}SPI_DMA;

/*----- Error mask (CRCERR | MODF | OVR | FRE) -----*/
#define SPI_ERR_MASK    ( (1U<<4) | (1U<<5) | (1U<<6) | (1U<<8) )

typedef void (*SPI_CB)(void);














#endif 
