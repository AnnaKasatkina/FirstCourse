#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#include "PhoneBook.h"

void addEntry(PhoneBookEntry* buffer, int length)
{
    printf("Введите имя контакта: ");
    if (scanf("%s", buffer[length].name) != 1)
    {
        printf("Ошибка!");
    }

    printf("Введите номер телефона: ");
    if (scanf("%s", buffer[length].phone) != 1)
    {
        printf("Ошибка!");
    }

    printf("\n");
}

void printAllEntry(PhoneBookEntry* buffer, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%s - %s\n", buffer[i].name, buffer[i].phone);
    }
    printf("\n");
}

void searchPhone(PhoneBookEntry* buffer, int length)
{
    printf("Введите искомый номер: ");
    const char phone[30] = "";
    if (scanf("%s", &phone) != 1)
    {
        printf("Ошибка!");
        return;
    }

    bool flag = TRUE;
    for (int i = 0; i < length; i++)
    {
        if (!strcmp(buffer[i].phone, phone))
        {
            printf("%s - %s\n\n", buffer[i].name, buffer[i].phone);
            flag = FALSE;
        }
    }
    if (flag)
        printf("Номер не найден.\n\n");
}

void searchName(PhoneBookEntry* buffer, int length)
{
    printf("Введите искомое имя: ");
    const char name[30] = "";
    if (scanf("%s", &name) != 1)
    {
        printf("Ошибка!");
        return;
    }

    bool flag = TRUE;
    for (int i = 0; i < length; i++)
    {
        if (!strcmp(buffer[i].name, name))
        {
            printf("%s - %s\n\n", buffer[i].name, buffer[i].phone);
            flag = FALSE;
        }
    }
    if (flag)
        printf("Имя не найдено.\n\n");
}

void saveFile(PhoneBookEntry* buffer, int length)
{
    FILE* file = fopen("PhoneBook.txt", "w");

    for (int i = 0; i < length; i++)
    {
        fprintf(file, "%s - %s", buffer[i].name, buffer[i].phone);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Файл записан.\n\n");
}

void choose(int choice, PhoneBookEntry* buffer, int length)
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
        printf("Введено неверное значение.");
        break;
    }
}