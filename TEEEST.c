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


/*================ LED (PA8 - TIM1_CH1) ================*/
void LED_ACCESS1(uint8_t port, uint8_t pin)
{
    GPIO_Init_Def led;

    led.PIN   = pin;
    led.MODE  = AF;
    led.OTYPE = OUTPUT_PUPD;
    led.SPEED = V_HIGH_SPEED;
    led.PULL  = NO_PULL;
    led.AFR   = 1;   // AF1 for TIM1

    GPIO_Init(port, &led);
}


void LED_ACCESS(uint8_t Copy_port,uint8_t Copy_pin){
	GPIO_Init_Def LED  ;
	LED.PIN = Copy_pin;
	LED.MODE = OUTPUT;
	LED.SPEED = V_HIGH_SPEED;
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

void TIMERs_Delay_ms(TIMx_n *TIMx, uint32_t Copy_ms)
{
    /*--- PSC يخلي كل tick = 1ms ---*/
    uint32_t PSC = (TIM_CLK / 1000) - 1;   // 24999 عند 25MHz

    TIMERs_Set_Counter(TIMx, DOWN, Edge_aligned, PSC, Copy_ms - 1);

    /*--- استنى لحد ما يحصل overflow ---*/
    while(GET_BIT(TIMx->REG_SR, 0) == 0);

    /*--- Clear الـ flag ---*/
    CLEAR_BIT(TIMx->REG_SR, 0);

    /*--- وقف العداد ---*/
    CLEAR_BIT(TIMx->REG_CR1, 0);
}

/*================ MAIN =================*/
int main(void)
{
    /* Clock */
    RCC_VoidSysInit();

    /* Init Timer */
    TIMERs_VoidInit(TIMER1);
    TIMERs_VoidInit(TIMER2);
    LED_ACCESS(GPIOC,PIN13);

    /* GPIO PA8 -> TIM1_CH1 */
    LED_ACCESS1(GPIOA, PIN8);

    /* PWM Setup */
    /*TIMERs_OutputCompareMode(
        TIM1,
        CH1,
        PWM_MODE_1,
        RISING_EDGE,
        PR_EN,
        999,     // ARR (1k resolution)
        0        // CCR start (0% duty)
    );*/


    /*TIMERs_OutputPWM(TIMx_n *TIMx,T_CH Copy_CH,OUTPUT_STATUS Copy_Status,T_Edge Copy_Edge, DIRx Copy_DIR , CNS_MODE Copy_Mode ,C_PSC Copy_psc,T_PR Copy_PRE ,uint32_t Copy_ARR,uint32_t Copy_CCR)*/
    TIMERs_OutputPWM(
    		TIM1,
			CH1,
			PWM_MODE_1,
			RISING_EDGE,
			UP,
			Edge_aligned,
			NONE,
			PR_EN,
			19999,
			0
        );



    while (1)
    {

    	GPIO_VoidTogglePin(GPIOC, PIN13);
    	TIMERs_Delay_ms(TIM2, 1000);
    }
}
