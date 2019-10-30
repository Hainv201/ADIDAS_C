#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"
#include <inttypes.h>

void encode(char * inputfile, char * outputfile)
{
    FILE *input_File;
    FILE *output_File;
    uint8_t character,encode_high_nibble,encode_low_nibble;
    input_File = fopen(inputfile, "r");
    output_File = fopen(outputfile, "w");
    if(input_File == NULL)
    {
        printf("Error: File pointer is null.\n");
        exit(1);
    }
    while (!feof(input_File))
    {
        fread(&character,sizeof(uint8_t),1,input_File);
        if(feof(input_File))
        {
            break;
        }
        ConvertCharactertoNibbles(character, &encode_high_nibble, &encode_low_nibble);
        encode_high_nibble = AddParity(encode_high_nibble);
        fwrite(&encode_high_nibble,sizeof(uint8_t),1,output_File);
        encode_low_nibble = AddParity(encode_low_nibble);
        fwrite(&encode_low_nibble,sizeof(uint8_t),1,output_File);
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