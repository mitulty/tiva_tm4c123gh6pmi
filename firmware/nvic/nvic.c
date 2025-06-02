#include "nvic.h"

void nvicEnableInterrupt(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        NVIC->ISER[interruptNumber / 32] = (1 << (interruptNumber % 32));
    }
}

void nvicDisableInterrupt(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        NVIC->ICER[interruptNumber / 32] = (1 << (interruptNumber % 32));
    }
}

uint8_t nvicGetInterruptEnabled(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        return ((NVIC->ISER[interruptNumber / 32] & (1 << (interruptNumber % 32))) != 0 ) ? 1 : 0;
    }
    return 0; // Return 0 if the interrupt number is invalid
}

void nvicSetPending(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        NVIC->ISPR[interruptNumber / 32] = (1 << (interruptNumber % 32));
    }
}

void nvicClearPending(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        NVIC->ICPR[interruptNumber / 32] = (1 << (interruptNumber % 32));
    }
}

uint8_t nvicGetInterruptPending(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        return ((NVIC->ISPR[interruptNumber / 32] & (1 << (interruptNumber % 32))) != 0 ) ? 1 : 0;
    }
    return 0; // Return 0 if the interrupt number is invalid
}

uint32_t nvicGetActive(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        return (NVIC->IABR[interruptNumber / 32] & (1 << (interruptNumber % 32))) != 0;
    }
    return 0; // Return 0 if the interrupt number is invalid
}
uint32_t nvicGetPriority(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        int registerIndex = interruptNumber / 4; // Each priority register holds 4 interrupts
        int bitOffset = (interruptNumber % 4) * 8; // Each interrupt priority is 8 bits
        // Extract the priority for the specific interrupt
        uint32_t priority = (NVIC->IPR[registerIndex] >> bitOffset) & 0xFF; // Mask to get the 8 bits
        return priority; // Return the priority value
    }
    return 0; // Return 0 if the interrupt number is invalid
}
void nvicSetPriority(uint32_t interruptNumber, uint32_t priority)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        int registerIndex = interruptNumber / 4; // Each priority register holds 4 interrupts
        int bitOffset = (interruptNumber % 4) * 8; // Each interrupt priority is 8 bits
        // Clear the bits for the specific interrupt
        NVIC->IPR[registerIndex] &= ~(0xFF << bitOffset);
        // Set the new priority
        NVIC->IPR[registerIndex] |= (priority & 0xFF) << bitOffset; // Ensure priority is within valid range
    }
}

void nvicSetAllInterruptsEnabled(void)
{
    for (int i = 0; i < 8; i++)
    {
        NVIC->ISER[i] = 0xFFFFFFFF; // Enable all interrupts
    }
}

void nvicSetAllInterruptsDisabled(void)
{
    for (int i = 0; i < 8; i++)
    {
        NVIC->ICER[i] = 0xFFFFFFFF; // Disable all interrupts
    }
}

void nvicSetAllInterruptsPending(void)
{
    for (int i = 0; i < 8; i++)
    {
        NVIC->ISPR[i] = 0xFFFFFFFF; // Set all interrupts as pending
    }
}

void nvicClearAllInterruptsPending(void)
{
    for (int i = 0; i < 8; i++)
    {
        NVIC->ICPR[i] = 0xFFFFFFFF; // Clear all pending interrupts
    }
}

void nvicSoftwareTrigger(uint32_t interruptNumber)
{
    if (interruptNumber < 240) // Check if the interrupt number is valid
    {
        NVIC->STIR = interruptNumber; // Software trigger the specified interrupt
    }
}