/*
Пузырёк и подсчёт
Написать сортировки пузырьком и подсчётом.
С помощью функции clock() из time.h
сравнить времена их работы на массиве из 100000 элементов.
Задача предполагает использование выделяемого с помощью malloc()
и освобождаемого с помощью free() массива.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

#define LEN 100000
#define RANGE 100000

typedef void (*SortMethod)(int *const, const size_t);

void randomFilling(int *const array, const size_t length)
{
    srand(time(NULL));
    for (size_t i = 0; i < length; ++i)
    {
        array[i] = rand() % RANGE;
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
    for (size_t i = 0; i < length; ++i)
        printf("%d ", array[i]);
    printf("\n\n");
}

void bubbleSort(int *const array, const size_t length)
{
    for (size_t i = 1; i < length; ++i)
    {
        for (size_t j = 1; j < length - i + 1; ++j)
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
        ++sortedMask[array[i]];
    }

    int index = 0;
    for (size_t i = 0; i < lenghtMask; ++i)
    {
        for (size_t j = sortedMask[i]; j > 0; --j)
        {
            array[index] = i;
            ++index;
        }
    }

    free(sortedMask);
}

bool compareArrays(int const *const array1, int const *const rightArray, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (array1[i] != rightArray[i])
        {
            return false;
        }
    }
    return true;
}

void printRezult(const bool rezult, const char *const nameTest, const char *const method)
{
    if (rezult)
    {
        printf("Test %s with %s is OK\n", nameTest, method);
    }
    else
    {
        printf("Test %s with %s failed with an error\n", nameTest, method);
    }
}

void testReverseArray()
{
    const size_t length = 5;
    int array1[] = {5, 4, 3, 2, 1};
    int array2[] = {5, 4, 3, 2, 1};
    int rightArray[] = {1, 2, 3, 4, 5};

    bubbleSort(array1, length);
    const bool rezult1 = compareArrays(array1, rightArray, length);
    printRezult(rezult1, "ReverseArray", "bubbleSort");

    countSort(array2, length);
    const bool rezult2 = compareArrays(array2, rightArray, length);
    printRezult(rezult2, "ReverseArray", "countSort");
}

void testIdenticalElements()
{
    const size_t length = 5;
    int array1[] = {2, 2, 2, 2, 2};
    int array2[] = {2, 2, 2, 2, 2};
    int rightArray[] = {2, 2, 2, 2, 2};

    bubbleSort(array1, length);
    const bool rezult1 = compareArrays(array1, rightArray, length);
    printRezult(rezult1, "IdenticalElements", "bubbleSort");

    countSort(array2, length);
    const bool rezult2 = compareArrays(array2, rightArray, length);
    printRezult(rezult2, "IdenticalElements", "countSort");
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

    printf("\nSelect the operating mode:\n"
           "1. Measuring the running time on an array of 100,000 elements\n"
           "2. User input\n"
           "Your choice: ");
    size_t choice = 0;
    scanf("%lu", &choice);

    if (choice == 1)
    {
        const size_t length = LEN;
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
        size_t length = 0;
        scanf("%lu", &length);

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

        free(array);
    }
    else
    {
        printf("Incorrect input!");
    }
    return 0;
}
