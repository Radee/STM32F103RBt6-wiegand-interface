/* INCLUDES *******************************************************************************************/
/*********************************************************************************************************/
#include "stm32f1xx.h"

/* FUNCTIONS PROTOTYPES *************************************************************************/
/*********************************************************************************************************/
void Gpio_Init(void);

/* FUNCTIONS *****************************************************************************************/
/*********************************************************************************************************/
void Gpio_Init(void)
{

	__IO uint32_t tmpreg;

	// Enable PORTs clocking
	RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN|RCC_APB2ENR_IOPCEN|RCC_APB2ENR_IOPDEN);
	tmpreg = (RCC->APB2ENR & (RCC_APB2ENR_IOPAEN|RCC_APB2ENR_IOPCEN|RCC_APB2ENR_IOPDEN));
	(void)tmpreg;

	// Configure which pins are launching EXTIx_IRQHandler
	AFIO->EXTICR[0] |= (AFIO_EXTICR1_EXTI2_PC|AFIO_EXTICR1_EXTI3_PC);

	// Enable interrupt and disable event as IRQ trigger
	EXTI->EMR &=~ (EXTI_IMR_IM2|EXTI_IMR_IM3);
	EXTI->IMR |= (EXTI_IMR_IM2|EXTI_IMR_IM3);

	// Set falling edge as IRQ trigger
	EXTI->RTSR &=~ (EXTI_IMR_IM2|EXTI_IMR_IM3);
	EXTI->FTSR |= (EXTI_IMR_IM2|EXTI_IMR_IM3);

	// Set pull-up on EXTI-pins
	GPIOC->ODR |= 0x0CUL;

	// Set pins as input
	GPIOC->CRL &= 0xFFFF00FFUL;
	GPIOC->CRL |= 0x8800UL;

	// Set priority grouping and enable EXTI_IRQ
	NVIC_SetPriority(EXTI2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI2_IRQn);
  NVIC_SetPriority(EXTI3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(EXTI3_IRQn);

}

