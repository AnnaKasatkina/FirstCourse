/*
3. Самый частый элемент
Найти наиболее часто встречающийся элемент в массиве быстрее,
чем за O(n^2). Если таких элементов несколько, надо вывести любой из них.
*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

#define INTERVAL 20
#define ERROR -1

void randomFilling(int *const array, const size_t length)
{
    srand(time(NULL));
    for (size_t i = 0; i < length; ++i)
    {
        array[i] = rand() % INTERVAL;
    }
}

void printArray(const int *const array, size_t length)
{
    for (size_t i = 0; i < length; ++i)
        printf("%d ", array[i]);
    printf("\n\n");
}

int compare(const void *const i, const void *const j)
{
    return *(const int *const)i - *(const int *const)j;
}

int mostCommonElement(const int *const array, size_t length)
{
    size_t count = 1;
    size_t maxCount = 0;
    int answer = 0;
    for (size_t i = 1; i <= length; ++i)
    {
        if (array[i] == array[i - 1])
        {
            ++count;
        }
        else if (count >= maxCount)
        {
            answer = array[i - 1];
            maxCount = count;
        }
        count = 1;
    }
    return answer;
}

void printResultTest(const bool rezult, const char *const nameTest)
{
    if (rezult)
    {
        printf("Test %s is OK\n", nameTest);
    }
    else
    {
        printf("Test %s failed with an error\n", nameTest);
    }
}

bool testCase(int * const testingArray, size_t length, const int answer)
{
    qsort(testingArray, length, sizeof(int), compare);
    int rezult = mostCommonElement(testingArray, length);

    return rezult == answer;
}

bool testMostCommonElement(void)
{
    int testingArray[] = {5, 4, 3, 2, 1, 5, 4, 3, 5};
    return testCase(testingArray, 9, 5);
}

bool testIdenticalElements(void)
{
    int testingArray[] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    return testCase(testingArray, 9, 3);
}

bool resultTests(void)
{
    const bool answerOne = testMostCommonElement();
    const bool answerTwo = testIdenticalElements();

    printResultTest(answerOne, "Most Common Element");
    printResultTest(answerTwo, "Identical Elements");
    printf("\n");

    return (answerOne && answerTwo);
}

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    size_t length = 0;
    printf("Enter the length of array: ");
    if (scanf("%d", &length) != 1)
    {
        printf("Input error!");
    }

    int *array = (int *)calloc(length, sizeof(int));
    randomFilling(array, length);
    qsort(array, length, sizeof(int), compare);

    printf("%d the most common element in the array: ", mostCommonElement(array, length));
    printArray(array, length);

    free(array);
    return 0;
}
