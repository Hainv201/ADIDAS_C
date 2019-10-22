#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"

FILE *input_File;
FILE *output_File;
char character;


void encode(char * inputfile, char * outputfile)
{
    input_File = fopen(inputfile, "r");
    output_File = fopen(outputfile, "wb");
    if(input_File == NULL)
    {
        printf("Error: File pointer is null.\n");
        exit(1);
    }
    else
    {
        while ((character = fgetc(input_File))!=EOF)
        {
            char* Nibbles = ConvertCharactertoNibbles(character);
            char encode_high_nibble = AddParity(Nibbles[0]);
            fputc(encode_high_nibble,output_File);
            char encode_low_nibble = AddParity(Nibbles[1]);
            fputc(encode_low_nibble,output_File);
        }
        
    }
    
    fclose(input_File);
    fclose(output_File);
}

int main (int argc, char* argv[]){
    if(argc != 3){
        printf("Please use command: ./encode input_file_name output_file_name");
    }
    else
    {
        encode(argv[1],argv[2]);
    }
    return 0;
}