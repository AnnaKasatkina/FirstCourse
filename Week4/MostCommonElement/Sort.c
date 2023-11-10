#include <stdio.h>

#include "Sort.h"

static void swap(int* const number1, int* const number2)
{
    const int tmp = *number1;
    *number1 = *number2;
    *number2 = tmp;
}

void quickSort(int* const begin, int* const end)
{
    if (end - begin <= 1)
    {
        return;
    }

    int* swapMarker = begin - 1;
    int* pivot = end - 1;
    int* pivotPos = NULL;
    for (int* currentIndex = begin; currentIndex != end; ++currentIndex)
    {
        if (*currentIndex <= *pivot)
        {
            ++swapMarker;
            if (currentIndex > swapMarker)
            {
                swap(currentIndex, swapMarker);
            }

            if (currentIndex == pivot)
            {
                pivotPos = swapMarker;
            }
        }
    }
    quickSort(begin, pivotPos);
    quickSort(pivotPos + 1, end);
}
