/*========================================================
File        : WDG_CONFGR
Description : This file contain IWDG & WWDG configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 7/5/2026
Github      : https://github.com/KerolosMaged
========================================================*/

#ifndef WDG_CONFGR_H
#define WDG_CONFGR_H


#include "../LIB/STD_TYPES_MATH.h"



typedef enum {

    PSC_4   =    0b000,
    PSC_8   =    0b001,
    PSC_16  =    0b010,
    PSC_32  =    0b011,
    PSC_64  =    0b100,
    PSC_128 =    0b101,
    PSC_256 =    0b110,

}PSC_n;


typedef  enum {

    DIV1   =   0b00,
    DIV2   =   0b01,
    DIV4   =   0b10,
    DIV8   =   0b11,
    
}CK_CNT_PSC;

#endif
