#include <stdlib.h>
#include <math.h>

#define LEN 10

int* numberToArray(int number, size_t* const length)
{
    int* array = (int*)calloc(LEN, sizeof(int));
    if (array == NULL)
    {
        return NULL;
    }

    while (number != 0)
    {
        array[*length] = number % 10;
        number /= 10;
        ++(*length);
    }

    return array;
}

void bubbleSort(int* const array, const size_t length)
{
    for (size_t i = 1; i < length; ++i)
    {
        for (size_t j = 1; j < length - i + 1; ++j)
        {
            if (array[j] < array[j - 1])
            {
                int intermediate = array[j];
                array[j] = array[j - 1];
                array[j - 1] = intermediate;
            }
        }
    }
}

int arrayToNumber(const int* const array, const size_t length)
{
    int number = 0;
    for (size_t i = 0; i < length; ++i)
    {
        number += array[i] * pow(10, length - i - 1);
    }
    return number;
}