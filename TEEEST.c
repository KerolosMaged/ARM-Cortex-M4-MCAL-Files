#include "RCC/RCC_INTERFACE.h"
#include "RCC/RCC_PRIVATE.h"
#include "RCC/RCC_CONFGR.h"

#include "LIB/STD_TYPES_MATH.h"

#include "GPIO/GPIO_INTERFACE.h"
#include "GPIO/GPIO_PRIVATE.h"
#include "GPIO/GPIO_CONFGR.h"

#include "NVIC/NVIC_CONFGR.h"
#include "NVIC/NVIC_INTERFACE.h"
#include "NVIC/NVIC_PRIVATE.h"

#include "SYSCFG/SYSCFG_CONFGR.h"
#include "SYSCFG/SYSCFG_INTERFACE.h"
#include "SYSCFG/SYSCFG_PRIVATE.h"

#include "SYSTICK/SYSTICK_CONFGR.h"
#include "SYSTICK/SYSTICK_INTERFACE.h"
#include "SYSTICK/SYSTICK_PRIVATE.h"

#include "EXTI/EXTI_CONFGR.h"
#include "EXTI/EXTI_INTERFACE.h"
#include "EXTI/EXTI_PRIVATE.h"

#include "TIMERS/TIMERS_CONFGR.h"
#include "TIMERS/TIMERS_INTERFACE.h"
#include "TIMERS/TIMERS_PRIVATE.h"

#include "WDG/WDG_CONFGR.h"
#include "WDG/WDG_INTERFACE.h"
#include "WDG/WDG_PRIVATE.h"


/*================ LED (PA8 - TIM1_CH1) ================*/
void LED_ACCESS1(uint8_t port, uint8_t pin)
{
    GPIO_Init_Def led;
    led.PIN   = pin;
    led.MODE  = AF;
    led.OTYPE = OUTPUT_PP;
    led.SPEED = MID_SPEED;
    led.PULL  = NO_PULL;
    led.AFR   = 1;   /* AF1 for TIM1 */

    GPIO_Init(port, &led);

    /* LED_ACCESS1(GPIOA, PIN8); */
}


void LED_ACCESS(uint8_t Copy_port, uint8_t Copy_pin){
    GPIO_Init_Def LED;
    LED.PIN   = Copy_pin;
    LED.MODE  = OUTPUT;
    LED.OTYPE = OUTPUT_PP;
    LED.SPEED = LOW_SPEED;
    LED.PULL  = NO_PULL;
    GPIO_Init(Copy_port, &LED);
}


void BUTTON_ACCESS(uint8_t Copy_port, uint8_t Copy_pin)
{
    GPIO_Init_Def BUTTON;
    BUTTON.MODE = INPUT;
    BUTTON.PIN  = Copy_pin;
    BUTTON.PULL = PULL_UP;
    GPIO_Init(Copy_port, &BUTTON);

    /* BUTTON_ACCESS(GPIOA, PIN11); */
}




/*================ MAIN =================*/

int main(void){

    RCC_VoidSysInit(RCC_HSE);
    IWDG_VoidInit();

    TIMERs_VoidInit(TIMER2, HSE_CLK);
    SysTick_Init();
    LED_ACCESS(GPIOC, PIN13);
    //BUTTON_ACCESS(GPIOA, PIN0);
    while(1)
    {
            GPIO_VoidWritePin(GPIOC, PIN13, HIGH);
            //TIMERs_VoidDelay_ms(TIM2, 2000);
            SysTick_VoidDelay_ms(2000);
            GPIO_VoidWritePin(GPIOC, PIN13, LOW);
            //TIMERs_VoidDelay_ms(TIM2, 500);
            SysTick_VoidDelay_ms(500);
            IWDG_VoidRefresh();

    }

}
