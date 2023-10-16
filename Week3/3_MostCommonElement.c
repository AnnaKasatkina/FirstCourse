/*
3. Самый частый элемент
Найти наиболее часто встречающийся элемент в массиве быстрее,
чем за O(n^2). Если таких элементов несколько, надо вывести любой из них.
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

#define LEN 20

void randomFilling(int *array)
{
    for (int i = 0; i < LEN; i++)
    {
        array[i] = 80 + rand() % 20;
    }
}

void printing(int *array)
{
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

int compare(const void *i, const void *j)
{
    return *(int *)i - *(int *)j;
}

int mostCommonElement(int *array)
{
    int count = 1;
    int max = 0;
    int answer = 0;
    for (int i = 1; i < LEN; ++i)
    {
        if (array[i] == array[i - 1])
        {
            count++;
        }
        else
        {
            if (count >= max)
            {
                answer = array[i - 1];
                max = count;
                count = 1;
            }
            count = 1;
        }
    }
    return answer;
}

void testMostCommonElement()
{
    int testingArray[] = {5, 4, 3, 2, 1, 5, 4, 3, 5};
    int lenght = 9;
    int answer = 5;

    qsort(testingArray, lenght, sizeof(int), compare);
    int rezult = mostCommonElement(testingArray);
    assert(rezult == answer);

    printf("Test Most Common Element is OK\n");
}

void testIdenticalElements()
{
    int testingArray[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    int lenght = 9;
    int answer = 3;

    qsort(testingArray, lenght, sizeof(int), compare);
    int rezult = mostCommonElement(testingArray);
    assert(rezult == answer);

    printf("Test Most Common Element with Identical Elements is OK\n\n");
}

int main(void)
{
    testMostCommonElement();
    testIdenticalElements();

    int *array = calloc(LEN, sizeof(int));
    randomFilling(array);
    qsort(array, LEN, sizeof(int), compare);

    printf("%d the most common element in the array: ", mostCommonElement(array));
    printing(array);

    free(array);
    return 0;
}
