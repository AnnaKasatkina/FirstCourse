#include "List.h"
#include "CyclicList.h"
#include "test.h"

#include <stdio.h>

#define ERROR -1

int main(void) 
{
    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    printf("Enter the number of wars and kill rate: ");
    size_t gap = 0;
    size_t amount = 0;

    if (scanf("%zu %zu", &amount, &gap) != 2) {
        printf("Input Error");
        return ERROR;
    }

    List* list = 0;
    initList(&list);

    fillList(amount, list);
    count(amount, gap, list);
    printResult(list);

    freeList(list);

    return 0;
}
