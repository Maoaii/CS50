#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int popStartSize = get_int("Starting population size: ");
    if (popStartSize < 9)
    {
        do
        {
            popStartSize = get_int("Starting population size (more than 8 llamas): ");
        }
        while (popStartSize < 9);
    }

    // TODO: Prompt for end size
    int popEndSize = get_int("Population end size: ");
    if (popEndSize < popStartSize)
    {
        do
        {
            popEndSize = get_int("Population end size (must be greater than the starting population): ");
        }
        while (popEndSize < popStartSize);
    }

    // TODO: Calculate number of years until we reach threshold
    int n = 0;

    while (popStartSize < popEndSize)
    {
        popStartSize = popStartSize + popStartSize / 3 - popStartSize / 4;
        n++;
    }
    
    // TODO: Print number of years
    printf("Years: %i\n", n);    

    
    
}