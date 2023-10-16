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

// Для режима тестирования установить для LEN значение 5
#define LEN 5

void randomFilling(int *array)
{
    for (int i = 0; i < LEN; i++)
    {
        array[i] = rand() % 1000;
        printf("%d ", array[i]);
    }
}

void sort(int *array)
{
    int firstNumber = array[0];
    int j = LEN - 1;
    int i = 0;

    while (i != j)
    {
        if (array[i] > array[i + 1])
        {
            int intermediate = 0;

            intermediate = array[i];
            array[i] = array[i + 1];
            array[i + 1] = intermediate;
            i++;
        }
        else
        {
            int intermediate = 0;

            intermediate = array[j];
            array[j] = array[i + 1];
            array[i + 1] = intermediate;
            j--;
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

void testIncreasingArray()
{
    int testingArray[] = {0, 1, 2, 3, 4};
    int rightTestingArray[] = {0, 2, 3, 4, 1};

    sort(testingArray);
    testArray(rightTestingArray, testingArray);
    printf("Test Increasing Array is OK\n");
}

void testDecreasingArray()
{
    int testingArray[] = {6, 5, 4, 3, 2};
    int rightTestingArray[] = {5, 4, 3, 2, 6};

    sort(testingArray);
    testArray(rightTestingArray, testingArray);
    printf("Test Decreasing Array is OK\n");
}

void testIdenticalCharacters()
{
    int testingArray[] = {6, 6, 6, 6, 6};
    int rightTestingArray[] = {6, 6, 6, 6, 6};

    sort(testingArray);
    testArray(rightTestingArray, testingArray);
    printf("Test tIdentical Characters is OK\n");
}

void printing(int *array)
{
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

int main()
{
    if (LEN == 5)
    {
        testIncreasingArray();
        testDecreasingArray();
        testIdenticalCharacters();
    }

    printf("\nOriginal array: ");
    int array[LEN] = {};

    randomFilling(array);
    sort(array);
    printf("\nSorting array: ");
    printing(array);

    return 0;
}
