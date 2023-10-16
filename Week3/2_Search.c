#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INTERVAL 100

void randomFilling(int *const array, const size_t length)
{
    srand(time(NULL));
    for (size_t i = 0; i < length; ++i)
    {
        array[i] = rand() % INTERVAL;
    }
}

void printArray(int const *const array, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
        printf("%d ", array[i]);
    printf("\n\n");
}

int compare(const void *i, const void *j)
{
    return *(int *)i - *(int *)j;
}

void binarySearch(const size_t number, int const *const array, const size_t length)
{
    int left = 0;
    int right = length - 1;
    bool find = false;

    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (number < array[middle])
        {
            right = middle - 1;
        }
        else if (number > array[middle])
        {
            left = middle + 1;
        }
        else
        {
            printf("The number %d is in the array\n", number);
            find = true;
            break;
        }
    }
    if (!find)
    {
        printf("The number %d is not in the array\n", number);
    }
}

int main(void)
{
    const size_t number = 0;
    const size_t length = 0;

    printf("Enter length of array and number of numbers: ");
    scanf("%d %d", &length, &number);

    int *array = (int *)calloc(length, sizeof(int));
    int *numbersArray = (int *)calloc(number, sizeof(int));

    randomFilling(array, length);
    randomFilling(numbersArray, number);

    qsort(array, length, sizeof(int), compare);

    printf("\nArray: ");
    printArray(array, length);

    printf("Numbers: ");
    printArray(numbersArray, number);

    for (int i = 0; i < number; ++i)
    {
        binarySearch(numbersArray[i], array, length);
    }

    free(array);
    free(numbersArray);
    return 0;
}