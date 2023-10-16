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

void randomFilling(int *const array, const size_t length)
{
    srand(time(NULL));
    for (size_t i = 0; i < length; i++)
    {
        array[i] = rand();
    }
}

void swap(int *const array, size_t i, size_t j)
{
    int intermediate = array[j];
    array[j] = array[i + 1];
    array[i + 1] = intermediate;
}

void halfQSort(int *const array, const size_t length)
{
    size_t j = length - 1;
    size_t i = 0;

    while (i != j)
    {
        if (array[i] > array[i + 1])
        {
            swap(array, i, i);
            i++;
        }
        else
        {
            swap(array, i, j);
            j--;
        }
    }
}

bool compareArrays(int const *const rightTestingArray, int const *const testingArray, const size_t length)
{
    bool identical = true;
    for (size_t i = 0; i < length; ++i)
    {
        if (rightTestingArray[i] != testingArray[i])
        {
            identical = false;
        }
    }
    return identical;
}

void testIncreasingArray()
{
    const size_t length = 5;
    int testingArray[] = {0, 1, 2, 3, 4};
    int rightTestingArray[] = {0, 2, 3, 4, 1};

    halfQSort(testingArray, length);
    if (compareArrays(rightTestingArray, testingArray, length))
    {
        printf("Test Increasing Array is OK\n");
    }
    else
    {
        printf("Test Increasing Array failed with an error\n");
    }
}

void testDecreasingArray()
{
    const size_t length = 10;
    int testingArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int rightTestingArray[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 10};

    halfQSort(testingArray, length);
    if (compareArrays(rightTestingArray, testingArray, length))
    {
        printf("Test Decreasing Array is OK\n");
    }
    else
    {
        printf("Test Decreasing Array failed with an error\n");
    }
}

void testIdenticalCharacters()
{
    const size_t length = 15;
    int testingArray[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    int rightTestingArray[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

    halfQSort(testingArray, length);
    if (compareArrays(rightTestingArray, testingArray, length))
    {
        printf("Test Identical Characters is OK\n");
    }
    else
    {
        printf("Test Identical Characters failed with an error\n");
    }
}

void printArray(int const *const array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

int main()
{

    testIncreasingArray();
    testDecreasingArray();
    testIdenticalCharacters();

    printf("Enter the length of the array: ");
    const size_t length = 0;
    scanf("%d", &length);

    int *array = (int *)calloc(length, sizeof(int));
    randomFilling(array, length);

    printf("\nOriginal array: ");
    printArray(array, length);

    halfQSort(array, length);
    printf("\nSorting array: ");
    printArray(array, length);

    return 0;
}