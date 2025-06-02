#ifndef NVIC_H
#define NVIC_H

#include <stdint.h>

typedef struct nvic_t
{
    uint32_t ISER[8];        // Interrupt Set Enable Register
    uint32_t Reserved_0[24]; // Reserved space
    uint32_t ICER[8];        // Interrupt Clear Enable Register
    uint32_t Reserved_1[24]; // Reserved space
    uint32_t ISPR[8];        // Interrupt Set Pending Register
    uint32_t Reserved_2[24]; // Reserved space
    uint32_t ICPR[8];        // Interrupt Clear Pending Register
    uint32_t Reserved_3[24]; // Reserved space
    uint32_t IABR[8];        // Interrupt Active Bit Register
    uint32_t Reserved_4[56]; // Reserved space
    uint32_t IPR[60];        // Interrupt Priority Register
    uint32_t Reserved_5[580]; // Reserved space
    uint32_t STIR;           // Software Trigger Interrupt Register
} nvic_registers_t;

#define NVIC_BASE_ADDRESS 0xE000E100

#define NVIC ((nvic_registers_t *)NVIC_BASE_ADDRESS)

void nvicEnableInterrupt(uint32_t interruptNumber);
void nvicDisableInterrupt(uint32_t interruptNumber);
void nvicSetPending(uint32_t interruptNumber);
uint8_t nvicGetInterruptEnabled(uint32_t interruptNumber);
uint8_t nvicGetInterruptPending(uint32_t interruptNumber);
uint32_t nvicGetActive(uint32_t interruptNumber);
void nvicSetPriority(uint32_t interruptNumber, uint32_t priority);
uint32_t nvicGetPriority(uint32_t interruptNumber);
void nvicSoftwareTrigger(uint32_t interruptNumber);
#endif // NVIC_H