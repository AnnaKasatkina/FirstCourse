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
            int second = pop(&digits);
            int first = pop(&digits);
            switch (*character)
            {
            case '+':
                push(&digits, first + second);
                break;
            case '/':
                push(&digits, first / second);
                break;
            case '*':
                push(&digits, first * second);
                break;
            case '-':
                push(&digits, first - second);
                break;
            default:
                break;
            }
        }
    }
    printf("%d", pop(&digits));

    return 0;
}
