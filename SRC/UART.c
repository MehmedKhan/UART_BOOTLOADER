/****************************************
 *  UART.c
 *
 *  Created on: Nov 25, 2021
 *  Author: Mohamed Salah
 *
 ****************************************/
#include "GPIO.h"
#include "UART.h"

void Init_UART_0(void)
{
    // Enable Digital function for PA0 & PA1
    GPIO_PORTA_DEN_REG   |= 0x3;
    // Enable Alternate function for PA0 & PA1
    GPIO_PORTA_AFSEL_REG |= 0x03;
    // Select UART Functionality for PA0 & PA1
    GPIO_PORTA_PCTL_REG  |= 0x11;

    // Disable UART0
    UART0_CTRL_REG       &= ~(0x01);

    // Set the integer & Float part of Clock divisor
    UART0_IBRD_REG       = UART0_INT_BR_DIV;
    UART0_FBRD_REG       = UART0_FLOAT_BR_DIV;

    // SET CLOCK SRC FOR UART0
    UART0_CLK_SRC_REG    = UART0_CLK_SRC;

    // SET CONFIGS OF UART FRAME
    UART0_LINE_CTRL_REG  = UART0_DATA_BIT_COUNT | UART0_PARITY_MODE | UART0_STOP_BIT_COUNT ;

    // Enable UART0
    UART0_CTRL_REG      |= 0x301;
}

// polling based
void UART0_TX_CHAR(const char c)
{
    // Wait while TX FIFO IS FULL
    while((UART0_FLAG_REG & (1<<5)));
    // ONCE TX FIFO IS NOT FULL
    UART0_DATA_REG = c;
}

void UART0_TX_STRING(const char* s)
{
    while (*s != 0) /* if not end of string */
        UART0_TX_CHAR(*s++); /* send the character through UART0 */
}


// polling based
char UART0_RX_CHAR()
{
    char c = 0;
    // wait while RX FIFO is Empty
    while((UART0_FLAG_REG & 0x10) != 0);
    // ONCE RX FIFO IS NOT EMPTY
    c = UART0_DATA_REG & 0xFF;
    return c;
}

// Receive till get char that not within HEX range
int UART0_RX_STRING(char* s)
{
    int len = 0;
    char *tmp = 0;
    do{
        tmp = s;

        *s = UART0_RX_CHAR();
        s++;
        len++;
    }
    while((*(tmp) >= '0' && *(tmp) <= '9') || (*(tmp) >= 'A' && *(tmp) <= 'F'));
    // put null after record end
    *s = '\0';

    return (len-1);
}

