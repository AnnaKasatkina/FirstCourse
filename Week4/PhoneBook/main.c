#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PhoneBook.h"
#include "Utility.h"
#include "Tests.h"
#include "UserModule.h"

#define ERROR -1

int main(void)
{
    if (!resultTests())
    {
        printf("Error tests!");
        return ERROR;
    }

    setlocale(LC_ALL, "Russian");
    printf("Добро пожаловать в телефонный справочник!\n\n");

    PhoneBook* buffer = readPhoneBook("PhoneBook.txt");
    if (buffer == NULL)
    {
        return ERROR;
    }

    while (true)
    {
        printf("Доступны следующие операции:\n"
            "0 - выйти\n1 - добавить запись (имя и телефон)\n2 - распечатать все имеющиеся записи\n"
            "3 - найти телефон по имени\n4 - найти имя по телефону\n5 - сохранить текущие данные в файл\nВаш выбор: ");

        int choice = 0;

        if (scanf("%d", &choice) != 1)
        {
            printf("Ошибка ввода!");
            return ERROR;
        }

        printf("\n");
        choose(choice, buffer);
        if (choice == 1)
        {
            ++buffer->length;
        }
    }

    return 0;
}
