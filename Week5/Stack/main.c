#include "Stack.h"
#include "PostfixCalculator.h"

#include <string.h>
#include <stdio.h>

int main(void)
{
    ErrorCode errorCode = ok;
    char* string = getString(&errorCode);
    if (errorCode = outOfMemory)
    {
        printf("Out of memory");
        return -1;
    }

    removeSpaces(string);
    postfixCalculator(string);

    free(string);

    return 0;
}
