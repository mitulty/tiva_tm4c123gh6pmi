#ifndef CM4_DEFINES_H
#define CM4_DEFINES_H

#include "stdint.h"
#include "systick.h"

typedef void (*ISRHandler)(void);

typedef enum Bool_e
{
    FALSE = 0,
    TRUE = 1
} bool;
#endif // CM4_DEFINES_H