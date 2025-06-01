    .syntax unified
    .section startup_code, "ax"
    .thumb
    .global _stack_end
    .global _stack_process_end
    .global reset_handler

    .type reset_handler, %function // This makes sure that the T-bit is set for the function
reset_handler:
    // Initialize core registers
    mov r0, #0x0        // Clear r0
    mov r1, r0          // Clear r1
    mov r2, r0          // Clear r2
    mov r3, r0          // Clear r3
    mov r4, r0          // Clear r4
    mov r5, r0          // Clear r5
    mov r6, r0          // Clear r6
    mov r7, r0          // Clear r7
    mov r8, r0          // Clear r8
    mov r9, r0          // Clear r9
    mov r10, r0         // Clear r10
    mov r11, r0         // Clear r11
    mov r12, r0         // Clear r12
    mov r13, r0         // Clear r13 (not used, but for completeness)
    mov r14, r0         // Clear r14 (not used, but for completeness)

    // Initialize the main stack pointer
    ldr sp, =_stack_end  // Set the stack pointer to the end of the stack

    // Initialize the process stack pointer
    mrs r0, control       // Read the control register
    orr r0, r0, #0x2     // Set the SP (Stack Pointer) bit
    msr control, r0      // Write back to the control register
    ldr sp, =_stack_process_end  // Set the PSP to the end of the stack
    and r0, r0, #0x0     // Clear the SP (Stack Pointer) bit
    msr control, r0      // Write back to the control register

    // Call the main function
    bl main
    // If main returns, enter an infinite loop

    b .
