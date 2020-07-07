/* INCLUDES *******************************************************************************************/
/*********************************************************************************************************/
#include "stm32f1xx.h"

/* FUNCTIONS PROTOTYPES *************************************************************************/
/*********************************************************************************************************/
void Rcc_Init(void);

/* FUNCTIONS *****************************************************************************************/
/*********************************************************************************************************/
void Rcc_Init(void)
{
	__IO uint32_t tmpreg;

	// Enable AFIO clocking
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	tmpreg = (RCC->APB2ENR & RCC_APB2ENR_AFIOEN);
	(void)tmpreg;

	// Set flash latency
	FLASH->ACR &=~ FLASH_ACR_LATENCY;
	FLASH->ACR |= FLASH_ACR_LATENCY_1;

	// Set bypass as HSE source and enable HSE
	RCC->CR |= RCC_CR_HSEBYP;
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));

	// Set  and enable PLL
	RCC->CFGR &=~ (RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL);
	RCC->CFGR |= (RCC_CFGR_PLLSRC|RCC_CFGR_PLLMULL9);
	RCC->CR |= RCC_CR_PLLON;
	while (!(RCC->CR & RCC_CR_PLLRDY));

	// Set  AHB prescaler
	RCC->CFGR &=~ RCC_CFGR_HPRE;
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

	// Set  APB1 prescaler
	RCC->CFGR &=~ RCC_CFGR_PPRE1;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

	// Set  APB2 prescaler
	RCC->CFGR &=~ RCC_CFGR_PPRE2;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;

	// Set  PLL as SYSCLK source
	RCC->CFGR &=~ RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);

	//	Update SystemCoreClock
	SystemCoreClockUpdate();

	//	Set systick
	SysTick_Config(SystemCoreClock / 1000);

}



