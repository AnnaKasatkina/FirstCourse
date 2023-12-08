#include "List.h"
#include "CyclicList.h"
#include "Tests.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define MEMORY_ERROR "Memory Error!"

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

    if (scanf("%zd %zd", &amount, &gap) != 2) {
        printf("Input Error");
        return ERROR;
    }

    List* list = (List*)calloc(1, sizeof(List));
    if (list == NULL)
    {
        printf(MEMORY_ERROR);
        return ERROR;
    }

    ErrorCode errorCode = ok;
    fillList(amount, list, &errorCode);
    if (errorCode != ok)
    {
        printf(MEMORY_ERROR);
        return ERROR;
    }

    size_t answer = kill(amount, gap, list);
    printf("Safe place if %zd", answer);

    freeList(list);

    return 0;
}
