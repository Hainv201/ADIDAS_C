#ifndef _SUPPORT_H
#define _SUPPORT_H

#define ENCODE_MASKP0 56
#define ENCODE_MASKP1 88
#define ENCODE_MASKP2 112
#define DECODE_MASKP0 57
#define DECODE_MASKP1 90
#define DECODE_MASKP2 116

char* ConvertCharactertoNibbles(char input_character);
int CheckEven(char nibble);
char AddParity(char nibble);
char CorrectInputCharacter(char character);
char GetData(char high_nibble,char low_nibble);

#endif