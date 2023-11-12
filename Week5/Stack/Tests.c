#include "Tests.h"
#include "PostfixCalculator.h"
#include "Stack.h"

#include <stdio.h>

#define ERROR_STR "Error!\n"

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

static bool testCorrectSequence(void)
{
    char* testString = "9 6 - 1 2 + *";
    ErrorCode errorCode = ok;
    const int answer = 9;

    int result = postfixCalculator(testString, &errorCode);
    if (errorCode != ok)
    {
        printf(ERROR_STR);
        return false;
    }

    return answer == result;
}

static bool testMultiplication(void)
{
    char* testString = "5 3 *";
    ErrorCode errorCode = ok;
    const int answer = 15;

    int result = postfixCalculator(testString, &errorCode);
    if (errorCode != ok)
    {
        printf(ERROR_STR);
        return false;
    }

    return answer == result;
}

bool resultTests(void)
{
    printResultTest(testCorrectSequence(), "Correct Sequence");
    printResultTest(testMultiplication(), "Incorrect Sequence");
    printf("\n");

    return testCorrectSequence() && testMultiplication();
}
