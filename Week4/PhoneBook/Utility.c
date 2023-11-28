#include "Utility.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

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

PhoneBookEntry* readPhoneBook(const char* const nameFile, size_t* length)
{
    PhoneBookEntry* buffer = (PhoneBookEntry*)calloc(SIZE, sizeof(PhoneBookEntry));
    FILE* file = fopen(nameFile, "a+");
    if (file == NULL)
    {
        return NULL;
    }

    for (; !feof(file); ++(*length))
    {
        buffer[*length].name = getElement(file, '-');
        buffer[*length].phone = getElement(file, '\n');
    }
    --(*length);

    fclose(file);
    return buffer;
}

char* getString(void)
{
    size_t length = 0;
    size_t capacity = 1;

    char* string = (char*)malloc(sizeof(char));
    if (string == NULL)
    {
        return NULL;
    }

    getchar();
    for (char character = getchar(); character != '\n'; character = getchar())
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
    string[length] = '\0';

    return string;
}

void saveFile(const PhoneBookEntry* const buffer, const size_t length)
{
    FILE* file = fopen("PhoneBook.txt", "w");

    for (size_t i = 0; i < length; ++i)
    {
        fprintf(file, "%s - %s", buffer[i].name, buffer[i].phone);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Файл записан.\n\n");
}
