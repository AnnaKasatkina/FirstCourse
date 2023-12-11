#include "Utility.h"

#include <stdio.h>
#include <stdlib.h>

char* getString(FILE* file, size_t* const length)
{
    size_t capacity = 1;

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        return NULL;
    }

    *length = 0;
    for (char character = fgetc(file); character != ' ' && character != EOF 
        && character != '\n'; character = fgetc(file))
    {
        string[(*length)++] = character;

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
                free(string);
                return NULL;
            }
        }
    }
    string[*length] = '\0';

    return string;
}

List* getStringFromFile(const char* const nameFile)
{
    ErrorCode errorCode = ok;
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        return NULL;
    }

    List* list = (List*)calloc(1, sizeof(List));
    if (list == NULL)
    {
        return NULL;
    }

    while (!feof(file))
    {
        size_t length = 0;
        char* value = getString(file, &length);
        if (value == NULL)
        {
            freeList(list);
            return NULL;
        }
        pushBack(list, value, length, &errorCode);
        if (errorCode != ok)
        {
            freeList(list);
            return NULL;
        }
    }
    fclose(file);

    return list;
}
