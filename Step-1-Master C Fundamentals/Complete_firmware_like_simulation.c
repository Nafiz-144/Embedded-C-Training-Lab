#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// ======== Step 1: Simulate Hardware Registers =========

// ধরা যাক একটা virtual GPIO register আছে
typedef struct
{
    volatile uint32_t ODR; // Output Data Register (LED control)
    volatile uint32_t IDR; // Input Data Register (Switch input)
} GPIO_TypeDef;

// ধরো আমাদের hardware address 0x40020000
#define GPIOA_BASE (0x40020000UL)
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)

// ======== Step 2: Enum for LED state =========
typedef enum
{
    LED_OFF = 0,
    LED_ON = 1
} LedState_t;

// ======== Step 3: System State Machine =========
typedef enum
{
    SYS_IDLE,
    SYS_RUNNING,
    SYS_ERROR
} SystemState_t;

// ======== Step 4: Function prototypes =========
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t pin, LedState_t state);
void delay(uint32_t count);
void System_Run(void);

// ======== Step 5: Global variable =========
volatile SystemState_t currentState = SYS_IDLE;

// ======== Step 6: Main Function =========
int main(void)
{
    printf("System Booting...\n");
    currentState = SYS_RUNNING;

    // main loop
    while (1)
    {
        System_Run();
    }
    return 0;
}

// ======== Step 7: GPIO Write Function =========
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t pin, LedState_t state)
{
    if (state == LED_ON)
        GPIOx->ODR |= (1 << pin); // bit set
    else
        GPIOx->ODR &= ~(1 << pin); // bit clear
}

// ======== Step 8: System Run Function =========
void System_Run(void)
{
    static LedState_t ledState = LED_OFF;

    if (currentState == SYS_RUNNING)
    {
        // Toggle LED state
        ledState = (ledState == LED_OFF) ? LED_ON : LED_OFF;

        // Write to virtual register
        GPIO_WritePin(GPIOA, 5, ledState);

        // Show result
        printf("LED %s | GPIOA->ODR = 0x%08X\n",
               (ledState == LED_ON) ? "ON" : "OFF",
               GPIOA->ODR);

        delay(1000000);
    }
    else if (currentState == SYS_ERROR)
    {
        printf("System in ERROR state!\n");
    }
}

// ======== Step 9: Delay Function =========
void delay(uint32_t count)
{
    for (volatile uint32_t i = 0; i < count; i++)
        ;
}
