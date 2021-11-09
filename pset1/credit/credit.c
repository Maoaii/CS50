#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for cc number
    long int cc_number;
    long int check2 = 0;
    long int check1 = 0;
    long int check_sum = 0;
    
    cc_number = get_long("Credit card number: ");

//AMEX

    //Check cc length and first two digits
    if (cc_number > 100000000000000 
    && cc_number < 1000000000000000 
    && (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000 == 3
    && (((cc_number % 100000000000000 - cc_number % 10000000000000) / 10000000000000) == 4
    || ((cc_number % 100000000000000 - cc_number % 10000000000000) / 10000000000000) == 7))
    {
        
        //Check sum pattern
        check2 =  ((cc_number % 100 - cc_number % 10) / 10) * 2
                + ((cc_number % 10000 - cc_number % 1000) / 1000) * 2
                + ((cc_number % 1000000 - cc_number % 100000) / 100000) * 2
                + ((cc_number % 100000000 - cc_number % 10000000) / 10000000) * 2
                + ((cc_number % 10000000000 - cc_number % 1000000000) / 1000000000) * 2
                + ((cc_number % 1000000000000 - cc_number % 100000000000) / 100000000000) * 2
                + ((cc_number % 100000000000000 - cc_number % 10000000000000) / 10000000000000) * 2;
            
        check1 =   cc_number % 10 
                + (cc_number % 1000 - cc_number % 100) / 100 
                + (cc_number % 100000 - cc_number % 10000) / 10000 
                + (cc_number % 10000000 - cc_number % 1000000) / 1000000
                + (cc_number % 1000000000 - cc_number % 100000000) / 100000000
                + (cc_number % 100000000000 - cc_number % 10000000000) / 10000000000
                + (cc_number % 10000000000000 - cc_number % 1000000000000) / 1000000000000
                + (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000;
    
        check_sum = check1 + check2;
        
        //Print AMEX or INVALID
        if (check_sum % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    
//MASTERCARD
    
    //Check length and first two digits
    else if (cc_number > 1000000000000000 
    && cc_number < 10000000000000000 
    && (((cc_number % 10000000000000000 - cc_number % 1000000000000000) / 1000000000000000) == 5
    || (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000 == 1
    || (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000 == 2
    || (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000 == 3
    || (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000 == 4
    || (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000 == 5))
    {
        //Check sum pattern
        check2 =  ((cc_number % 100 - cc_number % 10) / 10) * 2
                + ((cc_number % 10000 - cc_number % 1000) / 1000) * 2
                + ((cc_number % 1000000 - cc_number % 100000) / 100000) * 2
                + ((cc_number % 100000000 - cc_number % 10000000) / 10000000) * 2
                + ((cc_number % 10000000000 - cc_number % 1000000000) / 1000000000) * 2
                + ((cc_number % 1000000000000 - cc_number % 100000000000) / 100000000000) * 2
                + ((cc_number % 100000000000000 - cc_number % 10000000000000) / 10000000000000) * 2
                + ((cc_number % 10000000000000000 - cc_number % 1000000000000000) / 1000000000000000) * 2;
            
        check1 =   cc_number % 10 
                + (cc_number % 1000 - cc_number % 100) / 100 
                + (cc_number % 100000 - cc_number % 10000) / 10000 
                + (cc_number % 10000000 - cc_number % 1000000) / 1000000
                + (cc_number % 1000000000 - cc_number % 100000000) / 100000000
                + (cc_number % 100000000000 - cc_number % 10000000000) / 10000000000
                + (cc_number % 10000000000000 - cc_number % 1000000000000) / 1000000000000
                + (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000;
    
        check_sum = check1 + check2;
        
        //Print MASTERCARD or INVALID
        if (check_sum % 10 == 0)
        {
            printf("MASTERCARD\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    
//VISA

    //Check length
    else if ((cc_number > 1000000000000 && cc_number < 10000000000000 && (cc_number % 10000000000000 - cc_number % 1000000000000) / 1000000000000 == 4)
    || (cc_number > 1000000000000000 && cc_number < 10000000000000000 && (cc_number % 10000000000000000 - cc_number % 1000000000000000) / 1000000000000000 == 4))

    {
        //If it is 13-digit long
        if ((cc_number % 10000000000000 - cc_number % 1000000000000) / 1000000000000 == 4)
        {
            //Check sum pattern
            check2 =  ((cc_number % 100 - cc_number % 10) / 10) * 2
                    + ((cc_number % 10000 - cc_number % 1000) / 1000) * 2
                    + ((cc_number % 1000000 - cc_number % 100000) / 100000) * 2
                    + ((cc_number % 100000000 - cc_number % 10000000) / 10000000) * 2
                    + ((cc_number % 10000000000 - cc_number % 1000000000) / 1000000000) * 2
                    + ((cc_number % 1000000000000 - cc_number % 100000000000) / 100000000000) * 2;
            
            check1 =   cc_number % 10 
                    + (cc_number % 1000 - cc_number % 100) / 100 
                    + (cc_number % 100000 - cc_number % 10000) / 10000 
                    + (cc_number % 10000000 - cc_number % 1000000) / 1000000
                    + (cc_number % 1000000000 - cc_number % 100000000) / 100000000
                    + (cc_number % 100000000000 - cc_number % 10000000000) / 10000000000
                    + (cc_number % 10000000000000 - cc_number % 1000000000000) / 1000000000000;
        }

        //If it is 16-digit long
        else if ((cc_number % 10000000000000000 - cc_number % 1000000000000000) / 1000000000000000 == 4)
        {
            //Check sum pattern
            check2 =  ((cc_number % 100 - cc_number % 10) / 10) * 2
                    + ((cc_number % 10000 - cc_number % 1000) / 1000) * 2
                    + ((cc_number % 1000000 - cc_number % 100000) / 100000) * 2
                    + ((cc_number % 100000000 - cc_number % 10000000) / 10000000) * 2
                    + ((cc_number % 10000000000 - cc_number % 1000000000) / 1000000000) * 2
                    + ((cc_number % 1000000000000 - cc_number % 100000000000) / 100000000000) * 2
                    + ((cc_number % 100000000000000 - cc_number % 10000000000000) / 10000000000000) * 2
                    + ((cc_number % 10000000000000000 - cc_number % 1000000000000000) / 1000000000000000) * 2;
            
            check1 =   cc_number % 10 
                    + (cc_number % 1000 - cc_number % 100) / 100 
                    + (cc_number % 100000 - cc_number % 10000) / 10000 
                    + (cc_number % 10000000 - cc_number % 1000000) / 1000000
                    + (cc_number % 1000000000 - cc_number % 100000000) / 100000000
                    + (cc_number % 100000000000 - cc_number % 10000000000) / 10000000000
                    + (cc_number % 10000000000000 - cc_number % 1000000000000) / 1000000000000
                    + (cc_number % 1000000000000000 - cc_number % 100000000000000) / 100000000000000;
        }

        printf("%li\n", ((cc_number % 1000000000000 - cc_number % 100000000000) / 100000000000) * 2);
        
        check_sum = check1 + check2;
        printf("%li", check2);
        //Print VISA or INVALID
        if (check_sum % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
        
    }
    
}