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



void delay(void)
{
    for(volatile int i=0;i<500000;i++);
}


void LED_ACCESS(uint8_t Copy_port,uint8_t Copy_pin){
	GPIO_Init_Def LED  ;
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

int main(void)
{
	RCC_VoidSysInit();
	//GPIO_Init_Def LED_config;

	LED_ACCESS(GPIOA,PIN12);
	BUTTON_ACCESS(GPIOA,PIN11);

	while(1){
	    uint8_t BUTTONSTATUS = GPIO_uint8_tReadPin(GPIOA, PIN11);

	    if(BUTTONSTATUS == 1)
	    {
	        GPIO_VoidWritePin(GPIOA, PIN12, HIGH);
	    }
	    else
	    {
	        GPIO_VoidWritePin(GPIOA, PIN12, LOW);
	    }

    //delay();
	}
}

