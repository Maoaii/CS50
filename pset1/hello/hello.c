#include <stdio.h>
#include <cs50.h>

//Prompts the user to write out their name.
//Prints out "hello, name".
int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
