#include "Stack.h"
#include "BalanceBrackets.h"
#include "Tests.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 256

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return -1;
    }

    printf("Enter the text: ");
    ErrorCode errorCode = ok;
    char* string = getString(&errorCode);
    if (errorCode == outOfMemory)
    {
        printf("Out of memory");
        return -1;
    }

    bool result = isBracketsCorrect(string);
    printResult(result);

    return 0;
}
