#include "Utility.h"

#include <stdio.h>

wchar_t* getString(size_t* length)
{
    size_t capacity = 1;

    wchar_t* string = (wchar_t*)malloc(sizeof(wchar_t));
    if (string == NULL)
    {
        return NULL;
    }

    for (wchar_t character = getwchar(); character != '\n'; character = getwchar())
    {
        string[(*length)++] = character;

        if (*length >= capacity)
        {
            capacity *= 2;
            wchar_t* tmp = (wchar_t*)realloc(string, capacity * sizeof(wchar_t));
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
    string[*length] = '\0';

    return string;
}

wchar_t* getStringFromFile(const char* const nameFile, size_t* length)
{
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        return NULL;
    }

    size_t capacity = 1;

    wchar_t* string = (wchar_t*)malloc(sizeof(wchar_t));
    if (string == NULL)
    {
        return NULL;
    }

    for (wchar_t character = fgetwc(file); character != WEOF; character = fgetwc(file))
    {
        string[(*length)++] = character;
        if (*length >= capacity)
        {
            capacity *= 2;
            wchar_t* tmp = (wchar_t*)realloc(string, capacity * sizeof(wchar_t));
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
    string[*length] = '\0';
    fclose(file);

    return string;
}
