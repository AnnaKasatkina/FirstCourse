#include "ShuntingYard.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 

int getString(ErrorCode* errorCode, char **string)
{
    int capacity = 1;
    int length = 0;

    if (*string == NULL)
    {
        *errorCode = outOfMemory;
        return ERROR;
    }

    char character = getchar();

    while (character != '\n')
    {
        if (character != ' ')
        {
            (*string)[length++] = character;

            if (length >= capacity)
            {
                capacity *= 2;
                char* tmp = (char*)realloc(*string, capacity * sizeof(char));
                if (tmp != NULL)
                {
                    *string = tmp;
                }
                else
                {
                    *errorCode = outOfMemory;
                    return ERROR;
                }
            }
        }
        character = getchar();
    }
    (*string)[length] = '\0';

    return length;
}

ErrorCode shuntingYard(char* string, char* output)
{
    ErrorCode errorCode = ok;
    size_t index = 0;
    Stack* operations = NULL;

    char* upper = "*/";
    char* lower = "+-";

    for (char* character = string; *character != '\0'; ++character)
    {
        if (isdigit(*character))
        {
            output[index] = *character;
            ++index;
        }
        else if (strchr(lower, *character))
        {
            while (operations != NULL && (strchr(lower, (char)top(operations, &errorCode)) || strchr(upper, (char)top(operations, &errorCode))))
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
