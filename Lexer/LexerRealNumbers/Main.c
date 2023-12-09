#include <stdio.h>
#include <stdlib.h>

#include "LexerRealNumbers.h"
#include "Tests.h"
#include "Utility.h"

#define ERROR -1
#define ERROR_STRING "Error!"

int main() 
{
    if (!testResult())
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    printf("Enter the number: ");
    char* string = getString();
    if (string == NULL)
    {
        printf(ERROR_STRING);
        return ERROR;
    }

    if (lexer(string))
    {
        printf("This is a real number\n");
    }
    else 
    {
        printf("This is not a real number\n");
    }

    free(string);
    return 0;
}
