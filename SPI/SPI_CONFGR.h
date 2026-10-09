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

    FALLING_EDGE = 0,
    RISING_EDGE = 1,

}CLK_POL;

/*------ Selection of phase ------*/

typedef enum{

    FIRST_CLK = 0,
    SECOND_CLK = 1,

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

    N_2   =  0,
    N_4   =  7,
    N_8   =  1,
    N_16  =  2,
    N_32  =  3,
    N_64  =  4,
    N_128 =  5,
    N_256 =  6,

    
}BR_N;

/*----- Bidirectional mode ----*/

typedef enum{
    SPI_DIR_RX = 0,
    SPI_DIR_TX = 1,
}SPI_DIR;


#endif 
