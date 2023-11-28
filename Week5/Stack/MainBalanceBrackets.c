#include "Stack.h"
#include "BalanceBrackets.h"
#include "Tests.h"
#include "Utility.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define ERROR -1

void printResult(CodeBrackets result)
{
    if (result == correct)
    {
        printf("Correct");
    }
    else
    {
        printf("Incorrect");
    }
    printf("\n");
}

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    printf("Enter the text: ");
    ErrorCode errorCode = ok;
    char* string = getString(&errorCode);
    if (errorCode == outOfMemory)
    {
        printf("Out of memory");
        return ERROR;
    }

    CodeBrackets result = isBracketsCorrect(string);
    if (result == memoryError)
    {
        printf("Out of memory");
        return ERROR;
    }

    printResult(result);

    free(string);

    return 0;
}
