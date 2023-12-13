#include "Tests.h"

#include <stdlib.h>
#include <stdio.h>

static void printResultTest(const bool rezult, const char* const nameTest)
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

static bool testCase(const int number, const int answer)
{
    size_t length = 0;
    int* array = numberToArray(number, &length);
    bubbleSort(array, length);
    int result = arrayToNumber(array, length);
    return answer == result;
}

bool testResult(void)
{
    bool result1 = testCase(2147483647, 1234446778);
    bool result2 = testCase(123456, 123456);
    bool result3 = testCase(54321, 12345);

    printResultTest(result1, "Max number");
    printResultTest(result2, "Ready number");
    printResultTest(result3, "Reverse number");
    printf("\n");

    return result1 && result2 && result3;
}