/*
Нулевые элементы
Программа, считающая количество нулевых элементов в массиве.
*/

#include <stdio.h>

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

    int counter = 0;
    for (int i = 0; i < LEN; i++)
    {
        if (array[i] == 0)
        {
            counter++;
        }
    }

    printf("There are %d null elements.", counter);

    return 0;
}