﻿#include "BinaryRepresentation.h"

#include <math.h>

static void plusOne(char* const array, const size_t length)
{
    int tmp = 1;
    for (size_t i = length; i-- > 0;)
    {
        int sum = array[i] + tmp;
        array[i] = (sum) % 2;

        tmp = sum == 2 ? 1 : 0;
    }
}

void binarySum(const char* const array1, const char* const array2, char* const result, const size_t length)
{
    int tmp = 0;
    for (size_t i = length; i-- > 0;)
    {
        int sum = array1[i] + array2[i] + tmp;
        result[i] = (sum) % 2;

        tmp = sum >= 2 ? 1 : 0;
    }
}

static void reverse(char* const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        array[i] = 1 - array[i];
    }
}

static void twosComplement(char* const array, const int number, const size_t length)
{
    if (number < 0)
    {
        reverse(array, length);
        plusOne(array, length);
    }
}

void conversionToBinary(char* const array, int number, const size_t length)
{
    int tmp = abs(number);
    for (size_t i = length; i-- > 0;)
    {
        array[i] = tmp % 2;
        tmp /= 2;
    }
    twosComplement(array, number, length);
}

static void minusOne(char* const array, const size_t length)
{
    int tmp = 0;
    for (size_t i = length; i-- > 0;)
    {
        int sum = array[i] + 1 + tmp;
        array[i] = (sum) % 2;

        tmp = sum >= 2 ? 1 : 0;
    }
}

int conversionToDecimal(char* const array, const size_t length)
{
    int number = 0;
    int sign = 1;
    if (array[0] == 1)
    {
        sign = -1;
        minusOne(array, length);
        reverse(array, length);
    }

    size_t index = length - 1;
    for (size_t i = 1; i < length; ++i)
    {
        number += array[i] * (int)pow(2, (double)(index - i));
    }
    return number * sign;
}
