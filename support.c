#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

void ConvertCharactertoNibbles(uint8_t input_character, uint8_t* high_nibble, uint8_t* low_nibble){
    *high_nibble = (input_character & 0xF0)>>1;//Get High Nibble
    *low_nibble = (input_character & 0xF)<<3;//Get Low Nibble
}

int CheckEven(uint8_t nibble){
    nibble ^= nibble >> 4;
    nibble ^= nibble >> 2;
    nibble ^= nibble >> 1;
return nibble & 1; // return 0 if it is even and 1 if it is odd
}

uint8_t AddParity(uint8_t nibble){
    uint8_t p0 = 0;
    uint8_t p1 = 0;
    uint8_t p2 = 0;
    if(CheckEven(nibble & ENCODE_MASKP0) == 1){
        p0 = 1;
    }
    if(CheckEven(nibble & ENCODE_MASKP1) == 1){
        p1 = 1;
    }
    if(CheckEven(nibble & ENCODE_MASKP2) == 1){
        p2 = 1;
    }
    nibble |= p0;
    nibble |= (p1<<1);
    nibble |= (p2<<2);
    return nibble;
}

uint8_t CorrectInputCharacter(uint8_t character){
    if(CheckEven(character & DECODE_MASKP0) == 1 
    && CheckEven(character & DECODE_MASKP1) == 1 
    && CheckEven(character & DECODE_MASKP2) == 1) //incorrect at d1
    {
        character ^= 0x10;
    }
    else if (CheckEven(character & DECODE_MASKP0) == 1 
    && CheckEven(character & DECODE_MASKP1) == 1) //incorrect at d0
    {
        character ^= 0x8;
    }
    else if (CheckEven(character & DECODE_MASKP0) == 1
    && CheckEven(character & DECODE_MASKP2) == 1) // incorrect at d2
    {
        character ^= 0x20;
    }
    else if (CheckEven(character & DECODE_MASKP1) == 1 
    && CheckEven(character & DECODE_MASKP2) == 1) // incorrect at d3
    {
        character ^= 0x40;
    }
    else if (CheckEven(character & DECODE_MASKP0) == 1) // incorrect at p0
    {
        character ^= 0x1;
    }
    else if (CheckEven(character & DECODE_MASKP1) == 1) // incorrect at p1
    {
        character ^= 0x2;
    }   
    else if (CheckEven(character & DECODE_MASKP2) == 1) // incorrect at p2
    {
        character ^= 0x4;
    }
    else if (CheckEven(character & 0x80)== 1)
    {
        character ^= 0x80; //incorrect at first bit
    }
    return character;
}

uint8_t GetData(uint8_t high_nibble,uint8_t low_nibble){
    high_nibble = (high_nibble & 0x78) << 1;
    low_nibble = low_nibble >> 3;
    return high_nibble | low_nibble;
}
