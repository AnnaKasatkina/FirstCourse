#include "Stack.h"
#include "PostfixCalculator.h"
#include "Tests.h"
#include "Utility.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    printf("Enter an arithmetic expression: ");

    ErrorCode errorCode = ok;
    char* string = getString(&errorCode);
    if (errorCode == outOfMemory)
    {
        printf("Out of memory");
        return ERROR;
    }

    int result = postfixCalculator(string, &errorCode);
    if (errorCode != ok)
    {
        printf("Incorrect input data!");
        free(string);
        return ERROR;
    }
    printf("Result: %d", result);

    free(string);

    return 0;
}
