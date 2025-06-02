#include "int_vector_table.h"
#include "cm4_defines.h"

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

// Array to hold custom interrupt handlers
ISRHandler __attribute__((section(".external_interrupts_table"))) externalInterrupt[240] = {[0 ... 239] = default_handler};

ISRHandler __attribute__((section(".int_vector_table"))) int_vector_table[] = {
    (ISRHandler)&_stack_end, // Initial stack pointer
    reset_handler,           // Reset Handler
    NMI_Handler,             // NMI Handler
    HardFault_Handler,       // Hard Fault Handler
    MemManage_Handler,       // Memory Management Fault Handler
    BusFault_Handler,        // Bus Fault Handler
    UsageFault_Handler,      // Usage Fault Handler
    0, 0, 0, 0,              // Reserved
    SVC_Handler,             // SVC Handler
    Debug_Handler,           // Reserved
    0,                       // Reserved
    PendSV_Handler,          // PendSV Handler
    SysTick_Handler,         // SysTick Handler
};