#include "Utility.h"

#include <wchar.h>

wchar_t* getStringFromFile(const char* const nameFile, size_t* const length)
{
    FILE* file = fopen(nameFile, "a+");
    if (file == NULL)
    {
        return NULL;
    }

    return getString(file, length);
}

wchar_t* getString(FILE* file, size_t* const length)
{
    size_t capacity = 1;

    wchar_t* string = (wchar_t*)malloc(sizeof(wchar_t));
    if (string == NULL)
    {
        return NULL;
    }

    for (wchar_t character = fgetwc(file); character != WEOF && character != '\n'; character = fgetwc(file))
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
