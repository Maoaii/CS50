#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    
    //Cycle through the word input and check what points to give to the i'th character, in ASCII
    for (int i = 0; i < strlen(word); i++)
    {
        //If the word has uppercase letters, convert them to lowercase
        //Symbols are automatically given 0 points
        switch (tolower(word[i]))
        {
            //Characters worth 1 point
            case 97: 
            case 101: 
            case 105:
            case 108:
            case 110:
            case 111:
            case 114:
            case 115:
            case 116:
            case 117:
                score += 1;
                break;
            
            //Chars worth 2 points
            case 100:
            case 103:
                score += 2;
                break;
            
            //Chars worth 3 points
            case 98:
            case 99:
            case 109:
            case 112:
                score += 3;
                break;
            
            //Chars worth 4 points
            case 102:
            case 104:
            case 118:
            case 119:
            case 121:
                score += 4;
                break;
            
            //Chars worth 5 points
            case 107:
                score += 5;
                break;
            
            //Chars worth 8 points
            case 106:
            case 120:
                score += 8;
                break;
            
            //Chars worth 10 points
            case 113:
            case 122:
                score += 10;
                break;

        }
    }
    
    return score;
}
