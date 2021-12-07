/****************************************
 *  FPEC.c
 *
 *  Flash Programming Erasing Controller
 *
 *  Created on: Nov 25, 2021
 *  Author: Mohamed Salah
 *
 ****************************************/
#include "FPEC.h"


/**
 * this function is responsible for
 * flashing one word 32Bits in flash memory
 * @ address specified
 */
void FPEC_FlashWord(const unsigned long word, const unsigned long add)
{
    // Set The data we want to write in flash memory
    FPEC_MEM_DATA_REG = word;
    // Set The address where we want to write in flash memory
    FPEC_MEM_ADD_REG = add;

    // Check BOOT Configuration Register (KEY bit)
    // to know key value in Flash Memory Control register
    // & Set WRITE BIT to write word in flash
    FPEC_MEM_CTRL_REG = (BOOT_CNFG_REG & (1<<4)) ? 0xA4420001 : 0x71D50001;

    // wait till WRITE operation is done
    while(FPEC_MEM_CTRL_REG & 1);
}

/**
 * This function is dedicated to
 * erase a complete block of 1KB of Flash memory
 * this block start address is Specified from input
 *
 * return TRUE
 *        FALSE
 */
unsigned char FPEC_EraseBlock(const unsigned long address)
{
    if((address >= APP_START_ADD) && (address <= LAST_BLOCK_ADD))
    {
        FPEC_MEM_ADD_REG = address;

        // Check BOOT Configuration Register (KEY bit)
        // to know key value in Flash Memory Control register
        // & Set ERASE BIT to ERASE block in flash
        FPEC_MEM_CTRL_REG = (BOOT_CNFG_REG & (1<<4)) ? 0xA4420002 : 0x71D50002;

        // wait till ERASE operation is done
        while(FPEC_MEM_CTRL_REG & (1<<1));

        return TRUE;
    }
    return FALSE;
}

