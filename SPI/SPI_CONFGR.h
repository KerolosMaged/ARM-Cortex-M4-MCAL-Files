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


#endif 
