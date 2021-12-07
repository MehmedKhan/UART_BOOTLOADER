/****************************************
 *  UTIL.c
 *
 *  General Utils
 *
 *  Created on: Nov 25, 2021
 *  Author: Mohamed Salah
 *
 ****************************************/
#include "UTIL.h"
#include "FPEC.h"

unsigned long Ascii_2_Hex_Word(char* word)
{
    unsigned long data = 0x00000000;

    signed char i = 0;

    for(i = 7; i >= 0; i-= 2)
    {
        char x = *(word+i-1);
        if( x >= 0x30 && x <= 0x39 )
        {
            data |= (x & 0x0F);
        }
        else if(x >= 65 && x <= 70) //A : F
        {
            data |= x - 55;
        }


        data = data << 4;
        x = 0;


        x = *(word+i);
        if( x >= 0x30 && x <= 0x39 )
        {
            data |= (x & 0x0F);
        }
        else if(x >= 65 && x <= 70) //A : F
        {
            data |= x - 55;
        }

        if(i != 1)
            data = data << 4;
    }

    return data;
}


unsigned long Ascii_2_Hex_Address(char* data, char size)
{
    unsigned long address = 0x00000000;

    short i = 0;
    for(i = 0; i < size; i++)
    {
        int x = *(data+i);

        if( x >= 0x30 && x <= 0x39 )
        {
            address |= (*(data+i) & 0x0F);
        }
        else if(x >= 65 && x <= 70) //A : F
        {
            address |= x - 55;
        }

        if(i != size - 1)
            address = address << 4;
    }
    return address;
}

char Validate_Record(const char* record, int len)
{
    unsigned char sum = 0x00;
    unsigned char tmp = 0x00;

    char i = 0;
    for(i = 0 ; i < len ; i += 2)
    {
        tmp = 0x00;

        if( *(record + i) >= 0x30 && *(record + i) <= 0x39 )
        {
            tmp |= (*(record + i) & 0x0F);
        }
        else if(*(record + i) >= 65 && *(record + i) <= 70) //A : F
        {
            tmp |= *(record + i) - 55;
        }

        tmp = tmp << 4;

        if( *(record + i + 1) >= 0x30 && *(record + i + 1) <= 0x39 )
        {
            tmp |= (*(record + i + 1) & 0x0F);
        }
        else if(*(record + i + 1) >= 65 && *(record + i + 1) <= 70) //A : F
        {
            tmp |= *(record + i + 1) - 55;
        }

        sum += tmp;
    }

    return (sum == 0x00)? TRUE : FALSE;
}
