#include "Tests.h"
#include "BalanceBrackets.h"
#include "Stack.h"

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

static bool testCorrectSequence(void)
{
    char *testString = "[{(This is a test)}]";

    return isBracketsCorrect(testString);
}

static bool testIncorrectSequence(void)
{
    char* testString = "This is a test )( }{ []";

    return (!isBracketsCorrect(testString));
}

static bool testWithoutBrackets(void)
{
    char* testString = "This is a test";

    return isBracketsCorrect(testString);
}

bool resultTests(void)
{
    bool answerOne = testCorrectSequence();
    bool answerTwo = testIncorrectSequence();
    bool answerThree = testWithoutBrackets();

    printResultTest(answerOne, "Correct Sequence");
    printResultTest(answerTwo, "Incorrect Sequence");
    printResultTest(answerThree, "Sequence Without Brackets");
    printf("\n");

    return answerOne && answerTwo && answerThree;
}
