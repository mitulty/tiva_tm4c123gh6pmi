#ifndef SYSTICK
#define SYSTICK

#include "stdint.h"

typedef struct
{
    volatile uint32_t CTRL;  // Control and status register
    volatile uint32_t LOAD;  // Reload value register
    volatile uint32_t VAL;   // Current value register
    volatile uint32_t CALIB; // Calibration value register
} SysTick_Type;

#define SysTick ((SysTick_Type *)0xE000E010)

#define SYSTICK_CTRL_ENABLE 0x00000001
#define SYSTICK_CTRL_TICKINT 0x00000002
#define SYSTICK_CTRL_CLKSOURCE 0x00000004
#define SYSTICK_CTRL_COUNTFLAG 0x00010000
#define SYSTICK_CTRL_RESET 0x00000000
#define SYSTICK_CTRL_COUNTFLAG_Msk 0x00010000
#define SYSTICK_CTRL_CLKSOURCE_Msk 0x00000004
#define SYSTICK_CTRL_TICKINT_Msk 0x00000002
#define SYSTICK_CTRL_ENABLE_Msk 0x00000001

void systick_init(void);
void systick_delay(uint32_t delay_ms);
void systick_reset(void);
void systick_enable(void);
void systick_disable(void);
void systick_set_reload(uint32_t reload_value);
uint32_t systick_get_current_value(void);
void SysTick_Handler(void);

#endif // SYSTICK