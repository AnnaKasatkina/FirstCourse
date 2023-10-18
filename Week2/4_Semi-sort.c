/*
Полукусорт
Написать программу, которая заполняет массив случайными значениями
(с использованием функции rand из stdlib.h),
потом преобразует его без использования дополнительных массивов так,
что в начале массива будут элементы, меньшие первого,
а в конце — большие либо равные первому.
Программа должна работать за линейное время.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

#define RANGE 10000

void randomFilling(int *const array, const size_t length)
{
    srand(time(NULL));
    for (size_t i = 0; i < length; ++i)
    {
        array[i] = rand() % RANGE;
    }
}

void swap(int *const array, const size_t i, const size_t j)
{
    int intermediate = array[j];
    array[j] = array[i];
    array[i] = intermediate;
}

void halfQSort(int *const array, const size_t length)
{
    size_t j = length - 1;
    size_t i = 0;

    while (i != j)
    {
        if (array[i] > array[i + 1])
        {
            swap(array, i + 1, i);
            ++i;
        }
        else
        {
            swap(array, i + 1, j);
            --j;
        }
    }
}

bool compareArrays(int const *const array1, int const *const array2, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}

void printRezult(const bool rezult, const char *const nameTest)
{
    if (rezult)
    {
        printf("Test %s is OK\n", nameTest);
    }
    else
    {
        printf("Test %s failed with an error\n", nameTest);
    }
}

void testIncreasingArray()
{
    const size_t length = 5;
    int array1[] = {0, 1, 2, 3, 4};
    int array2[] = {0, 2, 3, 4, 1};

    halfQSort(array1, length);
    const bool rezult = compareArrays(array1, array2, length);
    printRezult(rezult, "Increasing Array");
}

void testDecreasingArray()
{
    const size_t length = 10;
    int array1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int array2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 10};

    halfQSort(array1, length);
    const bool rezult = compareArrays(array1, array2, length);
    printRezult(rezult, "Decreasing Array");
}

void testIdenticalCharacters()
{
    const size_t length = 15;
    int array1[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    int array2[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

    halfQSort(array1, length);
    const bool rezult = compareArrays(array1, array2, length);
    printRezult(rezult, "Identical Characters");
}

void printArray(int const *const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
        printf("%d ", array[i]);
    printf("\n\n");
}

int main()
{
    testIncreasingArray();
    testDecreasingArray();
    testIdenticalCharacters();

    printf("Enter the length of the array: ");
    size_t length = 0;
    scanf("%lu", &length);

    int *array = (int *)calloc(length, sizeof(int));
    randomFilling(array, length);

    printf("\nOriginal array: ");
    printArray(array, length);

    halfQSort(array, length);
    printf("\nSorting array: ");
    printArray(array, length);

    free(array);

    return 0;
}
