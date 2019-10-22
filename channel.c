#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

FILE *input_File;
FILE *output_File;
char character;

void channel(char * inputfile, char * outputfile)
{
    input_File = fopen(inputfile, "r");
    output_File = fopen(outputfile, "w");
    if(input_File == NULL)
    {
        printf("Error: File pointer is null.\n");
        exit(1);
    }
     else
    {
        srand (time (NULL));
        int index, mask;
        while ((character = fgetc(input_File))!=EOF)
        {
            index = rand()%7;
            mask = pow(2,index);
            character ^= mask;
            fputc(character,output_File);
        }
        
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