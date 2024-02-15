#include "Stack.h"
#include "ShuntingYard.h"
#include "Test.h"

#include <stdio.h>
#include <stdlib.h>

void printResult(const char* const output)
{
    printf("Answer: ");
    for (const char* character = output; *character != '\0'; ++character)
    {
        printf("%c ", *character);
    }
}

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    printf("Enter the expretion: ");
    ErrorCode errorCode = ok;
    size_t lengthOutput = 0;
    char* string = getString(&errorCode, &lengthOutput);
    if (errorCode == outOfMemory)
    {
        printf("Out of memory");
        return ERROR;
    }

    char* output = (char*)malloc((lengthOutput + 1) * sizeof(char));
    if (shuntingYard(string, output) != ok)
    {
        printf("Error!");
        return ERROR;
    }
    
    printResult(output);

    return 0;
}
