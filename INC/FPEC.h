/****************************************
 *  FPEC.h
 *
 *  Flash Programming Erasing Controller
 *
 *  Created on: Nov 25, 2021
 *  Author: Mohamed Salah
 *
 ****************************************/
#ifndef INC_FPEC_H_
#define INC_FPEC_H_

/*****************************************************************************
FLASH PROGRAMMING ERASING CONTROLLER (FPEC) REGISTERS
*****************************************************************************/
#define BOOT_CNFG_REG             (*((volatile unsigned long *) 0x400FE1D0))
#define FPEC_MEM_ADD_REG          (*((volatile unsigned long *) 0x400FD000))
#define FPEC_MEM_DATA_REG         (*((volatile unsigned long *) 0x400FD004))
#define FPEC_MEM_CTRL_REG         (*((volatile unsigned long *) 0x400FD008))

#define VECT_TABLE_OFFSET_REG     (*((volatile unsigned long *)0xE000ED08))


#define APP_START_ADD     0x00001000
#define LAST_BLOCK_ADD    0x0003FC00

#define FLASH_BASE_ADD    0x00000000


#define BYTE_COUNT_SIZE             2
#define LOW_ADDRESS_SIZE            4
#define REC_TYPR_SIZE               2
#define MAX_DATA_BYTES_SIZE         510 /* 255 * 2 */

#define BYTE_COUNT_START_POS         0
#define LOW_ADDRESS_START_POS        2
#define REC_TYPR_START_POS           6
#define DATA_BYTES_START_POS         8

#define WORD_SIZE                   0x04

#define TRUE   1
#define FALSE  0


void FPEC_FlashWord(const unsigned long word, const unsigned long add);

unsigned char FPEC_EraseBlock(const unsigned long address);


#endif /* INC_FPEC_H_ */
