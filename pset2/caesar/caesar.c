#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    //Check wether there is only 1 command line argument
    if (argc == 2)
    {
        //Check if there is any character that's not a digit
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //Convert key to an int
    int key = atoi(argv[1]);
    
    //Prompt plaintext
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    
    //Shift ciphertext's characters by the amount of "key"
    for (int i = 0; i < strlen(plaintext); i++)
    {
        //If it isn't a letter, do nothing
        if (isalpha(plaintext[i]) == false)
        {
            ciphertext[i] = plaintext[i];
        }
        else
        {
            //If it's uppercase
            if (isupper(plaintext[i]))
            {
                //Convert ASCII to alphabetical index
                plaintext[i] -= 'A';
                //Shift alphabetical index
                ciphertext[i] = (plaintext[i] + key) % 26;
                //Convert alphabetical index to ASCII
                ciphertext[i] += 'A';
            }
            //If it's lowercase
            else if (islower(plaintext[i]))
            {
                //Convert ASCII to alphabetical index
                plaintext[i] -= 'a';
                //Shift alphabetical index
                ciphertext[i] = (plaintext[i] + key) % 26;
                //Convert alphabetical index to ASCII
                ciphertext[i] += 'a';
            }
        
        }

    }
    
    //Print ciphertext
    printf("ciphertext: %s\n", ciphertext);
}
