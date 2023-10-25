#include "Stack.h"
#include "BalanceBrackets.h"

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

char* getString(ErrorCode* errorCode)
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

bool isBracketsCorrect(char* string)
{
    ErrorCode errorCode = ok;
    Stack* brackets = NULL;
    char open[] = "{([";
    char close[] = "})]";
    for (char* character = string; *character != '\0'; ++character) {
        if (strchr(open, *character) != NULL) {
            push(&brackets, *character);
        }
        else if (strchr(close, *character) != NULL)
        {
            char element = top(brackets, &errorCode);
            if (errorCode != ok || pop(&brackets) != ok)
            {
                return false;
            }

            if ((strchr(close, *character) - close) != (strchr(open, element) - open))
                return false;
        }
    }
    return true;
}

void printResult(bool result)
{
    if (result)
    {
        printf("Correct");
    }
    else
    {
        printf("Incorrect");
    }
}
