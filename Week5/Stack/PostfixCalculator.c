#include "Stack.h"
#include "PostfixCalculator.h"

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char* getString(ErrorCode *errorCode)
{
    int length = 0;
    int capacity = 1;

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        *errorCode = outOfMemory;
        return 0;
    }

    char character = getchar();

    while (character != '\n')
    {
        string[length++] = character;

        if (length >= capacity)
        {
            capacity *= 2;
            char* tmp = (char*)realloc(string, capacity * sizeof(char));
            if (tmp != NULL)
            {
                string = tmp;
            }
            else
            {
                *errorCode = outOfMemory;
                return 0;
            }
        }

        character = getchar();

    }

    string[length] = '\0';

    return string;
}

void removeSpaces(char* string)
{
    char* character = string;
    do
    {
        while (*character == ' ')
        {
            ++character;
        }
    } while (*(string++) = *(character++));
}

int postfixCalculator(char* string, ErrorCode* errorCode)
{
    Stack* digits = NULL;
    for (char* character = string; *character != '\0'; ++character)
    {
        if (isdigit(*character))
        {
            push(&digits, (int)*character - '0');
        }
        else
        {
            int second = top(digits, errorCode);
            if (*errorCode != ok || pop(&digits) != ok)
            {
                *errorCode = stackIsEmpty;
                return 0;
            }

            int first = top(digits, errorCode);
            if (*errorCode != ok || pop(&digits) != ok)
            {
                *errorCode = stackIsEmpty;
                return 0;
            }

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

    int answer = top(digits, errorCode);
    pop(&digits);

    return answer;
}
