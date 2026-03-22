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


uint8_t LED2_State = 0;

void MyCallback(void){
    if(LED2_State == 0){
        // ضغطة أولى → نور LED2 وأوقف الفلاشنج
        LED2_State = 1;
        GPIO_VoidWritePin(GPIOB, PIN13, HIGH);
    }
    else{
        // ضغطة تانية → طفي LED2 وارجع فلاشنج
        LED2_State = 0;
        GPIO_VoidWritePin(GPIOB, PIN13, LOW);
    }
}

int main(void)
{
    RCC_VoidSysInit();

    LED_ACCESS(GPIOB, PIN12);
    LED_ACCESS(GPIOB, PIN13);
    BUTTON_ACCESS(GPIOA, PIN0);

    EXTI_Init(GPIOA, PIN0, Rising_trigger);
    EXTI_SetCallBack(PIN0, MyCallback);
    NVIC_EnableIRQ(NVIC_EXTI0);
    EXTI_VoidEnable(PIN0, INTERRUPT);

    while(1){

        // LED1 دايماً فلاشنج
        GPIO_VoidWritePin(GPIOB, PIN12, HIGH);
        delay();

        // شغل LED2 لو state = 1
        if(LED2_State){
            GPIO_VoidWritePin(GPIOB, PIN13, HIGH);
        } else {
            GPIO_VoidWritePin(GPIOB, PIN13, LOW);
        }

        GPIO_VoidWritePin(GPIOB, PIN12, LOW);
        delay();

        // تأكد تاني بعد التأخير
        if(LED2_State){
            GPIO_VoidWritePin(GPIOB, PIN13, HIGH);
        } else {
            GPIO_VoidWritePin(GPIOB, PIN13, LOW);
        }
    }
}
