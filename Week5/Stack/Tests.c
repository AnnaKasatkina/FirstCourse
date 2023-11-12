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

static bool testCase(char* testString, const int answer)
{
    ErrorCode errorCode = ok;

    int result = postfixCalculator(testString, &errorCode);
    if (errorCode != ok)
    {
        printf(ERROR_STR);
        return false;
    }

    return answer == result;
}

static bool testSequence(void)
{
    char* testString = "9 6 - 1 2 + * 3 /";
    const int answer = 3;

    return testCase(testString, answer);
}

static bool testMultiplication(void)
{
    char* testString = "5 3 *";
    const int answer = 15;

    return testCase(testString, answer);
}

static bool testDivision(void)
{
    char* testString = "8 2 /";
    const int answer = 4;

    return testCase(testString, answer);
}

static bool testSubtraction(void)
{
    char* testString = "6 1 -";
    const int answer = 5;

    return testCase(testString, answer);
}

static bool testAddition(void)
{
    char* testString = "2 2 +";
    const int answer = 4;

    return testCase(testString, answer);
}

bool resultTests(void)
{
    const bool answerOne = testSequence();
    const bool answerTwo = testMultiplication();
    const bool answerThree = testDivision();
    const bool answerFour = testSubtraction();
    const bool answerFive = testAddition();

    printResultTest(answerOne, "Sequence");
    printResultTest(answerTwo, "Multiplication");
    printResultTest(answerThree, "Division");
    printResultTest(answerFour, "Subtraction");
    printResultTest(answerFive, "Addition");
    printf("\n");

    return answerOne && answerTwo && answerThree && answerFour && answerFive;
}
