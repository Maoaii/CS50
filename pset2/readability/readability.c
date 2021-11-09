#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float compute_grade(string text);

int main(void)
{
    //Declare variables
    string text;
    int grade;
    
    //Prompt user for text
    text = get_string("Text: ");
    
    //Get grade level
    grade = compute_grade(text);
    
    //Print text grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade); //Round
    }
    
    
}


//Grade computing function
float compute_grade(string text)
{
    //Declare variables
    int letters = 0;
    int words = 1; //Since the last word in the text isn't followed by a space, initialized as 1
    int sentences = 0;
    float L = 0;
    float S = 0;
    float index = 0;
    
    //Count letters, words and sentences in the text
    for (int i = 0; i < strlen(text); i++)
    {
        //Letter counter
        switch (tolower(text[i]))
        {
            case 97:
            case 98:
            case 99:
            case 100:
            case 101:
            case 102:
            case 103:
            case 104:
            case 105:
            case 106:
            case 107:
            case 108:
            case 109:
            case 110:
            case 111:
            case 112:
            case 113:
            case 114:
            case 115:
            case 116:
            case 117:
            case 118:
            case 119:
            case 120:
            case 121:
            case 122:
                letters++;
                break;
            
            //Word counter
            case 32:
                words++;
                break;
            
            //Sentence counter
            case 46:
            case 33:
            case 63:
                sentences++;
                break;
        }
    }
    
    //Calculate the average number of letters per 100 words in the text (L)
    L = (letters * 100.0) / words;
    
    //Calculate the average number of sentences per 100 words in the text (S)
    S = (sentences * 100.0) / words;
    
    //Calculate the grade level: index = 0.0588 * L - 0.296 * S - 15.8
    index = 0.0588 * L - 0.296 * S - 15.8;
    
    //Return the grade level
    return round(index);
    
}