#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

void channel(char * inputfile, char * outputfile)
{
    FILE *input_File;
    FILE *output_File;
    uint8_t character;
    input_File = fopen(inputfile, "r");
    output_File = fopen(outputfile, "w");
    if(input_File == NULL)
    {
        printf("Error: File pointer is null.\n");
        exit(1);
    }
    srand (time (NULL));
    int index;
    uint8_t mask;
    int read;
    read = fread(&character,1,1,input_File);
    while (read !=0)
    {
        index = rand()%8;
        mask = 1 << index;
        character ^= mask;
        fwrite(&character,1,1,output_File);
        read = fread(&character,1,1,input_File);
    } 
    fclose(input_File);
    fclose(output_File);
}

int main (int argc, char* argv[]){
    if(argc != 3){
        printf("Please use command: ./channel input_file_name output_file_name");
    }
    else
    {
        channel(argv[1],argv[2]);
    }
    return 0;
}