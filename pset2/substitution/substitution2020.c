#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    int i, temp, j;

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    for (i = 0; argv[1][i] != '\0'; i++)
        {
            //Loop through the key so that it checks that there are only alphabet characters, that there are exactly 26 characters and that every alphabet letter appears exactly once

            if (!(isalpha(argv[1][i]))) //Checks if the key has only alphabetic characters.
            {
                printf("The kay must only contain alphabetic characters.\n");
                return 1;
            }
            
            
            
            temp = i;
            
            for (j = 0; argv[1][j] != '\0'; j++)
            {
                if (argv[j] == argv[i])
                {
                    printf("The key must contain only one of each alphabetic character.\n");
                    return 1;
                }
        
            }
            
        }
    
    
    
    
    
        if (i != 26) //Checks wether the key contains 26 characters or not
        {
            printf("The key must contain exactly 26 characters.\n");
            return 1;
        }

    string p_text = get_string("plaintext: "); //Prompts the user for a text to cipher


}