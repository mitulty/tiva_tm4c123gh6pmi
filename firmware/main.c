#include "cm4_defines.h"
#include "stdint.h"
#include "FreeRTOS.h"
#include "gpio.h"
#include "systick.h"
#include "task.h"

__attribute__((section(".heap"))) uint8_t ucHeap[configTOTAL_HEAP_SIZE];

static void vTask1(void *pvParameters)
{
    while (1)
    {
        GPIO_SetPin(GPIO_PORTF, GPIO_PIN_2, 0); // Set PF2 low
        GPIO_SetPin(GPIO_PORTF, GPIO_PIN_1, 1); // Set PF1 high
        // systick_delay(500);                     // Delay for 500 ms
        // vTaskDelay(pdMS_TO_TICKS(1000));        // Delay for 1000 ms
        // GPIO_SetPin(GPIO_PORTF, GPIO_PIN_1, 0); // Set PF1 low
        // vTaskDelay(pdMS_TO_TICKS(500));        // Delay for 1000 ms
        // systick_delay(500);
    }
}

static void vTask2(void *pvParameters)
{
    while (1)
    {
        GPIO_SetPin(GPIO_PORTF, GPIO_PIN_1, 0); // Set PF1 low
        GPIO_SetPin(GPIO_PORTF, GPIO_PIN_2, 1); // Set PF2 high
        // systick_delay(500);                     // Delay for 500 ms
        // vTaskDelay(pdMS_TO_TICKS(1000));        // Delay for 1000 ms
        // GPIO_SetPin(GPIO_PORTF, GPIO_PIN_2, 0); // Set PF2 low
        // vTaskDelay(pdMS_TO_TICKS(500));        // Delay for 1000 ms
        // systick_delay(500);
    }
}

int main()
{

    BaseType_t result1, result2;

    // This function is used to blink an LED on Port F, Pin 1
    // It initializes the GPIO and toggles the pin in a loop
    // This is a simple test to ensure the GPIO functionality works
    // It does not use FreeRTOS tasks, but can be used for debugging purposes
    // The LED will blink at a rate of 1 Hz (500 ms on, 500 ms off)
    systick_init();                          // Initialize SysTick for delays
    GPIO_Init(GPIO_PORTF);                   // Initialize GPIO Port F
    GPIO_SetPortLock(GPIO_PORTF, 1);         // Unlock Port F
    GPIO_SetPortConfig(GPIO_PORTF, 0x01);    // Configure Port F for PF1
    GPIO_SetDigitalEnable(GPIO_PORTF, 1);    // Enable digital function for Port F
    GPIO_SetPortDirection(GPIO_PORTF, 0x06); // Set PF1 as output (0x02 = 0000 0010)

    // Create FreeRTOS tasks
    // These tasks will toggle PF1 and PF2 at a rate of 1 Hz
    // The tasks will run concurrently, allowing both LEDs to blink independently
    // The tasks will use FreeRTOS delay functions to manage timing
    // The tasks will run at priority 1, which is a low priority
    // The tasks will run indefinitely in a loop
    result1 = xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    result2 = xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    if (result1 != pdPASS || result2 != pdPASS)
    {
        // Handle task creation failure
        while (1)
            ;
    }
    vTaskStartScheduler(); // Start the FreeRTOS scheduler
    // The scheduler should never return, but if it does, we can handle it here
    while (1)
    {
        // Handle unexpected return from scheduler
    }
}