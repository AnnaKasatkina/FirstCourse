#include "Sort.h"
#include "MostCommonElement.h"
#include "tests.h"

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

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
    bool error = false;
    int* array = openFile(&length, &error);

    if (error == true)
    {
        printf("Error!");
        return ERROR;
    }

    quickSort(array, array + length);

    printf("%d the most common element in the array: ", isTheMostCommon(array, length));
    printArray(array, length);

    free(array);
    return 0;
}
