#include <stdio.h>
#include "Sort.h"

void insertionSort(int* array, int start, int end)
{
    for (start + 1; start < end; start++)
    {
        int sorted = start;
        while (sorted > -1 && array[sorted] > array[sorted + 1])
        {
            int temp = array[sorted];
            array[sorted] = array[sorted + 1];
            array[sorted + 1] = temp;
            sorted--;
        }
    }
}