#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "Task2.h"
#include "Tests.h"

#define ERROR -1
#define ERROR_STRING "Error!"

bool scanfArray(int* const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            return false;
        }
    }
    return true;
}

int* getArray(size_t* const length)
{
    printf("Enter length of array: ");
    if (scanf("%zu", length) != 1)
    {
        return NULL;
    }

    int* array = (int*)calloc(*length, sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }

    printf("Enter array: ");
    if (!scanfArray(array, *length))
    {
        free(array);
        return NULL;
    }
    return array;
}

void printArray(const int* const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) 
{
    if (!resultTests())
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    size_t length = 0;
    int* array = getArray(&length);
    if (array == NULL)
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    monkeySort(array, length);

    printf("Sorted array: ");
    printArray(array, length);

    free(array);
    return 0;
}
