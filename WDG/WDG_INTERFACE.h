/*========================================================
File        : WDG_INTERFACE
Description : This file contain the declerations of IWDG & WWDG functions 
Author      : Kerolos Maged Amin Fekry
Date        : 7/5/2026
Github      : https://github.com/KerolosMaged
========================================================*/
#ifndef     WDG_INTERFACE_H
#define     WDG_INTERFACE_H

#include "WDG_CONFGR.h"
#include "WDG_PRIVATE.h"
/*===========================================================*/
/*========================= IWDG =========================== */
/*===========================================================*/

/*------ Initialization the Independent WGD -------*/

void IWDG_VoidInit(void);

/*---- Refresh the IWDG----*/

void IWDG_VoidRefresh(void);


/*===========================================================*/
/*========================= WWDG =========================== */
/*===========================================================*/

/*------ Initialization the window WGD -------*/
void WWDG_VoidInit(CK_CNT_PSC Copy_psc,uint8_t Copy_Window);

/*---- Refresh the WWDG----*/
void WWDG_VoidRefresh(uint8_t Copy_CNT);

/*------- Enable Interrupt WWDG ------*/
void WWDG_EnableEWI(void);

/*------- Read Interrupt Flag ------*/
uint8_t WWDG_GetResetFlag(void);

/*------ Clear Interrupt Flag ----- */
void WWDG_ClearResetFlag(void);

#endif
