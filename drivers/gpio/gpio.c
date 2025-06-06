#include "gpio.h"

void GPIO_Init(GPIO_Port port)
{
    switch (port)
    {
    case GPIO_PORTA:
        SYSCTL_RCGCGPIO_R |= 0x01;
        break; // Enable clock for PORTA
    case GPIO_PORTB:
        SYSCTL_RCGCGPIO_R |= 0x02;
        break; // Enable clock for PORTB
    case GPIO_PORTC:
        SYSCTL_RCGCGPIO_R |= 0x04;
        break; // Enable clock for PORTC
    case GPIO_PORTD:
        SYSCTL_RCGCGPIO_R |= 0x08;
        break; // Enable clock for PORTD
    case GPIO_PORTE:
        SYSCTL_RCGCGPIO_R |= 0x10;
        break; // Enable clock for PORTE
    case GPIO_PORTF:
        SYSCTL_RCGCGPIO_R |= 0x20;
        break; // Enable clock for PORTF
    default:
        return; // Invalid port
    }
    while ((SYSCTL_RCGCGPIO_R & (1 << port)) == 0)
        ; // Wait for clock to stabilize
}

void GPIO_SetPortLock(GPIO_Port port, int unlock)
{

    volatile uint32_t *lock_reg;

    // Select the appropriate port register
    switch (port)
    {
    case GPIO_PORTA:
        lock_reg = &GPIO_PORTA_LOCK_R;
        break;
    case GPIO_PORTB:
        lock_reg = &GPIO_PORTB_LOCK_R;
        break;
    case GPIO_PORTC:
        lock_reg = &GPIO_PORTC_LOCK_R;
        break;
    case GPIO_PORTD:
        lock_reg = &GPIO_PORTD_LOCK_R;
        break;
    case GPIO_PORTE:
        lock_reg = &GPIO_PORTE_LOCK_R;
        break;
    case GPIO_PORTF:
        lock_reg = &GPIO_PORTF_LOCK_R;
        break;
    default:
        return; // Invalid port
    }

    // Set or clear the lock for the entire port
    if (unlock)
    {
        *lock_reg = 0x4C4F434B; // Unlock the port
    }
    else
    {
        *lock_reg = 0; // Lock the port
    }
}

void GPIO_SetPortConfig(GPIO_Port port, int config)
{

    volatile uint32_t *cr_reg;

    // Select the appropriate port register
    switch (port)
    {
    case GPIO_PORTA:
        cr_reg = &GPIO_PORTA_CR_R;
        break;
    case GPIO_PORTB:
        cr_reg = &GPIO_PORTB_CR_R;
        break;
    case GPIO_PORTC:
        cr_reg = &GPIO_PORTC_CR_R;
        break;
    case GPIO_PORTD:
        cr_reg = &GPIO_PORTD_CR_R;
        break;
    case GPIO_PORTE:
        cr_reg = &GPIO_PORTE_CR_R;
        break;
    case GPIO_PORTF:
        cr_reg = &GPIO_PORTF_CR_R;
        break;
    default:
        return; // Invalid port
    }

    // Set or clear the config for the entire port
    if (config)
    {
        *cr_reg |= 0xFF; // config all pins in the port
    }
    else
    {
        *cr_reg &= ~0xFF; // Unconfig all pins in the port
    }
}

void GPIO_SetDigitalEnable(GPIO_Port port, int enable)
{

    volatile uint32_t *den_reg;

    // Select the appropriate port register
    switch (port)
    {
    case GPIO_PORTA:
        den_reg = &GPIO_PORTA_DEN_R;
        break;
    case GPIO_PORTB:
        den_reg = &GPIO_PORTB_DEN_R;
        break;
    case GPIO_PORTC:
        den_reg = &GPIO_PORTC_DEN_R;
        break;
    case GPIO_PORTD:
        den_reg = &GPIO_PORTD_DEN_R;
        break;
    case GPIO_PORTE:
        den_reg = &GPIO_PORTE_DEN_R;
        break;
    case GPIO_PORTF:
        den_reg = &GPIO_PORTF_DEN_R;
        break;
    default:
        return; // Invalid port
    }

    // Set or clear the digital enable for the entire port
    if (enable)
    {
        *den_reg |= 0xFF; // Enable all pins in the port
    }
    else
    {
        *den_reg &= ~0xFF; // Disable all pins in the port
    }
}

void GPIO_SetPortDirection(GPIO_Port port, uint32_t direction)
{

    volatile uint32_t *dir_reg;

    // Select the appropriate port register
    switch (port)
    {
    case GPIO_PORTA:
        dir_reg = &GPIO_PORTA_DIR_R;
        break;
    case GPIO_PORTB:
        dir_reg = &GPIO_PORTB_DIR_R;
        break;
    case GPIO_PORTC:
        dir_reg = &GPIO_PORTC_DIR_R;
        break;
    case GPIO_PORTD:
        dir_reg = &GPIO_PORTD_DIR_R;
        break;
    case GPIO_PORTE:
        dir_reg = &GPIO_PORTE_DIR_R;
        break;
    case GPIO_PORTF:
        dir_reg = &GPIO_PORTF_DIR_R;
        break;
    default:
        return; // Invalid port
    }

    // Set the direction for the entire port
    *dir_reg = direction;
}

void GPIO_SetPin(GPIO_Port port, GPIO_Pin pin, int value)
{

    volatile uint32_t *data_reg;

    // Select the appropriate port register
    switch (port)
    {
    case GPIO_PORTA:
        data_reg = &GPIO_PORTA_DATA_R;
        break;
    case GPIO_PORTB:
        data_reg = &GPIO_PORTB_DATA_R;
        break;
    case GPIO_PORTC:
        data_reg = &GPIO_PORTC_DATA_R;
        break;
    case GPIO_PORTD:
        data_reg = &GPIO_PORTD_DATA_R;
        break;
    case GPIO_PORTE:
        data_reg = &GPIO_PORTE_DATA_R;
        break;
    case GPIO_PORTF:
        data_reg = &GPIO_PORTF_DATA_R;
        break;
    default:
        return; // Invalid port
    }

    // Set or clear the specified pin
    if (value)
    {
        *data_reg |= pin; // Set pin high
    }
    else
    {
        *data_reg &= ~pin; // Set pin low
    }
}

void GPIO_SetDirection(GPIO_Port port, GPIO_Pin pin, int direction)
{

    volatile uint32_t *dir_reg;

    // Select the appropriate port register
    switch (port)
    {
    case GPIO_PORTA:
        dir_reg = &GPIO_PORTA_DIR_R;
        break;
    case GPIO_PORTB:
        dir_reg = &GPIO_PORTB_DIR_R;
        break;
    case GPIO_PORTC:
        dir_reg = &GPIO_PORTC_DIR_R;
        break;
    case GPIO_PORTD:
        dir_reg = &GPIO_PORTD_DIR_R;
        break;
    case GPIO_PORTE:
        dir_reg = &GPIO_PORTE_DIR_R;
        break;
    case GPIO_PORTF:
        dir_reg = &GPIO_PORTF_DIR_R;
        break;
    default:
        return; // Invalid port
    }

    // Set the direction for the specified pin
    if (direction)
    {
        *dir_reg |= pin; // Set pin as output
    }
    else
    {
        *dir_reg &= ~pin; // Set pin as input
    }
}

void GPIO_SetPullUpPin(GPIO_Port port, GPIO_Pin pin, int enable)
{

    volatile uint32_t *pur_reg;

    // Select the appropriate port register
    switch (port)
    {
    case GPIO_PORTA:
        pur_reg = &GPIO_PORTA_PUR_R;
        break;
    case GPIO_PORTB:
        pur_reg = &GPIO_PORTB_PUR_R;
        break;
    case GPIO_PORTC:
        pur_reg = &GPIO_PORTC_PUR_R;
        break;
    case GPIO_PORTD:
        pur_reg = &GPIO_PORTD_PUR_R;
        break;
    case GPIO_PORTE:
        pur_reg = &GPIO_PORTE_PUR_R;
        break;
    case GPIO_PORTF:
        pur_reg = &GPIO_PORTF_PUR_R;
        break;
    default:
        return; // Invalid port
    }

    // Set or clear the pull-up resistor for the specified pin
    if (enable)
    {
        *pur_reg |= pin; // Enable pull-up for the pin
    }
    else
    {
        *pur_reg &= ~pin; // Disable pull-up for the pin
    }
}

void GPIO_SetPullDownPin(GPIO_Port port, GPIO_Pin pin, int enable)
{

    volatile uint32_t *pdr_reg;

    // Select the appropriate port register
    switch (port)
    {
    case GPIO_PORTA:
        pdr_reg = &GPIO_PORTA_PDR_R;
        break;
    case GPIO_PORTB:
        pdr_reg = &GPIO_PORTB_PDR_R;
        break;
    case GPIO_PORTC:
        pdr_reg = &GPIO_PORTC_PDR_R;
        break;
    case GPIO_PORTD:
        pdr_reg = &GPIO_PORTD_PDR_R;
        break;
    case GPIO_PORTE:
        pdr_reg = &GPIO_PORTE_PDR_R;
        break;
    case GPIO_PORTF:
        pdr_reg = &GPIO_PORTF_PDR_R;
        break;
    default:
        return; // Invalid port
    }

    // Set or clear the pull-down resistor for the specified pin
    if (enable)
    {
        *pdr_reg |= pin; // Enable pull-down for the pin
    }
    else
    {
        *pdr_reg &= ~pin; // Disable pull-down for the pin
    }
}