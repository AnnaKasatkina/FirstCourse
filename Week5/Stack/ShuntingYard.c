#include "ShuntingYard.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int getString(ErrorCode* errorCode, char **string)
{
    int capacity = 1;
    int length = 0;

    if (*string == NULL)
    {
        *errorCode = outOfMemory;
        return NULL;
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
                    return NULL;
                }
            }
        }
        character = getchar();
    }
    (*string)[length] = '\0';

    return length;
}
