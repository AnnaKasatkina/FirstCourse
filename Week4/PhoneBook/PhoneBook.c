#include "PhoneBook.h"
#include "Utility.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool compareName(const PhoneBookEntry* const elementOne, const char* const elementTwo)
{
    return strcmp(elementOne->name, elementTwo) == 0;
}

bool comparePhone(const PhoneBookEntry* const elementOne, const char* const elementTwo)
{
    return strcmp(elementOne->phone, elementTwo) == 0;
}

void addEntry(PhoneBook* const buffer, const char* const name, const char* const phone, ErrorCode* errorCode)
{
    size_t length = ++buffer->length;
    if (length > SIZE)
    {
        *errorCode = outOfMemory;
        return;
    }
    buffer->entries[length] = (PhoneBookEntry*)calloc(1, sizeof(PhoneBook));
    if (buffer->entries[length] == NULL)
    {
        *errorCode = outOfMemory;
        return;
    }

    buffer->entries[length]->name = name;
    buffer->entries[length]->phone = phone;
}

PhoneBookEntry* searchElement(const PhoneBook* const buffer, const char* const name, CompareFunc compare)
{
    for (size_t i = 0; i < buffer->length; ++i)
    {
        if (compare(buffer->entries[i], name))
        {
            return buffer->entries[i];
        }
    }
    return NULL;
}

void deletePhoneBook(PhoneBook* const buffer)
{
    for (size_t i = 0; buffer->entries[i]; i++)
    {
        free(buffer->entries[i]->name);
        free(buffer->entries[i]->phone);
        free(buffer->entries[i]);
    }
    free(buffer);
}

PhoneBook* readPhoneBook(const char* const nameFile)
{
    PhoneBook* buffer = (PhoneBook*)calloc(SIZE, sizeof(PhoneBook));
    if (buffer == NULL)
    {
        return NULL;
    }

    FILE* file = fopen(nameFile, "a+");
    if (file == NULL)
    {
        free(buffer);
        return NULL;
    }

    size_t length = 0;
    size_t sizeString = 0;
    for (; !feof(file); ++length)
    {
        if (length > SIZE)
        {
            free(buffer);
            return NULL;
        }
        buffer->entries[length] = (PhoneBookEntry*)calloc(1, sizeof(PhoneBook));

        char* stringName = getString(file, '-');
        if (stringName == NULL)
        {
            free(buffer);
            return NULL;
        }
        buffer->entries[length]->name = stringName;

        char* stringPhone = getString(file, '\n');
        if (stringPhone == NULL)
        {
            free(buffer);
            return NULL;
        }
        buffer->entries[length]->phone = stringPhone;

    }
    --length;

    fclose(file);

    buffer->length = length;
    return buffer;
}

void saveFile(const PhoneBook* const buffer, ErrorCode* errorCode)
{
    FILE* file = fopen("PhoneBook.txt", "w");
    if (file == NULL)
    {
        *errorCode = fileError;
        return;
    }

    for (size_t i = 0; i < buffer->length; ++i)
    {
        fprintf(file, "%s-%s", buffer->entries[i]->name, buffer->entries[i]->phone);
        fprintf(file, "\n");
    }

    fclose(file);
}

void printAllEntry(const PhoneBook* const buffer)
{
    for (size_t i = 0; i < buffer->length; ++i)
    {
        printf("%s-%s\n", buffer->entries[i]->name, buffer->entries[i]->phone);
    }
    printf("\n");
}
