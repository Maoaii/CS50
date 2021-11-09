#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    float dollars;
    int coins = 0, pb = 0;
    
//Prompt the user for a amount of owed change. (i.e.: 7.61$)
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
//Round the cents to the nearest penny
    int cents_change = round(dollars * 100);
    
//Subtract the coin value to the owed change until cents_change = 0
    while (cents_change >= 25)
    {
        coins++;
        cents_change = cents_change - 25; 
    }
    
    while (cents_change >= 10)
    {
        coins++;
        cents_change = cents_change - 10;
    }

    while (cents_change >= 5)
    {
        coins++;
        cents_change = cents_change - 5;
    }
    
    while (cents_change >= 1)
    {
        coins++;
        cents_change = cents_change - 1;
    }
    
//Prints out the least amount of coins needed to five back the owed change
    printf("%i\n", coins);
    

}
