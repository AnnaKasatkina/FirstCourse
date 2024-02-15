#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LexerRealNumbers.h"
#include "Tests.h"
#include "Utility.h"

#define ERROR -1
#define ERROR_STRING "Error!"

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "RunTests") == 0)
    {
        if (!testResult())
        {
            return ERROR;
        }
        return 0;
    }

    printf("Enter the number: ");
    char *string = getString();
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
