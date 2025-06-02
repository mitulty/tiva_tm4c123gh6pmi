#ifndef INT_VECTOR_TABLE_H
#define INT_VECTOR_TABLE_H

#include <stdint.h>

extern void default_handler(void); // Default handler for unhandled interrupts

void NMI_Handler(void) __attribute__((weak, alias("default_handler")));
void HardFault_Handler(void) __attribute__((weak, alias("default_handler")));
void MemManage_Handler(void) __attribute__((weak, alias("default_handler")));
void BusFault_Handler(void) __attribute__((weak, alias("default_handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("default_handler")));
void SVC_Handler(void) __attribute__((weak, alias("default_handler")));
void Debug_Handler(void) __attribute__((weak, alias("default_handler")));
void PendSV_Handler(void) __attribute__((weak, alias("default_handler")));
void SysTick_Handler(void) __attribute__((weak, alias("default_handler")));
#endif // INT_VECTOR_TABLE_H