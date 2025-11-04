// led.c
#include "led.h"

void LED_Init(void)
{
    RCC->APB2ENR |= (1 << 4);   // Enable GPIOC clock
    GPIOC->CRH &= ~(0xF << 20); // Clear config for PC13
    GPIOC->CRH |= (0x2 << 20);  // Output mode, 2MHz
}

void LED_On(void)
{
    GPIOC->BSRR = (1 << 13);
}

void LED_Off(void)
{
    GPIOC->BRR = (1 << 13);
}
