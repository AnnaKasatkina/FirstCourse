#include <stdio.h>
#include <stdbool.h>

#define LEN 10

int sumDigits(int number)
{
    int sum = 0;
    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int searchMaxSum(int* array)
{
    int maxSum = 0;
    for (size_t i = 0; i < LEN; i++)
    {
        int sum = sumDigits(array[i]);
        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }
    return maxSum;
}

void maxSum(int* array, int* answer)
{
    int maxSum = searchMaxSum(array);
    int index = 0;

    for (size_t i = 0; i < LEN; i++)
    {
        int sum = sumDigits(array[i]);
        if (sum == maxSum)
        {
            answer[index] = array[i];
            ++index;
        }
    }
}

void printResult(int* answer)
{
    int index = 0;
    do
    {
        printf("%d ", answer[index]);
        ++index;
    } while ((answer[index] != 0));
}

bool compareArrays(int const* const array1, int const* const array2, const size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (array1[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}

void testOne()
{
    int testArray[5] = { 123, 4567, 4568, 23465, 856742 };
    int result[5] = { 0 };

    int testAnswer[5] = { 856742, 0, 0, 0, 0 };

    maxSum(testArray, result);
    if (compareArrays(testAnswer, result, 5))
    {
        printf("testOne is ok\n");
        return;
    }
    printf("Error with testOne\n");
}

void testIdentical()
{
    int testArray[5] = { 123, 123, 123, 123, 123 };
    int result[5] = { 0 };

    int testAnswer[5] = { 123, 123, 123, 123, 123 };

    maxSum(testArray, result);
    if (compareArrays(testAnswer, result, 5))
    {
        printf("testIdentical is ok\n");
        return;
    }
    printf("Error with testIdentical\n");
}

int main()
{
    testOne();
    testIdentical();

    int array[LEN] = { 123, 1234, 3646, 2345, 345, 377, 2345, 9864, 1, 9855 };
    int answer[LEN] = { 0 };

    maxSum(array, answer);
    printResult(answer);

    return 0;
}