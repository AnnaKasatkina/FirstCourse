#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "PhoneBook.h"
#include "Utility.h"

#define ERROR "Ошибка!"

enum Choise
{
    exitProgram,
    addCommand,
    printCommand,
    searchPhoneCommand,
    searchNameCommand,
    saveCommand
};

static char* getElement(const char* const nameElement)
{
    printf("Введите %s контакта: ", nameElement);
    char* string = getString();
    return string;
}

static void methodEntryAdd(PhoneBookEntry* const buffer, const size_t length)
{
    char* name = getElement("имя");
    if (name == NULL)
    {
        return;
    }

    char* phone = getElement("телефон");
    if (phone == NULL)
    {
        return;
    }

    addEntry(buffer, length, name, phone);
}

static void printAllEntry(const PhoneBookEntry* const buffer, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        printf("%s - %s\n", buffer[i].name, buffer[i].phone);
    }
    printf("\n");
}

static void methodSearchPhone(const PhoneBookEntry* const buffer, const size_t length)
{
    char* name = getElement("имя");
    if (name == NULL)
    {
        return;
    }

    size_t index = searchPhone(buffer, length, name);

    if (index == -1)
    {
        printf("Имя не найден.\n\n");
        return;
    }
    printf("%s - %s\n\n", buffer[index].name, buffer[index].phone);
}

static void methodSearchName(const PhoneBookEntry* const buffer, const size_t length)
{
    char* phone = getElement("телефон");
    if (phone == NULL)
    {
        return;
    }

    size_t index = searchName(buffer, length, phone);

    if (index == -1)
    {
        printf("Номер не найден.\n\n");
        return;
    }
    printf("%s - %s\n\n", buffer[index].name, buffer[index].phone);
}

void choose(const int choice, PhoneBookEntry* const buffer, const size_t length)
{
    switch (choice)
    {
    case exitProgram:
        exit(EXIT_SUCCESS);
        break;

    case addCommand:
        methodEntryAdd(buffer, length);
        break;

    case printCommand:
        printAllEntry(buffer, length);
        break;

    case searchPhoneCommand:
        methodSearchPhone(buffer, length);
        break;

    case searchNameCommand:
        methodSearchName(buffer, length);
        break;

    case saveCommand:
        saveFile(buffer, length);
        break;

    default:
        printf("Введено неверное значение.\n");
        break;
    }
}
