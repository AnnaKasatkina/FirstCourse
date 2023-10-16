/*
Пузырёк и подсчёт
Написать сортировки пузырьком и подсчётом.
С помощью функции clock() из time.h
сравнить времена их работы на массиве из 100000 элементов.
Задача предполагает использование выделяемого с помощью malloc()
и освобождаемого с помощью free() массива.
*/

#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

typedef void (*SortMethod)(int *const, const size_t);

void randomFilling(int *const array, const size_t length)
{
    srand(time(NULL));
    for (size_t i = 0; i < length; i++)
    {
        array[i] = rand();
    }
}

int searchMaximum(int const *const array, const size_t length)
{
    int max = 0;
    for (size_t i = 0; i < length; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void printArray(int const *const array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

void bubbleSort(int *const array, const size_t length)
{
    for (size_t i = 1; i < length; i++)
    {
        for (size_t j = 1; j < length; j++)
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

void countSort(int *const array, const size_t length)
{
    int max = searchMaximum(array, length);
    int lenghtMask = max + 1;
    int *sortedMask = (int *)calloc(lenghtMask, sizeof(int));

    for (size_t i = 0; i < length; ++i)
    {
        sortedMask[array[i]]++;
    }

    int index = 0;
    for (size_t i = 0; i < lenghtMask; ++i)
    {
        for (size_t j = sortedMask[i]; j > 0; j--)
        {
            array[index] = i;
            index++;
        }
    }

    free(sortedMask);
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

void testReverseArray()
{
    const size_t length = 5;
    int testingArrayOne[] = {5, 4, 3, 2, 1};
    int testingArrayTwo[] = {5, 4, 3, 2, 1};
    int rightTestingArray[] = {1, 2, 3, 4, 5};
    int max = searchMaximum(testingArrayOne, length);
    int lenghtMask = max + 1;
    int *sortedMask = (int *)calloc(lenghtMask, sizeof(int));

    bubbleSort(testingArrayOne, length);
    if (compareArrays(rightTestingArray, testingArrayOne, length))
    {
        printf("Test Reverse Array with bubbleSort is OK\n");
    }
    else
    {
        printf("Test Reverse Array with bubbleSort failed with an error\n");
    }

    countSort(testingArrayTwo, length);
    if (compareArrays(rightTestingArray, testingArrayTwo, length))
    {
        printf("Test Reverse Array with countSort is OK\n\n");
    }
    else
    {
        printf("Test Reverse Array with countSort failed with an error\n\n");
    }

    free(sortedMask);
}

void testIdenticalElements()
{
    const size_t length = 5;
    int testingArrayOne[] = {2, 2, 2, 2, 2};
    int testingArrayTwo[] = {2, 2, 2, 2, 2};
    int rightTestingArray[] = {2, 2, 2, 2, 2};
    int max = searchMaximum(testingArrayOne, length);
    int lenghtMask = max + 1;
    int *sortedMask = (int *)calloc(lenghtMask, sizeof(int));

    bubbleSort(testingArrayOne, length);
    if (compareArrays(rightTestingArray, testingArrayOne, length))
    {
        printf("Test Identical Elements with bubbleSort is OK\n");
    }
    else
    {
        printf("Test Identical Elements with bubbleSort failed with an error\n");
    }

    countSort(testingArrayTwo, length);
    if (compareArrays(rightTestingArray, testingArrayTwo, length))
    {
        printf("Test Identical Elements with countSort is OK\n\n");
    }
    else
    {
        printf("Test Identical Elements with countSort failed with an error\n\n");
    }

    free(sortedMask);
}

double calcDuration(SortMethod method, int *const array, const size_t length)
{
    double timeSpent = 0.0;
    clock_t begin = clock();
    method(array, length);
    clock_t end = clock();
    timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;
    return timeSpent;
}

int main(void)
{
    testReverseArray();
    testIdenticalElements();

    printf("Select the operating mode:\n"
           "1. Measuring the running time on an array of 100,000 elements\n"
           "2. User input\n"
           "Your choice: ");
    const size_t choice = 0;
    scanf("%d", &choice);

    if (choice == 1)
    {
        const size_t length = 100000;
        int *array = (int *)calloc(length, sizeof(int));
        randomFilling(array, length);

        double timeSpentOne = calcDuration(bubbleSort, array, length);
        printf("bubbleSort - %f\n", timeSpentOne);

        double timeSpentTwo = calcDuration(countSort, array, length);
        printf("countSort - %f\n", timeSpentTwo);

        free(array);
    }

    else if (choice == 2)
    {
        printf("Enter the length of the array: ");
        const size_t length = 0;
        scanf("%d", &length);

        int *array = (int *)calloc(length, sizeof(int));
        randomFilling(array, length);

        printf("Array:\n");
        printArray(array, length);

        printf("CountSort array:\n");
        countSort(array, length);
        printArray(array, length);

        printf("BubbleSort array:\n");
        bubbleSort(array, length);
        printArray(array, length);
    }
    else
    {
        printf("Incorrect input!");
    }
    return 0;
}