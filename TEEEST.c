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
void LED_ACCESS(uint8_t port, uint8_t pin)
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



void BUTTON_ACCESS(uint8_t Copy_port,uint8_t Copy_pin)
{
	GPIO_Init_Def BUTTON;
	BUTTON.MODE = INPUT;
	BUTTON.PIN = Copy_pin;
	BUTTON.PULL = PULL_DOWN;
	GPIO_Init(Copy_port,&BUTTON);
}



/*================ MAIN =================*/
int main(void)
{
    /* Clock */
    RCC_VoidSysInit();

    /* Init Timer */
    TIMERs_VoidInit(TIMER1);

    /* GPIO PA8 -> TIM1_CH1 */
    LED_ACCESS(GPIOA, PIN8);

    /* PWM Setup */
    TIMERs_OutputCompareMode(
        TIM1,
        CH1,
        PWM_MODE_1,
        RISING_EDGE,
        PR_EN,
        999,     // ARR (1k resolution)
        0        // CCR start (0% duty)
    );

    /* Enable TIM1 main output */
    SET_BIT(TIM1->REG_BDTR, 15); // MOE

    /* Start timer */
    SET_BIT(TIM1->REG_CR1, 0);   // CEN

    while (1)
    {
        /* Fade IN */
        for (int i = 0; i <= 2999; i += 5)
        {
            TIM1->REG_CCR1 = i;
            for (volatile int d = 0; d < 20000; d++);
        }

        /* Fade OUT */
        for (int i = 2999; i >= 0; i -= 5)
        {
            TIM1->REG_CCR1 = i;
            for (volatile int d = 0; d < 20000; d++);
        }
    }
}
