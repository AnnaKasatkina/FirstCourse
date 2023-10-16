#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void randomFilling(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        array[i] = 80 + rand() % 10;
    }
}

void printing(int *array, int lenght)
{
    for (int i = 0; i < lenght; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

int compare(const void *i, const void *j)
{
    return *(int *)i - *(int *)j;
}

void binarySearch(int number, int *array, int lenght)
{
    int left = 0;
    int right = lenght - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (number < array[middle])
            right = middle - 1;
        else if (number > array[middle])
            left = middle + 1;
        else
            printf("The number %d is in the array\n", number);
        break;
    }
    printf("The number %d is not in the array\n", number);
}

int main(void)
{
    int number = 0;
    int lenght = 0;

    printf("Enter lenght of array and number of numbers: ");
    scanf("%d %d", &lenght, &number);

    int *array = calloc(lenght, sizeof(int));
    int *numbersArray = calloc(number, sizeof(int));

    randomFilling(array, lenght);
    randomFilling(numbersArray, number);

    qsort(array, lenght, sizeof(int), compare);

    printf("\nArray: ");
    printing(numbersArray, number);

    printf("Numbers: ");
    printing(array, lenght);

    for (int i = 0; i < number; ++i)
    {
        binarySearch(numbersArray[i], array, lenght);
    }

    free(array);
    free(numbersArray);
    return 0;
}