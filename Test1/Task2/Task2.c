#include "Task2.h"

#include <time.h>
#include <stdlib.h>

static bool isSorted(const int* const array, const size_t size)
{
    for (size_t i = 1; i < size; ++i)
    {
        if (array[i - 1] > array[i])
        {
            return false;
        }
    }
    return true;
}

void monkeySort(int* const array, const size_t size)
{
    srand((unsigned int)time(NULL));
    while (!isSorted(array, size))
    {
        for (size_t i = size - 1; i > 0; --i)
        {
            size_t j = rand() % (i + 1);
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}
