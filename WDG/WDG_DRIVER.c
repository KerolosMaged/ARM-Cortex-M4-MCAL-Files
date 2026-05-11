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
    PSC_n PSC = PSC_256 ;
    /*--- Unlock registers to write ---*/
    IWDG->IWDG_KR = 0x5555 ; 
    /*--- Prescaler ---*/
    IWDG->IWDG_PR = PSC ;
    /*--- value of counter ---*/
    IWDG->IWDG_RLR = 0xFFF ;
    /*--- check for values in RLR , PR*/
    while(IWDG->IWDG_SR != 0);
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

/*------ Initialization the window WGD -------*/
void WWDG_VoidInit(CK_CNT_PSC Copy_psc,uint8_t Copy_Window){
    /*----- Enable RCC APB1 ------*/
    RCC_VoidStatusPeripheral_CLK(RCC_APB1,WWDGEN,ENABLE);
    /*--- Clear and set the PSC ---*/
    WWDG->WWDG_CFR &= ~(0x3 << 7);
    WWDG->WWDG_CFR |= (Copy_psc << 7);
    /*--- Clear and set the Window ---*/
    WWDG->WWDG_CFR &= ~(0x7F );
    WWDG->WWDG_CFR |= (0x7F & Copy_Window );

    /*--- Set counter Value ---*/
    WWDG->WWDG_CR = 0x7F  ;
    /*--- Enable WWDG---*/
    SET_BIT(WWDG->WWDG_CR,7); 



}

/*---- Refresh the WWDG----*/
void WWDG_VoidRefresh(uint8_t Copy_CNT){
    Copy_CNT &= 0x7F;

    if(Copy_CNT < 0x40)
    {
        Copy_CNT = 0x40;
    }

    WWDG->WWDG_CR = (Copy_CNT | 0x80); 
}

/*------- Enable Interrupt WWDG ------*/
void WWDG_EnableEWI(void){


    SET_BIT(WWDG->WWDG_CFR,9);


}
/*------- Read Interrupt Flag ------*/

uint8_t WWDG_GetResetFlag(void){

    uint8_t EWIF = 0 ;
    EWIF = GET_BIT(WWDG->WWDG_SR,0); 
    return EWIF;
}

/*------ Clear Interrupt Flag ----- */
void WWDG_ClearResetFlag(void){
    CLEAR_BIT(WWDG->WWDG_SR, 0);
}
