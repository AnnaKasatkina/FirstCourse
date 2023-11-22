#include "Utility.h"

#include <stdio.h>
#include <ctype.h>

char* getStringFromFile(const char* const nameFile)
{
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        return NULL;
    }

    size_t length = 0;
    size_t capacity = 1;

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        return NULL;
    }

    for (char character = fgetc(file); character != EOF; character = fgetc(file))
    {
        if (character != ' ')
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
                    return NULL;
                }
            }
        }
    }
    string[length] = '\0';

    fclose(file);
    return string;
}

void printResult(char* string)
{
    printf("( ");
    for (char* character = string; *character != '\0'; (*character)++)
    {
        if (isdigit(*character) && )
        {

        }
    }
    printf(") ");
}
