#include "ShuntingYard.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 

char* getString(ErrorCode* const errorCode, size_t* length)
{
    size_t capacity = 1;
    size_t countCharIgnor = 0;
    const* charIgnor = "( )";

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        *errorCode = outOfMemory;
        return 0;
    }

    char character = getchar();

    while (character != '\n')
    {
        string[(*length)++] = character;
        if (strchr(charIgnor, character))
        {
            ++countCharIgnor;
        }

        if (*length >= capacity)
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

    string[(*length)] = '\0';
    *length -= countCharIgnor;

    return string;
}

ErrorCode shuntingYard(const char* const string, char* const output)
{
    ErrorCode errorCode = ok;
    size_t index = 0;
    Stack* operations = NULL;

    char* upper = "*/";
    char* lower = "+-";
    char* allOperations = "*/+-";

    for (const char* character = string; *character != '\0'; ++character)
    {
        if (isdigit(*character))
        {
            output[index] = *character;
            ++index;
        }
        else if (strchr(lower, *character))
        {
            while (operations != NULL && strchr(allOperations, (char)top(operations, &errorCode)))
            {
                output[index] = (char)top(operations, &errorCode);
                pop(&operations);
                ++index;
            }

            if (push(&operations, *character) != ok)
            {
                return outOfMemory;
            }
        }
        else if (strchr(upper, *character))
        {
            while (operations != NULL && strchr(upper, (char)top(operations, &errorCode)))
            {
                output[index] = (char)top(operations, &errorCode);
                pop(&operations);
                ++index;
            }

            if (push(&operations, *character) != ok)
            {
                return outOfMemory;
            }
        }
        else if (*character == '(')
        {
            if (push(&operations, *character) != ok)
            {
                return outOfMemory;
            }
        }
        else if (*character == ')')
        {
            while (operations != NULL && (char)top(operations, &errorCode) != '(')
            {
                output[index] = (char)top(operations, &errorCode);
                pop(&operations);
                ++index;
            }
            pop(&operations);
        }
    }

    while (operations != NULL)
    {
        output[index] = (char)top(operations, &errorCode);
        pop(&operations);
        ++index;
    }

    output[index] = '\0';

    return errorCode;
}
