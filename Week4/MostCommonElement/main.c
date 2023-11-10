#include "Sort.h"
#include "MostCommonElement.h"
#include "Tests.h"
#include "ReadFromFile.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define NAME "Array.txt"

void printArray(int const* const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
        printf("%d ", array[i]);
    printf("\n\n");
}

int main(void)
{
    if (!resultTests())
    {
        printf("Test error!");
        return ERROR;
    }

    size_t length = 0;
    int* array = openFile(&length, NAME);

    if (array == NULL)
    {
        printf("Error!");
        return ERROR;
    }

    printf("%d the most common element in the array: ", findTheMostCommon(array, length));
    printArray(array, length);

    free(array);
    return 0;
}
