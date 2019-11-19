#ifndef _SUPPORT_H
#define _SUPPORT_H

#include <stdint.h>

void ConvertCharactertoNibbles(uint8_t input_character, uint8_t* high_nibble, uint8_t* low_nibble);
int CheckEven(uint8_t nibble);
uint8_t AddParity(uint8_t nibble);
uint8_t CorrectInputCharacter(uint8_t character);
uint8_t GetData(uint8_t high_nibble,uint8_t low_nibble);

#endif