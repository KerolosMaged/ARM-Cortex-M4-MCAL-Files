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

    //LED_ACCESS1(GPIOA, PIN8);

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


   // BUTTON_ACCESS(GPIOA, PIN11);
}

void TIMERs_VoidDelay_ms(TIMx_n *TIMx, uint32_t Copy_ms, uint32_t F_CLK_MHz)
{
    // PSC و ARR عشان نعمل 1ms لكل tick
    TIMx->REG_PSC = (F_CLK_MHz * 1000) - 1;  // 1 tick = 1ms
    TIMx->REG_ARR = Copy_ms - 1;
    TIMx->REG_CNT = 0;

    // Clear update flag
    TIMx->REG_SR &= ~(1 << 0);

    // Enable counter
    TIMx->REG_CR1 |= (1 << 0);

    // Wait until update flag (UIF)
    while(!(TIMx->REG_SR & (1 << 0)));

    // Stop counter
    TIMx->REG_CR1 &= ~(1 << 0);

    // IWDG refresh
    //*(volatile uint32_t*)0x40003000 = 0xAAAA;
}
/*================ MAIN =================*/

int main(void){

/*    RCC_VoidSysInit(RCC_HSE);


    //TIMERs_VoidInit(TIMER1);
    //TIMERs_VoidInit(TIMER3);


    LED_ACCESS(GPIOA, PIN3);



    //TIMERs_SetPWM(TIM1, CH1, PWM_MODE_1);
    //TIMERs_PWM_SetFreq(TIM1, 20000);
    //TIMERs_PWM_SetDuty(TIM1, CH1, 20);


    	GPIO_VoidWritePin(GPIOA, PIN3 ,HIGH);
*/
	// حط الكود ده في أول الـ main قبل أي حاجة




	    // كل شوية اعمل refresh للـ IWDG
	    // أو الأسهل — شغل الـ IWDG بنفسك بـ timeout كبير

	    *(volatile uint32_t*)0x40003000 = 0x5555; // KR - unlock PR & RLR
	    *(volatile uint32_t*)0x40003004 = 0x06;   // PR - prescaler /256
	    *(volatile uint32_t*)0x40003008 = 0xFFF;  // RLR - max reload = ~32 ثانية
	    *(volatile uint32_t*)0x40003000 = 0xAAAA; // KR - reload
	    *(volatile uint32_t*)0x40003000 = 0xCCCC; // KR - start

	    RCC_VoidSysInit(RCC_HSE);
	    SysTick_Init();
	    TIMERs_VoidInit(TIMER2);

	    LED_ACCESS(GPIOA, PIN3);
	    GPIO_VoidWritePin(GPIOA, PIN3, HIGH);

	    while(1){
	        GPIO_VoidWritePin(GPIOA, PIN3, HIGH);
	        // TIM2, delay 1000ms, clock 16MHz
	        TIMERs_VoidDelay_ms(TIM2, 5000, 25);
	        GPIO_VoidWritePin(GPIOA, PIN3, LOW);
	        // TIM2, delay 1000ms, clock 16MHz
	        TIMERs_VoidDelay_ms(TIM2, 1000, 25);
	        //*(volatile uint32_t*)0x40003000 = 0xAAAA; // IWDG refresh
	    }


}
