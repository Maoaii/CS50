#include <stdio.h>
#include <cs50.h>

int main(void)
{
//Input for pyramid height
    int height;
    
    do
    {
        height = get_int("Pyramid Height: ");
    }
    while (height < 1 || height > 8);
    
    
    //Print \n for each row
    for (int i = 1; i <= height; i++)
    {
//Left pyramid

        //Print spaces descending in order from height
        for (int l = height; l > i; l--)
        {
            printf(" ");
        }
        
        //Print "#" same times as row number (i)
        for (int j = 0; j < i; j++)
        {
            printf("#");  
        }
        
        //Gap between pyramids
        printf("  ");

//Right pyramid
        
        //Print #'s according to row number
        for (int a = 0; a < i; a++)
        {
            printf("#");
        }   
    
        printf("\n");
        
    }
    
}