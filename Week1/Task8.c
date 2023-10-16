/*
8. Массив
Дан массив целых чисел x1...xm + n,
рассматриваемый как соединение двух его отрезков:
начала x1...xm длины m и конца xm + 1...xm + n длины n.
Не используя дополнительных массивов,
переставить местами начало и конец.
*/

#include <stdio.h>

void arrayReverse(int *array, int start, int end)
{
    char variable = 0;
    while (start < end)
    {
        variable = array[start];
        array[start] = array[end];
        array[end] = variable;
        start++;
        end--;
    }
}

#define LEN 10

int main()
{
    int array[LEN] = {0};
    printf("Enter %d numbers\n", LEN);

    for (int i = 0; i < LEN; i++)
    {
        printf("%d. ", i + 1);
        scanf("%d", &array[i]);
    }

    int m = 0;
    printf("Enter the length of the first segment less than %d: ", LEN);
    scanf("%d", &m);

    arrayReverse(array, 0, m - 1);
    arrayReverse(array, m, LEN - 1);
    arrayReverse(array, 0, LEN - 1);

    printf("Reverse array: ");
    for (int i = 0; i < LEN; i = i + 1)
    {
        printf("%d ", array[i]);
    }

    return 0;
}