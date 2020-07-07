/* INCLUDES *******************************************************************************************/
/*********************************************************************************************************/
#include "stm32f1xx.h"

/* FUNCTIONS PROTOTYPES *************************************************************************/
/*********************************************************************************************************/
void Timer_Init(void);
void msDelay(uint32_t delay);

/* VARIABLES ******************************************************************************************/
/*********************************************************************************************************/
__IO uint32_t vDelayTimerValue = 0;

/* FUNCTIONS *****************************************************************************************/
/*********************************************************************************************************/

void Timer_Init(void)
{
	__IO uint32_t tmpreg;

	// Enable TIM1 clocking
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	tmpreg = (RCC->APB2ENR & RCC_APB2ENR_TIM1EN);
	(void)tmpreg;

	// Set priority grouping and enable TIM1_IRQ
	NVIC_SetPriority(TIM1_UP_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(TIM1_UP_IRQn);

  // Set clock division, aligned mode, counter direction
	TIM1->CR1 &=~ (TIM_CR1_DIR | TIM_CR1_CMS | TIM_CR1_CKD);

	//  Set auto-reload value
	TIM1->ARR = 0x257UL;

	//  Set prescaler value
	TIM1->PSC = 0x1C1FUL;

	//  Set repetition counter value
	TIM1->RCR = 0x00UL;

	//  Generates an update of the registers
	TIM1->EGR |= TIM_EGR_UG;

	// Auto-reload preload disable
	TIM1->CR1 &=~ TIM_CR1_ARPE;

	// Set one pulse mode
	TIM1->CR1 &=~ TIM_CR1_OPM;
	TIM1->CR1 |= TIM_CR1_OPM;

	// The update event is selected as trigger output (TRGO)
	TIM1->CR2 &=~ TIM_CR2_MMS;
	TIM1->CR2 |= TIM_CR2_MMS_1;

	// Update interrupt enable
	TIM1->DIER |= TIM_DIER_UIE;

}
/********************************************/
/*******************************************/

//	Miliseconds dellay functions
void msDelay(uint32_t delay)
{
	vDelayTimerValue = delay;

	while(vDelayTimerValue);
}
/********************************************/
/*******************************************/

//	SysTick interrupt handle
void SysTick_Handler(void)
{
	vDelayTimerValue--;
}
/********************************************/
/*******************************************/

