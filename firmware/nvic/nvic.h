#ifndef NVIC_H
#define NVIC_H

#include <stdint.h>

void nvicEnableInterrupt(uint32_t interruptNumber);
void nvicDisableInterrupt(uint32_t interruptNumber);
void nvicSetPending(uint32_t interruptNumber);
uint8_t nvicGetInterruptEnabled(uint32_t interruptNumber);
uint8_t nvicGetInterruptPending(uint32_t interruptNumber);
uint32_t nvicGetActive(uint32_t interruptNumber);
void nvicSetPriority(uint32_t interruptNumber, uint32_t priority);
uint32_t nvicGetPriority(uint32_t interruptNumber);

#endif // NVIC_H