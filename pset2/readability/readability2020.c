#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


int main(void)
{

//Initializes all the variables needed
    float L, S, index;
    int i, l, w, s;
    i = l = s = L = S = index = 0;
    w = 1; //Needs to be 1 because otherwise it wouldn't count the last word


//Prompts the user for a text
    string text = get_string("Text: ");


//Counts the number of letters (l), words (w) and sentences (s) in the text
    while (text[i] != '\0')
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            l++;
        }
        else if (text[i] == ' ')
        {
            w++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }

        i++;

    }


//Calculates Coleman-Liau index
    L = 100.0 * l / w;
    S = 100.0 * s / w;
    index = (0.0588 * L) - (0.296 * S) - 15.8;
    index = round(index);


//Prints the readability grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }



}




