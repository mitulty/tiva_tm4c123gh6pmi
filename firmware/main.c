#include "cm4_defines.h"
#include "stdint.h"
#include "FreeRTOS.h"
#include "gpio.h"
#include "systick.h"

__attribute__((section(".heap"))) uint8_t ucHeap[configTOTAL_HEAP_SIZE];

int main()
{
    systick_init();                          // Initialize SysTick for delays
    GPIO_Init(GPIO_PORTF);                   // Initialize GPIO Port F
    GPIO_SetPortLock(GPIO_PORTF, 1);         // Unlock Port F
    GPIO_SetPortConfig(GPIO_PORTF, 0x01);    // Configure Port F for PF1
    GPIO_SetDigitalEnable(GPIO_PORTF, 1);    // Enable digital function for Port F
    GPIO_SetPortDirection(GPIO_PORTF, 0x02); // Set PF1 as output (0x02 = 0000 0010)

    while (1)
    {
        GPIO_SetPin(GPIO_PORTF, GPIO_PIN_1, 1); // Set PF1 high
        systick_delay(500);                     // Delay for 500 ms
        GPIO_SetPin(GPIO_PORTF, GPIO_PIN_1, 0); // Set PF1 low
        systick_delay(500);                     // Delay for 500 ms
    }
}