#include "Test.h"
#include "ShuntingYard.h"
#include "Stack.h"

#include <stdio.h>
#include <string.h>

static void printResultTest(const bool result, const char* const nameTest)
{
    if (result)
    {
        printf("Test %s is OK\n", nameTest);
    }
    else
    {
        printf("Test %s failed with an error\n", nameTest);
    }
}

static bool testWithMultiplication(void)
{
    char* testString = "7+2*2-7*9";
    char* correctString = "722*+79*-";
    char output[10] = "";

    shuntingYard(testString, output);

    return (strcmp(output, correctString) == 0);
}

static bool testWithBrackets(void)
{
    char* testString = "7/(1+2)*3+3";
    char* correctString = "712+/3*3+";
    char output[12] = "";

    shuntingYard(testString, output);

    return (strcmp(output, correctString) == 0);
}

static bool testAllOperations(void)
{
    char* testString = "5-5+5*5/5";
    char* correctString = "55-55*5/+";
    char output[10] = "";

    shuntingYard(testString, output);

    return (strcmp(output, correctString) == 0);
}

bool resultTests(void)
{
    bool answerOne = testWithMultiplication();
    bool answerTwo = testWithBrackets();
    bool answerThree = testAllOperations();

    printResultTest(answerOne, "With Multiplication");
    printResultTest(answerTwo, "With Brackets");
    printResultTest(answerThree, "All Operations");
    printf("\n");

    return answerOne && answerTwo && answerThree;
}
