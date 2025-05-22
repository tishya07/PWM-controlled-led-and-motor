/*
 * ECE 153B
 *
 * Name(s): Tishya Chauhan and Hannah Walker
 * Section: Wed and Tue
 * Lab: 3A
 */

#include "SysTimer.h"

uint32_t volatile msTicks;

void SysTick_Init(void) {
	// SysTick Control & Status Register
	SysTick->CTRL = 0; // Disable SysTick IRQ and SysTick Counter
	
	// SysTick Reload Value Register
	SysTick->LOAD = 999; // [TODO] - Enter the correct LOAD value that will give us a 1 ms period
	
	// SysTick Current Value Register
	SysTick->VAL = 0;
	
	// Configure and Enable SysTick interrupt in NVIC
	NVIC_EnableIRQ(SysTick_IRQn);
	NVIC_SetPriority(SysTick_IRQn, 1); // Set Priority to 1
	
	// Enables SysTick exception request
	// 1 = counting down to zero asserts the SysTick exception request
	// 0 = counting down to zero does not assert the SysTick exception request
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	
	// Select clock source
	// If CLKSOURCE = 0, the external clock is used. The frequency of SysTick clock is the frequency of the AHB clock divided by 8.
	// If CLKSOURCE = 1, the processor clock is used.
	SysTick->CTRL &= ~SysTick_CTRL_CLKSOURCE_Msk;		
	
	// Enable SysTick IRQ and SysTick Timer
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;  
}

void SysTick_Handler(void) {
	++msTicks;
}

void delay(uint32_t T) {
	uint32_t currentTicks; // Hint: It may be helpful to keep track of what the current tick count is
	currentTicks = msTicks;
	
	while ((msTicks - currentTicks) < T);	// [TODO] - Implement function that waits until a time specified by argument T
}