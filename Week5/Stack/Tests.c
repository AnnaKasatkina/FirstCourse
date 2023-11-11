#include "Tests.h"
#include "PostfixCalculator.h"
#include "Stack.h"

#include <stdio.h>

void printResultTest(const bool rezult, const char* const nameTest)
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

bool testCorrectSequence(void)
{
    char* testString = "96-12+*";
    ErrorCode errorCode = ok;
    const int answer = 9;

    int result = postfixCalculator(testString, &errorCode);
    if (errorCode != ok)
    {
        printf("Error! ");
        return false;
    }

    return answer == result;
}

bool testIncorrectSequence(void)
{
    char* testString = "96-12+*";
    ErrorCode errorCode = ok;
    const int answer = 8;

    int result = postfixCalculator(testString, &errorCode);
    if (errorCode != ok)
    {
        printf("Error! ");
        return false;
    }

    return answer != result;
}

bool resultTests(void)
{
    printResultTest(testCorrectSequence(), "Correct Sequence");
    printResultTest(testIncorrectSequence(), "Incorrect Sequence");
    printf("\n");

    return testCorrectSequence() && testIncorrectSequence();
}
