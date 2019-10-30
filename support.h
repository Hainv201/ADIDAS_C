#ifndef _SUPPORT_H
#define _SUPPORT_H

#include <stdint.h>
#define ENCODE_MASKP0 0x38
#define ENCODE_MASKP1 0x58
#define ENCODE_MASKP2 0x70
#define DECODE_MASKP0 0x39
#define DECODE_MASKP1 0x5A
#define DECODE_MASKP2 0x74

void ConvertCharactertoNibbles(uint8_t input_character, uint8_t* high_nibble, uint8_t* low_nibble);
int CheckEven(uint8_t nibble);
uint8_t AddParity(uint8_t nibble);
uint8_t CorrectInputCharacter(uint8_t character);
uint8_t GetData(uint8_t high_nibble,uint8_t low_nibble);

#endif