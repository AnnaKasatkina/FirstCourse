#include "Tests.h"
#include "Task3.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

static bool testCase(const char* const nameFile, const char* const answer)
{
    char* string = getStringFromFile(nameFile);
    if (string == NULL)
    {
        return false;
    }
    return strcmp(string, answer) == 0;
}

bool testResult(void)
{
    bool result1 = testCase("TestClassicString.txt", "abcdthpf\n");
    bool result2 = testCase("TestOneElement.txt", "a\n");
    bool result3 = testCase("TestLineBreaks.txt", "\n");

    printResultTest(result1, "Classic String");
    printResultTest(result2, "One Element");
    printResultTest(result3, "Line Breaks");
    printf("\n");

    return result1 && result2 && result3;
}
