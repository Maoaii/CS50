// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    
    //Declare the size of the header file in 1 bytes
    uint8_t header[HEADER_SIZE];
    
    //Read from input into the header buffer
    fread(header, HEADER_SIZE, 1, input);
    
    //Write into output from header buffer
    fwrite(header, HEADER_SIZE, 1, output);
    
    // TODO: Read samples from input file and write updated data to output file
    
    //Declare a buffer of 2 bytes (size of wav samples)
    int16_t buffer;
    
    //Read sample from input into buffer
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        //Multiply sample value by factor
        buffer *= factor;
        //Write new sample into output from buffer
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    
        
    // Close files
    fclose(input);
    fclose(output);
}
