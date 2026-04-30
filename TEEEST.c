#include "RCC/RCC_INTERFACE.h"
#include "RCC/RCC_PRIVATE.h"
#include "RCC/RCC_CONFGR.h"

#include "GPIO/GPIO_INTERFACE.h"
#include "GPIO/GPIO_PRIVATE.h"
#include "GPIO/GPIO_CONFGR.h"

#include "NVIC/NVIC_CONFGR.h"
#include "NVIC/NVIC_INTERFACE.h"
#include "NVIC/NVIC_PRIVATE.h"

#include "SYSCFG/SYSCFG_CONFGR.h"
#include "SYSCFG/SYSCFG_INTERFACE.h"
#include "SYSCFG/SYSCFG_PRIVATE.h"

#include "EXTI/EXTI_CONFGR.h"
#include "EXTI/EXTI_INTERFACE.h"
#include "EXTI/EXTI_PRIVATE.h"

#include "TIMERS/TIMERS_CONFGR.h"
#include "TIMERS/TIMERS_INTERFACE.h"
#include "TIMERS/TIMERS_PRIVATE.h"



void LED_ACCESS(uint8_t Copy_port,uint8_t Copy_pin){
	GPIO_Init_Def LED  ;
	LED.SPEED = V_HIGH_SPEED;
	LED.MODE = OUTPUT;
	LED.PIN = Copy_pin;
	GPIO_Init(Copy_port,&LED);
}

void BUTTON_ACCESS(uint8_t Copy_port,uint8_t Copy_pin){
	GPIO_Init_Def BUTTON;
	BUTTON.MODE = INPUT;
	BUTTON.PIN = Copy_pin;
	BUTTON.PULL = PULL_DOWN;
	GPIO_Init(Copy_port,&BUTTON);

}


uint8_t LED2_State = 0;





int main(void)
{
	RCC_VoidSysInit();
	Void_TIMx_Init(TIM11_ID);




	Void_Set_Counter(TIM11,UP,Edge_aligned,2499,2999);
	LED_ACCESS(GPIOC,PIN13);

	while (1){
		GPIO_VoidWritePin(GPIOC,PIN13, HIGH);

        while(GET_BIT(TIM11->REG_SR,0) == 0);
        CLEAR_BIT(TIM11->REG_SR,0);
		GPIO_VoidWritePin(GPIOC,PIN13, LOW);

        while(GET_BIT(TIM11->REG_SR,0) == 0);
        CLEAR_BIT(TIM11->REG_SR,0);
	}

}

