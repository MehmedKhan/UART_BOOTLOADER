/****************************************
 *  UART.h
 *
 *  Created on: Nov 25, 2021
 *  Author: Mohamed Salah
 *
 ****************************************/

#ifndef INC_UART_H_
#define INC_UART_H_

/*   CLKDIV = CLK_SRC / (16 * BAUD RATE)
 *
 *   FOR CLK_SRC   = 16 MHZ
 *       BAUD RATE = 9600
 *
 *       INT_PART   = INT(CLKDIV)
 *       FLOAT_PART = INT(CLKDIV * 64 + 0.5)
 *
 */
#define UART0_INT_BR_DIV     104
#define UART0_FLOAT_BR_DIV   11


/*
 * CLK SRC for UART
 *      0x0 --> SYS CLK
 *      0x5 --> PIOSC
 */
#define UART0_CLK_SRC   0x0


/*
 *  FRAME Control Of UART
 *      DATA BIT COUNT
 *          5 bits --> 0x00
 *          6 bits --> 0x20
 *          7 bits --> 0x40
 *          8 bits --> 0x60
 *
 *      Stop Bits
 *          1 bit --> 0x00
 *          2 bits--> 0x08
 *
 *      Parity
 *          No Parity --> 0x00
 *          Even      --> 0x06
 *          Odd       --> 0x02
 */
#define UART0_DATA_BIT_COUNT  0x60
#define UART0_STOP_BIT_COUNT  0x00
#define UART0_PARITY_MODE     0x00



/*****************************************************************************
UART REGISTERS (UART0)
*****************************************************************************/
#define UART0_CLK_SRC_REG         (*((volatile unsigned long *)0x4000CFC8))
#define UART0_IBRD_REG            (*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD_REG            (*((volatile unsigned long *)0x4000C028))
#define UART0_CTRL_REG            (*((volatile unsigned long *)0x4000C030))
#define UART0_LINE_CTRL_REG       (*((volatile unsigned long *)0x4000C02C))
#define UART0_DATA_REG            (*((volatile unsigned long *)0x4000C000))
#define UART0_FLAG_REG            (*((volatile unsigned long *)0x4000C018))


// UART CLOCK ENABLE
/*****************************************************************************/
#define RCGC_UART_REG             (*((volatile unsigned long *)0x400FE618))


void Init_UART_0(void);
void UART0_TX_CHAR(const char c);
void UART0_TX_STRING(const char* s);
char UART0_RX_CHAR();
int  UART0_RX_STRING(char* s);

#endif /* INC_UART_H_ */
