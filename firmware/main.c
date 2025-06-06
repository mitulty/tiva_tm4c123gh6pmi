#include "cm4_defines.h"
#include "stdint.h"
#include "FreeRTOS.h"

__attribute__((section(".heap"))) uint8_t ucHeap[ configTOTAL_HEAP_SIZE ];

int main()
{
    while(1);
}