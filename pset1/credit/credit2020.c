#include <stdio.h>
#include <cs50.h>


//Prompt the user to insert a credit card number and check if it's valid (identify which one it is)
int main(void)
{
    float credit_n;
    do
    {
        credit = get_float("Insert credit card number: ");
    }
    while (credit < 0)

    if (credit > 100000000000000 && credit < 1000000000000000)
    {
        printf("American Express.");
    }
    else if (credit < 1000000000000000 && credit > 1000000000000)
    {
        printf("Visa.");
    }
    else if (credit > 100000000000000)
    {
        printf("MasterCard.");
    }
}

//Get every other digit starting from the second-last one


//Multiply each one by 2


//Get the rest of the digits


//Add them together~


//Add all the digits we got


//If the last digit of the sum is 0, it is valid, if not, it is not valid