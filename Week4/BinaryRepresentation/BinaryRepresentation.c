#include "BinaryRepresentation.h"

#include <math.h>

void binarySum(int* const array1, const int* const array2, int* const rezult, const size_t length)
{
    int index = (int)(length - 1);
    for (int i = index; i >= 0; --i)
    {
        rezult[i] = (array1[i] + array2[i]) % 2;
        int sum = array1[i] + array2[i];

        if (sum >= 1 && i != 0)
        {
            array1[i - 1] += 1;
        }
    }
}

void conversionToBinary(int* const array, int number, const size_t length)
{
    number = abs(number);
    for (int i = (int)(length - 1); i >= 0; --i)
    {
        array[i] = number % 2;
        number /= 2;
    }
}

static void reverse(int* const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        array[i] = 1 - array[i];
    }
}

static int* fillArrayOne(const size_t length)
{
    int* one = (int*)calloc(length, sizeof(int));
    one[length - 1] = 1;
    return one;
}

void twosComplement(int* const array, const int number, const size_t length)
{
    conversionToBinary(array, number, length);
    if (number < 0)
    {
        reverse(array, length);
        int* one = fillArrayOne(length);
        binarySum(array, one, array, length);
        free(one);
    }
}

static int* fillArrayMinusOne(const size_t length)
{
    int* minusOne = (int*)calloc(length, sizeof(int));
    for (size_t i = 0; i < length; ++i)
    {
        minusOne[i] = 1;
    }
    return minusOne;
}

int conversionToDecimal(int* const array, const size_t length)
{
    int number = 0;
    int sign = 1;
    if (array[0] == 1)
    {
        sign = -1;
        int* minusOne = fillArrayMinusOne(length);
        binarySum(array, minusOne, array, length);
        reverse(array, length);
    }

    size_t index = length - 1;
    for (size_t i = 1; i < length; ++i)
    {
        number += array[i] * (int)pow(2, (double)(index - i));
    }
    return number *= sign;
}
