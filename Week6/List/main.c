#include "List.h"
#include "SortingList.h"

#include <locale.h>
#include <stdbool.h>

int main(void)
{
    setlocale(LC_ALL, "Russian");
    printf("����� ���������� � ������������� ������!\n\n");

    List* list = NULL;
    initList(&list);

    while (true)
    {
        printf("�������� ��������� ��������:\n"
            "0 - �����\n1 - �������� �������� � ������������� ������\n"
            "2 - ������� �������� �� ������\n3 - ����������� ������\n��� �����: ");

        size_t choice = 0;

        if (scanf("%zd", &choice) != 1)
        {
            printf("������ �����!");
            return 1;
        }

        printf("\n");
        choose(choice, list);
    }

    freeList(list);

    return 0;
}
