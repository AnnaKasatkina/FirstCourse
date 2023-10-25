#include "Tests.h"
#include "BalanceBrackets.h"
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

bool testCorrectSequence()
{
    char *testString = "[{(This is a test)}]";
    bool answer = true;

    bool result = isBracketsCorrect(testString);
    if (result != answer)
    {
        return false;
    }
    return true;
}

bool testIncorrectSequence()
{
    char* testString = "This is a test )( }{ []";
    bool answer = false;

    bool result = isBracketsCorrect(testString);
    if (result != answer)
    {
        return false;
    }
    return true;
}

bool testWithoutBrackets()
{
    char* testString = "This is a test";
    bool answer = true;

    bool result = isBracketsCorrect(testString);
    if (result != answer)
    {
        return false;
    }
    return true;
}

bool resultTests()
{
    printResultTest(testCorrectSequence(), "Correct Sequence");
    printResultTest(testIncorrectSequence(), "Incorrect Sequence");
    printResultTest(testWithoutBrackets(), "Sequence Without Brackets");
    printf("\n");

    if (testCorrectSequence() && testIncorrectSequence() && testWithoutBrackets())
    {
        return true;
    }
    return false;
}
