#include "int_vector_table.h"

extern uint32_t _stack_end;      // Defined in the linker script
extern void reset_handler(void); // Defined in the startup code


void default_handler(void)
{
    // Default handler for unhandled interrupts
    while (1)
    {
        // Infinite loop to indicate an unhandled interrupt
    }
}

uint32_t *__attribute__((section(".isr_vector"))) isr_vector[] = {
    (uint32_t *)&_stack_end,        // Initial stack pointer
    (uint32_t *)reset_handler,      // Reset Handler
    (uint32_t *)NMI_Handler,        // NMI Handler
    (uint32_t *)HardFault_Handler,  // Hard Fault Handler
    (uint32_t *)MemManage_Handler,  // Memory Management Fault Handler
    (uint32_t *)BusFault_Handler,   // Bus Fault Handler
    (uint32_t *)UsageFault_Handler, // Usage Fault Handler
    0, 0, 0, 0,                     // Reserved
    (uint32_t *)SVC_Handler,        // SVC Handler
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
};