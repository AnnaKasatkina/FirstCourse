/*
Написать программу — телефонный справочник.
Она должна уметь хранить имена и номера телефонов,
в интерактивном режиме осуществлять следующие операции:

0 - выйти
1 - добавить запись (имя и телефон)
2 - распечатать все имеющиеся записи
3 - найти телефон по имени
4 - найти имя по телефону
5 - сохранить текущие данные в файл

При запуске программа должна читать данные из файла (того самого, в который сохраняет данные),
если файла нет — начинать с пустой базы номеров. Размер базы ограничен сотней записей.
Поскольку операции над файловой системой дорогие по времени,
читаться файл должен только в начале программы, а записываться — только по команде пользователя.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

typedef struct
{
    char name[30];
    char phone[30];
} PhoneBookEntry;

void addEntry(PhoneBookEntry *buffer, int length)
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

void printAllEntry(PhoneBookEntry *buffer, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%s - %s\n", buffer[i].name, buffer[i].phone);
    }
    printf("\n");
}

void searchPhone(PhoneBookEntry *buffer, int length)
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

void searchName(PhoneBookEntry *buffer, int length)
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

void saveFile(PhoneBookEntry *buffer, int length)
{
    FILE *file = fopen("PhoneBook.txt", "w");

    for (int i = 0; i < length; i++)
    {
        fprintf(file, "%s - %s", buffer[i].name, buffer[i].phone);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Файл записан.\n\n");
}

void choose(int choice, PhoneBookEntry *buffer, int length)
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

int main()
{
    system("chcp 65001");
    printf("\nДобро пожаловать в телефонный справочник!\n\n");

    FILE *file = fopen("PhoneBook.txt", "a+");
    PhoneBookEntry buffer[100] = {};

    int length = 0;
    while (fscanf(file, "%s - %[^\n]", buffer[length].name, buffer[length].phone) == 2)
    {
        length++;
    }

    fclose(file);

    while (TRUE)
    {
        printf("Доступны следующие операции:\n"
               "0 - выйти\n1 - добавить запись (имя и телефон)\n2 - распечатать все имеющиеся записи\n"
               "3 - найти телефон по имени\n4 - найти имя по телефону\n5 - сохранить текущие данные в файл\nВаш выбор: ");

        int choice = 0;

        if (scanf("%d", &choice) != 1)
        {
            printf("Ошибка ввода!");
            return 1;
        }

        printf("\n");
        choose(choice, buffer, length);
        if (choice == 1)
            length++;
    }

    return 0;
}