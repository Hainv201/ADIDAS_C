#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

char* ConvertCharactertoNibbles(char input_character){
    char* Nibbles = malloc(sizeof(char));
    Nibbles[0] = (input_character&240)>>1;//Get High Nibble
    Nibbles[1] = (input_character&15)<<3;//Get Low Nibble
    return Nibbles;
}

int CheckEven(char nibble){
    nibble ^= nibble >> 4;
    nibble ^= nibble >> 2;
    nibble ^= nibble >> 1;
return nibble & 1; // return 0 if it is even and 1 if it is odd
}

char AddParity(char nibble){
    char parity[3]={0,0,0};
    if(CheckEven(nibble&ENCODE_MASKP0) == 1){
        parity[0] =1;
    }
    if(CheckEven(nibble&ENCODE_MASKP1) == 1){
        parity[1] = 1;
    }
    if(CheckEven(nibble&ENCODE_MASKP2) == 1){
        parity[2] =1;
    }
    nibble ^=parity[0];
    nibble ^=(parity[1]<<1);
    nibble ^=(parity[2]<<2);
    return nibble;
}

char CorrectInputCharacter(char character){
    if(CheckEven(character&DECODE_MASKP0) == 1 
    && CheckEven(character&DECODE_MASKP1)==1 
    && CheckEven(character&DECODE_MASKP2)==1) //incorrect at d1
    {
        return character^16;
    }
    else if (CheckEven(character&DECODE_MASKP0) == 1 
    && CheckEven(character&DECODE_MASKP1)==1) //incorrect at d0
    {
        return character ^8;
    }
    else if (CheckEven(character&DECODE_MASKP0) == 1 
    && CheckEven(character&DECODE_MASKP2)==1) // incorrect at d2
    {
        return character ^32;
    }
    else if (CheckEven(character&DECODE_MASKP1) == 1 
    && CheckEven(character&DECODE_MASKP2)==1) // incorrect at d3
    {
        return character ^64;
    }
    else if (CheckEven(character&DECODE_MASKP0) == 1) // incorrect at p0
    {
        return character ^1;
    }
    else if (CheckEven(character&DECODE_MASKP1) == 1) // incorrect at p1
    {
        return character ^2;
    }   
    else if (CheckEven(character&DECODE_MASKP2) == 1) // incorrect at p2
    {
        return character ^4;
    }
    else
    {
        return character ^128; //incorrect at first bit
    }
}

char GetData(char high_nibble,char low_nibble){
    high_nibble = (high_nibble&120)<<1;
    low_nibble = low_nibble>>3;
    return high_nibble^low_nibble;
}
