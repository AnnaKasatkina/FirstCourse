#include <stdlib.h>
#include <stdio.h>

#include "StatesAndCities.h"
#include "Tests.h"

static bool compareArrays(const int* const array1, const int* const array2, const size_t length)
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

static void printResultTest(const bool result, const char* const nameTest)
{
    printf(result ? "Test %s is OK\n" : "Test %s failed with an error\n", nameTest);
}

static bool testsCase(const char* const fileName, const int* const expectedResults, size_t length)
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
    bool result = compareArrays(array, expectedResults, length);

    free(array);
    deleteInputData(&inputData);
    return result;
}

static bool testOne(void)
{
    const int expectedResults[] = { 1, 2, 5, 4, 3, 6 };

    return testsCase("TestOne.txt", expectedResults, 6);
}

static bool testTwo(void)
{
    const int expectedResults[] = { 1 };

    return testsCase("TestTwo.txt", expectedResults, 1);
}

static bool testThree(void)
{
    const int expectedResults[] = { 1, 2, 3, 4, 5, 6 };

    return testsCase("TestThree.txt", expectedResults, 6);
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
