#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "support.h"
#include <inttypes.h>


void decode(char * inputfile, char * outputfile)
{
    FILE *input_File;
    FILE *output_File;
    input_File = fopen(inputfile, "r");
    output_File = fopen(outputfile, "w");
    if(input_File == NULL)
    {
        printf("Error: File pointer is null.\n");
        exit(1);
    }
    uint8_t low_nibble, high_nibble,data;
    while (!feof(input_File))
    {
        fread(&high_nibble,sizeof(uint8_t),1,input_File);
        fread(&low_nibble,sizeof(uint8_t),1,input_File);
        if(feof(input_File))
        {
            break;
        }
        high_nibble = CorrectInputCharacter(high_nibble);
        low_nibble = CorrectInputCharacter(low_nibble);
        data = GetData(high_nibble,low_nibble);
        fwrite(&data,sizeof(uint8_t),1,output_File);
    }
    
    fclose(input_File);
    fclose(output_File);
}


int main (int argc, char* argv[]){
    if(argc != 3){
        printf("Please use command: ./decode input_file_name output_file_name");
    }
    else
    {
        decode(argv[1],argv[2]);
    }
    return 0;
}