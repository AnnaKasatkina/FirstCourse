#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "PhoneBook.h"
#include "Utility.h"

#define ERROR "Ошибка!"

static void addEntry(PhoneBookEntry* const buffer, const size_t length)
{
    printf("Введите имя контакта: ");
    buffer[length].name = getString();
    if (buffer[length].name == NULL)
    {
        printf(ERROR);
        return;
    }

    printf("Введите номер телефона: ");
    buffer[length].phone = getString();
    if (buffer[length].phone == NULL)
    {
        printf(ERROR);
        return;
    }

    printf("\n");
}

static void printAllEntry(const PhoneBookEntry* const buffer, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        printf("%s - %s\n", buffer[i].name, buffer[i].phone);
    }
    printf("\n");
}

static void searchPhone(const PhoneBookEntry* const buffer, const size_t length)
{
    printf("Введите искомый номер: ");
    char* phone = getString();
    if (phone == NULL)
    {
        printf(ERROR);
        return;
    }

    bool flag = true;
    for (size_t i = 0; i < length; ++i)
    {
        if (!strcmp(buffer[i].phone, phone))
        {
            printf("%s - %s\n\n", buffer[i].name, buffer[i].phone);
            flag = false;
        }
    }
    if (flag)
    {
        printf("Номер не найден.\n\n");
    }
}

static void searchName(const PhoneBookEntry* const buffer, const size_t length)
{
    printf("Введите искомое имя: ");
    char* name = getString();
    if (name == NULL)
    {
        printf(ERROR);
        return;
    }

    bool flag = true;
    for (size_t i = 0; i < length; ++i)
    {
        if (!strcmp(buffer[i].name, name))
        {
            printf("%s - %s\n\n", buffer[i].name, buffer[i].phone);
            flag = false;
        }
    }
    if (flag)
    {
        printf("Имя не найдено.\n\n");
    }
}

void choose(const int choice, PhoneBookEntry* const buffer, const size_t length)
{
    switch (choice)
    {
    case 0:
        exit(EXIT_SUCCESS);
        break;

    case 1:
        addEntry(buffer, length);
        break;

    case 2:
        printAllEntry(buffer, length);
        break;

    case 3:
        searchPhone(buffer, length);
        break;

    case 4:
        searchName(buffer, length);
        break;

    case 5:
        saveFile(buffer, length);
        break;

    default:
        printf("Введено неверное значение.\n");
        break;
    }
}
