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

// Для режима тестирования установить для LEN значение 5
#define LEN 100000

void randomFilling(int *array)
{
    for (int i = 0; i < LEN; i++)
    {
        array[i] = 80 + rand() % 1000;
    }
}

int searchMaximum(int *array)
{
    int max;
    for (int i = 0; i < LEN; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void printing(int *array)
{
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

void bubbleSort(int *array)
{
    for (int i = 1; i < LEN; i++)
    {
        for (int j = 1; j < LEN; j++)
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

void calculationSort(int *array, int *sortedMask, int lenghtMask)
{
    for (int i = 0; i < LEN; ++i)
    {
        sortedMask[array[i]]++;
    }

    int index = 0;
    for (int i = 0; i < lenghtMask; ++i)
    {
        int j = sortedMask[i];
        for (; j > 0; j--)
        {
            array[index] = i;
            index++;
        }
    }
}

void testArray(int *rightTestingArray, int *testingArray)
{
    for (int i = 0; i < LEN; ++i)
    {
        assert(rightTestingArray[i] == testingArray[i]);
    }
}

void testReverseArray()
{
    int testingArray[] = {5, 4, 3, 2, 1};
    int rightTestingArray[] = {1, 2, 3, 4, 5};
    int max = searchMaximum(testingArray);
    int lenghtMask = max + 1;
    int *sortedMask = calloc(lenghtMask, sizeof(int));

    bubbleSort(testingArray);
    testArray(rightTestingArray, testingArray);
    printf("Test Reverse Array with bubbleSort is OK\n");

    calculationSort(testingArray, sortedMask, lenghtMask);
    testArray(rightTestingArray, testingArray);
    printf("Test Reverse Array with calculationSort is OK\n\n");

    free(sortedMask);
}

void testIdenticalElements()
{
    int testingArray[] = {2, 2, 2, 2, 2};
    int rightTestingArray[] = {2, 2, 2, 2, 2};
    int max = searchMaximum(testingArray);
    int lenghtMask = max + 1;
    int *sortedMask = calloc(lenghtMask, sizeof(int));

    bubbleSort(testingArray);
    testArray(rightTestingArray, testingArray);
    printf("Test Identical Elements with bubbleSort is OK\n");

    calculationSort(testingArray, sortedMask, lenghtMask);
    testArray(rightTestingArray, testingArray);
    printf("Test Identical Elements with calculationSort is OK\n\n");

    free(sortedMask);
}

int main(void)
{
    if (LEN == 5)
    {
        testReverseArray();
        testIdenticalElements();
    }

    int array[LEN] = {0};
    randomFilling(array);

    int max = searchMaximum(array);
    int lenghtMask = max + 1;
    int *sortedMask = calloc(lenghtMask, sizeof(int));

    // printf("Array:\n");
    //  printing(array);

    double timeSpentOne = 0.0;
    clock_t beginOne = clock();
    bubbleSort(array);
    clock_t endOne = clock();
    timeSpentOne += (double)(endOne - beginOne) / CLOCKS_PER_SEC;
    printf("bubbleSort - %f\n", timeSpentOne);

    // printf("Sorted array:\n");
    // printing(array);

    double timeSpentTwo = 0.0;
    clock_t beginTwo = clock();
    calculationSort(array, sortedMask, lenghtMask);
    clock_t endTwo = clock();
    timeSpentTwo += (double)(endTwo - beginTwo) / CLOCKS_PER_SEC;
    printf("calculationSort - %f\n", timeSpentTwo);

    // printf("Sorted array:\n");
    // printing(array);

    free(sortedMask);

    return 0;
}