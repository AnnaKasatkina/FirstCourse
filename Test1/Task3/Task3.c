#include "Task3.h"

#include <stdio.h>
#include <stdlib.h>

char* getStringFromFile(const char* const nameFile)
{
    FILE* file = fopen(nameFile, "r");

    size_t length = 0;
    size_t capacity = 1;

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        return NULL;
    }

    char previousCharacter = '\0';
    for (char character = fgetc(file); character != EOF; character = fgetc(file))
    {
        if (previousCharacter == character)
        {
            continue;
        }

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
                return NULL;
            }
        }
        previousCharacter = character;
    }

    string[length] = '\0';

    return string;
}
