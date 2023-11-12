#include "BalanceBrackets.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ERROR_STR "Error!\n"

char* getString(ErrorCode* const errorCode)
{
    int length = 0;
    int capacity = 1;

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        *errorCode = outOfMemory;
        return NULL;
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
                return NULL;
            }
        }
        character = getchar();
    }
    string[length] = '\0';

    return string;
}

bool isBracketsCorrect(const char* const string)
{
    ErrorCode errorCode = ok;
    Stack* brackets = NULL;
    char open[] = "{([";
    char close[] = "})]";
    for (const char* character = string; *character != '\0'; ++character) 
    {
        if (strchr(open, *character) != NULL) 
        {
            if (push(&brackets, *character) != ok)
            {
                free(brackets);
                printf(ERROR_STR);
                return false;
            }
        }
        else if (strchr(close, *character) != NULL)
        {
            char element = top(brackets, &errorCode);
            if (errorCode != ok)
            {
                free(brackets);
                return false;
            }
            pop(&brackets);

            if ((strchr(close, *character) - close) != (strchr(open, element) - open))
                return false;
        }
    }
    return true;
}
