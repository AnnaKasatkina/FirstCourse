#include "CyclicList.h"

#include <stdlib.h>

void fillList(int amount, List* list)
{
    for (size_t i = 0; i < amount; i++)
    {
        pushBack(list, i);
    }
}

void count(int amount, int gap, List* list)
{
    int countAlive = amount;
    size_t killIndex = gap - 1;
    while (countAlive >= 2)
    {
        setAt(list, killIndex, -1);
        countAlive--;
        killIndex += gap;
    }
}

printResult(List* list)
{
    for (size_t i = 0; i < getSize(list); i++)
    {
        if (getAt(list, i) != -1) {
            printf("%d", getAt(list, i));
            break;
        }
    }
}
