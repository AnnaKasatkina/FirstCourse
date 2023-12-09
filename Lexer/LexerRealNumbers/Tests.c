#include "Tests.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "LexerRealNumbers.h"

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

static bool testInteger(void)
{
    const char* const number = "321";
    return lexer(number);
}

static bool testRealNumber(void)
{
    const char* const number = "123.45e-6";
    return lexer(number);
}

static bool testWithoutE(void)
{
    const char* const number = "895.456";
    return lexer(number);
}

static bool testNotRealNumber(void)
{
    const char* const number = "895.5-5";
    return !lexer(number);
}

bool testResult(void)
{
    bool result1 = testInteger();
    bool result2 = testRealNumber();
    bool result3 = testWithoutE();
    bool result4 = testNotRealNumber();

    printResultTest(result1, "Integer");
    printResultTest(result2, "Real Number");
    printResultTest(result3, "Without E");
    printResultTest(result4, "Not Real Number");
    printf("\n");

    return result1 && result2 && result3 && result4;
}
