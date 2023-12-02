#include "List.h"
#include "MergeSort.h"
#include "test.h"

#include <stdio.h>
#include <string.h>

#define ERROR -1

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    List* list = 0;
    initList(&list);

    readFromFile("file.txt", list);

    Criteria choice = 0;
    printf("Select mode:\n"
        "0. Sort by name\n"
        "1. Sorting by phone\n"
        "Your choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Input error!");
        return ERROR;
    }

    if (choice != byName && choice != byNumber)
    {
        printf("Wrong input!");
        return ERROR;
    }

    list = mergeSort(list, choice);
    printList(list);

    freeList(list);

    return 0;
}
