#include "List.h"
#include "MergeSort.h"

#include <stdio.h>
#include <string.h>

List* merge(List* const first, List* const second, const Criteria criteria)
{
    List* third = initList();
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

List* mergeSort(List* const list, const Criteria criteria)
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