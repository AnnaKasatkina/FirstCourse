#include "Stack.h"
#include "PostfixCalculator.h"
#include "Tests.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return -1;
    }

    ErrorCode errorCode = ok;
    char* string = getString(&errorCode);
    if (errorCode == outOfMemory)
    {
        printf("Out of memory");
        return -1;
    }

    removeSpaces(string);
    int result = postfixCalculator(string, &errorCode);
    if (errorCode != ok)
    {
        printf("Incorrect input data!");
        return -1;
    }
    printf("Result: %d", result);

    free(string);

    return 0;
}
