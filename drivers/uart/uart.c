#include "uart.h"

void UART_Init(UART_Port port)
{

    SYSCTL_RCGCUART_R |= (0x1 << port); // Enable UART port clock
    // Wait for the UART module to be ready

    while ((SYSCTL_PRUART_R & (0x1 << port)) == 0)
    {
        // Wait until the UART module is ready
    }
    // Enable the Clock for GPIO port for the specified UART port

    switch (port)
    {
    case UART_PORT_0:
        SYSCTL_RCGCGPIO_R |= 0x01; // Enable Clock for GPIO Port A for UART0
        break;
    case UART_PORT_1:
        SYSCTL_RCGCGPIO_R |= 0x04; // Enable Clock for GPIO Port C for UART1
        break;
    case UART_PORT_2:
        SYSCTL_RCGCGPIO_R |= 0x08; // Enable Clock for GPIO Port D for UART2
        break;
    case UART_PORT_3:
        SYSCTL_RCGCGPIO_R |= 0x04; // Enable Clock for GPIO Port C for UART3
        break;
    case UART_PORT_4:
        SYSCTL_RCGCGPIO_R |= 0x04; // Enable Clock for GPIO Port C for UART4
        break;
    case UART_PORT_5:
        SYSCTL_RCGCGPIO_R |= 0x10; // Enable Clock for GPIO Port E for UART5
        break;
    case UART_PORT_6:
        SYSCTL_RCGCGPIO_R |= 0x08; // Enable Clock for GPIO Port D for UART6
        break;
    case UART_PORT_7:
        SYSCTL_RCGCGPIO_R |= 0x10; // Enable Clock for GPIO Port E for UART7
        break;
    default:
        // Invalid port, handle error
        return;
    }

    switch (port)
    {
    case UART_PORT_0:
        GPIO_PORTA_AFSEL_R |= 0x03;      // Enable alternate function for PA0 and PA1
        GPIO_PORTA_PCTL_R |= 0x00000011; // Configure PA0 and PA1 as UART pins
        GPIO_PORTA_DEN_R |= 0x03;        // Enable digital function on PA0 and PA1
        break;
    case UART_PORT_1:
        GPIO_PORTC_AFSEL_R |= 0x30;      // Enable alternate function for PC4 and PC5
        GPIO_PORTC_PCTL_R |= 0x00110000; // Configure PC4 and PC5 as UART pins
        GPIO_PORTC_DEN_R |= 0x30;        // Enable digital function on PC4 and PC5
        break;
    case UART_PORT_2:
        GPIO_PORTD_AFSEL_R |= 0xC0;      // Enable alternate function for PD6 and PD7
        GPIO_PORTD_PCTL_R |= 0x11000000; // Configure PD6 and PD7 as UART pins
        GPIO_PORTD_DEN_R |= 0xC0;        // Enable digital function on PD6 and PD7
        break;
    case UART_PORT_3:
        GPIO_PORTC_AFSEL_R |= 0xC0;      // Enable alternate function for PC6 and PC7
        GPIO_PORTC_PCTL_R |= 0x11000000; // Configure PC6 and PC7 as UART pins
        GPIO_PORTC_DEN_R |= 0xC0;        // Enable digital function on PC6 and PC7
        break;
    case UART_PORT_4:
        GPIO_PORTC_AFSEL_R |= 0x30;      // Enable alternate function for PC4 and PC5
        GPIO_PORTC_PCTL_R |= 0x00110000; // Configure PC4 and PC5 as UART pins
        GPIO_PORTC_DEN_R |= 0x30;        // Enable digital function on PC4 and PC5
        break;
    case UART_PORT_5:
        GPIO_PORTE_AFSEL_R |= 0x30;      // Enable alternate function for PE4 and PE5
        GPIO_PORTE_PCTL_R |= 0x00110000; // Configure PE4 and PE5 as UART pins
        GPIO_PORTE_DEN_R |= 0x30;        // Enable digital function on PE4 and PE5
        break;
    case UART_PORT_6:
        GPIO_PORTD_AFSEL_R |= 0x30;      // Enable alternate function for PD4 and PD5
        GPIO_PORTD_PCTL_R |= 0x00110000; // Configure PD4 and PD5 as UART pins
        GPIO_PORTD_DEN_R |= 0x30;        // Enable digital function on PD4 and PD5
        break;
    case UART_PORT_7:
        GPIO_PORTE_AFSEL_R |= 0x03;      // Enable alternate function for PE0 and PE1
        GPIO_PORTE_PCTL_R |= 0x00000011; // Configure PE0 and PE1 as UART pins
        GPIO_PORTE_DEN_R |= 0x03;        // Enable digital function on PE0 and PE1
        break;
    default:
        // Invalid port, handle error
        return;
    }
}

void UART_configure(UART_Port port)
{
    // Configure UART settings (baud rate, data bits, stop bits, etc.)
    switch (port)
    {
    case UART_PORT_0:
        UART0_CTL_R &= ~0x01; // Disable UART0
        UART0_IBRD_R = 104;   // IBRD = int(16,000,000 / (16 * 9600)) = 104
        UART0_FBRD_R = 11;    // FBRD = int(0.1668 * 64 + 0.5) = 11
        UART0_LCRH_R = 0x70;  // 8-bit word length, enable FIFO
        UART0_CTL_R |= 0x301; // Enable UART0, TX, and RX
        break;
    case UART_PORT_1:
        UART1_CTL_R &= ~0x01; // Disable UART1
        UART1_IBRD_R = 104;   // IBRD = int(16,000,000 / (16 * 9600)) = 104
        UART1_FBRD_R = 11;    // FBRD = int(0.1668 * 64 + 0.5) = 11
        UART1_LCRH_R = 0x70;  // 8-bit word length, enable FIFO
        UART1_CTL_R |= 0x301; // Enable UART1, TX, and RX
        break;
    case UART_PORT_2:
        UART2_CTL_R &= ~0x01; // Disable UART2
        UART2_IBRD_R = 104;   // IBRD = int(16,000,000 / (16 * 9600)) = 104
        UART2_FBRD_R = 11;    // FBRD = int(0.1668 * 64 + 0.5) = 11
        UART2_LCRH_R = 0x70;  // 8-bit word length, enable FIFO
        UART2_CTL_R |= 0x301; // Enable UART2, TX, and RX
        break;
    case UART_PORT_3:
        UART3_CTL_R &= ~0x01; // Disable UART3
        UART3_IBRD_R = 104;   // IBRD = int(16,000,000 / (16 * 9600)) = 104
        UART3_FBRD_R = 11;    // FBRD = int(0.1668 * 64 + 0.5) = 11
        UART3_LCRH_R = 0x70;  // 8-bit word length, enable FIFO
        UART3_CTL_R |= 0x301; // Enable UART3, TX, and RX
        break;
    case UART_PORT_4:
        UART4_CTL_R &= ~0x01; // Disable UART4
        UART4_IBRD_R = 104;   // IBRD = int(16,000,000 / (16 * 9600)) = 104
        UART4_FBRD_R = 11;    // FBRD = int(0.1668 * 64 + 0.5) = 11
        UART4_LCRH_R = 0x70;  // 8-bit word length, enable FIFO
        UART4_CTL_R |= 0x301; // Enable UART4, TX, and RX
        break;
    case UART_PORT_5:
        UART5_CTL_R &= ~0x01; // Disable UART5
        UART5_IBRD_R = 104;   // IBRD = int(16,000,000 / (16 * 9600)) = 104
        UART5_FBRD_R = 11;    // FBRD = int(0.1668 * 64 + 0.5) = 11
        UART5_LCRH_R = 0x70;  // 8-bit word length, enable FIFO
        UART5_CTL_R |= 0x301; // Enable UART5, TX, and RX
        break;
    case UART_PORT_6:
        UART6_CTL_R &= ~0x01; // Disable UART6
        UART6_IBRD_R = 104;   // IBRD = int(16,000,000 / (16 * 9600)) = 104
        UART6_FBRD_R = 11;    // FBRD = int(0.1668 * 64 + 0.5) = 11
        UART6_LCRH_R = 0x70;  // 8-bit word length, enable FIFO
        UART6_CTL_R |= 0x301; // Enable UART6, TX, and RX
        break;
    case UART_PORT_7:
        UART7_CTL_R &= ~0x01; // Disable UART7
        UART7_IBRD_R = 104;   // IBRD = int(16,000,000 / (16 * 9600)) = 104
        UART7_FBRD_R = 11;    // FBRD = int(0.1668 * 64 + 0.5) = 11
        UART7_LCRH_R = 0x70;  // 8-bit word length, enable FIFO
        UART7_CTL_R |= 0x301; // Enable UART7, TX, and RX
        break;
    default:
        // Invalid port, handle error
        return;
    }
}

void UART_SendChar(UART_Port port, char data)
{
    volatile uint32_t *UART_DR_R;
    volatile uint32_t *UART_FR_R;
    switch (port)
    {
    case UART_PORT_0:
        UART_DR_R = &UART0_DR_R;
        UART_FR_R = &UART0_FR_R;
        break;
    case UART_PORT_1:
        UART_DR_R = &UART1_DR_R;
        UART_FR_R = &UART1_FR_R;
        break;
    case UART_PORT_2:
        UART_DR_R = &UART2_DR_R;
        UART_FR_R = &UART2_FR_R;
        break;
    case UART_PORT_3:
        UART_DR_R = &UART3_DR_R;
        UART_FR_R = &UART3_FR_R;
        break;
    case UART_PORT_4:
        UART_DR_R = &UART4_DR_R;
        UART_FR_R = &UART4_FR_R;
        break;
    case UART_PORT_5:
        UART_DR_R = &UART5_DR_R;
        UART_FR_R = &UART5_FR_R;
        break;
    case UART_PORT_6:
        UART_DR_R = &UART6_DR_R;
        UART_FR_R = &UART6_FR_R;
        break;
    case UART_PORT_7:
        UART_DR_R = &UART7_DR_R;
        UART_FR_R = &UART7_FR_R;
        break;
    default:
        // Invalid port, handle error
        return;
    }
    while ((*UART_FR_R & 0x20) != 0)
        ;              // Wait until TX buffer is not full
    *UART_DR_R = data; // Send the character
}

void UART_SendString(UART_Port port, char *string)
{
    while (*string)
    {
        UART_SendChar(port, *string);
        string++;
    }
}

char UART_Receiver(UART_Port port)
{
    char data;
    volatile uint32_t *UART_DR_R;
    volatile uint32_t *UART_FR_R;
    switch (port)
    {
    case UART_PORT_0:
        UART_DR_R = &UART0_DR_R;
        UART_FR_R = &UART0_FR_R;
        break;
    case UART_PORT_1:
        UART_DR_R = &UART1_DR_R;
        UART_FR_R = &UART1_FR_R;
        break;
    case UART_PORT_2:
        UART_DR_R = &UART2_DR_R;
        UART_FR_R = &UART2_FR_R;
        break;
    case UART_PORT_3:
        UART_DR_R = &UART3_DR_R;
        UART_FR_R = &UART3_FR_R;
        break;
    case UART_PORT_4:
        UART_DR_R = &UART4_DR_R;
        UART_FR_R = &UART4_FR_R;
        break;
    case UART_PORT_5:
        UART_DR_R = &UART5_DR_R;
        UART_FR_R = &UART5_FR_R;
        break;
    case UART_PORT_6:
        UART_DR_R = &UART6_DR_R;
        UART_FR_R = &UART6_FR_R;
        break;
    case UART_PORT_7:
        UART_DR_R = &UART7_DR_R;
        UART_FR_R = &UART7_FR_R;
        break;
    default:
        // Invalid port, handle error
        return;
    }
    // Polling
    while ((*UART_FR_R & (1 << 4)) != 0)
        ;             /* wait until Rx buffer is not full */
    data = UART_DR_R; /* before giving it another byte */
    while(1){
        // Infinite loop to prevent falling through
    }
}