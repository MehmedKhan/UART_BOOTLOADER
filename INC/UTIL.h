/****************************************
 *  UTIL.h
 *
 *  General Utils
 *
 *  Created on: Nov 25, 2021
 *  Author: Mohamed Salah
 *
 ****************************************/

#ifndef INC_UTIL_H_
#define INC_UTIL_H_



unsigned long Ascii_2_Hex_Word(char* word);

unsigned long Ascii_2_Hex_Address(char* data, char size);

char Validate_Record(const char* record, int len);

#endif /* INC_UTIL_H_ */
