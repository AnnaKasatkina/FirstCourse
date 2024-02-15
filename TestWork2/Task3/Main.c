#include <stdio.h>

#include "Task3.h"
#include "Tests.h"
#include "Utility.h"

#define ERROR -1

int main(void) 
{
    if (!testResult())
    {
        printf("Error!");
        return ERROR;
    }

    printf("Enter the string: ");
    char* string = getString();
    if (string == NULL)
    {
        printf("Error!");
        return ERROR;
    }

    printf(processString(string) ? "Correct!\n" : "Wrong!\n");
    free(string);
    return 0;
}
