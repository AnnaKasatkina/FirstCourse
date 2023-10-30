#include "List.h"
#include "MergeSort.h"
#include "test.h"

#include <stdio.h>
#include <string.h>

#define ERROR -1

void printList(List* list)
{
    for (size_t i = 0; i < getSize(list); i++)
    {
        printf("%s - %s\n", getAt(list, i), getAt(list, i) + BUFFERSIZE);
    }
}

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

    int choice = 0;
    printf("Select mode:\n"
        "0. Sort by name\n"
        "1. Sorting by phone\n"
        "Your choice: ");

    if (scanf("%d", &choice) != 1)
    {
        printf("Input error!");
        return ERROR;
    }

    if (choice != 1 && choice != 0)
    {
        printf("Wrong input!");
        return ERROR;
    }

    list = mergeSort(list, choice);
    printList(list);

    return 0;
}
