#include "systick.h"

void systick_init(void)
{
    // Enable the system tick timer
    SysTick->CTRL = 0;                                                                   // Disable SysTick during setup
    SysTick->LOAD = 16000000 - 1;                                                        // Load value for 1 second at 16 MHz clock
    SysTick->VAL = 0;                                                                    // Clear current value
    // SysTick->CTRL = SYSTICK_CTRL_CLKSOURCE | SYSTICK_CTRL_TICKINT | SYSTICK_CTRL_ENABLE; // Enable SysTick with interrupt and processor clock
    SysTick->CTRL = SYSTICK_CTRL_ENABLE; // Enable SysTick
}

void systick_delay(uint32_t delay_ms)
{
    uint32_t start = SysTick->VAL;       // Get the current value of SysTick
    uint32_t ticks = (16000 * delay_ms); // Calculate the number of ticks for the delay

    while ((start - SysTick->VAL) < ticks) // Wait until the specified delay has passed
    {
        // Do nothing, just wait
    }
}

void systick_reset(void)
{
    SysTick->CTRL &= ~SYSTICK_CTRL_ENABLE; // Disable SysTick
    SysTick->VAL = 0;                      // Clear current value
    SysTick->CTRL |= SYSTICK_CTRL_ENABLE;  // Re-enable SysTick
}

void systick_enable(void)
{
    SysTick->CTRL |= SYSTICK_CTRL_ENABLE; // Enable SysTick
}

void systick_disable(void)
{
    SysTick->CTRL &= ~SYSTICK_CTRL_ENABLE; // Disable SysTick
}

void systick_set_reload(uint32_t reload_value)
{
    SysTick->LOAD = reload_value - 1; // Set the reload value
}

uint32_t systick_get_current_value(void)
{
    return SysTick->VAL; // Return the current value of SysTick
}

//*****************************************************************************
//
// SysTick interrupt handler
//*****************************************************************************
void SysTick_Handler(void)
{
    // This function is called when the SysTick timer reaches zero.
}