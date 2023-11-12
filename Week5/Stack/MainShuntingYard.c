#include "Stack.h"
#include "ShuntingYard.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    if (!resultTests())
    {
        printf("Error!");
        return ERROR;
    }

    printf("Enter the expretion: ");
    ErrorCode errorCode = ok;
    char* string = (char*)malloc(sizeof(char));
    int length = getString(&errorCode, &string);
    if (errorCode == outOfMemory)
    {
        printf("Out of memory");
        return ERROR;
    }

    char* output = (char*)malloc((length + 1) * sizeof(char));
    if (shuntingYard(string, output) != ok)
    {
        printf("Error!");
        return ERROR;
    }
    
    printf("Answer: % s\n", output);

    return 0;
}
