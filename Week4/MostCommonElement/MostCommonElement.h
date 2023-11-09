#pragma once

#include <stdlib.h>
#include <stdbool.h>

// Нахождение наиболее популярного элемента
int isTheMostCommon(const int* const array, const size_t length);

// Считывание массива из файла
int* openFile(size_t* const length, bool* const error);
