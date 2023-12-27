#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    if (!testsResult())
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

    Node* tree = makeTreeFromArray(array, length);
    if (tree == NULL)
    {
        free(array);
        printf(ERROR_STRING);
        return ERROR;
    }

    size_t index = 0;
    orderTree(tree, array, &index);

    printf("Sorted array: ");
    printArray(array, length);

    free(array);
    deleteTree(&tree);
    return 0;
}