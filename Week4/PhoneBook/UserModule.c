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
    getchar();
    char* string = getString(stdin, '\n');
    return string;
}

static void menthodexitProgram(PhoneBook* const buffer)
{
    deletePhoneBook(buffer);
    exit(EXIT_SUCCESS);
}

static void methodEntryAdd(PhoneBook* const buffer)
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

    addEntry(buffer, name, phone);
    printf("\n");
}

static void methodSearchPhone(const PhoneBook* const buffer)
{
    char* name = getElement("имя");
    if (name == NULL)
    {
        return;
    }

    char* phone = searchElement(buffer, name, compareName)->phone;
    if (phone == NULL)
    {
        printf("Имя не найдено.\n\n");
        return;
    }

    printf("%s\n\n", phone);
}

static void methodSearchName(const PhoneBook* const buffer)
{
    char* phone = getElement("телефон");
    if (phone == NULL)
    {
        return;
    }

    char* name = searchElement(buffer, phone, comparePhone)->name;
    if (name == NULL)
    {
        printf("Номер не найден.\n\n");
        return;
    }

    printf("%s\n\n", name);
}

void choose(const int choice, PhoneBook* const buffer)
{
    switch (choice)
    {
    case exitProgram:
        menthodexitProgram(buffer);
        break;

    case addCommand:
        methodEntryAdd(buffer);
        break;

    case printCommand:
        printAllEntry(buffer);
        break;

    case searchPhoneCommand:
        methodSearchPhone(buffer);
        break;

    case searchNameCommand:
        methodSearchName(buffer);
        break;

    case saveCommand:
        saveFile(buffer);
        break;

    default:
        printf("Введено неверное значение.\n");
        break;
    }
}
