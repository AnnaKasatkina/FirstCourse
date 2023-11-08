#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PhoneBook.h"

int print(size_t length, PhoneBookEntry *buffer)
{
    while (true)
    {
        printf("Доступны следующие операции:\n"
            "0 - выйти\n1 - добавить запись (имя и телефон)\n2 - распечатать все имеющиеся записи\n"
            "3 - найти телефон по имени\n4 - найти имя по телефону\n5 - сохранить текущие данные в файл\nВаш выбор: ");

        int choice = 0;

        if (scanf("%d", &choice) != 1)
        {
            return 1;
        }

        printf("\n");
        choose(choice, buffer, length);
        if (choice == 1)
        {
            length++;
        }
    }
    return 0;
}

size_t openFile(PhoneBookEntry* buffer)
{
    FILE* file = fopen("PhoneBook.txt", "a+");

    size_t length = 0;
    while (fscanf(file, "%s - %[^\n]", buffer[length].name, buffer[length].phone) == 2)
    {
        length++;
    }

    fclose(file);

    return length;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Добро пожаловать в телефонный справочник!\n\n");


    PhoneBookEntry buffer[100] = { 0 };
    size_t length = openFile(buffer);

    if (print(length, buffer) != 0)
    {
        printf("Ошибка ввода!");
        return 1;
    }

    return 0;
}