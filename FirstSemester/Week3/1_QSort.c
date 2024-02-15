/*
1. Умный QSort
Реализовать qsort, который для сортировки кусков массива
размером меньше 10 использует сортировку вставкой.
Поскольку qsort делит массив на части и сортирует каждую qsort-ом же,
можно добиться заметного ускорения, если совсем уж маленькие части сортировать
квадратичной сортировкой с меньшей константой. Эту идею и надо реализовать.
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#define LEN 10
#define ERROR -1

int scanfArray(int *const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            return ERROR;
        }
    }
    return 0;
}

void printArray(const int *const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
        printf("%d ", array[i]);
    printf("\n\n");
}

void insertionSort(int *const start, int *const end)
{
    int *index = start + 1;
    for (index; index != end; ++index)
    {
        int newElement = *index;
        int *location = index - 1;
        while (location >= start && *location > newElement)
        {
            *(location + 1) = *location;
            --location;
        }
        *(location + 1) = newElement;
    }
}

void swap(int *const number1, int *const number2)
{
    int tmp = *number1;
    *number1 = *number2;
    *number2 = tmp;
}

void quickSort(int *const begin, int *const end)
{
    if (end - begin <= 1)
    {
        return;
    }

    if (end - begin <= LEN)
    {
        insertionSort(begin, end);
        return;
    }

    int *swapMarker = begin - 1;
    int *pivot = end - 1;
    int *pivotPos = NULL;
    for (int *currentIndex = begin; currentIndex != end; ++currentIndex)
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

bool compareArrays(const int *const array1, const int *const array2, const size_t length)
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

void printResultTest(const bool rezult, const char *const nameTest)
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

bool testIncreasingArray()
{
    const size_t length = 5;
    int array1[] = {0, 1, 2, 3, 4};
    int array2[] = {0, 1, 2, 3, 4};

    quickSort(array1, array1 + length);
    return compareArrays(array1, array2, length);
}

bool testDecreasingArray()
{
    const size_t length = 10;
    int array1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int array2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    quickSort(array1, array1 + length);
    return compareArrays(array1, array2, length);
}

bool testIdenticalCharacters()
{
    const size_t length = 15;
    int array1[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    int array2[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

    quickSort(array1, array1 + length);
    return compareArrays(array1, array2, length);
}

bool resultTests(void)
{
    const bool answerOne = testIncreasingArray();
    const bool answerTwo = testDecreasingArray();
    const bool answerThree = testIdenticalCharacters();

    printResultTest(answerOne, "Increasing Array");
    printResultTest(answerTwo, "Decreasing Array");
    printResultTest(answerTwo, "Identical Characters");
    printf("\n");

    return (answerOne && answerTwo && answerThree);
}

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    size_t length = 0;
    printf("Enter length of array: ");
    if (scanf("%lu", &length) != 1)
    {
        printf("Input error");
        return ERROR;
    }

    int *array = (int *)calloc(length, sizeof(int));
    if (scanfArray(array, length) == ERROR)
    {
        printf("Input error!");
        return ERROR;
    }

    quickSort(array, array + length);
    printArray(array, length);

    free(array);
    return 0;
}