#include "Tests.h"
#include "Task3.h"

#include <stdlib.h>
#include <stdio.h>

static void printResultTest(const bool result, const char* const nameTest)
{
    printf(result ? "Test %s is OK\n" : "Test %s failed with an error\n", nameTest);
}

bool testResult(void)
{
    bool result1 = processString("Abc123_xyz");
    bool result2 = !processString("1_Arrr");

    printResultTest(result1, "with correct string");
    printResultTest(result2, "with wrong string");
    printf("\n");

    return result1 && result2;
}
