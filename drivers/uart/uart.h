#ifndef UART_H
#define UART_H

#include "stdint.h"
#include "sysctl_registers.h"
#include "gpio.h"
/**
 * @file uart.h
 * @brief UART (Universal Asynchronous Receiver-Transmitter) driver header file for Tiva C Series microcontrollers.
 */

/**
 * TM4C123GH6PM UART Ports Mapping
 * This mapping is based on the Tiva C Series microcontroller's
 * UART Ports and their corresponding pin assignments.
 * * UART0: Port A (PA0 - RX, PA1 - TX) - 0x4000C000
 * * UART1: Port C (PC4 - RX, PC5 - TX) - 0x4000D000
 * * UART2: Port D (PD6 - RX, PD7 - TX) - 0x4000E000
 * * UART3: Port C (PC6 - RX, PC7 - TX) - 0x4000F000
 * * UART4: Port C (PC4 - RX, PC5 - TX) - 0x40010000
 * * UART5: Port E (PE4 - RX, PE5 - TX) - 0x40011000
 * * UART6: Port D (PD4 - RX, PD5 - TX) - 0x40012000
 * * UART7: Port E (PE0 - RX, PE1 - TX) - 0x40013000
 * * Note: The actual pin assignments may vary based on the specific Tiva C Series
 */

typedef enum UART_Port_t
{
    // Enum for UART ports
    UART_PORT_0 = 0, // UART0
    UART_PORT_1,     // UART1
    UART_PORT_2,     // UART2
    UART_PORT_3,     // UART3
    UART_PORT_4,     // UART4
    UART_PORT_5,     // UART5
    UART_PORT_6,     // UART6
    UART_PORT_7      // UART7
} UART_Port;

void UART_Init(UART_Port port);
void UART_configure(UART_Port port);
void UART_SendChar(UART_Port port, char data);
void UART_SendString(UART_Port port, char *string);
char UART_Receiver(UART_Port port);
//*****************************************************************************
//
// UART registers (UART0)
//
//*****************************************************************************
#define UART0_DR_R (*((volatile uint32_t *)0x4000C000))
#define UART0_RSR_R (*((volatile uint32_t *)0x4000C004))
#define UART0_ECR_R (*((volatile uint32_t *)0x4000C004))
#define UART0_FR_R (*((volatile uint32_t *)0x4000C018))
#define UART0_ILPR_R (*((volatile uint32_t *)0x4000C020))
#define UART0_IBRD_R (*((volatile uint32_t *)0x4000C024))
#define UART0_FBRD_R (*((volatile uint32_t *)0x4000C028))
#define UART0_LCRH_R (*((volatile uint32_t *)0x4000C02C))
#define UART0_CTL_R (*((volatile uint32_t *)0x4000C030))
#define UART0_IFLS_R (*((volatile uint32_t *)0x4000C034))
#define UART0_IM_R (*((volatile uint32_t *)0x4000C038))
#define UART0_RIS_R (*((volatile uint32_t *)0x4000C03C))
#define UART0_MIS_R (*((volatile uint32_t *)0x4000C040))
#define UART0_ICR_R (*((volatile uint32_t *)0x4000C044))
#define UART0_DMACTL_R (*((volatile uint32_t *)0x4000C048))
#define UART0_9BITADDR_R (*((volatile uint32_t *)0x4000C0A4))
#define UART0_9BITAMASK_R (*((volatile uint32_t *)0x4000C0A8))
#define UART0_PP_R (*((volatile uint32_t *)0x4000CFC0))
#define UART0_CC_R (*((volatile uint32_t *)0x4000CFC8))

//*****************************************************************************
//
// UART registers (UART1)
//
//*****************************************************************************
#define UART1_DR_R (*((volatile uint32_t *)0x4000D000))
#define UART1_RSR_R (*((volatile uint32_t *)0x4000D004))
#define UART1_ECR_R (*((volatile uint32_t *)0x4000D004))
#define UART1_FR_R (*((volatile uint32_t *)0x4000D018))
#define UART1_ILPR_R (*((volatile uint32_t *)0x4000D020))
#define UART1_IBRD_R (*((volatile uint32_t *)0x4000D024))
#define UART1_FBRD_R (*((volatile uint32_t *)0x4000D028))
#define UART1_LCRH_R (*((volatile uint32_t *)0x4000D02C))
#define UART1_CTL_R (*((volatile uint32_t *)0x4000D030))
#define UART1_IFLS_R (*((volatile uint32_t *)0x4000D034))
#define UART1_IM_R (*((volatile uint32_t *)0x4000D038))
#define UART1_RIS_R (*((volatile uint32_t *)0x4000D03C))
#define UART1_MIS_R (*((volatile uint32_t *)0x4000D040))
#define UART1_ICR_R (*((volatile uint32_t *)0x4000D044))
#define UART1_DMACTL_R (*((volatile uint32_t *)0x4000D048))
#define UART1_9BITADDR_R (*((volatile uint32_t *)0x4000D0A4))
#define UART1_9BITAMASK_R (*((volatile uint32_t *)0x4000D0A8))
#define UART1_PP_R (*((volatile uint32_t *)0x4000DFC0))
#define UART1_CC_R (*((volatile uint32_t *)0x4000DFC8))

//*****************************************************************************
//
// UART registers (UART2)
//
//*****************************************************************************
#define UART2_DR_R (*((volatile uint32_t *)0x4000E000))
#define UART2_RSR_R (*((volatile uint32_t *)0x4000E004))
#define UART2_ECR_R (*((volatile uint32_t *)0x4000E004))
#define UART2_FR_R (*((volatile uint32_t *)0x4000E018))
#define UART2_ILPR_R (*((volatile uint32_t *)0x4000E020))
#define UART2_IBRD_R (*((volatile uint32_t *)0x4000E024))
#define UART2_FBRD_R (*((volatile uint32_t *)0x4000E028))
#define UART2_LCRH_R (*((volatile uint32_t *)0x4000E02C))
#define UART2_CTL_R (*((volatile uint32_t *)0x4000E030))
#define UART2_IFLS_R (*((volatile uint32_t *)0x4000E034))
#define UART2_IM_R (*((volatile uint32_t *)0x4000E038))
#define UART2_RIS_R (*((volatile uint32_t *)0x4000E03C))
#define UART2_MIS_R (*((volatile uint32_t *)0x4000E040))
#define UART2_ICR_R (*((volatile uint32_t *)0x4000E044))
#define UART2_DMACTL_R (*((volatile uint32_t *)0x4000E048))
#define UART2_9BITADDR_R (*((volatile uint32_t *)0x4000E0A4))
#define UART2_9BITAMASK_R (*((volatile uint32_t *)0x4000E0A8))
#define UART2_PP_R (*((volatile uint32_t *)0x4000EFC0))
#define UART2_CC_R (*((volatile uint32_t *)0x4000EFC8))

//*****************************************************************************
//
// UART registers (UART3)
//
//*****************************************************************************
#define UART3_DR_R (*((volatile uint32_t *)0x4000F000))
#define UART3_RSR_R (*((volatile uint32_t *)0x4000F004))
#define UART3_ECR_R (*((volatile uint32_t *)0x4000F004))
#define UART3_FR_R (*((volatile uint32_t *)0x4000F018))
#define UART3_ILPR_R (*((volatile uint32_t *)0x4000F020))
#define UART3_IBRD_R (*((volatile uint32_t *)0x4000F024))
#define UART3_FBRD_R (*((volatile uint32_t *)0x4000F028))
#define UART3_LCRH_R (*((volatile uint32_t *)0x4000F02C))
#define UART3_CTL_R (*((volatile uint32_t *)0x4000F030))
#define UART3_IFLS_R (*((volatile uint32_t *)0x4000F034))
#define UART3_IM_R (*((volatile uint32_t *)0x4000F038))
#define UART3_RIS_R (*((volatile uint32_t *)0x4000F03C))
#define UART3_MIS_R (*((volatile uint32_t *)0x4000F040))
#define UART3_ICR_R (*((volatile uint32_t *)0x4000F044))
#define UART3_DMACTL_R (*((volatile uint32_t *)0x4000F048))
#define UART3_9BITADDR_R (*((volatile uint32_t *)0x4000F0A4))
#define UART3_9BITAMASK_R (*((volatile uint32_t *)0x4000F0A8))
#define UART3_PP_R (*((volatile uint32_t *)0x4000FFC0))
#define UART3_CC_R (*((volatile uint32_t *)0x4000FFC8))

//*****************************************************************************
//
// UART registers (UART4)
//
//*****************************************************************************
#define UART4_DR_R (*((volatile uint32_t *)0x40010000))
#define UART4_RSR_R (*((volatile uint32_t *)0x40010004))
#define UART4_ECR_R (*((volatile uint32_t *)0x40010004))
#define UART4_FR_R (*((volatile uint32_t *)0x40010018))
#define UART4_ILPR_R (*((volatile uint32_t *)0x40010020))
#define UART4_IBRD_R (*((volatile uint32_t *)0x40010024))
#define UART4_FBRD_R (*((volatile uint32_t *)0x40010028))
#define UART4_LCRH_R (*((volatile uint32_t *)0x4001002C))
#define UART4_CTL_R (*((volatile uint32_t *)0x40010030))
#define UART4_IFLS_R (*((volatile uint32_t *)0x40010034))
#define UART4_IM_R (*((volatile uint32_t *)0x40010038))
#define UART4_RIS_R (*((volatile uint32_t *)0x4001003C))
#define UART4_MIS_R (*((volatile uint32_t *)0x40010040))
#define UART4_ICR_R (*((volatile uint32_t *)0x40010044))
#define UART4_DMACTL_R (*((volatile uint32_t *)0x40010048))
#define UART4_9BITADDR_R (*((volatile uint32_t *)0x400100A4))
#define UART4_9BITAMASK_R (*((volatile uint32_t *)0x400100A8))
#define UART4_PP_R (*((volatile uint32_t *)0x40010FC0))
#define UART4_CC_R (*((volatile uint32_t *)0x40010FC8))

//*****************************************************************************
//
// UART registers (UART5)
//
//*****************************************************************************
#define UART5_DR_R (*((volatile uint32_t *)0x40011000))
#define UART5_RSR_R (*((volatile uint32_t *)0x40011004))
#define UART5_ECR_R (*((volatile uint32_t *)0x40011004))
#define UART5_FR_R (*((volatile uint32_t *)0x40011018))
#define UART5_ILPR_R (*((volatile uint32_t *)0x40011020))
#define UART5_IBRD_R (*((volatile uint32_t *)0x40011024))
#define UART5_FBRD_R (*((volatile uint32_t *)0x40011028))
#define UART5_LCRH_R (*((volatile uint32_t *)0x4001102C))
#define UART5_CTL_R (*((volatile uint32_t *)0x40011030))
#define UART5_IFLS_R (*((volatile uint32_t *)0x40011034))
#define UART5_IM_R (*((volatile uint32_t *)0x40011038))
#define UART5_RIS_R (*((volatile uint32_t *)0x4001103C))
#define UART5_MIS_R (*((volatile uint32_t *)0x40011040))
#define UART5_ICR_R (*((volatile uint32_t *)0x40011044))
#define UART5_DMACTL_R (*((volatile uint32_t *)0x40011048))
#define UART5_9BITADDR_R (*((volatile uint32_t *)0x400110A4))
#define UART5_9BITAMASK_R (*((volatile uint32_t *)0x400110A8))
#define UART5_PP_R (*((volatile uint32_t *)0x40011FC0))
#define UART5_CC_R (*((volatile uint32_t *)0x40011FC8))

//*****************************************************************************
//
// UART registers (UART6)
//
//*****************************************************************************
#define UART6_DR_R (*((volatile uint32_t *)0x40012000))
#define UART6_RSR_R (*((volatile uint32_t *)0x40012004))
#define UART6_ECR_R (*((volatile uint32_t *)0x40012004))
#define UART6_FR_R (*((volatile uint32_t *)0x40012018))
#define UART6_ILPR_R (*((volatile uint32_t *)0x40012020))
#define UART6_IBRD_R (*((volatile uint32_t *)0x40012024))
#define UART6_FBRD_R (*((volatile uint32_t *)0x40012028))
#define UART6_LCRH_R (*((volatile uint32_t *)0x4001202C))
#define UART6_CTL_R (*((volatile uint32_t *)0x40012030))
#define UART6_IFLS_R (*((volatile uint32_t *)0x40012034))
#define UART6_IM_R (*((volatile uint32_t *)0x40012038))
#define UART6_RIS_R (*((volatile uint32_t *)0x4001203C))
#define UART6_MIS_R (*((volatile uint32_t *)0x40012040))
#define UART6_ICR_R (*((volatile uint32_t *)0x40012044))
#define UART6_DMACTL_R (*((volatile uint32_t *)0x40012048))
#define UART6_9BITADDR_R (*((volatile uint32_t *)0x400120A4))
#define UART6_9BITAMASK_R (*((volatile uint32_t *)0x400120A8))
#define UART6_PP_R (*((volatile uint32_t *)0x40012FC0))
#define UART6_CC_R (*((volatile uint32_t *)0x40012FC8))

//*****************************************************************************
//
// UART registers (UART7)
//
//*****************************************************************************
#define UART7_DR_R (*((volatile uint32_t *)0x40013000))
#define UART7_RSR_R (*((volatile uint32_t *)0x40013004))
#define UART7_ECR_R (*((volatile uint32_t *)0x40013004))
#define UART7_FR_R (*((volatile uint32_t *)0x40013018))
#define UART7_ILPR_R (*((volatile uint32_t *)0x40013020))
#define UART7_IBRD_R (*((volatile uint32_t *)0x40013024))
#define UART7_FBRD_R (*((volatile uint32_t *)0x40013028))
#define UART7_LCRH_R (*((volatile uint32_t *)0x4001302C))
#define UART7_CTL_R (*((volatile uint32_t *)0x40013030))
#define UART7_IFLS_R (*((volatile uint32_t *)0x40013034))
#define UART7_IM_R (*((volatile uint32_t *)0x40013038))
#define UART7_RIS_R (*((volatile uint32_t *)0x4001303C))
#define UART7_MIS_R (*((volatile uint32_t *)0x40013040))
#define UART7_ICR_R (*((volatile uint32_t *)0x40013044))
#define UART7_DMACTL_R (*((volatile uint32_t *)0x40013048))
#define UART7_9BITADDR_R (*((volatile uint32_t *)0x400130A4))
#define UART7_9BITAMASK_R (*((volatile uint32_t *)0x400130A8))
#define UART7_PP_R (*((volatile uint32_t *)0x40013FC0))
#define UART7_CC_R (*((volatile uint32_t *)0x40013FC8))

#endif // UART_H