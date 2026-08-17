/*========================================================
File        : USART_CONFGR
Description : This file contain USART configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 30/4/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef USART_CONFGR_H
#define USART_CONFGR_H


/*---- Length of data ----*/

typedef enum{

    bit_8 = 0 ,
    bit_9 = 1 ,

}LENGTH_b;

/*---- Stop bit ----*/

typedef enum {
    
    bit_1       = 0,
    bit_0_5     = 1,
    bit_2       = 2,
    bit_1_5     = 3,

}STOP_b;

/*---- Parity bit ----*/

typedef enum {
       
    PARITY_ODD  = 0 ,
    PARITY_EVEN = 1 ,
    PARITY_NONE = 2 ,
    
}PARITY_b;

/*---- polarity ----*/

typedef enum {
       
    ACTIVE_CLK_LOW  = 0 ,
    ACTIVE_CLK_HIGH = 1 ,
    
}POLARITY_b;

/*---- Phase selection*/

typedef enum {
       
    FIRST_CLK  = 0 ,
    SECOND_CLK = 1 ,
    
}PHASE_b;
 
/*---- Last bit clock pulse ----*/

typedef enum {
       
    LBCP_OFF  = 0 ,
    LBCP_ON   = 1 ,
    
}LBCP_b;


typedef enum {
    LIN_ROLE_RESPOND,
    LIN_ROLE_RECEIVE,
    LIN_ROLE_IGNORE
} LIN_SlaveRole_t;
#endif 
