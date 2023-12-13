#include <stdio.h>

#include "Task1.h"
#include "Tests.h"

#define ERROR -1

int main(void)
{
    if (!testResult())
    {
        printf("Test Error!");
        return ERROR;
    }

    int number = 0;
    printf("Enter Natural number: ");
    if (scanf("%d", &number) != 1 || number <= 0)
    {
        printf("Error!");
        return ERROR;
    }

    size_t length = 0;
    int* array = numberToArray(number, &length);
    bubbleSort(array, length);
    int result = arrayToNumber(array, length);

    printf("Min number: %d\n", result);
}