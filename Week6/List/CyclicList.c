#include "CyclicList.h"

#include <stdlib.h>

#define START_INDEX 1

void fillList(const size_t amount, List* const list)
{
    for (size_t i = START_INDEX; i < amount + START_INDEX; i++)
    {
        pushBack(list, i);
    }
}

static size_t kill(List* const list, size_t index, const size_t gap)
{
    ListElement* currentElement = list->begin;
    size_t pointer = 0;

    for (size_t i = 0; i < index; i++)
    {
        currentElement = currentElement->next;
    }

    while (pointer != gap - 1)
    {
        if (currentElement->value != -1)
        {
            ++pointer;
        }
        currentElement = currentElement->next;
        ++index;
    }

    while (currentElement->value == -1)
    {
        currentElement = currentElement->next;
    }

    currentElement->value = -1;

    return index;
}

void count(const size_t amount, const size_t gap, List* const list)
{
    size_t countAlive = amount;
    size_t killIndex = 0;
    while (countAlive > gap - 1)
    {
        killIndex = kill(list, killIndex, gap);
        countAlive--;
    }
}

int* listToArray(const List* const list, const size_t gap)
{
    int* array = (int*)calloc(gap - 1, sizeof(int));
    ListElement* currentElement = list->begin;
    size_t index = 0;
    size_t length = getSize(list);

    for (size_t i = 0; i < length; i++)
    {
        if (currentElement->value != -1)
        {
            array[index] = currentElement->value;
            ++index;
        }
        currentElement = currentElement->next;
    }

    return array;
}

void printResult(const List* const list)
{
    printf("Safe place: ");
    for (size_t i = 0; i < getSize(list); i++)
    {
        if (getAt(list, i) != -1) {
            printf("%d ", getAt(list, i));
        }
    }
}
