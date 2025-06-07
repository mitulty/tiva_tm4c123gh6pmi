#include "stdint.h"

extern uint32_t _data_flash_start;
extern uint32_t _data_ram_start;
extern uint32_t _data_ram_end;
extern uint32_t _bss_start;
extern uint32_t _bss_end;

/**
 * @brief Initializes the data and BSS sections of the system.
 *
 * This function copies the initialized data from flash to RAM and clears the BSS section.
 * It is typically called during system startup to prepare the memory for use.
 */
void section_init(void)
{
    // Copy data section from flash to RAM
    // This is typically done by the startup code, but can be done here if needed
    uint32_t *src = &_data_flash_start;
    uint32_t *dest = &_data_ram_start;
    while (dest < &_data_ram_end)
    {
        *dest++ = *src++;
    }

    uint32_t *bss_start = &_bss_start;
    uint32_t *bss_end = &_bss_end;

    // Initialize BSS section to zero

    while (bss_start < bss_end)
    {
        *bss_start++ = 0; // Set each word in BSS to 0
    }
    return;
}