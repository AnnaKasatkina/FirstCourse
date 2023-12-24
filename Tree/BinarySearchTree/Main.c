#include "UserModule.h"
#include "Tests.h"

#include <stdbool.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#define ERROR 1

int main(int argc, char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "RunTests") == 0)
    {
        if (!testResult())
        {
            return ERROR;
        }
        return 0;
    }

    setlocale(LC_ALL, "Russian");
    printf("Добро пожаловать в Словарь!\n\n");

    Node* tree = NULL;

    while (true)
    {
        printf("Доступны следующие операции:\n"
            "0 - выйти\n1 - Добавить значение по заданному ключу в словарь\n"
            "2 - Получить значение по заданному ключу из словаря\n"
            "3 - Проверить наличие заданного ключа в словаре\n"
            "4 - Удалить заданный ключ и связанное с ним значение из словаря\nВаш выбор: ");

        size_t choice = 0;

        if (scanf("%zd", &choice) != 1)
        {
            deleteTree(&tree);
            printf("Ошибка ввода!");
            return ERROR;
        }

        printf("\n");
        choose(choice, &tree);
    }
    return 0;
}
