#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float owed;
    int coins = 0;
    
    //Prompt user for owed change
    do
    {
        owed = round(get_float("Change owed: ") * 100);    
    }
    while (owed < 0);
    
    //Until there is no more change
    while (owed > 0)
    {
        //Use a quarter
        if (owed >= 25)
        {
            owed = owed - 25;
            coins++;
        }
        //Use a dime
        else if (owed < 25 && owed >= 10)
        {
            owed = owed - 10;
            coins++;
        }
        //Use a 
        else if (owed < 10 && owed >= 5)
        {
            owed = owed - 5;
            coins++;
        }
        //Use a penny
        else if (owed < 5 && owed > 0)
        {
            owed = owed - 1;
            coins++;
        }
        //If not owing, 0 coins are used
        else
        {
            printf("%i\n", coins);
        }
    }
    
    //Print number of coins used
    printf("%i\n", coins);
    
}