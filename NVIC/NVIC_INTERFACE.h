#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#include "../LIB/STD_TYPES_MATH.h"

void NVIC_EnableIRQ(IRQn_Type IRQn);

void NVIC_DisableIRQ(IRQn_Type IRQn);

void NVIC_SetPendingIRQ(IRQn_Type IRQn);

void NVIC_ClearPendingIRQ(IRQn_Type IRQn);

uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn);

void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);

uint32_t NVIC_GetPriority(IRQn_Type IRQn);




#endif