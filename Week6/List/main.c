#include "List.h"
#include "SortingList.h"

#include <locale.h>
#include <stdbool.h>

int main(void)
{
    setlocale(LC_ALL, "Russian");
    printf("Добро пожаловать в сортированный список!\n\n");

    List* list = NULL;
    initList(&list);

    while (true)
    {
        printf("Доступны следующие операции:\n"
            "0 - выйти\n1 - добавить значение в сортированный список\n"
            "2 - удалить значение из списка\n3 - распечатать список\nВаш выбор: ");

        size_t choice = 0;

        if (scanf("%zd", &choice) != 1)
        {
            printf("Ошибка ввода!");
            return 1;
        }

        printf("\n");
        choose(choice, list);
    }

    freeList(list);

    return 0;
}
