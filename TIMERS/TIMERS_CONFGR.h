/*========================================================
File        : TIMERS_CONFGR
Description : This file contain TIMERS configration options 
Author      : Kerolos Maged Amin Fekry
Date        : 10/3/2026
Github      : https://github.com/KerolosMaged
========================================================*/


#ifndef TIMERS_CONFGR_H
#define TIMERS_CONFGR_H


/*------------ Counter Mode selection -----------*/
typedef enum {
    uint


}CNS_MODE;

/*------------ CLOCK selection -----------*/
typedef enum {

    uint8_t   CK_INT;       // APB BUS CLOCK
    uint8_t   CK_TIx;       // FRON EXTERNAL CLOCK IN PIN 
    uint8_t   CK_ETR;       // FRON EXTERNAL CLOCK IN PIN 
    uint8_t   CK_ITRx;      // INTERNAL CLOCK FROM ANOTHER TIMER

}Clk_SR;




#endif