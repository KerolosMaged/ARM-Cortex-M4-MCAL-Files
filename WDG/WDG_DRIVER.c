/*========================================================
File        : WDG_INTERFACE
Description : This file contain the definetions of WDG functions and source file of IWDG & WWDG
Author      : Kerolos Maged Amin Fekry
Date        : 7/5/2026
Github      : https://github.com/KerolosMaged
========================================================*/

/********** Include STD_TYPES_MATH file ***********/
#include "../LIB/STD_TYPES_MATH.h"
/*********** Include of RCC files  **********/
#include "../RCC/RCC_CONFGR.h"
#include "../RCC/RCC_INTERFACE.h"
#include "../RCC/RCC_PRIVATE.h"
/*********** Include of WDG files  **********/
#include "WDG_CONFGR.h"
#include "WDG_INTERFACE.h"
#include "WDG_PRIVATE.h"




/*===========================================================*/
/*========================= IWDG =========================== */
/*===========================================================*/

/*------ Initialization the Independent WGD -------*/
void IWDG_VoidInit(void ){
    /*--- PSC CHOOSE ---*/
    IWDG_n PSC = PSC_256 ;
    /*--- Unlock registers to write ---*/
    IWDG->IWDG_KR = 0x5555 ; 
    /*--- Prescaler ---*/
    IWDG->IWDG_PR = PSC ;
    /*--- value of counter ---*/
    IWDG->IWDG_RLR = 0xFFF ;
    /*--- check for values in RLR , PR*/
    while(IWDG->SR != 0);
    /*---- reload counter ----*/
    IWDG->IWDG_KR = 0xAAAA ;
    /*---- Starts count down */
    IWDG->IWDG_KR = 0xCCCC ;


}

/*---- Refresh the IWDG----*/

void IWDG_VoidRefresh(void){

    IWDG->IWDG_KR = 0xAAAA;

}



/*===========================================================*/
/*========================= WWDG =========================== */
/*===========================================================*/
