#include "CyclicList.h"

#include <stdlib.h>
#include <stdio.h>

#define START_INDEX 1

void fillList(const size_t amount, List* const list, ErrorCode* errorCode)
{
    for (int i = START_INDEX; i < amount + START_INDEX; ++i)
    {
        pushBack(list, i, errorCode);
        if (*errorCode != ok)
        {
            return;
        }
    }
}

size_t kill(const size_t amount, const size_t gap, List* const list)
{
    ListElement* currentElement = list->begin;
    size_t index = 0;

    while (list->begin != list->end)
    {
        currentElement = getSubsequentElement(currentElement, gap);
        eraseNextElement(currentElement, list);
        currentElement = currentElement->next;
    }

    return list->begin->value;
}
