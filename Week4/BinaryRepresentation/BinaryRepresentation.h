#pragma once

#include <stdlib.h>

// Подсчет суммы двух числе в двоичной системе
void binarySum(const int* const array1, const int* const array2, int* const rezult, const size_t length);

// Перевод числа в двоичное представление
void conversionToBinary(int* const array, int number, const size_t length);

// Перевод числа в десятичное представление
int conversionToDecimal(int* const array, const size_t length);
