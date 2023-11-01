#include "CyclicList.h"

#include <stdlib.h>
#include <stdio.h>

#define START_INDEX 1

void fillList(const size_t amount, List* const list)
{
    for (size_t i = START_INDEX; i < amount + START_INDEX; ++i)
    {
        pushBack(list, i);
    }
}

static size_t kill(List* const list, size_t index, const size_t gap)
{
    ListElement* currentElement = getElement(list, index);
    size_t pointer = 0;

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
    size_t killIndex = gap - 1;
    while (countAlive > gap - 1)
    {
        erase(list, killIndex);
        killIndex = killIndex % countAlive + gap - 1;
        --countAlive;
    }
}

void printResult(const List* const list)
{
    printf("Safe place: ");
    for (size_t i = 0; i < getSize(list); ++i)
    {
        if (getAt(list, i) != -1) {
            printf("%d ", getAt(list, i));
        }
    }
}
