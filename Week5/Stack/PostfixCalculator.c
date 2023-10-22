#include "Stack.h"
#include <string.h>
#include <stdio.h>

#define LEN 256

void removeSpaces(char* string)
{
    char* character = string;
    do
    {
        while (*character == ' ')
        {
            ++character;
        }
    } while (*string++ = *character++);
}

int main(void)
{
    Stack* digits = NULL;
    char string[LEN] = "";
    gets(string);
    removeSpaces(string);
    for (char* character = string; *character != '\0'; ++character)
    {
        if (isdigit(*character))
        {
            push(&digits, (int)*character - '0');
        }
        else
        {
            switch (*character)
            {
            case '+':
                push(&digits, pop(&digits) + pop(&digits));
                break;
            case '/':
                push(&digits, pop(&digits) / pop(&digits));
                break;
            case '*':
                push(&digits, pop(&digits) * pop(&digits));
                break;
            case '-':
                push(&digits, pop(&digits) - pop(&digits));
                break;
            default:
                break;
            }
        }
    }
    printf("%d", pop(&digits));

    return 0;
}