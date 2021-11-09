#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{


    if (argc == 2) //Limits the command line argument quantity
    {
        
        for (int i = 0; argv[1][i] != '\0'; i++)
        {  
            
            if (isalpha(argv[1][i])) //If any character is from the alphabet, print the error
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
    
    
    int key = atoi(argv[1]); //Converts the key to an int
    
    
    //User input for the text
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    
    
    //The conditions: preserve case, digits and ponctuation
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        
        if (plaintext[i] <= 'z' && plaintext[i] >= 'a')
        {
            
            if (plaintext[i] + key > 'z')
            {
                
                int sum = (plaintext[i] - 'a' + key) % 26 + 'a'; //Make it so the sum loops in the alphabet
                printf("%c", sum);
                
            }
            else
            {
                
                printf("%c", plaintext[i] + key); //Print when doesn't loop the alphabet
                
            }
            
        }
        else if (plaintext[i] <= 'Z' && plaintext[i] >= 'A')
        {
            
            if (plaintext[i] + key > 'Z')
            {
                
                int sum = (plaintext[i] - 'A' + key) % 26 + 'A'; //Make it so the sum loops in the alphabet
                printf("%c", sum);
                
            }
            else
            {
                
                printf("%c", plaintext[i] + key); //Print when doesn't loop the alphabet
                
            }
        }
        else
        {
            
            printf("%c", plaintext[i]); //Print digits and punctuation
            
        }

    }
    
    printf("\n");
    
}