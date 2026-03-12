#include "RCC/RCC_INTERFACE.h"
#include "RCC/RCC_PRIVATE.h"
#include "RCC/RCC_CONFGR.h"

#include "GPIO/GPIO_INTERFACE.h"
#include "GPIO/GPIO_PRIVATE.h"
#include "GPIO/GPIO_CONFGR.h"

void delay(void)
{
    for(volatile int i=0;i<500000;i++);
}




int main(void)
{
	RCC_VoidSysInit();

	//GPIO_Init_Def LED_config;
	GPIO_Init_Def BUTTON;
	GPIO_Init_Def LED  ;
	LED.MODE = OUTPUT;
	LED.PIN = PIN12;
	BUTTON.MODE = INPUT;
	BUTTON.PIN = PIN11;
	BUTTON.PULL = PULL_DOWN;
	GPIO_Init(GPIOA,&BUTTON);
	GPIO_Init(GPIOA,&LED);
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

