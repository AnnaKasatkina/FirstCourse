#pragma once

#include <stdlib.h>

// Подсчет суммы двух числе в двоичной системе
void binarySum(const char* const array1, const char* const array2, char* const result, const size_t length);

// Перевод числа в двоичное представление
void conversionToBinary(char* const array, int number, const size_t length);

// Перевод числа в десятичное представление
int conversionToDecimal(char* const array, const size_t length);
