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


/*================ LED (PA8 - TIM1_CH1) ================*/
void LED_ACCESS1(uint8_t port, uint8_t pin)
{
    GPIO_Init_Def led;
    led.PIN   = pin;
    led.MODE  = AF;
    led.OTYPE = OUTPUT_PP;
    led.SPEED = MID_SPEED;
    led.PULL  = NO_PULL;
    led.AFR   = 1;   // AF1 for TIM1

    GPIO_Init(port, &led);
}


void LED_ACCESS(uint8_t Copy_port,uint8_t Copy_pin){
	GPIO_Init_Def LED  ;
	LED.PIN = Copy_pin;
	LED.MODE = OUTPUT;
    LED.OTYPE = OUTPUT_PP;
	LED.SPEED = LOW_SPEED;
    LED.PULL  = NO_PULL;
	GPIO_Init(Copy_port,&LED);
}

void BUTTON_ACCESS(uint8_t Copy_port,uint8_t Copy_pin)
{
	GPIO_Init_Def BUTTON;
	BUTTON.MODE = INPUT;
	BUTTON.PIN = Copy_pin;
	BUTTON.PULL = PULL_DOWN;
	GPIO_Init(Copy_port,&BUTTON);
}


/*================ MAIN =================*/

int main(void){

    RCC_VoidSysInit(RCC_HSE);


    TIMERs_VoidInit(TIMER1);
    TIMERs_VoidInit(TIMER3);


    LED_ACCESS(GPIOB, PIN5);
    BUTTON_ACCESS(GPIOA, PIN11);
    LED_ACCESS1(GPIOA, PIN8);

    TIMERs_SetPWM(TIM1, CH1, PWM_MODE_1);
    TIMERs_PWM_SetFreq(TIM1, 20000);
    TIMERs_PWM_SetDuty(TIM1, CH1, 20);

    TIMERs_InputCaptureInit(TIM3,CH1,24,RISING_EDGE);

    uint32_t t_rise = 0, t_fall = 0 , echo_width = 0;
    f32 distance_cm = 0;
    distance_cm = echo_width / 58.0f;

    while(1){
    	   TIMERs_IC_SetEdge(TIM3, CH1, RISING_EDGE);
    	    t_rise = TIMERs_IC_GetValue(TIM3, CH1);

    	    TIMERs_IC_SetEdge(TIM3, CH1, FALLING_EDGE);
    	    t_fall = TIMERs_IC_GetValue(TIM3, CH1);
    	    if (t_fall >= t_rise)
    	        echo_width = t_fall - t_rise;
    	    else
    	        echo_width = (0xFFFF - t_rise) + t_fall;

    	uint32_t Echo = TIMERs_IC_GetValue(TIM3,CH1);

    }


}
