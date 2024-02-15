#include <stdio.h>
#include <stdlib.h>

#include "List.h"

static char* getElement(FILE* file, char separator)
{
    size_t length = 0;
    size_t capacity = 1;

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        return NULL;
    }

    for (char character = fgetc(file); character != separator; character = fgetc(file))
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

char*** readPhoneBook(const char* const nameFile, size_t* length)
{
    char* buffer[COUNT][SIZE] = {""};
    FILE* file = fopen(nameFile, "a+");
    if (file == NULL)
    {
        return NULL;
    }

    for (; !feof(file); ++(*length))
    {
        buffer[0][*length] = getElement(file, '-');
        if (buffer[0][*length] == NULL)
        {
            return NULL;
        }

        buffer[0][*length] = getElement(file, '\n');
        if (buffer[0][*length] == NULL)
        {
            return NULL;
        }
    }
    --(*length);

    fclose(file);
    return buffer;
}