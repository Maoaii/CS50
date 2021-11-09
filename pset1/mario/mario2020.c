//Fiz este em 2020. Usar como referência ou ajuda se for preciso

#include <cs50.h>
#include <stdio.h>

int main(void)
{


    int n;


//Prompts the user for a desired pyramid height
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);


//Develops the left half of the pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j < (n - 1))
            {
                printf(" "); 
                
            }
            else
            {    
                printf("#"); 
                
            }
        }
        


//Gap between the pyramids
        printf("  ");


//Develops the right half of the pyramid
        for (int k = 0; k < n; k++)
        {
            if (k <= i)
            {
                printf("#");
            }
        }


//New line in the pyramid (depends on the height)
        printf("\n");
    
    
    }
}