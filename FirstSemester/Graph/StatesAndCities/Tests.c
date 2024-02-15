#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "StatesAndCities.h"
#include "Tests.h"

static void printResultTest(const bool result, const char* const nameTest)
{
    printf(result ? "Test %s is OK\n" : "Test %s failed with an error\n", nameTest);
}

static bool testsCase(const char* const fileName, const int* const expectedResults, const size_t length)
{
    InputData* inputData = readDataFromFile(fileName);
    if (inputData == NULL)
    {
        return false;
    }
    distributeCities(inputData);

    int* array = convertToArray(inputData);
    if (array == NULL)
    {
        deleteInputData(&inputData);
        return false;
    }
    bool result = memcmp(array, expectedResults, length) == 0;

    free(array);
    deleteInputData(&inputData);
    return result;
}

static bool testOne(void)
{
    const int expectedResults[] = { -1, 1, 2, 5, -1, 4, 3, 6 };

    return testsCase("TestOne.txt", expectedResults, 8);
}

static bool testTwo(void)
{
    const int expectedResults[] = { -1, 1 };

    return testsCase("TestTwo.txt", expectedResults, 2);
}

static bool testThree(void)
{
    const int expectedResults[] = { -1, 1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6 };

    return testsCase("TestThree.txt", expectedResults, 12);
}

bool testResult(void)
{
    bool result1 = testOne();
    bool result2 = testTwo();
    bool result3 = testThree();

    printResultTest(result1, "with standard input data");
    printResultTest(result2, "with one city");
    printResultTest(result3, "where the whole city is the capital");
    printf("\n");

    return result1 && result2 && result3;
}
