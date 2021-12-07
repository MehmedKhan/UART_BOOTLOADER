/****************************************
 *  main.c
 *
 *  Created on: Nov 22, 2021
 *  Author: Mohamed Salah
 *
 ****************************************/
#include "GPIO.h"
#include "UART.h"
#include "FPEC.h"
#include "UTIL.h"

#include <string.h>

typedef void(*Function_Ptr)(void);
Function_Ptr CallApplication = 0;

void main(void)
{
    char record   [BYTE_COUNT_SIZE + LOW_ADDRESS_SIZE + REC_TYPR_SIZE + MAX_DATA_BYTES_SIZE + 1];

    unsigned short length = 0;
    unsigned short i      = 0;

    unsigned long  address = 0x0;
    unsigned long  word    = 0x0;

    // initialize UART_0  & GPIOA clock
    RCGC_GPIO_REG |= 0x01;
    RCGC_UART_REG |= 0x01;
    // wait 3 clock cycles
    volatile long delay = RCGC_UART_REG;

    // initialize UART0 FOR TX & RX
    Init_UART_0();

    for(;;)
    {
        memset(record, 0x00, sizeof(record));
        address = 0x0;
        length = 0;

        /* Receive record till sender script sends special character
           to notify end of record */
        int recordLen = UART0_RX_STRING(record);

        // CHECK SUM VALIDATION
        if(Validate_Record(record, recordLen) == FALSE)
        {
            // RECORD ERROR
            UART0_TX_CHAR('E');
            // stuck
            while(TRUE);
        }

        // get data digits count in decimal
        // Always it is just two digits containing data bytes count in hexadecimal
        length = ((record[BYTE_COUNT_START_POS] - 0x30) * 16) +
                (record[BYTE_COUNT_START_POS + 1] - 0x30);
        length *= 2;

        // Address offset is 4-digits(2-bytes) after char count
        address = Ascii_2_Hex_Address(&record[LOW_ADDRESS_START_POS], 4);
        // get start address to flash data
        address += FLASH_BASE_ADD;

        // check record type 7th digit in the record
        // type == 1 --> End Of File
        if(record[REC_TYPR_START_POS + 1] == '1')
        {
            // FILE FLASH DONE
            UART0_TX_CHAR('F');
            break;
        }

        for(i = 0 ; i < length ; i+=8)
        {
            // data start @ 8th digit in the record
            // get value of whole word in hex
            word = Ascii_2_Hex_Word(&record[i + DATA_BYTES_START_POS]);
            // write complete word in flash
            FPEC_FlashWord(word, address);
            // increment address for next word
            address = address + WORD_SIZE;
        }

        // RECORD FLASH DONE
        UART0_TX_CHAR('D');
    }

    // jump to new application
    CallApplication = *((Function_Ptr*) (APP_START_ADD + WORD_SIZE));
    CallApplication();
}
