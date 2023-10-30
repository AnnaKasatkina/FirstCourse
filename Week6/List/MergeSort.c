#include "List.h"
#include "MergeSort.h"

#include <stdio.h>
#include <string.h>

void readFromFile(char* nameFile, List* list)
{
    FILE* file = fopen(nameFile, "r");
    if (file == NULL)
    {
        printf("File is not open\n");
        return;
    }

    while (!feof(file))
    {
        char* newEntry = (char*)malloc(sizeof(char) * BUFFERSIZE * 2);
        fscanf(file, "%s - %s", newEntry, newEntry + BUFFERSIZE);
        pushBack(list, newEntry);
    }
    fclose(file);
}

List* merge(List* first, List* second, int criteria)
{
    List* third;
    initList(&third);
    while (first->begin != first->end->next && second->begin != second->end->next)
    {
        char* firstString = first->begin->value + criteria * BUFFERSIZE;
        char* secondString = second->begin->value + criteria * BUFFERSIZE;
        if (strcmp(firstString, secondString) > 0)
        {
            pushBack(third, second->begin->value);
            second->begin = second->begin->next;
        }
        else
        {
            pushBack(third, first->begin->value);
            first->begin = first->begin->next;
        }
    }
    while (first->begin != first->end->next)
    {
        pushBack(third, first->begin->value);
        first->begin = first->begin->next;
    }

    while (second->begin != second->end->next)
    {
        pushBack(third, second->begin->value);
        second->begin = second->begin->next;
    }
    freeList(first);
    freeList(second);

    return third;
}

List* mergeSort(List* list, int criteria)
{
    if (getSize(list) <= 1)
    {
        return list;
    }
    List* listOne = (List*)malloc(sizeof(List));
    listOne->begin = list->begin;
    listOne->end = getElement(list, getSize(list) / 2 - 1);
    listOne->size = getSize(list) / 2;

    List* listTwo = (List*)malloc(sizeof(List));
    listTwo->begin = getElement(list, getSize(list) / 2);
    listTwo->end = list->end;
    listTwo->size = getSize(list) - getSize(listOne);

    listOne = mergeSort(listOne, criteria);
    listTwo = mergeSort(listTwo, criteria);

    free(list);

    return merge(listOne, listTwo, criteria);
}
