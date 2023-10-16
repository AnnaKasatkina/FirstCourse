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

void scanfArray(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            printf("Input error ");
            break;
        }
    }
}

void printing(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

int movementOfSigns(int *array, int left, int right)
{
    int pivot = array[(left + right) / 2];
    while (left <= right)
    {
        while (array[left] < pivot)
        {
            left++;
        }

        while (array[right] > pivot)
        {
            right--;
        }

        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    }

    return left;
}

void insertionSort(int *array, int start, int end)
{
    for (start + 1; start < end; start++)
    {
        int sorted = start;
        while (sorted > -1 && array[sorted] > array[sorted + 1])
        {
            int temp = array[sorted];
            array[sorted] = array[sorted + 1];
            array[sorted + 1] = temp;
            sorted--;
        }
    }
}

void quickSort(int *array, int start, int end)
{
    if (end - start < 10)
    {
        insertionSort(array, start, end);
        return;
    }
    int rightStart = movementOfSigns(array, start, end);

    quickSort(array, start, rightStart - 1);
    quickSort(array, rightStart, end);
}

void testArray(int *rightTestingArray, int *testingArray, int lenght)
{
    for (int i = 0; i < lenght; ++i)
    {
        assert(rightTestingArray[i] == testingArray[i]);
    }
}

void testIncreasingArray()
{
    int lenght = 15;
    int testingArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int rightTestingArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    quickSort(testingArray, 0, lenght);
    testArray(rightTestingArray, testingArray, lenght);
    printf("Test Increasing Array is OK\n");
}

void testDecreasingArray()
{
    int lenght = 10;
    int testingArray[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int rightTestingArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    quickSort(testingArray, 0, lenght);
    testArray(rightTestingArray, testingArray, lenght);
    printf("Test Decreasing Array is OK\n");
}

void testIdenticalCharacters()
{
    int lenght = 15;
    int testingArray[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};
    int rightTestingArray[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

    quickSort(testingArray, 0, lenght);
    testArray(rightTestingArray, testingArray, lenght);
    printf("Test Identical Characters is OK\n");
}

int main(void)
{
    testIncreasingArray();
    testDecreasingArray();
    testIdenticalCharacters();

    int lenght = 0;
    printf("Enter lenght of array: ");
    if (scanf("%d", &lenght) != 1)
    {
        printf("Input error");
        return 1;
    }

    int *array = calloc(lenght, sizeof(int));
    scanfArray(array, lenght);

    quickSort(array, 0, lenght - 1);
    printing(array, lenght);

    free(array);
    return 0;
}