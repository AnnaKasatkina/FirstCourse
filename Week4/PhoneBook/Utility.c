#include "Utility.h"

#include <stdlib.h>
#include <stdbool.h>

char* getString(FILE* file, const char separator)
{
    size_t length = 0;
    size_t capacity = 1;

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        return NULL;
    }

    for (char character = fgetc(file); character != separator && character != EOF; character = fgetc(file))
    {
        if (feof(file))
        {
            return NULL;
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

    }
    string[length] = '\0';

    return string;
}
